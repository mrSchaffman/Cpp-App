#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title): wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(580,620))
{
	wxImage iconImage(wxT("icon.png"), wxBITMAP_TYPE_ANY);
	wxBitmap iconBmp(iconImage);
	wxIcon appIcon;
	appIcon.CopyFromBitmap(iconBmp);

	SetIcon(appIcon);
	m_menuBar = new MenuBar(this);
	SetMenuBar(m_menuBar);
}
