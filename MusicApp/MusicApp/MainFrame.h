#pragma once
#include "wx/wx.h"
#include"MusicList.h"

class MainFrame : public wxFrame
{
public:

	MainFrame(const wxString title);
		~MainFrame() = default;

private:
	wxPanel* m_panel = nullptr;
	MusicList* m_playlist = nullptr;
	wxTextCtrl* m_logMessageWindow = nullptr;
	wxBoxSizer* m_topSizer =  nullptr;
	
	wxLog * m_log;


	wxDECLARE_EVENT_TABLE();
	//wxWindow *parent = nullptr;
	
};

