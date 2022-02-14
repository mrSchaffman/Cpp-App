#pragma once
#include"wx/wx.h"
#include"wx/hyperlink.h"
#include"Card.h"
#include<array>
#include"wx/valnum.h"


enum {
	ID_PAGE_SETTING = 12,

	A1,
	A2,
	A3,
	A4,
	A5,
	ANSI_C,
	ANSI_D,
	ANSI_E,

	ID_SIZE_CBOX,
	ID_PORTRAIT = 50,
	ID_LANDSCAPE,
	ID_CARD,

	ID_MARGIN_LEFT,
	ID_MARGIN_RIGHT,
	ID_MARGIN_TOP,
	ID_MARGIN_BOTTOM,
	ID_HEADER,
	ID_FOOTER,
	ID_MY_INPUT_VALUE,
	ID_SOURCE_CBOX,
	ID_RADIOBOX,
	ID_ORIENTATION,
	PORTRAIT,
	LANDSCAPE,
};

class PageSettingDialogue: public wxDialog
{
public:
	PageSettingDialogue(wxFrame*parent, wxWindowID id = wxID_ANY,
		const wxString& caption = wxT("Page Settings"),
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxSize(560, 390));
		//long style = wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU);

	virtual ~PageSettingDialogue() = default;

	// Accessors
	void SetLeft(int size);

	void CreateControls();

	void OnSizeTypeChanged(wxCommandEvent &event);
	void OnMarginLeftChanged(wxCommandEvent &event);
	void OnMarginTopChanged(wxCommandEvent &event);
	void OnMarginRightChanged(wxCommandEvent &event);
	void OnMarginBottomChanged(wxCommandEvent &event);

	void OnOrientationChanged(wxCommandEvent &event);

	void Init();
private:

	bool TransferDataToWindow();
	bool TransferDataFromWindow();

	wxFrame* m_parent = nullptr;


	bool m_orientation{};

	Card* m_preview_win = nullptr;


	int m_left;
	int m_top;
	int m_right;
	int m_bottom;

	wxString m_header{};
	wxString m_footer{};

	int m_size{};
	int m_source{};
	wxArrayString m_sizes{};
	wxArrayString m_sources{};
	wxArrayString m_orientations{};

	bool isPortrait = true;
	//size_t m_format;
	wxSize m_current_format{};
	std::array<wxSize, 6> m_formats{};

	std::array<wxBitmap,6> m_bmps{};
	wxBitmap m_current_bmp{};

	wxDECLARE_EVENT_TABLE();
};

