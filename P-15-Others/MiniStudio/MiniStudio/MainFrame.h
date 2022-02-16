#pragma once
#include"wx/wx.h"
#include"MenuBar.h"

class MainFrame : public wxFrame
{
public:

	MainFrame(const wxString & title=wxT("Mini File Studio"));
	virtual~MainFrame() = default;

private:

	MenuBar* m_menuBar{};
	wxDECLARE_EVENT_TABLE();
};

