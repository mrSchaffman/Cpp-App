#include "ScrolledWin.h"
wxBEGIN_EVENT_TABLE(ScrolledWin, wxScrolledWindow)
EVT_PAINT(ScrolledWin::OnPaint)
//EVT_LEFT_DOWN(ScrolledWin::OnMouseDown)
//EVT_LEFT_UP(ScrolledWin::OnMouseUp)
EVT_MOUSE_EVENTS(ScrolledWin::OnMouse)
wxEND_EVENT_TABLE()

ScrolledWin::ScrolledWin(wxFrame* frame):wxScrolledWindow(frame,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxHSCROLL||wxVSCROLL)//,m_frame(std::move(frame))
{


	SetBackgroundColour(wxColour (255, 183, 0));

	// m_link = new wxHyperlinkCtrl(this, wxID_ANY, wxT("?"), wxT("https://github.com/mrSchaffman"), wxPoint(285,0), wxSize(25,40));
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
wxBitmap ScrolledWin::CreateHeaderBitmap()
{

	wxColour penCol(250, 163, 7);
	wxColour headerColor(250, 163, 7);
	wxMemoryDC memDC;

	wxImage::AddHandler(new wxPNGHandler);
	wxImage im(wxT("InfoIcon.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpIcon(im);

	wxBitmap bitmap(GetParent()->GetSize().GetX(), 40);
	memDC.SelectObject(bitmap);

	wxRect headerRect(wxSize(GetParent()->GetSize().GetX(), 40));
	//memDC.SetBackground(wxBrush(col3, wxBRUSHSTYLE_SOLID));
	memDC.Clear();

	memDC.SetPen(headerColor);
	memDC.SetBrush(wxBrush(headerColor, wxBRUSHSTYLE_SOLID));
	memDC.DrawRectangle(headerRect);
	memDC.DrawText(wxT("Select the snip using the mode Button or click the \nNew button "),wxPoint(5,5));
	memDC.DrawBitmap(bmpIcon, wxPoint(285, 0));



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
	dc.DrawBitmap(CreateHeaderBitmap(),wxPoint(0,0));


}

void ScrolledWin::OnMouse(wxMouseEvent & event)
{
	wxPoint pos = event.GetPosition();
	if (event.LeftDown())
	{
		wxPoint p1(285, 5);
		wxPoint p2(310, 5);
		wxPoint p3(285, 40);
		wxPoint p4(310, 40);

		//if ((pos.x <= p2.x && pos.x >= p1.x && pos.y >= p1.y) && (pos.y <= p3.y && pos.y >= p1.y ))
		//{
		//	wxString msg;
		//	msg.Printf("This is a Snipping Tool \n Copyright(C) Barth. Feudong \t 2022"
		//	);

		//	wxMessageBox(msg, "About Snipping", wxOK | wxICON_INFORMATION, this);
		//}

	}
	if (event.LeftUp())
	{
		if (m_rubberBand)
		{
			//ReleaseMouse();

		}
	}
	if (event.Moving())
	{

	}

}
