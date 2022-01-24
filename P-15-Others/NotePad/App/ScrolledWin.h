#pragma once
#include"wx/wx.h"
#include"wx/overlay.h"
class ScrolledWin: public wxScrolledWindow
{
public:
	ScrolledWin(wxFrame*frame);
	virtual~ScrolledWin() = default;

	void OnMouseDown(wxMouseEvent& event);
	void OnMouseUp(wxMouseEvent& event);
	void OnMouseMove(wxMouseEvent& event);
	void OnPaint(wxPaintEvent &event);

private:
	wxFrame*m_frame = nullptr;

	int m_pixelsPerUnixX = 10;
	int m_pixelsPerUnixY = 10;
	int m_noUnitsX = 100;
	int m_noUnitsY = 100;

	bool         m_useBuffer;
	bool         m_showBBox;
	bool         m_rubberBand;
	wxPoint      m_anchorpoint;
	wxPoint      m_currentpoint;
	wxCoord      m_sizeX;
	wxCoord      m_sizeY;
	wxOverlay    m_overlay;



	int m_ln = 0;
	int m_col = 0;

	wxDECLARE_EVENT_TABLE();

};

