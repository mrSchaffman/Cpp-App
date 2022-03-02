#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	


wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title) :wxFrame(nullptr, wxID_ANY, title, wxPoint(200,100), wxSize(990, 700))
{

	wxImage img(wxT("Icon.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpIcon(img);

	wxIcon AppIcon;
	AppIcon.CopyFromBitmap(bmpIcon);
	SetIcon(AppIcon);

	SetTitle(m_filename + " - " + title);
	SetMinSize(wxSize(400, 500));



//#if wxUSE_STATUSBAR
//	int m_widths[5] = { 250,120,30,80,80 };
//
//	CreateStatusBar(5, wxSTB_DEFAULT_STYLE);
//	SetStatusWidths(5, m_widths);
//
//	SetStatusBarPane(0);
//	wxString LinCol;
//	LinCol.Printf("Ln %d, Col %d", m_ln, m_col);
//	SetStatusText(LinCol, 1);
//	SetStatusText(wxT("100%"), 2);
//	SetStatusText(wxT("Win...(CRLF)"), 3);
//	SetStatusText(wxT("UTF-8"), 4);
//#endif // wxUSE_STATUSBAR


	{
		wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);
		{
			wxBoxSizer *sizer2 = new wxBoxSizer(wxHORIZONTAL);
			{
				topSizer->Add(sizer2, 1, wxEXPAND, 0);
				wxPanel * card1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(40, -1));
				{
					card1->SetBackgroundColour(wxColour(100, 100, 100));
				}
				sizer2->Add(card1, 0, wxEXPAND, 0);

				wxSplitterWindow *splittermain = new wxSplitterWindow(this, wxID_ANY);
				{
					splittermain->SetMinimumPaneSize(100); // Smalest size the
					sizer2->Add(splittermain, 1, wxEXPAND, 0);


					SplitterItemWin* spliter2 = new SplitterItemWin(splittermain);

					wxPanel *pnl3 = new wxPanel(splittermain, wxID_ANY);
					{
						wxBoxSizer *txt2sizer = new wxBoxSizer(wxVERTICAL);
						{
							m_text = new TextCtrl(pnl3);
							txt2sizer->Add(m_text, 1, wxEXPAND, 0);

						}
						pnl3->SetSizer(txt2sizer);

					}
					splittermain->SplitVertically(spliter2, pnl3);

				}


			}
			wxPanel * card2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 30));
			card2->SetBackgroundColour(wxColour(100, 100, 100));

			topSizer->Add(card2, 0, wxEXPAND, 0);



		}

		SetSizer(topSizer);
		//topSizer->SetSizeHints(this);
	}

	m_menubar = new MenuBar(this, nullptr);
	SetMenuBar(m_menubar);

	{
		//wxBoxSizer *mainsizer = new wxBoxSizer(wxHORIZONTAL);
		//wxSplitterWindow *splittermain = new wxSplitterWindow(this, wxID_ANY);
		//mainsizer->Add(splittermain, 1, wxBOTTOM | wxLEFT | wxEXPAND, 5);

		//wxPanel *panelgroup1 = new wxPanel(splittermain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);
		//wxStaticBoxSizer *group1 = new wxStaticBoxSizer(wxVERTICAL, panelgroup1, _T("Group 1"));
		//group1->SetMinSize(550, -1);
		//wxTextCtrl *txt1 = new wxTextCtrl(panelgroup1,	wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize,	wxTE_MULTILINE);
		//group1->Add(txt1, 1, wxALL | wxEXPAND, 5);
		//panelgroup1->SetSizer(group1);

		//wxPanel *panelgroup2 = new wxPanel(splittermain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);
		//wxStaticBoxSizer *group2 = new wxStaticBoxSizer(wxVERTICAL, panelgroup2, _T("Group 2"));
		//group2->SetMinSize(550, -1);
		//wxTextCtrl *txt2 = new wxTextCtrl(panelgroup2, wxID_ANY,	wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
		//group2->Add(txt2, 1, wxALL | wxEXPAND, 5);
		//panelgroup2->SetSizer(group2);

		//splittermain->SetSashGravity(1.0);
		//splittermain->SplitHorizontally(panelgroup2, panelgroup1);

		//SetSizer(mainsizer);
		//mainsizer->SetSizeHints(this);
	}
}

