#include "ScrolledWin.h"
wxBEGIN_EVENT_TABLE(ScrolledWin, wxScrolledWindow)
EVT_MOTION(ScrolledWin::OnMouseMove)
EVT_LEFT_DOWN(ScrolledWin::OnMouseDown)
EVT_LEFT_UP(ScrolledWin::OnMouseUp)
EVT_PAINT(ScrolledWin::OnPaint)
wxEND_EVENT_TABLE()

ScrolledWin::ScrolledWin(wxFrame * frame):wxScrolledWindow(frame,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxHSCROLL||wxVSCROLL)
{
	m_frame = frame;
	SetScrollbars(m_pixelsPerUnixX, m_pixelsPerUnixY, m_noUnitsX, m_noUnitsY);
}

void ScrolledWin::OnMouseDown(wxMouseEvent & event)
{
	int x, y, xx, yy;
	event.GetPosition(&x, &y);

	// translate between scrolled and unscrolled coordinates
	CalcUnscrolledPosition(x, y, &xx, &yy);
	m_anchorpoint = wxPoint(xx, yy);
	m_currentpoint = m_anchorpoint;
	m_rubberBand = true;

	m_ln = xx;
	m_col = yy;

	CaptureMouse();
}

void ScrolledWin::OnMouseUp(wxMouseEvent & event)
{
	if (m_rubberBand)
	{
		ReleaseMouse();

		m_overlay.Reset();
		m_rubberBand = false;

		wxPoint endpoint = CalcUnscrolledPosition(event.GetPosition());
		if (endpoint == m_anchorpoint)
		{
			wxString lnCol;
			lnCol.Printf("Ln %d, Col %d", m_col, m_ln);
			m_frame->SetStatusText(lnCol, 1);
		}
	}
}

void ScrolledWin::OnMouseMove(wxMouseEvent & event)
{
	if (m_rubberBand)
	{
		int x, y, xx, yy;
		event.GetPosition(&x, &y);
		CalcUnscrolledPosition(x, y, &xx, &yy);
		m_currentpoint = wxPoint(xx, yy);

		wxRect newRect(m_anchorpoint, m_currentpoint);

		wxClientDC dc(this);
		PrepareDC(dc);

		wxDCOverlay overlay_dc(m_overlay, &dc);
		overlay_dc.Clear();

		dc.SetPen(wxPen(*wxRED, 1));
		//dc.SetBrush(*wxTRANSPARENT_BRUSH);

		dc.DrawRectangle(newRect);

	}
}

void ScrolledWin::OnPaint(wxPaintEvent & event)
{
	wxPaintDC p_dc(this);
	DoPrepareDC(p_dc);

	//p_dc.SetPen(*wxRED_PEN);
	p_dc.SetPen(wxPen(*wxRED, 2));

	p_dc.DrawLine(10, 10, 10, 50);
	p_dc.DrawLine(10, 50, 50, 50);
	//p_dc.DrawLine(0, 0, 200, 200);
	//p_dc.DrawLine(0, 0, 200, 200);
	p_dc.DrawRectangle(wxRect(wxPoint(100, 100), wxPoint(250, 130)));
	p_dc.SetPen(*wxBLACK_PEN);
	p_dc.DrawRectangle(wxRect(wxPoint(110, 110), wxPoint(120, 120)));
}
