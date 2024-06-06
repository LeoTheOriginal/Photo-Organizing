#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
    m_image.AddHandler(new wxJPEGHandler);
    m_image.AddHandler(new wxPNGHandler);

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
}

void GUIMyFrame1::m_button_source_selectOnButtonClick(wxCommandEvent& event)
{
    wxString filename;
    wxFileDialog openFileDialog(this, _("Choose a file"), "", "",
        "Image files (*.bmp;*.jpg)|*.bmp;*.jpg",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_OK)
    {
        filename = openFileDialog.GetPath();

        if (!m_image.LoadFile(filename, wxBITMAP_TYPE_ANY))
        {
            wxLogError(_("Cannot load image '%s'."), filename);
            return;
        }
        else
        {
            UpdateImageSize();
        }

        m_staticText_selected_source->SetLabel(filename);
    }
}

void GUIMyFrame1::m_button_destination_selectOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_button_destination_selectOnButtonClick
}

void GUIMyFrame1::m_choice_measurementsOnChoice( wxCommandEvent& event )
{
    UpdateImageSize();
}

void GUIMyFrame1::m_choice_compressionOnChoice( wxCommandEvent& event )
{
// TODO: Implement m_choice_compressionOnChoice
}

void GUIMyFrame1::m_button_rotation_leftOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_button_rotation_leftOnButtonClick
}

void GUIMyFrame1::m_button_rotation_rightOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_button_rotation_rightOnButtonClick
}

void GUIMyFrame1::m_button_next_thumbnailOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_button_next_thumbnailOnButtonClick
}

void GUIMyFrame1::UpdateImageSize()
{
    wxString selectedSize = m_choice_measurements->GetStringSelection();
    int maxWidth, maxHeight;
    sscanf(selectedSize.c_str(), "%d x %d", &maxWidth, &maxHeight);

    if (m_image.IsOk())
    {
        int imageWidth = m_image.GetWidth();
        int imageHeight = m_image.GetHeight();

        // Calculate new dimensions while preserving aspect ratio
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

        // Adjust the main frame size if the image is larger than the default window size
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
    wxBitmap bitmap(m_resizedImage);      // Tworzymy tymczasowa bitmape na podstawie Img_Cpy
    wxClientDC dc(m_scrolledWindow1);     // Pobieramy kontekst okna
    m_scrolledWindow1->DoPrepareDC(dc);   // Musimy wywolac w przypadku wxScrolledWindow, zeby suwaki prawidlowo dzialaly
    dc.DrawBitmap(bitmap, 0, 0, true);    // Rysujemy bitmape na kontekscie urzadzenia
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




