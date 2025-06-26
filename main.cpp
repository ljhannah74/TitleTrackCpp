#include <wx/wx.h>
#include "MyFrame.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit() override {
        MyFrame* frame = new MyFrame("wxWidgets App");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
