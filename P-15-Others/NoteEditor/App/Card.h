#pragma once
#include"wx/wx.h"


static wxSize PanelSize = wxSize(152, 252);
static wxSize CardDefaultSize = wxSize(132, 232);

class Card: public wxPanel
{
public:
	Card(wxDialog*parent, wxWindowID id, wxSize & format,wxSize & size = PanelSize);
	virtual~Card() = default;

	void OnPaint(wxPaintEvent&event);
	void OnMouse(wxMouseEvent& event);

	bool GetOrientation() { return m_style; }
	void SetOrientation( bool style) { style? m_style = 1: m_style = 0; }
	void SetMargins(size_t left, size_t right, size_t top, size_t bottom){
		m_margin_left = left;
		m_margin_right = right;
		m_margin_top = top;
		m_margin_bottom = bottom;
	}

	void SetMarginTop(size_t marg) { m_margin_top = marg; }
	void SetMarginLeft(size_t marg) {m_margin_left = marg;}
	void SetMarginRight(size_t marg) { m_margin_right = marg; }
	void SetMarginBottom(size_t marg) { m_margin_bottom = marg; }
	//wxSize& UpdateDimensions(const wxSize& size);

	void DrawCard(wxDC&dc);
	void DrawCardMargins();
	void UpdateMargins(wxDC & dc,const wxRect& size);

	void UpdateMarginLeft(int size);
	void UpdateMarginRight(int size);
	void UpdateMarginTop(int size);
	void UpdateMarginButtom(int size);

	void UpdateCard(const wxSize&  size);

	void SetBitmap(wxBitmap bmp) { m_preview_bmp = bmp; }
	void SetFormat(wxSize format) { m_format = format; }

	wxBitmap GetBitmap()const { return m_preview_bmp; }

	void Init();

private:
	wxDialog* m_parent = nullptr;

	bool m_style;

	int m_margin_left{};
	int m_margin_right{};
	int m_margin_top{};
	int m_margin_bottom{};

	wxPoint m_p1{};
	wxPoint m_p2{};

	wxSize m_shadow;
	wxSize m_format;
	wxSize m_margins;


	wxBitmap m_preview_bmp{};


	wxDECLARE_EVENT_TABLE();

};

