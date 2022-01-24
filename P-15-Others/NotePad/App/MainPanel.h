#pragma once
#include"wx/wx.h"
#include"MainFrame.h"

enum {

	ID_PARENT = 10,
};

// container windows for the Top level window (MainFrame)
// go and desing the  MainFrame
class MainPanel : wxPanel
{
public: 

	MainPanel(wxFrame* parent);
	virtual~MainPanel() = default;

	//void OnPaint(wxPaintEvent &event);
	//void OnMouseMove(wxMouseEvent &event);
	//void OnMouseDown(wxMouseEvent &event);
	//void OnMouseUp(wxMouseEvent &event);

private:

	//MainFrame *m_parent;// = nullptr;





	int          m_show;
	wxBitmap     m_smile_bmp;
	wxIcon       m_std_icon;
	bool         m_clip;
	bool         m_rubberBand;
	wxPoint      m_anchorpoint;
	wxPoint      m_currentpoint;
	bool         m_useBuffer;
	bool         m_showBBox;
	wxCoord      m_sizeX;
	wxCoord      m_sizeY;

};

