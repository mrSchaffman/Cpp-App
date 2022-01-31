#pragma once
#include"wx/wx.h"
#include"wx/hyperlink.h"
#include"Card.h"
#include<array>


enum {
	ID_PAGE_SETTING = 12,

	A1=13,
	A2,
	A3,
	A4,
	A5,
	ANSI_C,
	ANSI_D,
	ANSI_E,

	ID_SIZE,
	ID_PORTRAIT = 50,
	ID_LANDSCAPE,

	ID_MARGIN_LEFT,
	ID_MARGIN_RIGHT,
	ID_MARGIN_TOP,
	ID_MARGIN_BOTTOM,
	ID_HEADER,
	ID_FOOTER,
	ID_MY_INPUT_VALUE,

	ID_RADIOBOX,
	PORTRAIT,
	LANDSCAPE,
};

class PageSettingDialogue: public wxDialog
{
public:
	PageSettingDialogue(wxFrame*parent);
	virtual ~PageSettingDialogue() = default;

	void OnSizeTypeChanged(wxCommandEvent &event);
	void OnMarginLeftChanged(wxCommandEvent &event);
	void OnMarginTopChanged(wxCommandEvent &event);
	void OnMarginRightChanged(wxCommandEvent &event);
	void OnMarginBottomChanged(wxCommandEvent &event);

	void OnOrientationChanged(wxCommandEvent &event);

private:

	wxFrame* m_parent = nullptr;
	wxBoxSizer* m_row3 = nullptr;

	wxTextCtrl*m_header = nullptr;
	wxTextCtrl*m_footer = nullptr;
	wxRadioBox* m_orientation = nullptr;
	Card* m_preview_win = nullptr;

	bool isPortrait = true;
	size_t m_format;
	wxSize m_current_format;
	std::array<wxSize, 6> m_formats;

	wxDECLARE_EVENT_TABLE();
};

