#pragma once
#include"wx/wx.h"
#include"wx/hyperlink.h"
#include"Card.h"
#include<array>
#include<set>
#include"wx/valnum.h"


enum {
	ID_PAGE_SETTING = 12,

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

	ID_OK,
	ID_CANCEL,
	ID_RESET,
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
	void SetSize(int size) { m_size = size; }
	int GetSize()const { return m_size; }

	void SetSource(int size) { m_source = size; }
	int GetSource()const { return m_source; }

	void SetLeft(int size) { m_left = size; }
	int GetLeft()const { return m_left; }

	void SetRight(int size) { m_right = size; }
	int GetRight()const { return m_right; }

	void SetTop(int size) { m_top = size; }
	int GetTop()const { return m_top; }

	void SetBottom(int size) { m_bottom = size; }
	int GetBottom()const { return m_bottom; }

	void SetOrientation(bool orientation) { orientation ? m_orientation = 1: m_orientation = 0; } // false -> portrait, true-> landscape
	bool GetOrientation()const { return m_orientation; }

	void SetHeader(const wxString& str) { m_header = str; }
	wxString GetHeader()const { return m_header; }

	void SetFooter(const wxString& str) { m_footer = str; }
	wxString GetFooter()const { return m_footer; }


	// Laying out the constrol
	void CreateControls();

	// Event Handler
	void OnOK(wxCommandEvent &event);
	void OnResetClick(wxCommandEvent &event);

	void OnSizeTypeUpdate(wxUpdateUIEvent &event);
	void OnSourceUpdate(wxUpdateUIEvent &event);
	void OnMarginLeftUpdate(wxUpdateUIEvent &event);
	void OnMarginTopUpdate(wxUpdateUIEvent &event);
	void OnMarginRightUpdate(wxUpdateUIEvent &event);
	void OnMarginBottomUpdate(wxUpdateUIEvent &event);
	void OnOrientationUpdate(wxUpdateUIEvent &event);


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

	//std::set<int, Card> m_cards{};
	wxBitmap m_current_bmp{};

	wxDECLARE_EVENT_TABLE();
};

