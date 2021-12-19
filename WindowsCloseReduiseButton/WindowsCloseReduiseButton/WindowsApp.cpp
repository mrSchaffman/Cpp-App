#include "WindowsApp.h"
DECLARE_APP(WindowsApp)
IMPLEMENT_APP(WindowsApp)

bool WindowsApp::OnInit()
{
	frame = new MainFrame();

	frame->Show(true);
	return true;
}
