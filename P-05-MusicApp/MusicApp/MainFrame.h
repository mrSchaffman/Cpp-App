#pragma once
#include "wx/wx.h"
#include"MusicList.h"
#include"MainPanel.h"
enum {
	MENU_NEW = 2,
	MENU_OPEN,
	MENU_SAVE,
	MENU_SAVE_AS,
	MENU_SETTINGS,
	MENU_EXIT,

	MENU_ABOUT = 1000
};
class MainFrame : public wxFrame
{
public:

	MainFrame(const wxString& title);
		~MainFrame() = default;

		void OnAbout(wxCommandEvent &event);
		void OnExit(wxCommandEvent &event);
		void OnSave(wxCommandEvent &event);
		void OnSaveAs(wxCommandEvent &event);
		void OnSettings(wxCommandEvent &event);
		void OnNew(wxCommandEvent &event);
		void OnOpen(wxCommandEvent &event);

private:
	MainPanel* m_panel = nullptr;
	wxBoxSizer* m_topSizer = nullptr;

	MusicList* m_playlist = nullptr;
	wxTextCtrl* m_logWindow = nullptr;
	
	wxLog * m_log;


	wxDECLARE_EVENT_TABLE();
	//wxWindow *parent = nullptr;
	
};

