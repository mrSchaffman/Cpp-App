#include"App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	m_frame = new MainFrame(wxT("Snipping App"));
	m_frame->Show(true);

	return true;
}
