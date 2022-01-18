#pragma once
#include "wx/wx.h"


class NumberTextCtrl :public wxTextCtrl
{
public:
	NumberTextCtrl(wxWindow *parent, wxWindowID id, const wxString&value = wxEmptyString, const wxPoint&pos = wxDefaultPosition, const wxSize&size = wxDefaultSize, int style = 0) :wxTextCtrl(parent, id, value, pos, size, style) {
		mHasCapture = false;
	}

	//Respond to a wxEVT_TEXT event, generated when the text changes.
	void OnText(wxCommandEvent& event);

	// Respond to a wxEVT_TEXT_ENTER event, 
	// generated when enter is pressed in a text control which 
	// must have wxTE_PROCESS_ENTER style for this event to be generated.
	void OnTextEnter(wxCommandEvent& event);

	// A mouse event occurred over an URL in the text control (wxMSW and wxGTK2 only currently).
	void OnTextURL(wxTextUrlEvent& event);

	// This event is generated when the user tries to enter more text into the control 
	// than the limit set by wxTextCtrl::SetMaxLength(), see its description. 
	void OnTextMaxLen(wxCommandEvent& event);

private:
	wxDECLARE_EVENT_TABLE();
		bool mHasCapture;


};

