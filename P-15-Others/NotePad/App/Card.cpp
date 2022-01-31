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

	//wxClientDC dc(this);
	//PrepareDC(dc);

	//if (event.Entering())
	//{
	//	this->ClearBackground();
	//	SetCardSize(wxSize(m_size.GetWidth() + 4,m_size.GetHeight() + 4));
	//	DrawCard(dc);
	//}
	//if (event.Leaving())
	//{
	//	this->ClearBackground();
	//	SetCardSize(wxSize(m_size.GetWidth(), m_size.GetHeight()));
	//	DrawCard(dc);
	//}

}

void Card::SetMargins(size_t left, size_t right, size_t top, size_t bottom)
{
	m_margin_left = left;
	m_margin_right = right;
	m_margin_top = top;
	m_margin_bottom = bottom;
}

//wxSize& Card::UpdateDimensions(const wxSize&  size )
//{
//	m_card = m_shadow = size;
//
//	wxRect temp(m_card);
//	temp.SetLeft((PanelSize.GetX() - size.GetX()) / 2);
//	temp.SetTop((PanelSize.GetY() - size.GetY()) / 2);
//
//	wxRect tempS(m_card);
//	tempS.SetLeft((PanelSize.GetX() - size.GetX()) / 2 + 2);
//	tempS.SetTop((PanelSize.GetY() - size.GetY()) / 2 + 2);
//
//	//m_margins.SetSize(wxSize(size.GetX() - 20, size.GetY() - 20));
//	//m_margins.SetLeft((PanelSize.GetX() - size.GetX()) / 2 + m_margin_left);
//	//m_margins.SetTop((PanelSize.GetY() - size.GetY()) / 2 + m_margin_top);
//
//}
//

void Card::DrawCard(wxDC & dc)
{
	{
		dc.SetPen(m_shadow_pen);
		dc.SetBrush(m_shadow_brush);
		wxRect tempS(m_card);

		tempS.SetLeft((PanelSize.GetX() - m_card.GetX()) / 2 + 2);
		tempS.SetTop((PanelSize.GetY() - m_card.GetY()) / 2 + 2);
		dc.DrawRectangle(tempS);

	}


	{
		dc.SetPen(m_card_pen);
		dc.SetBrush(m_card_brush);
		wxRect temp(m_card);

		temp.SetLeft((PanelSize.GetX() - m_card.GetX()) / 2);
		temp.SetTop((PanelSize.GetY() - m_card.GetY()) / 2);
		dc.DrawRectangle(temp);

	}



}

void Card::DrawCardShadaw(wxDC&dc)
{

	//dc.SetPen(m_shadow_pen);
	//dc.SetBrush(m_shadow_brush);
	//m_shadow.SetLeft((PanelSize.GetX() - m_card.GetX()) / 2 + 2);
	//m_shadow.SetTop((PanelSize.GetY() - m_card.GetY()) / 2 + 2);
	//dc.DrawRectangle(m_shadow);

}

void Card::DrawCardMargins()
{
	wxClientDC dc(this);
	PrepareDC(dc);

	dc.SetPen(m_margings_pen);
	dc.SetBrush(m_margings_brush);
	dc.DrawRectangle(m_margins);

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
