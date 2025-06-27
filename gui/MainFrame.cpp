#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)) {
    
    wxPanel* panel = new wxPanel(this, -1);
    new wxStaticText(panel, wxID_ANY, "Welcome to TitleTrack", wxPoint(10, 10));
}
