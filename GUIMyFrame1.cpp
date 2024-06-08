#include "GUIMyFrame1.h"

static wxString WrapText(const wxString& text, size_t maxLineLength)
{
    wxString result;
    size_t length = text.length();
    for (size_t i = 0; i < length; i += maxLineLength)
    {
        result += text.Mid(i, maxLineLength);
        if (i + maxLineLength < length)
            result += '\n';
    }
    return result;
}

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent ), m_compressionLevel(20), m_currentImageIndex(0), m_totalImageCount(0)
{
    m_image.AddHandler(new wxJPEGHandler);
    m_image.AddHandler(new wxPNGHandler);
    m_image.AddHandler(new wxTIFFHandler);

    m_scrolledWindow1->Bind(wxEVT_PAINT, &GUIMyFrame1::OnPaint, this);
    m_scrolledWindow1->Bind(wxEVT_SIZE, &GUIMyFrame1::OnSize, this);

    m_scrolledWindow1->Bind(wxEVT_SCROLLWIN_TOP, &GUIMyFrame1::OnScroll, this);
    m_scrolledWindow1->Bind(wxEVT_SCROLLWIN_BOTTOM, &GUIMyFrame1::OnScroll, this);
    m_scrolledWindow1->Bind(wxEVT_SCROLLWIN_LINEUP, &GUIMyFrame1::OnScroll, this);
    m_scrolledWindow1->Bind(wxEVT_SCROLLWIN_LINEDOWN, &GUIMyFrame1::OnScroll, this);
    m_scrolledWindow1->Bind(wxEVT_SCROLLWIN_PAGEUP, &GUIMyFrame1::OnScroll, this);
    m_scrolledWindow1->Bind(wxEVT_SCROLLWIN_PAGEDOWN, &GUIMyFrame1::OnScroll, this);
    m_scrolledWindow1->Bind(wxEVT_SCROLLWIN_THUMBTRACK, &GUIMyFrame1::OnScroll, this);
    m_scrolledWindow1->Bind(wxEVT_SCROLLWIN_THUMBRELEASE, &GUIMyFrame1::OnScroll, this);
    m_scrolledWindow1->Bind(wxEVT_SCROLLWIN_THUMBRELEASE, &GUIMyFrame1::OnScrollThumbRelease, this);
    m_scrolledWindow1->Bind(wxEVT_SCROLLWIN_THUMBTRACK, &GUIMyFrame1::OnScrollThumbTrack, this);

    m_choice_measurements->Bind(wxEVT_CHOICE, &GUIMyFrame1::m_choice_measurementsOnChoice, this);

    m_gauge_done_tasks->SetRange(100);
}

void GUIMyFrame1::m_button_source_selectOnButtonClick(wxCommandEvent& event)
{
    wxDirDialog openDirDialog(this, _("Choose a source directory"), "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

    if (openDirDialog.ShowModal() == wxID_OK)
    {
        m_sourceBasePath = openDirDialog.GetPath();
        if (!m_sourceBasePath.EndsWith(wxFileName::GetPathSeparator()))
        {
            m_sourceBasePath += wxFileName::GetPathSeparator();
        }

        if (!wxDirExists(m_sourceBasePath))
        {
            wxLogError(_("Source directory '%s' does not exist or is not accessible."), m_sourceBasePath);
            return;
        }

        LoadImagesFromDirectory(m_sourceBasePath);
        if (!m_imagePaths.empty())
        {
            m_currentImageIndex = 0;
            LoadNextImage();
        }

        if (!m_destinationPath.IsEmpty())
        {
            ScanAndCreateDirectories(m_sourceBasePath, m_destinationPath);
        }

        m_gauge_done_tasks->SetValue(0);
    }
}

void GUIMyFrame1::LoadNextImage()
{
    if (m_currentImageIndex < m_imagePaths.size())
    {
        wxString currentImagePath = m_imagePaths[m_currentImageIndex];
        if (m_image.LoadFile(currentImagePath, wxBITMAP_TYPE_ANY))
        {
            UpdateImageSize();
            wxString wrappedFilename = WrapText(currentImagePath, 40);
            m_staticText_selected_source->SetLabel(wrappedFilename);
            m_staticText_selected_source->Wrap(m_staticText_selected_source->GetClientSize().GetWidth());
            m_staticText_selected_source->GetParent()->Layout();
        }
        else
        {
            wxLogError(_("Cannot load image '%s'."), currentImagePath);
        }
    }
}

void GUIMyFrame1::ScanDirectory(const wxString& directory)
{
    std::queue<wxString> dirsToProcess;
    dirsToProcess.push(directory);

    while (!dirsToProcess.empty())
    {
        wxString currentDir = dirsToProcess.front();
        dirsToProcess.pop();

        wxDir dir(currentDir);
        if (!dir.IsOpened())
        {
            wxLogError(_("Could not open directory '%s'."), currentDir);
            continue;
        }

        wxString filename;
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES | wxDIR_DIRS);
        while (cont)
        {
            wxString filepath = currentDir + wxFileName::GetPathSeparator() + filename;
            if (wxDirExists(filepath))
            {
                dirsToProcess.push(filepath);
            }
            else
            {
                wxString extension = wxFileName(filepath).GetExt().Lower();
                if (extension == "bmp" || extension == "jpg" || extension == "jpeg" || extension == "png" || extension == "tif" || extension == "tiff")
                {
                    m_imagePaths.push_back(filepath);
                }
            }
            cont = dir.GetNext(&filename);
        }
    }
}


