///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6a)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrameBase.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_btnNewAbstract = new wxButton( this, wxID_ANY, _("New Abstract"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_btnNewAbstract, 0, wxALIGN_LEFT|wxALL, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	m_listAbstracts = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxBORDER_SUNKEN );
	bSizer1->Add( m_listAbstracts, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MainFrameBase::~MainFrameBase()
{
}
