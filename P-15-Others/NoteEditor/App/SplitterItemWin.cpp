#include "SplitterItemWin.h"

wxBEGIN_EVENT_TABLE(SplitterItemWin, wxSplitterWindow)



wxEND_EVENT_TABLE()

SplitterItemWin::SplitterItemWin(wxWindow * parent): wxSplitterWindow(parent, wxID_ANY,wxDefaultPosition,wxDefaultSize, wxSP_THIN_SASH| wxSP_LIVE_UPDATE)
{
	SetSashGravity(0.1);
	SetBackgroundColour(wxColour(35, 35, 35));
	SetMinimumPaneSize(100); // Smalest size the
	//Add(splitter2, 1, wxEXPAND, 0);

	//wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	//{
	//	SetSizer(topSizer);
		wxPanel * panel1 = new wxPanel(this, wxID_ANY,wxDefaultPosition, wxSize(100, 660));
		{
			wxBoxSizer* panel1Sizer = new wxBoxSizer(wxVERTICAL);
			{
				FileTreeCtrl *m_tree1 = new FileTreeCtrl(panel1, ID_TREE, wxDefaultPosition, wxSize(100, 650), wxTR_NO_BUTTONS | wxTR_SINGLE | wxTR_NO_LINES | wxBORDER_NONE);
				wxPanel * card2 = new wxPanel(panel1, wxID_ANY, wxDefaultPosition, wxSize(75, 40));
				card2->SetBackgroundColour(wxColour(70, 70, 70));

				panel1Sizer->Add(m_tree1, 1, wxEXPAND, 0);
				panel1Sizer->Add(card2, 0, wxEXPAND | wxTOP|wxRIGHT | wxBOTTOM, 1);

			}
			panel1->SetSizer(panel1Sizer);

		}
		wxPanel * panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(130, 660));
		{
			wxBoxSizer* panel2Sizer = new wxBoxSizer(wxVERTICAL);
			{
				FileTreeCtrl *m_tree2 = new FileTreeCtrl(panel2, ID_TREE, wxDefaultPosition, wxSize(130, 650), wxTR_NO_BUTTONS | wxTR_SINGLE | wxTR_NO_LINES | wxBORDER_NONE);
				wxPanel * card2 = new wxPanel(panel2, wxID_ANY, wxDefaultPosition, wxSize(75, 40));
				card2->SetBackgroundColour(wxColour(70, 70, 70));
				

				panel2Sizer->Add(m_tree2, 1, wxEXPAND, 0);
				panel2Sizer->Add(card2, 0, wxEXPAND | wxTOP|wxLEFT|wxBOTTOM , 1);

			}
			panel2->SetSizer(panel2Sizer);

		}

		SplitVertically(panel1, panel2);

	//}

}