void GUIMyFrame1::LoadImagesFromDirectory(const wxString& directory)
{
    m_imagePaths.clear();
    ScanDirectory(directory);
    if (m_imagePaths.empty())
    {
        wxLogMessage(_("No image files found in the selected directory."));
    }
    else
    {
        m_totalImageCount = m_imagePaths.size();
        UpdateImageCount();
    }
}

void GUIMyFrame1::UpdateImageCount()
{
    wxString imageCountText = wxString::Format("%lu", static_cast<unsigned long>(m_totalImageCount));
    m_staticText_amount->SetLabel(imageCountText);
    m_staticText_amount->GetParent()->Layout();
}

void GUIMyFrame1::m_button_destination_selectOnButtonClick( wxCommandEvent& event )
{
    wxDirDialog openDirDialog(this, _("Choose a destination directory"), "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

    if (openDirDialog.ShowModal() == wxID_OK)
    {
        m_destinationPath = openDirDialog.GetPath();

        if (!wxDirExists(m_destinationPath))
        {
            wxLogError(_("Destination directory '%s' does not exist or is not accessible."), m_destinationPath);
            return;
        }

        wxString wrappedPath = WrapText(m_destinationPath, 40);
        m_staticText_selected_destination_text->SetLabel(wrappedPath);

        m_staticText_selected_destination_text->Wrap(m_staticText_selected_destination_text->GetClientSize().GetWidth());
        m_staticText_selected_destination_text->GetParent()->Layout();

        if (!m_sourceBasePath.IsEmpty())
        {
            ScanAndCreateDirectories(m_sourceBasePath, m_destinationPath);
        }
    }
}

void GUIMyFrame1::ScanAndCreateDirectories(const wxString& sourceDir, const wxString& destDir)
{
    std::queue<wxString> dirsToProcess;
    dirsToProcess.push(sourceDir);

    while (!dirsToProcess.empty())
    {
        wxString currentDir = dirsToProcess.front();
        dirsToProcess.pop();

        wxDir dir(currentDir);
        if (!dir.IsOpened())
        {
            wxLogError(_("Could not open directory '%s'."), currentDir);
            continue;
        }

        wxString relativePath;
        if (currentDir.StartsWith(m_sourceBasePath, &relativePath))
        {
            if (relativePath.StartsWith(wxFileName::GetPathSeparator()))
            {
                relativePath = relativePath.Mid(1);
            }
        }
        else
        {
            wxLogError(_("The path '%s' does not start with the base path '%s'."), currentDir, m_sourceBasePath);
            continue;
        }

        wxString targetDir = destDir + wxFileName::GetPathSeparator() + relativePath;

        bool hasSupportedFiles = false;
        wxString filename;
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);
        while (cont)
        {
            wxString extension = wxFileName(filename).GetExt().Lower();
            if (extension == "bmp" || extension == "jpg" || extension == "jpeg" || extension == "png" || extension == "tif" || extension == "tiff")
            {
                hasSupportedFiles = true;
                break;
            }
            cont = dir.GetNext(&filename);
        }

        if (!hasSupportedFiles && !dir.HasSubDirs())
        {
            // Skip creating the target directory as the current directory is empty or contains only unsupported files
            continue;
        }

        if (!wxDirExists(targetDir))
        {
            if (!wxFileName::Mkdir(targetDir, wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL))
            {
                wxLogError(_("Could not create directory '%s'."), targetDir);
                continue;
            }
        }

        cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
        while (cont)
        {
            wxString subDirPath = currentDir + wxFileName::GetPathSeparator() + filename;
            dirsToProcess.push(subDirPath);
            cont = dir.GetNext(&filename);
        }
    }
}

