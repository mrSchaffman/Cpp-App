
#include "App.h"

wxDECLARE_APP(App);
wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	wxImage::AddHandler(new wxPNGHandler());


	MainFrame * frame = new MainFrame();

	frame->Show(true);
	return true;
}
