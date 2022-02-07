#include "Card.h"
wxBEGIN_EVENT_TABLE(Card, wxPanel)
	EVT_PAINT(Card::OnPaint)
	EVT_MOUSE_EVENTS(Card::OnMouse)
wxEND_EVENT_TABLE()

Card::Card(wxDialog * parent, wxSize & size):wxPanel(parent,wxID_ANY,wxDefaultPosition, PanelSize)
{
	m_parent = parent;
	m_card = size;


	m_shadow = m_card;
	m_margins = wxSize(m_card.GetWidth() - 5, m_card.GetHeight() - 5);


	m_shadow_pen = wxPen(wxColour(222, 226, 230));
	m_margings_pen = wxPen(wxColour(255, 0, 0), 1, wxPENSTYLE_SHORT_DASH);
	m_card_pen = wxPen(*wxWHITE_PEN);

	m_card_brush = wxBrush(*wxWHITE_BRUSH);
	m_margings_brush = wxBrush(*wxTRANSPARENT_BRUSH);
	m_shadow_brush = wxBrush(wxColour(222, 226, 230), wxBRUSHSTYLE_SOLID);


}

void Card::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	PrepareDC(dc);

	DrawCard(dc);

}

void Card::OnMouse(wxMouseEvent & event)
{

	if (event.Entering())
	{
		wxSize sizeZoomIn(m_card.GetWidth() + 4, m_card.GetHeight() + 4);
		UpdateCard(sizeZoomIn);
	}
	if (event.Leaving())
	{
		wxSize sizeZoomOut(m_card.GetWidth() - 4, m_card.GetHeight() - 4);
		UpdateCard(sizeZoomOut);
	}

}

void Card::SetMargins(size_t left, size_t right, size_t top, size_t bottom)
{
	m_margin_left = left;
	m_margin_right = right;
	m_margin_top = top;
	m_margin_bottom = bottom;
}

void Card::SetMarginTop(size_t marg)
{
	m_margin_top = marg;
	// updateMargin
}

void Card::SetMarginLeft(size_t marg)
{
	m_margin_left = marg;
}

void Card::SetMarginRight(size_t marg)
{
	m_margin_right = marg;
}

void Card::SetMarginBottom(size_t marg)
{
	m_margin_bottom = marg;
}


void Card::DrawCard(wxDC & dc)
{
	{
		dc.SetPen(m_shadow_pen);
		dc.SetBrush(m_shadow_brush);
		wxRect tempS(m_card);

		tempS.SetLeft((PanelSize.GetX() - m_card.GetX()) / 2 + 3);
		tempS.SetTop((PanelSize.GetY() - m_card.GetY()) / 2 + 3);
		dc.DrawRectangle(tempS);

	}


	{
		dc.SetPen(m_card_pen);
		dc.SetBrush(m_card_brush);
		wxRect temp(m_card);

		temp.SetLeft((PanelSize.GetX() - m_card.GetX()) / 2);
		temp.SetTop((PanelSize.GetY() - m_card.GetY()) / 2 );
		dc.DrawRectangle(temp);

	}
	DrawCardMargins();


}


void Card::DrawCardMargins()
{
	wxClientDC dc(this);
	PrepareDC(dc);

	dc.SetPen(m_margings_pen);
	dc.SetBrush(m_margings_brush);

	//wxRect m_margins(wxPoint(m_margin_top, m_margin_left), wxPoint(m_margin_right, m_margin_bottom));
	wxRect temp(m_margins);

	temp.SetLeft((PanelSize.GetX() - m_card.GetX()) / 2 + m_margin_left);
	temp.SetTop((PanelSize.GetY() - m_card.GetY()) / 2 + m_margin_top);

	temp.SetRight((PanelSize.GetX() - m_card.GetX()) / 2 - m_margin_right );
	temp.SetBottom((PanelSize.GetY() - m_card.GetY()) / 2 - m_margin_bottom);

	dc.DrawRectangle(temp);

}

void Card::UpdateMargins(wxDC & dc,const wxRect & size)
{
	this->RefreshRect(PanelSize);
	dc.DrawRectangle(size);
}

void Card::UpdateCard(const wxSize&  size)
{
	m_card = size;

	this->RefreshRect(PanelSize);

	wxClientDC dc(this);
	PrepareDC(dc);

	DrawCard(dc);

}
