#pragma once
#include "wx/wx.h"
#include"MusicList.h"
#include"MainPanel.h"
enum {
	NEW = 2,
	OPEN,
	SAVE,
	SAVE_AS,
	SETTINGS,
	EXIT,

	ABOUT = 100
};
class MainFrame : public wxFrame
{
public:

	MainFrame(const wxString title);
		~MainFrame() = default;

private:
	MainPanel* m_panel = nullptr;
	wxBoxSizer* m_topSizer = nullptr;

	MusicList* m_playlist = nullptr;
	wxTextCtrl* m_logWindow = nullptr;
	
	wxLog * m_log;


	wxDECLARE_EVENT_TABLE();
	//wxWindow *parent = nullptr;
	
};

