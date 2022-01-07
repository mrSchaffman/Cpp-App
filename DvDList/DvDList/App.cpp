#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	frame = new MainFrame("DVD List");

	frame->Show(true);
	return true;
}
