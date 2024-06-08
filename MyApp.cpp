#include <wx/wxprec.h>
#include "GUIMyFrame1.h"
#include <wx/wx.h>
#include "MyApp.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	SetProcessDPIAware();
	wxFrame* mainFrame = new GUIMyFrame1(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}

int MyApp::FilterEvent(wxEvent& event)
{
    if (event.GetEventType() == wxEVT_KEY_DOWN)
    {
        wxKeyEvent& keyEvent = static_cast<wxKeyEvent&>(event);
        if (keyEvent.GetKeyCode() == WXK_LEFT || keyEvent.GetKeyCode() == WXK_RIGHT || keyEvent.GetKeyCode() == WXK_UP)
        {
            GUIMyFrame1* frame = dynamic_cast<GUIMyFrame1*>(GetTopWindow());
            if (frame)
            {
                frame->ProcessKeyDown(keyEvent);
                return true;
            }
        }
    }
    return wxApp::FilterEvent(event);
}