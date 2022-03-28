#pragma once
#include"wx/wx.h"
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& caption);
	virtual ~MainFrame() = default;

private:

	wxDECLARE_EVENT_TABLE();
};

