#include <wx/string.h>
#include <wx/menu.h>
#include <wx/textctrl.h>

class Oscillator: public wxApp {
public:
    virtual bool OnInit();
};
class OscillatorFrame : public wxFrame {
public:
    wxString CurrentDocPath;
    wxTextCtrl *MainEditBox;
    
    OscillatorFrame();
    void OpenFile(wxCommandEvent& WXUNUSED(event));

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};
enum {
    ID_Hello = 1
};

