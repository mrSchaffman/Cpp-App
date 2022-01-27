#pragma once
#include"wx/wx.h"

class PreviewWin: public wxPanel
{
public:
	PreviewWin(wxDialog*parent);
	virtual~PreviewWin() = default;

	void OnPaint(wxPaintEvent&event);
private:
	wxDialog* m_parent = nullptr;
	wxPaintDC* dc = nullptr;

	wxDECLARE_EVENT_TABLE();

};

