#pragma once
#include "wx/wx.h"
class MyTextCtrl : public wxTextCtrl
{
public:
	MyTextCtrl(wxWindow *parent, wxWindowID id, const wxString&value, const wxPoint&pos, const wxSize&size, int style = 0) :wxTextCtrl(parent, id, value, pos, size, style) {
		mHasCapture = false;
	}
	void OnText(wxCommandEvent& event);
	void OnTextEnter(wxCommandEvent& event);
	void OnTextURL(wxTextUrlEvent& event);
	void OnTextMaxLen(wxCommandEvent& event);

	static bool msLogKey;
	static bool msLogChar;
	static bool msLogMouse;
	static bool msLogText;
	static bool msLogFocus;
	static bool msLogClip;

private:
	bool mHasCapture;
	wxDECLARE_EVENT_TABLE();
};

