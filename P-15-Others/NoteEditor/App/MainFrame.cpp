#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	


wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title) :wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(720, 580))
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
	
		wxBoxSizer*topSizer = new wxBoxSizer(wxVERTICAL);
		{
			SetSizer(topSizer);
			//SetSizeHints(wxSize(720, 580), wxSize(720, 580));

			wxBoxSizer*box = new wxBoxSizer(wxHORIZONTAL);
			{
				topSizer->Add(box, 1, wxALL);

				wxBoxSizer*col1 = new wxBoxSizer(wxVERTICAL);
				{
					box->Add(col1, 1, wxALL);
					m_tree = new FileTreeCtrl(this, ID_TREE, wxDefaultPosition, wxSize(130, 450));// wxTR_NO_BUTTONS/*wxTR_HAS_BUTTONS*/ | wxTR_SINGLE | wxTR_NO_LINES | wxBORDER_NONE);

						wxPanel * card = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(130, 50));
						card->SetBackgroundColour(wxColour(217, 237, 146));
				
					col1->Add(m_tree, 1, wxALL);
					col1->Add(card, 0, wxALL);

				}
				wxBoxSizer*col2 = new wxBoxSizer(wxVERTICAL);
				{
					box->Add(col2, 1, wxALL);


					wxTextCtrl * text = new wxTextCtrl(this, TXT_CTRL, wxEmptyString, wxDefaultPosition, wxSize(580, 580), wxTE_MULTILINE | wxHSCROLL /*| wxTE_NO_VSCROLL*/ | wxTE_NOHIDESEL | wxBORDER_NONE);
					text->SetBackgroundColour(wxColour(216, 243, 220));
					col2->Add(text, 1, wxALL);

					m_menubar = new MenuBar(this, text);

				}

			}
			
		}

		SetMenuBar(m_menubar);
		//SetBackgroundColour(wxColour(217, 237, 146));

	
}

void MainFrame::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	PrepareDC(dc);

	dc.SetPen(*wxRED_PEN);
	dc.SetBrush(*wxRED_BRUSH);
	dc.DrawRectangle(wxPoint(0, GetClientSize().GetY() - 105), wxSize(50, 50));
}
