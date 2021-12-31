#include "App.h"
DECLARE_APP(App)
IMPLEMENT_APP(App)

bool App::OnInit()
{
	frame =new MainFrame(wxT("ISBN Validator"));

	frame->Show(true);
	return true;
}
