#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title):wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(320,200))
{
	m_toolbar = new ToolBar(this);
	SetToolBar(m_toolbar);

	SetMaxSize(wxSize(320, 200));

	wxImage::AddHandler(new wxPNGHandler);
	wxImage im(wxT("Icon.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpIcon(im);

	wxIcon icon;
	icon.CopyFromBitmap(bmpIcon);
	SetIcon(icon);
	m_scrolled_win = new ScrolledWin(this);
}
