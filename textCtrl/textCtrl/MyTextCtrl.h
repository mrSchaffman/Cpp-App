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

private:
	bool mHasCapture;
};

