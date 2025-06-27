#include "MainFrame.h"

MainFrame::MainFrame(wxWindow* parent)
    : MainFrameBase(parent, wxID_ANY, "TitleTrack - Abstract Management System", wxDefaultPosition, wxSize(800, 600), wxDEFAULT_FRAME_STYLE) 
{
    m_btnNewAbstract->Bind(wxEVT_BUTTON, &MainFrame::OnNewAbstractButtonClick, this);

    // Setup list control columns
    m_listAbstracts->InsertColumn(0, "Order No");
    m_listAbstracts->InsertColumn(1, "Client");
    m_listAbstracts->InsertColumn(2, "Effective Date");
    m_listAbstracts->InsertColumn(3, "Product Type");
    m_listAbstracts->InsertColumn(4, "Property Address");

    // Optional: Set column widths
    m_listAbstracts->SetColumnWidth(0, 100);
    m_listAbstracts->SetColumnWidth(1, 150);
    m_listAbstracts->SetColumnWidth(2, 120);
    m_listAbstracts->SetColumnWidth(3, 120);
    m_listAbstracts->SetColumnWidth(4, 250);

    long index = m_listAbstracts->InsertItem(0, "ORD-00123");
    m_listAbstracts->SetItem(index, 1, "Acme Corp");
    m_listAbstracts->SetItem(index, 2, "2025-06-27");
    m_listAbstracts->SetItem(index, 3, "Full Search");
    m_listAbstracts->SetItem(index, 4, "123 Main St, Springfield");
}

void MainFrame::OnNewAbstractButtonClick(wxCommandEvent& event) {
    wxMessageBox("NEw Abstract Button clicked!", "Info");
}
