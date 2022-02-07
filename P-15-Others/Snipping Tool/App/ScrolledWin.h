#pragma once
#include"wx/wx.h"
#include"wx/overlay.h"
#include "wx/dcbuffer.h"
#include"wx/effects.h"
#include"wx/hyperlink.h"


class ScrolledWin: public wxScrolledWindow
{
public:
	ScrolledWin(wxFrame*frame);
	virtual~ScrolledWin() 
	{ 
		if (m_frame!=nullptr)
		{
			delete m_frame;
		}
		//this->Destroy(); 
	}

	//Drawing on Bitmaps with wxMemoryDC
	wxBitmap CreateRedOutlineBitmap();

	//Accessing the Screen with wxScreenDC
	wxBitmap GetScreenShot();

	void OnPaint(wxPaintEvent&event);
	void OnMouse(wxMouseEvent&event);

private:
	wxFrame*m_frame = nullptr;
	wxHyperlinkCtrl* m_link = nullptr;

	bool         m_useBuffer;
	bool         m_showBBox;
	bool         m_rubberBand;
	wxPoint      m_anchorpoint;
	wxPoint      m_currentpoint;
	wxCoord      m_sizeX;
	wxCoord      m_sizeY;
	wxOverlay    m_overlay;




	wxDECLARE_EVENT_TABLE();

};

