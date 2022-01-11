#pragma once
#include"wx/wx.h"
#include <wx/dcclient.h>
#include <wx/mstream.h>
#include <wx/dcmemory.h>
#include <wx/rawbmp.h>

#include <wx/msw/wrapwin.h>
#include <uxtheme.h>
#include <Vssym32.h>

#include <map>
// Helper data types
struct BGInfo
{
	wxRect BgRect;
	wxRect SizingMargins;
	wxRect ContentMargins;
	int    TotalStates;
};

struct ButtonInfo
{
	wxRect ButtonRect;
	int    TotalStates;
};

enum class DPI
{
	dpi96 = 0,
	dpi120,
	dpi144,
	dpi196
};

enum class Button
{
	Close = 0,
	Min,
	Max,
	Restore,
	Help
};

// Helper functions
void MarginsToRect(const MARGINS& m, wxRect& r)
{
	r.SetLeft(m.cxLeftWidth);
	r.SetRight(m.cxRightWidth);
	r.SetTop(m.cyTopHeight);
	r.SetBottom(m.cyBottomHeight);
}

void RectTowxRect(const RECT & r, wxRect& r2)
{
	r2.SetLeft(r.left);
	r2.SetTop(r.top);
	r2.SetRight(r.right - 1);
	r2.SetBottom(r.bottom - 1);
}

wxBitmap ExtractAtlas(const wxBitmap& atlas, int total, int loc)
{

	int bgheight = atlas.GetHeight();
	int individualHeight = bgheight / total;
	int bgWidth = atlas.GetWidth();
	int atlasOffset = individualHeight * loc;
	wxRect bgRect = wxRect(wxPoint(0, atlasOffset),wxSize(bgWidth, individualHeight));

	return atlas.GetSubBitmap(bgRect);
}

void TileBitmap(const wxBitmap& bmp, wxDC& dc, const wxRect& r)
{
	dc.SetClippingRegion(r);

	for (int y = 0; y < r.GetHeight(); y += bmp.GetHeight())
	{
		for (int x = 0; x < r.GetWidth(); x += bmp.GetWidth())
		{
			dc.DrawBitmap(bmp, r.GetLeft() + x, r.GetTop() + y, true);
		}
	}

	dc.DestroyClippingRegion();
}

void TileTo(const wxBitmap& in, const wxRect& margins, wxBitmap& out, int w, int h)
{
	// Theoretically we're supposed to split the bitmap into 9 pieces based on
	// the sizing margins and leave the 8 outside pieces as unchanged as
	// possible and the fill the remainder with the center piece. However doing
	// that doesn't look actual control buttons.  So I'm going to just tile
	// the center bitmap to fill the whole space.
	int ml = margins.GetLeft();
	int mr = margins.GetRight();
	int mt = margins.GetTop();
	int mb = margins.GetBottom();

	int bw = in.GetWidth();
	int bh = in.GetHeight();

	wxBitmap center = in.GetSubBitmap(wxRect(wxPoint(ml, mt), wxSize(bw - ml - mr, bh - mb - mt)));

	// Create and initially transparent bitmap.
	unsigned char* data = reinterpret_cast<unsigned char*>(malloc(3 * w*h));
	unsigned char* alpha = reinterpret_cast<unsigned char*>(malloc(w*h));
	memset(alpha, 0, w*h);

	wxImage im(w, h, data, alpha);
	wxBitmap bmp(im);

	wxMemoryDC dc(bmp);
	TileBitmap(center, dc, wxRect(wxPoint(0, 0), wxSize(w, h)));
	dc.SelectObject(wxNullBitmap);

	out = bmp;
}





class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame() = default;

private:
	wxDECLARE_EVENT_TABLE();


	void OnPaintImagePanel(wxPaintEvent&);
	void OnListSelection(wxCommandEvent&);

	void BuildItemToDraw();
	void LoadThemeData();

	wxListBox* m_typeBox, *m_dpiBox, *m_stateBox;
	wxPanel* m_imagePanel;
	wxBitmap m_fullAtlas;
	wxBitmap m_itemToDraw;

	BGInfo m_closeInfo;
	BGInfo m_otherInfo;
	std::map<std::pair<DPI, Button>, ButtonInfo> m_themeMap;
};
