#pragma once
#include"wx/wx.h"
#include"wx/hyperlink.h"
#include"Card.h"


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

	PORTRAIT,
	LANDSCAPE,
};

class PageSettingDialogue: public wxDialog
{
public:
	PageSettingDialogue(wxFrame*parent);
	virtual ~PageSettingDialogue() = default;

	void OnSizeTypeChanged(wxCommandEvent &event);

private:

	wxFrame* m_parent = nullptr;
	wxBoxSizer* m_row3 = nullptr;

	wxTextCtrl*m_header = nullptr;
	wxTextCtrl*m_footer = nullptr;
	wxStaticBoxSizer* m_orientation = nullptr;
	Card* m_preview_win = nullptr;

	wxDECLARE_EVENT_TABLE();
};

