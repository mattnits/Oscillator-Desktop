#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "oscillator.h"

wxIMPLEMENT_APP(Oscillator);
bool Oscillator::OnInit() {
    
    OscillatorFrame *frame = new OscillatorFrame();
    frame->Show(true);
    return true;
}
OscillatorFrame::OscillatorFrame()
    : wxFrame(NULL, wxID_ANY, "Hello World", wxDefaultPosition, wxSize(1920, 1080)) {
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    menuHelp->Append(wxID_OPEN);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    Bind(wxEVT_MENU, &OscillatorFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &OscillatorFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &OscillatorFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &OscillatorFrame::OpenFile, this, wxID_OPEN);
}

void OscillatorFrame::OpenFile(wxCommandEvent& WXUNUSED(event)) {
	wxFileDialog *OpenDialog = new wxFileDialog(
		this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
		_("Text files (*.txt)|*.txt|C++ Source Files (*.cpp, *.cxx)|*.cpp;*.cxx|C Source files (*.c)|*.c|C header files (*.h)|*.h"),
		wxFD_OPEN, wxDefaultPosition);

	// Creates a "open file" dialog with 4 file types
	if (OpenDialog->ShowModal() == wxID_OK) {
		CurrentDocPath = OpenDialog->GetPath();

		// Sets our current document to the file the user selected
		MainEditBox->LoadFile(CurrentDocPath); //Opens that file
		// Set the Title to reflect the  file open
		SetTitle(wxString("Edit - ") << OpenDialog->GetFilename());
	}
}

void OscillatorFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void OscillatorFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
void OscillatorFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Hello world from wxWidgets!");
}