#pragma once
#include <wx/wx.h>
#include "MainFrameBase.h"

class MainFrame : public MainFrameBase {
public:
    MainFrame(wxWindow* parent);
    void OnNewAbstractButtonClick(wxCommandEvent& event);
};
