#include "Card.h"
wxBEGIN_EVENT_TABLE(Card, wxPanel)
	EVT_PAINT(Card::OnPaint)
	EVT_MOUSE_EVENTS(Card::OnMouse)
wxEND_EVENT_TABLE()

Card::Card(wxDialog * parent):wxPanel(parent,wxID_ANY,wxDefaultPosition,wxSize(152,252))
{
	m_parent = parent;
	m_size = wxSize(132, 187);
	SetCardSize(m_size);


}

void Card::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	PrepareDC(dc);

	DrawCard(dc);
}

void Card::OnMouse(wxMouseEvent & event)
{
	this->ClearBackground();

	wxClientDC dc(this);
	PrepareDC(dc);

	if (event.Entering())
	{
		SetCardSize(wxSize(m_size.GetWidth() + 4,m_size.GetHeight() + 4));
		DrawCard(dc);
	}
	if (event.Leaving())
	{
		SetCardSize(wxSize(m_size.GetWidth(), m_size.GetHeight()));
		DrawCard(dc);
	}

}

void Card::SetMargings(size_t left, size_t right, size_t top, size_t bottom)
{
	m_margin_left = left;
	m_margin_right = right;
	m_margin_top = top;
	m_margin_bottom = bottom;


}

void Card::SetCardSize(const wxSize&  size)
{
	m_card.SetSize(size);
	m_card.SetLeft((152 - size.GetX()) / 2);
	m_card.SetTop((252-size.GetY())/2);

	m_shadow.SetSize(wxSize(size.GetX() + 1, size.GetY() + 1));
	m_shadow.SetLeft((152 - size.GetX()) / 2 + 2);
	m_shadow.SetTop((252 - size.GetY()) / 2 + 2);

	m_margings.SetSize(wxSize(size.GetX() - 20, size.GetY() - 20));
	m_margings.SetLeft((152 - size.GetX()) / 2 + m_margin_left);
	m_margings.SetTop((252 - size.GetY()) / 2 + m_margin_top);



	m_shadow_pen = wxPen(wxColour(222, 226, 230));
	m_margings_pen = wxPen(wxColour(255, 0, 0), 1, wxPENSTYLE_SHORT_DASH);
	m_card_pen = wxPen(*wxWHITE_PEN);

	m_card_brush = wxBrush(*wxWHITE_BRUSH);
	m_margings_brush = wxBrush(*wxTRANSPARENT_BRUSH);
	m_shadow_brush = wxBrush(wxColour(222, 226, 230), wxBRUSHSTYLE_SOLID);

}

void Card::DrawCard(wxDC & dc)
{
	{
		dc.SetPen(m_shadow_pen);
		dc.SetBrush(m_shadow_brush);
		dc.DrawRectangle(m_shadow);

	}
	{
		dc.SetPen(m_card_pen);
		dc.SetBrush(m_card_brush);
		dc.DrawRectangle(m_card);

	}
	{
		dc.SetPen(m_margings_pen);
		dc.SetBrush(m_margings_brush);
		dc.DrawRectangle(m_margings);

	}

}

void Card::UpdateCard(const wxSize&  size)
{
	this->ClearBackground();

	m_size = size;

	wxClientDC dc(this);
	PrepareDC(dc);

	SetCardSize(m_size);
	DrawCard(dc);

}
