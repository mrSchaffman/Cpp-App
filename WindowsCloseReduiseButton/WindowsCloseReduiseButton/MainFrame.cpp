#include "MainFrame.h"

MainFrame::MainFrame() :wxFrame(NULL, wxID_ANY, "Windows Control Button Demo", wxDefaultPosition,
	wxSize(400, 300))
{
	// Start all the image handlers.  Only the PNG handler is actually needed.
	::wxInitAllImageHandlers();

	// Build the UI.
	wxPanel* bg = new wxPanel(this, wxID_ANY);
	wxStaticText* typeText = new wxStaticText(bg, wxID_ANY, "Type:");
	m_typeBox = new wxListBox(bg, wxID_ANY);
	wxStaticText* dpiText = new wxStaticText(bg, wxID_ANY, "dpi:");
	m_dpiBox = new wxListBox(bg, wxID_ANY);
	wxStaticText* stateText = new wxStaticText(bg, wxID_ANY, "State:");
	m_stateBox = new wxListBox(bg, wxID_ANY);
	m_imagePanel = new wxPanel(bg, wxID_ANY);

	wxBoxSizer* mainSzr = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* boxSzr = new wxBoxSizer(wxHORIZONTAL);
	boxSzr->Add(typeText, wxSizerFlags().Border(wxALL));
	boxSzr->Add(m_typeBox, wxSizerFlags().Border(wxTOP | wxRIGHT | wxBOTTOM));
	boxSzr->Add(dpiText, wxSizerFlags().Border(wxALL));
	boxSzr->Add(m_dpiBox, wxSizerFlags().Border(wxTOP | wxRIGHT | wxBOTTOM));
	boxSzr->Add(stateText, wxSizerFlags().Border(wxALL));
	boxSzr->Add(m_stateBox, wxSizerFlags().Border(wxTOP | wxRIGHT | wxBOTTOM));

	mainSzr->Add(boxSzr, wxSizerFlags());
	mainSzr->Add(m_imagePanel, wxSizerFlags(1).Expand().Border(wxLEFT | wxRIGHT | wxBOTTOM));

	bg->SetSizer(mainSzr);

	// Set the needed event handlers for the controls.
	m_imagePanel->Bind(wxEVT_PAINT, &MainFrame::OnPaintImagePanel, this);
	m_typeBox->Bind(wxEVT_LISTBOX, &MainFrame::OnListSelection, this);
	m_dpiBox->Bind(wxEVT_LISTBOX, &MainFrame::OnListSelection, this);
	m_stateBox->Bind(wxEVT_LISTBOX, &MainFrame::OnListSelection, this);

	// Concigure the controls.
	m_typeBox->Append("Close");
	m_typeBox->Append("Help");
	m_typeBox->Append("Max");
	m_typeBox->Append("Min");
	m_typeBox->Append("Restore");

	m_dpiBox->Append("96");
	m_dpiBox->Append("120");
	m_dpiBox->Append("144");
	m_dpiBox->Append("192");

	m_stateBox->Append("Normal");
	m_stateBox->Append("Hot");
	m_stateBox->Append("Pressed");
	m_stateBox->Append("Inactive");

	m_typeBox->Select(0);
	m_dpiBox->Select(0);
	m_stateBox->Select(0);

	// Load the theme data and finish setting up.
	LoadThemeData();
	BuildItemToDraw();
}
void MainFrame::LoadThemeData()
{
	HINSTANCE handle = LoadLibraryEx(L"C:\\Windows\\Resources\\Themes\\aero\\aero.msstyles", 0, LOAD_LIBRARY_AS_DATAFILE); // to edit

	if (handle == NULL)
	{
		return;
	}

	HTHEME theme = OpenThemeData(reinterpret_cast<HWND>(this->GetHandle()), L"DWMWindow");

	VOID* PBuf = NULL;
	DWORD BufSize = 0;

	GetThemeStream(theme, 0, 0, TMT_DISKSTREAM, &PBuf, &BufSize, handle);

	wxMemoryInputStream mis(PBuf, static_cast<int>(BufSize));
	wxImage im(mis, wxBITMAP_TYPE_PNG);

	if (!im.IsOk())
	{
		return;
	}

	wxBitmap b2(im);
	m_fullAtlas = wxBitmap(im);;

	MARGINS m;
	RECT r;

	int BUTTONACTIVECAPTION = 3;
	int BUTTONACTIVECLOSE = 7;
	int BUTTONCLOSEGLYPH96 = 11;
	int BUTTONRESTOREGLYPH192 = 30;

	// Store some of the theme info for the parts BUTTONACTIVECAPTION
	// and BUTTONACTIVECLOSE.
	GetThemeRect(theme, BUTTONACTIVECAPTION, 0, TMT_ATLASRECT, &r);
	RectTowxRect(r, m_otherInfo.BgRect);
	GetThemeMargins(theme, NULL, BUTTONACTIVECAPTION, 0, TMT_CONTENTMARGINS, NULL, &m);
	MarginsToRect(m, m_otherInfo.ContentMargins);
	GetThemeMargins(theme, NULL, BUTTONACTIVECAPTION, 0, TMT_SIZINGMARGINS, NULL, &m);
	MarginsToRect(m, m_otherInfo.SizingMargins);
	GetThemeInt(theme, BUTTONACTIVECAPTION, 0, TMT_IMAGECOUNT, &(m_otherInfo.TotalStates));

	GetThemeRect(theme, BUTTONACTIVECLOSE, 0, TMT_ATLASRECT, &r);
	RectTowxRect(r, m_closeInfo.BgRect);
	GetThemeMargins(theme, NULL, BUTTONACTIVECLOSE, 0, TMT_CONTENTMARGINS, NULL, &m);
	MarginsToRect(m, m_closeInfo.ContentMargins);
	GetThemeMargins(theme, NULL, BUTTONACTIVECLOSE, 0, TMT_SIZINGMARGINS, NULL, &m);
	MarginsToRect(m, m_closeInfo.SizingMargins);
	GetThemeInt(theme, BUTTONACTIVECLOSE, 0, TMT_IMAGECOUNT, &(m_closeInfo.TotalStates));

	// Since the part numbers for BUTTONCLOSEGLYPH96..BUTTONRESTOREGLYPH192
	// are all sequential and the dpis all run from 96 to 192 in the same
	// order, we can use a for loop to store
	for (int i = BUTTONCLOSEGLYPH96; i <= BUTTONRESTOREGLYPH192; ++i)
	{
		int j = i - BUTTONCLOSEGLYPH96;

		Button b = static_cast<Button>(j / 4);
		DPI dpi = static_cast<DPI>(j % 4);
		std::pair<DPI, Button> item;
		ButtonInfo info;

		item = std::make_pair(dpi, b);

		GetThemeRect(theme, i, 0, TMT_ATLASRECT, &r);
		RectTowxRect(r, info.ButtonRect);
		GetThemeInt(theme, i, 0, TMT_IMAGECOUNT, &(info.TotalStates));
		m_themeMap.insert(std::make_pair(item, info));
	}

	CloseThemeData(theme);
	FreeLibrary(handle);
}

