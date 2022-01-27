#include "PreviewWin.h"
wxBEGIN_EVENT_TABLE(PreviewWin, wxPanel)
	EVT_PAINT(PreviewWin::OnPaint)
wxEND_EVENT_TABLE()

PreviewWin::PreviewWin(wxDialog * parent):wxPanel(parent,wxID_ANY,wxDefaultPosition,wxSize(152,252))
{
	m_parent = parent;
}

void PreviewWin::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	PrepareDC(dc);

	{
		wxPen pen(wxColour(222, 226, 230));
		dc.SetPen(pen);
		wxBrush brush(wxColour(222, 226, 230), wxBRUSHSTYLE_SOLID);
		dc.SetBrush(brush);

		wxRect shadow(wxPoint(30, 50), wxPoint(125, 217));
		dc.DrawRectangle(shadow);

	}
	{
		wxPen pen(wxColour(222, 226, 230));
		dc.SetPen(*wxWHITE_PEN);
		wxBrush brush(*wxWHITE_BRUSH);
		dc.SetBrush(brush);

		wxRect shadow(wxPoint(20, 40), wxPoint(115, 207));
		dc.DrawRectangle(shadow);

	}
}
