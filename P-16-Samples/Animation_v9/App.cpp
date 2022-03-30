#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	wxImage::AddHandler(new wxGIFHandler());

	if (!wxApp::OnInit())
	{
		return false;
	}
	MainFrame* frame = new MainFrame(wxT("Animation"));
	frame->Show(true);

	wxLogWindow* logWin = new wxLogWindow(nullptr, "The log Window", true, true);


	return true;
}