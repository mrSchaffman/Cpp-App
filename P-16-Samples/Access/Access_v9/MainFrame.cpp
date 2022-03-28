#include "MainFrame.h"

#if wxUSE_ACCESSIBILITY

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(ID_ABOUT, MainFrame::OnAbout)
EVT_MENU(ID_QUERY, MainFrame::OnQuery)
EVT_MENU(ID_QUIT, MainFrame::OnQuit)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
	: wxFrame(nullptr, wxID_ANY, caption, pos, size, style)
{
	LayoutControls();
}

void MainFrame::Init()
{
	// the initiliazation
}

bool MainFrame::Create(const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	Init();
	MainFrame(caption, pos, size, style);
	return true;
}

void MainFrame::LayoutControls()
{
	SetAccessible(new FrameAccessible(this));

#if wxUSE_MENUS

	wxMenu* menuFile = new wxMenu;
	{
		menuFile->Append(ID_QUERY, wxT("Query"), wxT("Query the Window hierachy"));
		menuFile->AppendSeparator();
		menuFile->Append(ID_QUIT, wxT("E&xit\tAlt-F4"), wxT("Exit the Program"));

	}
	wxMenu* menuHelp = new wxMenu;
	{
		menuHelp->Append(ID_ABOUT, wxT("&About"), wxT("Show the About dialog"));
	}

	wxMenuBar* menuBar = new wxMenuBar();
	{
		menuBar->Append(menuFile, wxT("&File"));
		menuBar->Append(menuHelp, wxT("&Help"));
	}

	SetMenuBar(menuBar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
	CreateStatusBar();
	SetStatusText(wxT("The Access Sample"));
#endif // wxUSE_STATUSBAR

	wxSplitterWindow* splitterWin = new wxSplitterWindow(this, wxID_ANY);
	{
		splitterWin->SetAccessible(new SplitterWindowAccessible(splitterWin));
		wxListBox* listBox = new wxListBox(splitterWin, wxID_ANY);
		{
			listBox->Append(wxT("Cabbages"));
			listBox->Append(wxT("Kings"));
			listBox->Append(wxT("Sealing wax"));
			listBox->Append(wxT("Strings"));
			listBox->SetHelpText("This is a sample wxWidgets listbox, with a number of items in it.");
		}
		m_logger = new wxTextCtrl(splitterWin,
			wxID_ANY, wxEmptyString, wxDefaultPosition,
			wxDefaultSize, wxTE_MULTILINE);
		m_logger->SetHelpText(wxT("a multiline text control."));
		m_logger->CreateAccessible();

		splitterWin->SplitHorizontally(listBox, m_logger, 150);

	}


}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxString msg;
	msg.Printf("About the Accessible Sample, version %s", wxVERSION_STRING);
	wxMessageBox(msg, wxT("About"), wxICON_INFORMATION | wxOK, this);
}

void MainFrame::OnQuery(wxCommandEvent& WXUNUSED(event))
{
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(this);
}

void MainFrame::Log(const wxString& message)
{
}

void MainFrame::LogObject(int intent, IAccessible* object)
{
}

#endif // wxUSE_ACCESSIBILITY
