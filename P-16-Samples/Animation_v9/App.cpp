#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	if (!wxApp::OnInit())
	{
		return false;
	}
	MainFrame* frame = new MainFrame(wxT("Animation"));
	frame->Show(true);

	return true;
}