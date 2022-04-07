#pragma once
#include"wx/wx.h"
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& caption,
		const wxPoint& pos = wxPoint(500,300),
		const wxSize& size = wxDefaultSize,
		long style = wxCLOSE_BOX | wxCAPTION | wxRESIZE_BORDER);
	MainFrame() = default;

	void Init();
	bool Create(const wxString& caption,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxDEFAULT_FRAME_STYLE);



private:

	wxDECLARE_EVENT_TABLE();
};