void MainFrame::OnPaintImagePanel(wxPaintEvent&)
{
	wxPaintDC dc(m_imagePanel);
	dc.Clear();

	if (m_itemToDraw.IsOk())
	{
		dc.DrawBitmap(m_itemToDraw, 0, 0, true);
	}
}

void MainFrame::OnListSelection(wxCommandEvent&)
{
	BuildItemToDraw();
}

void MainFrame::BuildItemToDraw()
{
	BGInfo bginfo;
	Button b = static_cast<Button>(m_typeBox->GetSelection());
	DPI dpi = static_cast<DPI>(m_dpiBox->GetSelection());
	int state = m_stateBox->GetSelection();

	if (b == Button::Close)
	{
		bginfo = m_closeInfo;
	}
	else
	{
		bginfo = m_otherInfo;
	}

	wxBitmap bgAtlas = m_fullAtlas.GetSubBitmap(bginfo.BgRect);
	int totalbgs = bginfo.TotalStates;
	wxBitmap bg = ExtractAtlas(bgAtlas, totalbgs, state);
	std::pair<DPI, Button> item = std::make_pair(dpi, b);

	auto it = m_themeMap.find(item);

	if (it != m_themeMap.end())
	{
		ButtonInfo info = it->second;

		wxBitmap itemAtlas = m_fullAtlas.GetSubBitmap(info.ButtonRect);

		wxBitmap item = ExtractAtlas(itemAtlas, info.TotalStates, state);

		wxRect contentmargins = bginfo.ContentMargins;
		wxRect Sizingmargins = bginfo.SizingMargins;
		int width = item.GetWidth() + contentmargins.GetLeft() + contentmargins.GetRight();
		int height = item.GetHeight() + contentmargins.GetTop() + contentmargins.GetBottom();

		if (bg.GetWidth() > width)
		{
			width = bg.GetWidth();
		}

		if (bg.GetHeight() > height)
		{
			height = bg.GetHeight();
		}

		wxBitmap bmp(width, height, 32);
		TileTo(bg, Sizingmargins, bmp, width, height);

		wxMemoryDC dc(bmp);
		int leftOffset = (width - item.GetWidth()) / 2;
		int topOffset = (height - item.GetHeight()) / 2;

		dc.DrawBitmap(item, leftOffset, topOffset, true);
		dc.SelectObject(wxNullBitmap);

		m_itemToDraw = bmp;
	}

	m_imagePanel->Refresh();
	m_imagePanel->Update();
}
