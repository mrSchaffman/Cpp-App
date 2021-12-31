#include "BrowserApp.h"
#include"wx/statline.h"
#include"wx/listctrl.h"

DECLARE_APP(BrowserApp)
IMPLEMENT_APP(BrowserApp)

bool BrowserApp::OnInit()
{
	frame = new MainFrame(wxString("Data Structure Browser"));

	frame->Show(true);
	return true;
}
