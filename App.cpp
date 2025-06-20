#include <wx/wx.h>
#include "MyFrameDerived.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        MyFrameDerived* frame = new MyFrameDerived(nullptr);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);

