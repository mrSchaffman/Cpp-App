#include "App.h"

// Implements App& GetApp()
//#define wxDECLARE_APP(appname)     extern appname& wxGetApp()

DECLARE_APP(App)
// Give wxWidgets the means to create a MyApp object
IMPLEMENT_APP(App)

bool App::OnInit()
{
	if (!wxApp::OnInit())
	{
		return false;
	}
	MainFrame* frame = new MainFrame(wxT("Access"));
	frame->Show(true);

	return true;
}