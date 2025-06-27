#include <wx/wx.h>
#include "../gui/MainFrame.h"

class TitleTrackApp : public wxApp {
public:
    virtual bool OnInit() override {
        MainFrame* frame = new MainFrame(nullptr);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(TitleTrackApp);
