#pragma once
#include "wx/wx.h"

enum
{
	RICHTEXT_CLOSE = 1000,
	RICHTEXT_LEFT_ALIGN,
	RICHTEXT_RIGHT_ALIGN,
	RICHTEXT_CENTRE,
	RICHTEXT_JUSTIFY,
	RICHTEXT_CHANGE_FONT,
	RICHTEXT_CHANGE_TEXT_COLOUR,
	RICHTEXT_CHANGE_BACKGROUND_COLOUR,
	RICHTEXT_LEFT_INDENT,
	RICHTEXT_RIGHT_INDENT,
	RICHTEXT_TAB_STOPS
};
class RichTextFrame : public wxFrame
{
public:
	RichTextFrame(wxWindow* parent, const wxString& title);

	// Event handlers

	void OnClose(wxCommandEvent& event);
	void OnIdle(wxIdleEvent& event);
	void OnLeftAlign(wxCommandEvent& event);
	void OnRightAlign(wxCommandEvent& event);
	void OnJustify(wxCommandEvent& event);
	void OnCentre(wxCommandEvent& event);
	void OnChangeFont(wxCommandEvent& event);
	void OnChangeTextColour(wxCommandEvent& event);
	void OnChangeBackgroundColour(wxCommandEvent& event);
	void OnLeftIndent(wxCommandEvent& event);
	void OnRightIndent(wxCommandEvent& event);
	void OnTabStops(wxCommandEvent& event);

private:
	wxTextCtrl *m_textCtrl;
	long m_currentPosition;

	wxDECLARE_EVENT_TABLE();
};

