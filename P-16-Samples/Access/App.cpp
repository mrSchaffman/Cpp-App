#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* frame = new MainFrame(wxT("Access"));
	frame->Show(true);

	return true;
}