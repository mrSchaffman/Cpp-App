#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	


wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title) :wxFrame(nullptr, wxID_ANY, title, wxPoint(100,100), wxSize(920, 700))
{

	wxImage img(wxT("Icon.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpIcon(img);

	wxIcon AppIcon;
	AppIcon.CopyFromBitmap(bmpIcon);
	SetIcon(AppIcon);

	SetTitle(m_filename + " - " + title);

	//m_menubar = new MenuBar(this, nullptr);
	//SetMenuBar(m_menubar);



//#if wxUSE_STATUSBAR
//	int m_widths[5] = { 250,120,30,80,80 };
//
//	CreateStatusBar(5, wxSTB_DEFAULT_STYLE);
//	SetStatusWidths(5, m_widths);
//
//	SetStatusBarPane(0);
//	wxString LinCol;
//	LinCol.Printf("Ln %d, Col %d", m_ln, m_col);
//	SetStatusText(LinCol, 1);
//	SetStatusText(wxT("100%"), 2);
//	SetStatusText(wxT("Win...(CRLF)"), 3);
//	SetStatusText(wxT("UTF-8"), 4);
//#endif // wxUSE_STATUSBAR



	m_panel = new MainPanel(this);
	m_panel->GetSizer()->Fit(this);

}

