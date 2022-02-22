#pragma once
#include"wx/wx.h"
#include"MenuBar.h"
#include"StatusBar.h"
#include"TextCtrl.h"
#include"MainPanel.h"
#include"FileTreeCtrl.h"





enum {

	ID_MENU_FILE = 101,
};
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString & title);
	virtual~MainFrame() = default;

	void SetFilename(const wxString & name) { m_filename = name; }
	wxString GetFilename() { return m_filename; }

	void SetTextCtrl(TextCtrl& text) { m_text = &text; }
	TextCtrl GetTextCtrl()const { return m_text; }

private:

	MenuBar * m_menubar = nullptr;
	StatusBar * m_statusbar = nullptr;

	wxString m_filename = "Untitled";
	TextCtrl* m_text = nullptr;
	FileTreeCtrl * m_tree = nullptr;

	MainPanel * m_panel = nullptr;

	int m_ln = 0;
	int m_col = 0;

	wxDECLARE_EVENT_TABLE();
};


