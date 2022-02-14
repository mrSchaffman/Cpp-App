#include"App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	wxImage::AddHandler(new wxPNGHandler);
	m_frame = new MainFrame(wxT("NoteEditor"));
	m_frame->Show(true);

	return true;
}
