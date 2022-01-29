#pragma once
#include"wx/wx.h"
#include"MenuBar.h"
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

	wxString m_filename = "Untitled";


	wxDECLARE_EVENT_TABLE();
};


