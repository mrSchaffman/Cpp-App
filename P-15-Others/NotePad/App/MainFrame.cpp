#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title):wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(620,480))
{
	SetTitle(m_filename + " - " + title);
	m_menubar = new MenuBar();

	SetMenuBar(m_menubar);

#if wxUSE_STATUSBAR
	int m_widths[5] = { 250,120,30,80,80 };

	CreateStatusBar(5, wxSTB_DEFAULT_STYLE);
	SetStatusWidths(5, m_widths);

	SetStatusBarPane(0);
	SetStatusText("Ln--, Col--", 1);
	SetStatusText(wxT("100%"), 2);
	SetStatusText(wxT("Win...(CRLF)"), 3);
	SetStatusText(wxT("UTF-8"), 4);
#endif // wxUSE_STATUSBAR

	m_text_screen = new  TextCtrl(this);
}
