#pragma once
#include"wx/wx.h"
#include"MainPanel.h"
#include"MenuBar.h"
#include"StatusBar.h"
#include"TextCtrl.h"




enum {

	ID_MENU_FILE = 101,
};
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString & title);
	virtual~MainFrame() = default;

private:

	MenuBar * m_menubar = nullptr;
	StatusBar * m_statusbar = nullptr;

	wxString m_filename = "Untitled";
	TextCtrl* m_text_screen = nullptr;

	wxDECLARE_EVENT_TABLE();
};