void GUIMyFrame1::m_choice_measurementsOnChoice( wxCommandEvent& event )
{
    UpdateImageSize();
}

void GUIMyFrame1::m_choice_compressionOnChoice( wxCommandEvent& event )
{
    wxString selectedCompression = m_choice_compression->GetStringSelection();
    if (selectedCompression == "Very Low")
    {
        m_compressionLevel = 20;
    }
    else if (selectedCompression == "Low")
    {
        m_compressionLevel = 40;
    }
    else if (selectedCompression == "Medium")
    {
        m_compressionLevel = 60;
    }
    else if (selectedCompression == "High")
    {
        m_compressionLevel = 80;
    }
    else if (selectedCompression == "Very High")
    {
        m_compressionLevel = 100;
    }
}

void GUIMyFrame1::m_button_rotation_leftOnButtonClick( wxCommandEvent& event )
{
    if (m_image.IsOk())
    {
        m_image = m_image.Rotate90(false);
        UpdateImageSize();
    }
}

void GUIMyFrame1::m_button_rotation_rightOnButtonClick( wxCommandEvent& event )
{
    if (m_image.IsOk())
    {
        m_image = m_image.Rotate90(true);
        UpdateImageSize();
    }
}

void GUIMyFrame1::m_button_next_thumbnailOnButtonClick(wxCommandEvent& event)
{
    if (!m_resizedImage.IsOk() || m_destinationPath.IsEmpty())
    {
        wxLogError(_("Image not loaded or destination path not set."));
        return;
    }

    if (m_currentImageIndex >= m_imagePaths.size())
    {
        wxLogMessage(_("No more images to process."));
        return;
    }

    wxString originalImagePath = m_imagePaths[m_currentImageIndex];
    wxFileName originalFileName(originalImagePath);

    wxString relativePath;
    if (originalImagePath.StartsWith(m_sourceBasePath, &relativePath))
    {
        if (relativePath.StartsWith(wxFileName::GetPathSeparator()))
        {
            relativePath = relativePath.Mid(1);
        }
    }
    else
    {
        wxLogError(_("The path '%s' does not start with the base path '%s'."), originalImagePath, m_sourceBasePath);
        return;
    }

    wxString saveDirectory = m_destinationPath + wxFileName::GetPathSeparator() + relativePath.BeforeLast(wxFileName::GetPathSeparator());

    if (!wxDirExists(saveDirectory))
    {
        wxLogError(_("The directory '%s' does not exist."), saveDirectory);
        return;
    }

    wxString savePath = saveDirectory + wxFileName::GetPathSeparator() + originalFileName.GetName() + "_thumbnail.jpg";
    m_resizedImage.SetOption(wxIMAGE_OPTION_QUALITY, m_compressionLevel);

    if (!m_resizedImage.SaveFile(savePath))
    {
        wxLogError(_("Cannot save image to '%s'."), savePath);
    }
    else
    {
        wxLogMessage(_("Image saved to '%s'."), savePath);
        m_currentImageIndex++;
        UpdateProgress();
        if (m_currentImageIndex < m_imagePaths.size())
        {
            LoadNextImage();
        }
        else
        {
            wxLogMessage(_("No more images to process."));
        }
    }
}

void GUIMyFrame1::UpdateProgress()
{
    if (m_totalImageCount > 0)
    {
        int progress = static_cast<int>((m_currentImageIndex * 100) / m_totalImageCount);
        m_gauge_done_tasks->SetValue(progress);
    }
}


