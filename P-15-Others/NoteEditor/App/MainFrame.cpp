#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title):wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(580, 620))
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
	SetStatusText(LinCol,1);
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

				m_fileTree = new FileTreeCtrl(this, ID_TREE, wxDefaultPosition, wxSize(150, 620), wxTR_EDIT_LABELS | wxTR_NO_LINES);
				m_text_screen = new  TextCtrl(this);


				box->Add(m_fileTree, 0);
				box->AddSpacer(5);
				box->Add(m_text_screen, 1);
			}

		}
	}

	m_menubar = new MenuBar(this, m_text_screen);
	SetMenuBar(m_menubar);


}

