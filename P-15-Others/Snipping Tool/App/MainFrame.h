#pragma once
#include"wx/wx.h"
#include"ToolBar.h"
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
	ToolBar * m_toolbar = nullptr;

	wxString m_filename = "Untitled";


	wxDECLARE_EVENT_TABLE();
};


