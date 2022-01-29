#include "ScrolledWin.h"
wxBEGIN_EVENT_TABLE(ScrolledWin, wxScrolledWindow)
EVT_PAINT(ScrolledWin::OnPaint)
//EVT_LEFT_DOWN(ScrolledWin::OnMouseDown)
//EVT_LEFT_UP(ScrolledWin::OnMouseUp)
wxEND_EVENT_TABLE()

ScrolledWin::ScrolledWin(wxFrame * frame):wxScrolledWindow(frame,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxHSCROLL||wxVSCROLL)
{
	m_frame = frame;
	SetScrollbars(m_pixelsPerUnixX, m_pixelsPerUnixY, m_noUnitsX, m_noUnitsY);

	wxBitmap bitmap = CreateRedOutlineBitmap();
	wxBitmap screenshot = GetScreenShot();

	wxColour col2(120, 120, 120);
	//wxColour col3(160, 160, 160);
	//wxColour col4(200, 200, 200);
	SetBackgroundColour(col2);


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

	dc.DrawBitmap(CreateRedOutlineBitmap(),wxPoint(0,0));
	//dc.DrawBitmap(GetScreenShot(), wxPoint(200, 200));
}
