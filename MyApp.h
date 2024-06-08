#ifndef __MYAPP_H__
#define __MYAPP_H__

#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
    virtual int FilterEvent(wxEvent& event);
    virtual int OnExit() { return 0; }
};

#endif // __MYAPP_H__
