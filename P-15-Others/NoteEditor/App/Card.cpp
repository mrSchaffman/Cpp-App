#include "Card.h"
wxBEGIN_EVENT_TABLE(Card, wxPanel)
	EVT_PAINT(Card::OnPaint)
	EVT_MOUSE_EVENTS(Card::OnMouse)
wxEND_EVENT_TABLE()

Card::Card(wxDialog * parent, wxWindowID id, wxSize & format, wxSize & size):wxPanel(parent,id,wxDefaultPosition, size), m_parent (parent), m_format ( format)
{


	Init();

	//SetBackgroundColour(wxColour(216, 243, 220));
}

void Card::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	PrepareDC(dc);

	wxRect format(DrawCard(dc));
	
	wxPoint p1(format.GetLeft() + m_margin_left, format.GetTop() + m_margin_top);
	wxPoint p2(format.GetRight() - m_margin_right, format.GetBottom() + m_margin_bottom);
	wxRect marginRect(p1, p2);
	//DrawCard(dc);


}

void Card::OnMouse(wxMouseEvent & event)
{

	if (event.Entering())
	{
		wxSize sizeZoomIn(m_format.GetWidth() + 4, m_format.GetHeight() + 4);
		UpdateCard(sizeZoomIn);
	}
	if (event.Leaving())
	{
		wxSize sizeZoomOut(m_format.GetWidth() - 4, m_format.GetHeight() - 4);
		UpdateCard(sizeZoomOut);
	}

}


void Card::UpdateMargins(const wxRect & rect)
{
	m_format_anchor = wxPoint((PanelSize.GetX() - m_format.GetX()) / 2, (PanelSize.GetY() - m_format.GetY()) / 2);
	{

		wxPoint p1(m_format_anchor.x + m_margin_left, m_format_anchor.y + m_margin_top);
		wxPoint p2(m_format_anchor.x + m_format.GetWidth() - m_margin_right, m_format_anchor.y + m_format.GetHeight() - m_margin_bottom);
		wxRect marginRect(p1, p2);

		m_margins = marginRect;

	}

}

wxRect & Card::DrawCard(wxDC & dc)
{
	{
		wxPen m_shadow_pen = wxPen(wxColour(116, 198, 157));
		wxBrush m_shadow_brush = wxBrush(wxColour(116, 198, 157), wxBRUSHSTYLE_SOLID);

		dc.SetPen(m_shadow_pen);
		dc.SetBrush(m_shadow_brush);
		wxRect tempS(m_format);

		tempS.SetLeft((PanelSize.GetX() - m_format.GetX()) / 2 + 3);
		tempS.SetTop((PanelSize.GetY() - m_format.GetY()) / 2 + 3);
		dc.DrawRectangle(tempS);

	}


	wxRect temp(m_format);
	{
		wxPen m_format_pen = wxPen(*wxWHITE_PEN);
		wxBrush m_format_brush = wxBrush(*wxWHITE_BRUSH);

		dc.SetPen(m_format_pen);
		dc.SetBrush(m_format_brush);

		wxPoint formatAnchor((PanelSize.GetX() - m_format.GetX()) / 2, (PanelSize.GetY() - m_format.GetY()) / 2);

		dc.DrawRectangle(formatAnchor,wxSize(m_format));

	}

	// the margins
	{


		DrawCardMargins(dc, temp);

	}

	return temp;

}


void Card::DrawCardMargins(wxDC& dc,wxRect& rect)
{
	wxClientDC margin_dc(this); // so i can use clear on it
	PrepareDC(margin_dc);


	// new to use blit for the two dc's

	//wxPoint p1(rect.GetLeft() + m_margin_left, rect.GetTop() + m_margin_top);
	//wxPoint p2(rect.GetRight() - m_margin_right, rect.GetBottom() - m_margin_bottom);
	//wxRect marginRect(p1, p2);


	wxPen m_margings_pen = wxPen(wxColour(255, 0, 0), 1, wxPENSTYLE_SHORT_DASH);
	wxBrush m_margings_brush = wxBrush(*wxTRANSPARENT_BRUSH);


	dc.SetPen(m_margings_pen);
	dc.SetBrush(m_margings_brush);


	dc.DrawRectangle(m_margins);

}

void Card::UpdateMargins(wxDC & dc,const wxRect & size)
{
	this->RefreshRect(PanelSize);
	dc.DrawRectangle(size);
}

void Card::UpdateMarginLeft(int size)
{

}

void Card::UpdateMarginRight(int size)
{
}

void Card::UpdateMarginTop(int size)
{
}

void Card::UpdateMarginButtom(int size)
{
}


void Card::UpdateCard(const wxSize&  size)
{
	m_format = size;
	//UpdateMargins(m_format);

	this->RefreshRect(PanelSize);

	wxClientDC dc(this);
	PrepareDC(dc);

	DrawCard(dc);

}

void Card::Init()
{
	m_shadow = m_format;
	m_style = true;

	wxSize temp(m_format.GetHeight(), m_format.GetWidth());
	//m_formats = { m_format, temp };
	// margins
	{
		m_margin_left = 20;
		m_margin_right = 20;
		m_margin_top = 20;
		m_margin_bottom = 20;

		m_p1 = wxPoint(m_margin_left, m_margin_top);
		m_p2 = wxPoint(m_format.GetHeight() - m_margin_bottom, m_format.GetWidth() - m_margin_right);

		 m_format_anchor = wxPoint((PanelSize.GetX() - m_format.GetX()) / 2, (PanelSize.GetY() - m_format.GetY()) / 2);
		{

			wxPoint p1(m_format_anchor.x + m_margin_left, m_format_anchor.y + m_margin_top);
			wxPoint p2(m_format_anchor.x + m_format.GetWidth() - m_margin_right, m_format_anchor.y + m_format.GetHeight() - m_margin_bottom);
			wxRect marginRect(p1, p2);

			m_margins = marginRect;

		}

	}
}
