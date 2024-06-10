#ifndef __MYAPP_H__
#define __MYAPP_H__

#include <wx/wx.h>

/**
 * @class MyApp
 * @brief Main application class derived from wxApp.
 */
class MyApp : public wxApp
{
public:
    /**
     * @brief Initializes the application.
     * @return True if initialization is successful, false otherwise.
     */
    virtual bool OnInit();

    /**
     * @brief Filters events before they are processed.
     * @param event The event to filter.
     * @return Event processing result.
     */
    virtual int FilterEvent(wxEvent& event);

    /**
     * @brief Cleans up any resources before the application exits.
     * @return Always returns 0.
     */
    virtual int OnExit() { return 0; }
};

#endif // __MYAPP_H__
