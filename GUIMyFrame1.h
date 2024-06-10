#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
 * @file GUIMyFrame1.h
 * @brief Subclass of MyFrame1, which is generated by wxFormBuilder.
 */

#include "GUI.h"

 //// end generated include

#include <wx/scrolwin.h>
#include <wx/wx.h>
#include <string.h>
#include <wx/filedlg.h>
#include <wx/log.h>
#include <wx/dirdlg.h>
#include <wx/filename.h>
#include <wx/dir.h>
#include <queue>
#include <wx/dcbuffer.h>
#include "wx/mstream.h"
#include <wx/wfstream.h>
#include <wx/stdpaths.h>
#include <wx/filefn.h>

/**
 * @class GUIMyFrame1
 * @brief Implements MyFrame1 and provides functionality for handling image processing tasks.
 */
class GUIMyFrame1 : public MyFrame1
{
protected:
    /**
     * @brief Handles the event when the source select button is clicked.
     * @param event The event object.
     */
    void m_button_source_selectOnButtonClick(wxCommandEvent& event);

    /**
     * @brief Handles the event when the destination select button is clicked.
     * @param event The event object.
     */
    void m_button_destination_selectOnButtonClick(wxCommandEvent& event);

    /**
     * @brief Handles the event when a measurement choice is made.
     * @param event The event object.
     */
    void m_choice_measurementsOnChoice(wxCommandEvent& event);

    /**
     * @brief Handles the event when a compression choice is made.
     * @param event The event object.
     */
    void m_choice_compressionOnChoice(wxCommandEvent& event);

    /**
     * @brief Handles the event when the left rotation button is clicked.
     * @param event The event object.
     */
    void m_button_rotation_leftOnButtonClick(wxCommandEvent& event);

    /**
     * @brief Handles the event when the right rotation button is clicked.
     * @param event The event object.
     */
    void m_button_rotation_rightOnButtonClick(wxCommandEvent& event);

    /**
     * @brief Handles the event when the next thumbnail button is clicked.
     * @param event The event object.
     */
    void m_button_next_thumbnailOnButtonClick(wxCommandEvent& event);

    /**
     * @brief Handles the paint event for the scrolled window.
     * @param event The event object.
     */
    void OnPaint(wxPaintEvent& event);

    /**
     * @brief Handles the resize event for the scrolled window.
     * @param event The event object.
     */
    void OnSize(wxSizeEvent& event);

    /**
     * @brief Handles the scroll event for the scrolled window.
     * @param event The event object.
     */
    void OnScroll(wxScrollWinEvent& event);

    /**
     * @brief Handles the scroll thumb release event for the scrolled window.
     * @param event The event object.
     */
    void OnScrollThumbRelease(wxScrollWinEvent& event);

    /**
     * @brief Handles the scroll thumb track event for the scrolled window.
     * @param event The event object.
     */
    void OnScrollThumbTrack(wxScrollWinEvent& event);

public:
    /**
     * @brief Constructor for GUIMyFrame1.
     * @param parent The parent window.
     */
    GUIMyFrame1(wxWindow* parent);

    /**
     * @brief Processes key down events.
     * @param event The event object.
     */
    void ProcessKeyDown(wxKeyEvent& event);

private:
    wxImage m_image;              ///< The currently loaded image.
    wxBitmap m_bitmap;            ///< The bitmap representation of the image.
    wxImage m_resizedImage;       ///< The resized image.
    std::vector<wxString> m_imagePaths; ///< Vector of image paths to be processed.
    size_t m_currentImageIndex;   ///< The current index of the image being processed.
    size_t m_totalImageCount;     ///< The total number of images to be processed.

    wxString m_sourceBasePath;    ///< The base path of the source directory.
    wxString m_destinationPath;   ///< The destination directory path.
    int m_compressionLevel;       ///< The level of compression to apply to images.

    /**
     * @brief Updates the size of the currently loaded image.
     */
    void UpdateImageSize();

    /**
     * @brief Calculates the rescaled dimensions for an image.
     * @param originalWidth The original width of the image.
     * @param originalHeight The original height of the image.
     * @param maxWidth The maximum width allowed.
     * @param maxHeight The maximum height allowed.
     * @param newWidth The calculated new width.
     * @param newHeight The calculated new height.
     */
    void CalculateRescaledDimensions(int originalWidth, int originalHeight, int maxWidth, int maxHeight, int& newWidth, int& newHeight);

    /**
     * @brief Updates the window size to fit the new image dimensions.
     * @param imageWidth The width of the image.
     * @param imageHeight The height of the image.
     */
    void UpdateWindowSize(int imageWidth, int imageHeight);

    /**
     * @brief Repaints the scrolled window.
     */
    void Repaint();

    /**
     * @brief Applies the compression level and refreshes the image display.
     * @param compressionLevel The compression level to apply.
     */
    void ApplyCompressionAndRefresh(int compressionLevel);

    /**
     * @brief Loads the next image in the list.
     */
    void LoadNextImage();

    /**
     * @brief Loads images from the specified directory.
     * @param directory The directory to load images from.
     */
    void LoadImagesFromDirectory(const wxString& directory);

    /**
     * @brief Scans the specified directory for images.
     * @param directory The directory to scan.
     */
    void ScanDirectory(const wxString& directory);

    /**
     * @brief Updates the image count display.
     */
    void UpdateImageCount();

    /**
     * @brief Scans the source directory and creates corresponding directories in the destination path.
     * @param sourceDir The source directory to scan.
     * @param destDir The destination directory to create.
     */
    void ScanAndCreateDirectories(const wxString& sourceDir, const wxString& destDir) const;

    /**
     * @brief Updates the progress gauge.
     */
    void UpdateProgress();

    static const int DEFAULT_WIDTH = 900;  ///< The default width of the frame.
    static const int DEFAULT_HEIGHT = 600; ///< The default height of the frame.
};

#endif // __GUIMyFrame1__