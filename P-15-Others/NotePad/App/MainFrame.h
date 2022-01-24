#pragma once
#include"wx/wx.h"
#include"MainPanel.h"
#include"MenuBar.h"
#include"StatusBar.h"
#include"ScrolledWin.h"


enum {

	ID_MENU_FILE = 101,
};
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString & title);
	virtual~MainFrame() = default;

private:

	ScrolledWin* m_scrolled_win = nullptr;
	MenuBar * m_menubar = nullptr;
	StatusBar * m_statusbar = nullptr;

	wxString m_filename = "Untitled";


	wxDECLARE_EVENT_TABLE();
};


