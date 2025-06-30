#include "MainFrame.h"
#include <TitleAbstractDAL.h>
#include <wx/stdpaths.h>
#include <filesystem>

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

    loadAbstracts();  // Load abstracts on startup
}

void MainFrame::OnNewAbstractButtonClick(wxCommandEvent& event) {
    wxMessageBox("NEw Abstract Button clicked!", "Info");
}

void MainFrame::loadAbstracts() {
    m_listAbstracts->DeleteAllItems();  // Clear existing

    std::string dbPath = wxStandardPaths::Get().GetUserLocalDataDir().ToStdString() + "/TitleTrack.db";  // Update with actual path
    std::filesystem::create_directories(std::filesystem::path(wxStandardPaths::Get().GetUserLocalDataDir().ToStdString()));  // Ensure directory exists
    TitleAbstractDAL dal;
    if(!dal.connect(dbPath)) {  // Update with actual path
        wxMessageBox("Failed to open the database file:\n" + dbPath, "Database Error", wxICON_ERROR);
        return;
    }
    
    dal.createTable();  // Ensure table exists

    std::vector<TitleAbstract> abstracts = dal.getAllAbstracts();  // Assumes DAL method

    for (size_t i = 0; i < abstracts.size(); ++i) {
        const auto& a = abstracts[i];
        long index = m_listAbstracts->InsertItem(i, a.OrderNo);
        m_listAbstracts->SetItem(index, 1, a.Client);
        m_listAbstracts->SetItem(index, 2, a.EffectiveDate);
        m_listAbstracts->SetItem(index, 3, a.ProductType);
        m_listAbstracts->SetItem(index, 4, a.PropertyAddress);
    }
}