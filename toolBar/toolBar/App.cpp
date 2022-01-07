#include "App.h"
#include"MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	// Create the main frame window
	MainFrame* frame = new MainFrame((wxFrame *)NULL, wxID_ANY,"wxToolBar Sample",wxPoint(100, 100), wxDefaultSize);

	frame->Show(true);

#if wxUSE_STATUSBAR
	frame->SetStatusText("Hello, wxWidgets");
#endif

	wxInitAllImageHandlers();

	return true;
}
