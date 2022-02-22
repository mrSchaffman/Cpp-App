#include "MainPanel.h"
wxBEGIN_EVENT_TABLE(MainPanel, wxPanel)

EVT_PAINT(MainPanel::OnPaint)

wxEND_EVENT_TABLE()

MainPanel::MainPanel(wxFrame * frame): wxPanel(frame,wxID_ANY,wxPoint(48,0	), wxSize(920, 680),wxBORDER_NONE)
{
	// setting the Controls
	wxBoxSizer*topSizer = new wxBoxSizer(wxVERTICAL);
	{
		SetSizer(topSizer);
		wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
		{
			// Make the 1st row growable
			{
				{
					wxPanel * row1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(920, 75));
					row1->SetBackgroundColour(wxColour(100, 100, 100));
					{
						
					}
					topSizer->Add(row1, 0, wxALL | wxEXPAND);


				}
				topSizer->Add(sizer, 1, wxALL | wxEXPAND);

				{

		

					wxPanel * colomn1 = new wxPanel(this, wxID_ANY, wxPoint(0, 150), wxSize(48, 480));
					colomn1->SetBackgroundColour(wxColour(80, 80, 80));

					wxBoxSizer*colomn2= new wxBoxSizer(wxVERTICAL);
					{
						m_tree = new FileTreeCtrl(this, ID_TREE, wxPoint(50, 0), wxSize(166, 590), wxTR_NO_BUTTONS/*wxTR_HAS_BUTTONS*/ | wxTR_SINGLE | wxTR_NO_LINES | wxBORDER_NONE);
						wxPanel * card2 = new wxPanel(this, wxID_ANY, wxPoint(50, 540), wxSize(166, 48));
						card2->SetBackgroundColour(wxColour(75, 75, 75));

						colomn2->Add(m_tree, 1, wxRIGHT|wxBOTTOM,1 );
						colomn2->Add(card2, 0, wxALL );
					}

					sizer->Add(colomn1, 0, wxALL | wxEXPAND);
					sizer->Add(colomn2, 0, wxALL|wxEXPAND);

				}
				{
					wxTextCtrl * text = new wxTextCtrl(this, TXT_CTRL, wxEmptyString, wxPoint(210, 0), wxSize(695, 640), wxTE_MULTILINE /*| wxTE_NO_VSCROLL*/ | wxTE_NOHIDESEL | wxBORDER_NONE);
					text->SetBackgroundColour(wxColour(90, 90, 90));
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
					text->SetForegroundColour(wxColour(255, 255, 255));
					text->SetMargins(wxPoint(10, 20));

					sizer->Add(text, 1, wxALL | wxEXPAND);


				}

			}
		}

	}


	SetBackgroundColour(wxColour(0, 0, 0));



}

void MainPanel::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	PrepareDC(dc);

	{
		//dc.DrawBitmap(CreateLogo(), wxPoint(48, GetClientSize().GetY() - 48));

		//wxImage img(wxT("undo.png"), wxBITMAP_TYPE_PNG);
		//wxBitmap bmp(img);

		//dc.DrawBitmap(bmp, wxPoint(0, 0));

		//wxImage img2(wxT("redo.png"), wxBITMAP_TYPE_PNG);
		//wxBitmap bmp2(img2);

		//dc.DrawBitmap(bmp2, wxPoint(0, 49));

		//wxImage img3(wxT("search.png"), wxBITMAP_TYPE_PNG);
		//wxBitmap bmp3(img3);

		//dc.DrawBitmap(bmp3, wxPoint(0, 98));

		//dc.SetPen(wxPen(wxColour(0, 0, 0), 0, wxPENSTYLE_TRANSPARENT));
		//dc.SetBrush(wxBrush(wxColour(255, 255, 255), wxBRUSHSTYLE_SOLID));
		//dc.DrawRectangle(wxPoint(49, 0), wxSize(165, 592));

	}

}

wxBitmap MainPanel::CreateLogo()
{
	wxMemoryDC memDC;

	wxImage img(wxT("NoteEditorLogo.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmp(img);

	memDC.SelectObject(bmp);
	//memDC.SetBackground(*wxWHITE_BRUSH);
	//memDC.Clear();

	memDC.DrawBitmap(bmp,wxPoint(0,0));
	memDC.SelectObject(wxNullBitmap);

	return bmp;
}

wxBitmap MainPanel::CreateSideButtons()
{
	wxMemoryDC memDC;

	wxImage img(wxT("undo.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmp(img);

	memDC.SelectObject(bmp);
	//memDC.SetBackground(*wxWHITE_BRUSH);
	//memDC.Clear();

	memDC.DrawBitmap(bmp, wxPoint(0, 0));
	memDC.SelectObject(wxNullBitmap);

	return bmp;
}
