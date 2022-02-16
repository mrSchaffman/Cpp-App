
#include "App.h"

DECLARE_APP(App);
wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	wxImage::AddHandler(new wxPNGHandler);

	return true;
}
