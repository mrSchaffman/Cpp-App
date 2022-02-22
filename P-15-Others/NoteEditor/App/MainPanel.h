#pragma once
#include"wx/wx.h"
#include"TextCtrl.h"
#include"FileTreeCtrl.h"

class MainPanel: public wxPanel
{
public:

	MainPanel(wxFrame*frame);
	virtual ~MainPanel()=default;

	void OnPaint(wxPaintEvent&event);
	wxBitmap CreateLogo();
	wxBitmap CreateSideButtons();

private:

	TextCtrl* m_text{};
	FileTreeCtrl*m_tree{};

	wxDECLARE_EVENT_TABLE();

};