void GUIMyFrame1::UpdateImageSize()
{
    wxString selectedSize = m_choice_measurements->GetStringSelection();
    int maxWidth, maxHeight;
    int result = sscanf(selectedSize.c_str(), "%d x %d", &maxWidth, &maxHeight);

    if (result != 2) {
        wxLogError(_("Failed to parse the dimensions from the selected size."));
        return;
    }

    if (m_image.IsOk())
    {
        int imageWidth = m_image.GetWidth();
        int imageHeight = m_image.GetHeight();

        double max_aspectRatio = static_cast<double>(maxWidth) / maxHeight;
        double image_aspectRatio = static_cast<double>(imageWidth) / imageHeight;
        int newWidth, newHeight;

        if (image_aspectRatio > max_aspectRatio)
        {
            newWidth = maxWidth;
            newHeight = static_cast<int>(newWidth / image_aspectRatio);
        }
        else
        {
            newHeight = maxHeight;
            newWidth = static_cast<int>(newHeight * image_aspectRatio);
        }

        m_resizedImage = m_image.Copy().Rescale(newWidth, newHeight);
        m_bitmap = wxBitmap(m_resizedImage);
        m_scrolledWindow1->SetScrollbars(10, 10, m_bitmap.GetWidth() / 10, m_bitmap.GetHeight() / 10);
        m_scrolledWindow1->SetVirtualSize(m_bitmap.GetWidth(), m_bitmap.GetHeight());

        int toolSizerWidth = 450;
        int toolSizerHeight = 75;
        int totalWidth = newWidth + toolSizerWidth;
        int totalHeight = newHeight + toolSizerHeight;
        int newFrameWidth = GetSize().GetWidth();
        int newFrameHeight = GetSize().GetHeight();

        if (totalWidth > DEFAULT_WIDTH) {
            newFrameWidth = totalWidth;
        }
        else {
            newFrameWidth = DEFAULT_WIDTH;
        }

        if (totalHeight > DEFAULT_HEIGHT) {
            newFrameHeight = totalHeight;
        }
        else {
            newFrameHeight = DEFAULT_HEIGHT;
        }

        SetClientSize(wxSize(newFrameWidth, newFrameHeight));

        Repaint();
    }
}



void GUIMyFrame1::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(m_scrolledWindow1);
    if (m_bitmap.IsOk())
    {
        dc.DrawBitmap(m_bitmap, 0, 0, false);
    }
}

void GUIMyFrame1::OnSize(wxSizeEvent& event)
{
    m_scrolledWindow1->Refresh();
    event.Skip();
}

void GUIMyFrame1::Repaint()
{
    wxBitmap bitmap(m_resizedImage);
    wxClientDC dc(m_scrolledWindow1);
    m_scrolledWindow1->DoPrepareDC(dc);
    dc.DrawBitmap(bitmap, 0, 0, true);
}

void GUIMyFrame1::OnScroll(wxScrollWinEvent& event)
{
    Repaint();
    event.Skip();
}

void GUIMyFrame1::OnScrollThumbRelease(wxScrollWinEvent& event)
{
    Repaint();
    event.Skip();
}

void GUIMyFrame1::OnScrollThumbTrack(wxScrollWinEvent& event)
{
    Repaint();
    event.Skip();
}

void GUIMyFrame1::ProcessKeyDown(wxKeyEvent& event)
{
    if (m_image.IsOk())
    {
        int keyCode = event.GetKeyCode();
        switch (keyCode)
        {
        case WXK_LEFT:
            m_image = m_image.Rotate90(false);
            UpdateImageSize();
            break;
        case WXK_RIGHT:
            m_image = m_image.Rotate90(true);
            UpdateImageSize();
            break;
        case WXK_UP:
            {
                wxCommandEvent newEvent(wxEVT_COMMAND_BUTTON_CLICKED, m_button_next_thumbnail->GetId());
                newEvent.SetEventObject(m_button_next_thumbnail);
                wxPostEvent(m_button_next_thumbnail, newEvent);
            }
            break;
        default:
            event.Skip();
            break;
        }
    }
}