#pragma once
#include "wx/wx.h"
#include"MainPanel.h"

enum
{
	TEXT_QUIT = wxID_EXIT,
	TEXT_ABOUT = wxID_ABOUT,
	//TEXT_LOAD = 101,
	//TEXT_SAVE,
};
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, int x, int y);
	void OnQuit(wxCommandEvent &evt);
	void OnAbout(wxCommandEvent &evt);

private:
	MainPanel * mPanel = nullptr;

	wxDECLARE_EVENT_TABLE();
};

