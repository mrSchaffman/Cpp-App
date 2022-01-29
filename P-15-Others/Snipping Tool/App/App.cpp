#include"App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	m_frame = new MainFrame(wxT("Drawing"));
	m_frame->Show(true);

	return true;
}
