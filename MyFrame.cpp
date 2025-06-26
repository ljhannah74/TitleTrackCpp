#include "MyFrame.h"

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)) {
    
    wxPanel* panel = new wxPanel(this, -1);
    new wxStaticText(panel, wxID_ANY, "Hello wxWidgets!", wxPoint(10, 10));
}
