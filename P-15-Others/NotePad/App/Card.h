#pragma once
#include"wx/wx.h"


static wxSize PanelSize = wxSize(152, 252);
static wxSize CardDefaultSize = wxSize(132, 232);

class Card: public wxPanel
{
public:
	Card(wxDialog*parent,wxSize & size);
	virtual~Card() = default;

	void OnPaint(wxPaintEvent&event);
	void OnMouse(wxMouseEvent& event);

	bool isPortrait() { return m_style; }
	void SetPortrait( bool style) {  m_style = style; }
	void SetMargins(size_t left, size_t right, size_t top, size_t bottom);

	void SetMarginTop(size_t marg);
	void SetMarginLeft(size_t marg);
	void SetMarginRight(size_t marg);
	void SetMarginBottom(size_t marg);
	//wxSize& UpdateDimensions(const wxSize& size);

	void DrawCard(wxDC&dc);
	void DrawCardMargins();
	void UpdateMargins(wxDC & dc,const wxRect& size);
	void UpdateCard(const wxSize&  size);

private:
	wxDialog* m_parent = nullptr;

	bool m_style;

	size_t m_margin_left = 10;
	size_t m_margin_right = 10;
	size_t m_margin_top  = 10;
	size_t m_margin_bottom = 10;
	wxSize m_shadow;
	wxSize m_card;
	wxSize m_margins;

	wxSize m_size;
	wxSize m_format;
	wxPen m_card_pen;
	wxPen m_margings_pen;
	wxPen m_shadow_pen;

	wxBrush m_card_brush;
	wxBrush m_margings_brush;
	wxBrush m_shadow_brush;



	wxDECLARE_EVENT_TABLE();

};

