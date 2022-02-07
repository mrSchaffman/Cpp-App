#include "ScrolledWin.h"
wxBEGIN_EVENT_TABLE(ScrolledWin, wxScrolledWindow)
EVT_PAINT(ScrolledWin::OnPaint)
//EVT_LEFT_DOWN(ScrolledWin::OnMouseDown)
//EVT_LEFT_UP(ScrolledWin::OnMouseUp)
EVT_MOUSE_EVENTS(ScrolledWin::OnMouse)
wxEND_EVENT_TABLE()

ScrolledWin::ScrolledWin(wxFrame* frame):wxScrolledWindow(frame,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxHSCROLL||wxVSCROLL)//,m_frame(std::move(frame))
{


	SetBackgroundColour(wxColour (120, 120, 120));

	 //m_link = new wxHyperlinkCtrl(this, wxID_ANY, wxT("see more: @Barth.Feudong"), wxT("https://github.com/mrSchaffman"), wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL | wxTE_READONLY);

}


wxBitmap ScrolledWin::CreateRedOutlineBitmap()
{
	wxColour penCol(120, 120, 120);
	wxColour shadowPenCol(155, 155, 155);
	wxColour col3(160, 160,160);
	wxMemoryDC memDC;
	wxBitmap bitmap(GetParent()->GetSize().GetX(), GetParent()->GetSize().GetY());
	memDC.SelectObject(bitmap);


	memDC.SetBackground(wxBrush(col3,wxBRUSHSTYLE_SOLID));
	memDC.Clear();

	memDC.SetPen(shadowPenCol);
	memDC.SetBrush(wxBrush(shadowPenCol, wxBRUSHSTYLE_SOLID));
	memDC.DrawRectangle(wxRect(40, 40, 120, 120));


	memDC.SetPen(penCol);
	memDC.SetBrush(wxBrush(penCol,wxBRUSHSTYLE_SOLID));
	memDC.DrawRectangle(wxRect(50, 50, 100, 100));


	memDC.SelectObject(wxNullBitmap);
	return bitmap;
}
wxBitmap ScrolledWin::GetScreenShot()
{
	wxSize screenSize = wxGetDisplaySize();
	wxBitmap bitmap(screenSize.x, screenSize.y);
	wxScreenDC dc;
	wxMemoryDC memDC;
	memDC.SelectObject(bitmap);
	memDC.Blit(0, 0, screenSize.x, screenSize.y, &dc, 0, 0);
	memDC.SelectObject(wxNullBitmap);
	return bitmap;
}

void ScrolledWin::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	PrepareDC(dc);

	wxPen pen(wxColour(180, 180, 180));
	wxBrush brush(wxColour(180, 180, 180), wxBRUSHSTYLE_SOLID);
	wxBitmap bmp(wxSize(GetClientSize().GetX(), 60));

	dc.SetPen(pen);
	dc.SetBrush(brush);
	dc.DrawBitmap(bmp,wxPoint(0,0),true);

	wxFont font(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	dc.SetFont(font);
	dc.SetBackgroundMode(wxTRANSPARENT);
	dc.SetTextForeground(*wxWHITE);
	dc.SetTextBackground(wxTRANSPARENT);

	dc.DrawLabel(wxT("Barth"), wxRect(wxSize(GetClientSize().GetX(), 40)));

}

void ScrolledWin::OnMouse(wxMouseEvent & event)
{
	if (event.LeftDown())
	{
		m_anchorpoint = event.GetPosition();
		m_rubberBand = true;
		CaptureMouse();
	}
	if (event.LeftUp())
	{
		if (m_rubberBand)
		{
			ReleaseMouse();
			m_currentpoint = event.GetPosition();

		}
	}
	if (event.Moving())
	{

	}

}
