#include "ScrolledWin.h"
wxBEGIN_EVENT_TABLE(ScrolledWin, wxScrolledWindow)
//EVT_PAINT(MainScrolledWindow::OnPaint)
//EVT_MOTION(MainScrolledWindow::OnMouseMove)
EVT_LEFT_DOWN(ScrolledWin::OnMouseDown)
EVT_LEFT_UP(ScrolledWin::OnMouseUp)
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

		wxPoint endpoint = CalcUnscrolledPosition(event.GetPosition());
		if (endpoint == m_anchorpoint)
		{
			wxString lnCol;
			lnCol.Printf("Ln %d, Col %d", m_col, m_ln);
			m_frame->SetStatusText(lnCol, 1);
		}
	}
}
