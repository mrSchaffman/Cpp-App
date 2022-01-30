#pragma once
#include"wx/wx.h"

class Card: public wxPanel
{
public:
	Card(wxDialog*parent);
	virtual~Card() = default;

	void OnPaint(wxPaintEvent&event);
	void OnMouse(wxMouseEvent& event);

	bool isPortrait() { return m_style; }
	void SetPortrait( bool style) {  m_style = style; }
	void SetMargings(size_t left, size_t right, size_t top, size_t bottom);
	void SetCardSize(const wxSize& size);
	void DrawCard(wxDC&dc);
	void UpdateCard(const wxSize&  size);

private:
	wxDialog* m_parent = nullptr;

	bool m_style;

	size_t m_margin_left = 10;
	size_t m_margin_right = 10;
	size_t m_margin_top  = 10;
	size_t m_margin_bottom = 10;
	wxRect m_shadow;
	wxRect m_card;
	wxRect m_margings;

	wxSize m_size;
	wxPen m_card_pen;
	wxPen m_margings_pen;
	wxPen m_shadow_pen;

	wxBrush m_card_brush;
	wxBrush m_margings_brush;
	wxBrush m_shadow_brush;

	//wxDC dc;

	wxDECLARE_EVENT_TABLE();

};

