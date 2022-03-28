#include "App.h"

// Implements App& GetApp()
//#define wxDECLARE_APP(appname)     extern appname& wxGetApp()

DECLARE_APP(App)
// Give wxWidgets the means to create a MyApp object
IMPLEMENT_APP(App)

bool App::OnInit()
{
	if (!wxApp::OnInit())
	{
		return false;
	}

#if wxUSE_ACCESSIBILITY
	wxHelpProvider::Set(new wxSimpleHelpProvider());
	MainFrame* frame = new MainFrame(wxT("Access"), wxDefaultPosition, wxSize(480, 320));
	frame->Show(true);

	return true;
#else
	wxMessageBox(wxT("This App. has to be compile with wxUSE_ACCESSIBILITY"));
	return false;
#endif // wxUSE_ACCESSIBILITY

}