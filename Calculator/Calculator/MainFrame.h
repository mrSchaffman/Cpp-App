#pragma once
#include"wx/wx.h"
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString&title);
	~MainFrame();

private:
	DECLARE_EVENT_TABLE()
};

