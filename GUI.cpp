///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer_tools;
	bSizer_tools = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer_source_tools;
	bSizer_source_tools = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer_source_text;
	bSizer_source_text = new wxBoxSizer( wxVERTICAL );

	m_staticText_source_text = new wxStaticText( this, wxID_ANY, wxT("Source"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_source_text->Wrap( -1 );
	bSizer_source_text->Add( m_staticText_source_text, 0, wxALL, 5 );


	bSizer_source_tools->Add( bSizer_source_text, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_source_button;
	bSizer_source_button = new wxBoxSizer( wxVERTICAL );

	m_button_source_select = new wxButton( this, wxID_ANY, wxT("Select"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_source_button->Add( m_button_source_select, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer_source_tools->Add( bSizer_source_button, 1, wxEXPAND, 5 );


	bSizer_tools->Add( bSizer_source_tools, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_destination_tools;
	bSizer_destination_tools = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer_destination_text;
	bSizer_destination_text = new wxBoxSizer( wxVERTICAL );

	m_staticText_destination_choice = new wxStaticText( this, wxID_ANY, wxT("Destination directory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_destination_choice->Wrap( -1 );
	bSizer_destination_text->Add( m_staticText_destination_choice, 0, wxALL, 5 );


	bSizer_destination_tools->Add( bSizer_destination_text, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_destination_button;
	bSizer_destination_button = new wxBoxSizer( wxVERTICAL );

	m_button_destination_select = new wxButton( this, wxID_ANY, wxT("Select"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_destination_button->Add( m_button_destination_select, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer_destination_tools->Add( bSizer_destination_button, 1, wxEXPAND, 5 );


	bSizer_tools->Add( bSizer_destination_tools, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_measurements_tools;
	bSizer_measurements_tools = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer_measurements_text;
	bSizer_measurements_text = new wxBoxSizer( wxVERTICAL );

	m_staticText_dimensions = new wxStaticText( this, wxID_ANY, wxT("Thumbnail dimensions"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_dimensions->Wrap( -1 );
	bSizer_measurements_text->Add( m_staticText_dimensions, 0, wxALL, 5 );


	bSizer_measurements_tools->Add( bSizer_measurements_text, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_measurements_choice;
	bSizer_measurements_choice = new wxBoxSizer( wxVERTICAL );

	wxString m_choice_measurementsChoices[] = { wxT("150 x 150"), wxT("250 x 250"), wxT("300 x 200"), wxT("300 x 300"), wxT("400 x 300"), wxT("500 x 500"), wxT("640 x 360"), wxT("1200 x 630"), wxT("1080 x 1080"), wxT("1280 x 720") };
	int m_choice_measurementsNChoices = sizeof( m_choice_measurementsChoices ) / sizeof( wxString );
	m_choice_measurements = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_measurementsNChoices, m_choice_measurementsChoices, 0 );
	m_choice_measurements->SetSelection( 0 );
	bSizer_measurements_choice->Add( m_choice_measurements, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer_measurements_tools->Add( bSizer_measurements_choice, 1, wxEXPAND, 5 );


	bSizer_tools->Add( bSizer_measurements_tools, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_format_tools;
	bSizer_format_tools = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer_format_text;
	bSizer_format_text = new wxBoxSizer( wxVERTICAL );

	m_staticText_format = new wxStaticText( this, wxID_ANY, wxT("Save format"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_format->Wrap( -1 );
	bSizer_format_text->Add( m_staticText_format, 0, wxALL, 5 );


	bSizer_format_tools->Add( bSizer_format_text, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_format_choice;
	bSizer_format_choice = new wxBoxSizer( wxVERTICAL );

	wxString m_choice_formatChoices[] = { wxT("JPG") };
	int m_choice_formatNChoices = sizeof( m_choice_formatChoices ) / sizeof( wxString );
	m_choice_format = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_formatNChoices, m_choice_formatChoices, 0 );
	m_choice_format->SetSelection( 0 );
	bSizer_format_choice->Add( m_choice_format, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer_format_tools->Add( bSizer_format_choice, 1, wxEXPAND, 5 );


	bSizer_tools->Add( bSizer_format_tools, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_compression_tools;
	bSizer_compression_tools = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer_compression_text;
	bSizer_compression_text = new wxBoxSizer( wxVERTICAL );

	m_staticText_compression = new wxStaticText( this, wxID_ANY, wxT("Compression level"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_compression->Wrap( -1 );
	bSizer_compression_text->Add( m_staticText_compression, 0, wxALL, 5 );


	bSizer_compression_tools->Add( bSizer_compression_text, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_compression_choice;
	bSizer_compression_choice = new wxBoxSizer( wxVERTICAL );

	wxString m_choice_compressionChoices[] = { wxT("Low"), wxT("Medium"), wxT("High") };
	int m_choice_compressionNChoices = sizeof( m_choice_compressionChoices ) / sizeof( wxString );
	m_choice_compression = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_compressionNChoices, m_choice_compressionChoices, 0 );
	m_choice_compression->SetSelection( 0 );
	bSizer_compression_choice->Add( m_choice_compression, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer_compression_tools->Add( bSizer_compression_choice, 1, wxEXPAND, 5 );


	bSizer_tools->Add( bSizer_compression_tools, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_selected_source_tools;
	bSizer_selected_source_tools = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer_selected_source_text_const;
	bSizer_selected_source_text_const = new wxBoxSizer( wxVERTICAL );

	m_staticText_selected_source_const = new wxStaticText( this, wxID_ANY, wxT("Selected source"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_selected_source_const->Wrap( -1 );
	bSizer_selected_source_text_const->Add( m_staticText_selected_source_const, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer_selected_source_tools->Add( bSizer_selected_source_text_const, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_selected_source_text;
	bSizer_selected_source_text = new wxBoxSizer( wxVERTICAL );

	m_staticText_selected_source = new wxStaticText( this, wxID_ANY, wxT("Not selected"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_selected_source->Wrap( -1 );
	bSizer_selected_source_text->Add( m_staticText_selected_source, 0, wxALL, 5 );


	bSizer_selected_source_tools->Add( bSizer_selected_source_text, 0, wxEXPAND, 5 );


	bSizer_tools->Add( bSizer_selected_source_tools, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_selected_destination_tools;
	bSizer_selected_destination_tools = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer_selected_destination_text_const;
	bSizer_selected_destination_text_const = new wxBoxSizer( wxVERTICAL );

	m_staticText_selected_destination_const = new wxStaticText( this, wxID_ANY, wxT("Selected destination directory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_selected_destination_const->Wrap( -1 );
	bSizer_selected_destination_text_const->Add( m_staticText_selected_destination_const, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer_selected_destination_tools->Add( bSizer_selected_destination_text_const, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_selected_destination_text;
	bSizer_selected_destination_text = new wxBoxSizer( wxVERTICAL );

	m_staticText_selected_destination_text = new wxStaticText( this, wxID_ANY, wxT("Not selected"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_selected_destination_text->Wrap( -1 );
	bSizer_selected_destination_text->Add( m_staticText_selected_destination_text, 0, wxALL, 5 );


	bSizer_selected_destination_tools->Add( bSizer_selected_destination_text, 1, wxEXPAND, 5 );


	bSizer_tools->Add( bSizer_selected_destination_tools, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_amount_tools;
	bSizer_amount_tools = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer_amount_text_const;
	bSizer_amount_text_const = new wxBoxSizer( wxVERTICAL );

	m_staticText_amount_const = new wxStaticText( this, wxID_ANY, wxT("Number of photos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_amount_const->Wrap( -1 );
	bSizer_amount_text_const->Add( m_staticText_amount_const, 0, wxALL, 5 );


	bSizer_amount_tools->Add( bSizer_amount_text_const, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_amount_text;
	bSizer_amount_text = new wxBoxSizer( wxVERTICAL );

	m_staticText_amount = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_amount->Wrap( -1 );
	bSizer_amount_text->Add( m_staticText_amount, 0, wxALL, 5 );


	bSizer_amount_tools->Add( bSizer_amount_text, 1, wxEXPAND, 5 );


	bSizer_tools->Add( bSizer_amount_tools, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_gauge_tools;
	bSizer_gauge_tools = new wxBoxSizer( wxVERTICAL );

	m_staticText_created_thumbnails = new wxStaticText( this, wxID_ANY, wxT("Created thumbnails"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_created_thumbnails->Wrap( -1 );
	bSizer_gauge_tools->Add( m_staticText_created_thumbnails, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_gauge_done_tasks = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge_done_tasks->SetValue( 0 );
	bSizer_gauge_tools->Add( m_gauge_done_tasks, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer_tools->Add( bSizer_gauge_tools, 0, wxEXPAND, 5 );


	bSizer1->Add( bSizer_tools, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_preview;
	bSizer_preview = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer_preview_tools;
	bSizer_preview_tools = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer_rotation_left_button;
	bSizer_rotation_left_button = new wxBoxSizer( wxVERTICAL );

	m_button_rotation_left = new wxButton( this, wxID_ANY, wxT("Rotate left 90"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_rotation_left_button->Add( m_button_rotation_left, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer_preview_tools->Add( bSizer_rotation_left_button, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_rotation_right_button;
	bSizer_rotation_right_button = new wxBoxSizer( wxVERTICAL );

	m_button_rotation_right = new wxButton( this, wxID_ANY, wxT("Rotate right 90"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_rotation_right_button->Add( m_button_rotation_right, 0, wxALL, 5 );


	bSizer_preview_tools->Add( bSizer_rotation_right_button, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer_next_thumbnail_button;
	bSizer_next_thumbnail_button = new wxBoxSizer( wxVERTICAL );

	m_button_next_thumbnail = new wxButton( this, wxID_ANY, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer_next_thumbnail_button->Add( m_button_next_thumbnail, 0, wxALL, 5 );


	bSizer_preview_tools->Add( bSizer_next_thumbnail_button, 1, wxEXPAND, 5 );


	bSizer_preview->Add( bSizer_preview_tools, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer_thumbnail_preview_window;
	bSizer_thumbnail_preview_window = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	m_scrolledWindow1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	bSizer_thumbnail_preview_window->Add( m_scrolledWindow1, 1, wxEXPAND | wxALL, 5 );


	bSizer_preview->Add( bSizer_thumbnail_preview_window, 1, wxEXPAND|wxALL, 5 );


	bSizer1->Add( bSizer_preview, 1, wxEXPAND|wxLEFT, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button_source_select->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_source_selectOnButtonClick ), NULL, this );
	m_button_destination_select->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_destination_selectOnButtonClick ), NULL, this );
	m_choice_measurements->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::m_choice_measurementsOnChoice ), NULL, this );
	m_choice_compression->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::m_choice_compressionOnChoice ), NULL, this );
	m_button_rotation_left->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_rotation_leftOnButtonClick ), NULL, this );
	m_button_rotation_right->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_rotation_rightOnButtonClick ), NULL, this );
	m_button_next_thumbnail->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_next_thumbnailOnButtonClick ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_button_source_select->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_source_selectOnButtonClick ), NULL, this );
	m_button_destination_select->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_destination_selectOnButtonClick ), NULL, this );
	m_choice_measurements->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::m_choice_measurementsOnChoice ), NULL, this );
	m_choice_compression->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::m_choice_compressionOnChoice ), NULL, this );
	m_button_rotation_left->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_rotation_leftOnButtonClick ), NULL, this );
	m_button_rotation_right->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_rotation_rightOnButtonClick ), NULL, this );
	m_button_next_thumbnail->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_next_thumbnailOnButtonClick ), NULL, this );

}
