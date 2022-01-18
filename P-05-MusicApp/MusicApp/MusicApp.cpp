#include "MusicApp.h"

wxIMPLEMENT_APP(MusicApp);

bool MusicApp::OnInit()
{
	m_frame = new MainFrame(wxT("Music Playlist"));

	m_frame->Show(true);

	return true;
}
