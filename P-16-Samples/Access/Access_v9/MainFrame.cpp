#include "MainFrame.h"
wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_MENU(ID_ABOUT,MainFrame::OnAbout)
	EVT_MENU(ID_QUERY,MainFrame::OnQuery)
	EVT_MENU(ID_QUIT,MainFrame::OnQuit)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & caption, const wxPoint & pos, const wxSize & size, long style)
	: wxFrame(nullptr,wxID_ANY, caption, pos,size,style)
{
	LayoutControls();
}

void MainFrame::Init()
{
	// the initiliazation
}

bool MainFrame::Create(const wxString & caption, const wxPoint & pos, const wxSize & size, long style)
{
	Init();
	MainFrame(caption, pos, size, style);
	return true;
}

void MainFrame::LayoutControls()
{
#if wxUSE_MENUS

	wxMenu* menuFile = new wxMenu;
	{
		menuFile->Append(ID_QUERY, wxT("Query"), wxT("Query the Window hierachy"));
		menuFile->AppendSeparator();
		menuFile->Append(ID_QUIT, wxT("E&xit\tAlt-F4"), wxT("Exit the Program"));

	}
	wxMenu* menuHelp = new wxMenu;
	{
		menuHelp->Append(ID_ABOUT,wxT("&About"),wxT("Show the About dialog"));
	}

	wxMenuBar* menuBar = new wxMenuBar();
	{
		menuBar->Append(menuFile, wxT("&File"));
		menuBar->Append(menuHelp, wxT("&Help"));
	}

	SetMenuBar(menuBar);
#endif // wxUSE_MENUS

}

void MainFrame::OnAbout(wxCommandEvent& event)
{
}

void MainFrame::OnQuery(wxCommandEvent& event)
{
}

void MainFrame::OnQuit(wxCommandEvent& event)
{
	Close(this);
}

void MainFrame::Log(const wxString& message)
{
}

void MainFrame::LogObject(int intent, IAccessible* object)
{
}
