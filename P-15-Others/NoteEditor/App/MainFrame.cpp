#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title) :wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(580, 620))
{

	wxImage img(wxT("Icon.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpIcon(img);

	wxIcon AppIcon;
	AppIcon.CopyFromBitmap(bmpIcon);
	SetIcon(AppIcon);

	SetTitle(m_filename + " - " + title);





#if wxUSE_STATUSBAR
	int m_widths[5] = { 250,120,30,80,80 };

	CreateStatusBar(5, wxSTB_DEFAULT_STYLE);
	SetStatusWidths(5, m_widths);

	SetStatusBarPane(0);
	wxString LinCol;
	LinCol.Printf("Ln %d, Col %d", m_ln, m_col);
	SetStatusText(LinCol, 1);
	SetStatusText(wxT("100%"), 2);
	SetStatusText(wxT("Win...(CRLF)"), 3);
	SetStatusText(wxT("UTF-8"), 4);
#endif // wxUSE_STATUSBAR


	// setting the Controls
	{
		wxBoxSizer*topSizer = new wxBoxSizer(wxVERTICAL);
		{
			SetSizer(topSizer);

			wxBoxSizer*box = new wxBoxSizer(wxHORIZONTAL);
			{
				topSizer->Add(box, 1);

				{
					 m_tree = new FileTreeCtrl(this, ID_TREE, wxPoint(0, 0), wxSize(100, 620), wxTR_HAS_BUTTONS | wxTR_SINGLE | wxTR_NO_LINES | wxBORDER_NONE);

					wxTextCtrl * text = new wxTextCtrl(this, TXT_CTRL, wxEmptyString, wxDefaultPosition, wxSize(470, 620), wxTE_MULTILINE| wxHSCROLL /*| wxTE_NO_VSCROLL*/ | wxTE_NOHIDESEL | wxBORDER_NONE);
					text->SetBackgroundColour(wxColour(216, 243, 220));
					box->Add(text, 1);
					box->Add(m_tree, 0);
				}

			}
		}

		m_menubar = new MenuBar(this, m_text_screen);
		SetMenuBar(m_menubar);


	}
}

