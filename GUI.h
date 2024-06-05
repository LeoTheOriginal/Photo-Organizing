///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/choice.h>
#include <wx/gauge.h>
#include <wx/scrolwin.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText_source_text;
		wxButton* m_button_source_select;
		wxStaticText* m_staticText_destination_choice;
		wxButton* m_button_destination_select;
		wxStaticText* m_staticText_dimensions;
		wxChoice* m_choice_measurements;
		wxStaticText* m_staticText_format;
		wxChoice* m_choice_format;
		wxStaticText* m_staticText_compression;
		wxChoice* m_choice_compression;
		wxStaticText* m_staticText_created_thumbnails;
		wxGauge* m_gauge_done_tasks;
		wxStaticText* m_staticText_selected_source_const;
		wxStaticText* m_staticText_selected_source;
		wxStaticText* m_staticText_selected_destination_const;
		wxStaticText* m_staticText_selected_destination_text;
		wxStaticText* m_staticText_amount_const;
		wxStaticText* m_staticText_amount;
		wxButton* m_button_rotation_left;
		wxButton* m_button_rotation_right;
		wxButton* m_button_next_thumbnail;
		wxScrolledWindow* m_scrolledWindow1;

	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Photo organizing"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

