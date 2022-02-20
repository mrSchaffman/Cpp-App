#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	


wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title) :wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(820, 580))
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
		//topSizer->Fit(this);
		//topSizer->SetSizeHints(this);

		wxFlexGridSizer* flexGridSizer = new wxFlexGridSizer(1, 2, 0, 0);
		{
			// Make the 1st row growable
			flexGridSizer->AddGrowableCol(1);
			{
				topSizer->Add(flexGridSizer, 1, wxEXPAND);

				{
					m_tree = new FileTreeCtrl(this, ID_TREE, wxPoint(0, 10), wxSize(130, 580));// wxTR_NO_BUTTONS/*wxTR_HAS_BUTTONS*/ | wxTR_SINGLE | wxTR_NO_LINES | wxBORDER_NONE);

					//wxPanel * card = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(130, 50));
					//card->SetBackgroundColour(wxColour(217, 237, 146));

					flexGridSizer->Add(m_tree, 0);
					//flexGridSizer->Add(card, 0, wxGROW);

				}
				{
					wxTextCtrl * text = new wxTextCtrl(this, TXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxHSCROLL /*| wxTE_NO_VSCROLL*/ | wxTE_NOHIDESEL | wxBORDER_NONE);
					text->SetBackgroundColour(wxColour(216, 243, 220));
					text->SetValue(wxT("DYNAMIQUE DES FLUIDES INCOMPRESSIBLES\n\n")
						wxT("L’hydrodynamique est la branche de la mécanique des fluides qui étudie le mouvement des particules fluides \n")
						wxT("soumises à un système de forces.Bien souvent, on commence par l’étude les fluides fictifs dit « fluides parfaits\n")
						wxT("».Ils ont la particularité de ne pas avoir de viscosité et de ne pas développer de la turbulence.Les fluides réels\n")
						wxT("engendrent des forces de frottement dues à la turbulence et à la viscosité.La présence de ces forces induit une\n")
						wxT("perte de charge(énergie) qui est une transformation irréversible de l’énergie mécanique en énergie thermique.\n")
						wxT("Pour résoudre un problème d’écoulement d’un fluide réel, on fait appel à des résultats expérimentaux, en\n")
						wxT("particulier ceux de l’ingénieur et physicien britannique Osborne Reynolds.Ce chapitre aborde, dans un premier\n")
						wxT("temps, l’équation de continuité et surtout l’établissement de l’équation de Bernoulli.Dans un deuxième temps,\n")
						wxT("l’évaluation des pertes de charges ainsi que les méthodes de calcul des réseaux hydrauliques en charge sont\n")
						wxT("exposées.Elles sont indispensables pour le dimensionnement des diverses installations hydrauliques(de\n")
						wxT("pompage, de turbines, de machines hydrauliques et thermiques dans lesquelles est véhiculé un fluide réel…etc.)\n"));

					// i need consolas font regular
					text->SetFont(wxFont(11, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial"), wxFONTENCODING_SYSTEM));
					text->SetMargins(wxPoint(10, 20));
					flexGridSizer->Add(text, 1, wxGROW);

					m_menubar = new MenuBar(this, text);

				}

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
