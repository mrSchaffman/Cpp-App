#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title): wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(580,620))
{
	wxImage iconImage(wxT("icon.png"), wxBITMAP_TYPE_ANY);
	wxBitmap iconBmp(iconImage);
	wxIcon appIcon;
	appIcon.CopyFromBitmap(iconBmp);

	SetIcon(appIcon);
	m_menuBar = new MenuBar(this);
	SetMenuBar(m_menuBar);

	// setting the Controls
	{
		wxBoxSizer*topSizer = new wxBoxSizer(wxVERTICAL);
		{
			wxBoxSizer*box = new wxBoxSizer(wxHORIZONTAL);
			{
				topSizer->Add(box, 1,  wxALL, 5);
				
				wxPanel* panel1 = new wxPanel(this);
				panel1->SetSizer(topSizer);

				FileTreeCtrl*m_treeCtrl = new FileTreeCtrl(panel1, ID_TREE, wxDefaultPosition, wxSize(180,620), wxTR_EDIT_LABELS | wxTR_NO_LINES);
				wxStaticBoxSizer* staticBox = new wxStaticBoxSizer(wxVERTICAL, panel1, wxT("Preview"));
				{
					wxTextCtrl * text = new wxTextCtrl(panel1, wxID_ANY, wxEmptyString,  wxDefaultPosition,wxSize(400,620),wxTE_MULTILINE);
					text->SetBackgroundColour(wxColour(206, 212, 218));
					staticBox->Add(text, 1, wxCENTER);
				}

				box->Add(m_treeCtrl,0, wxALL, 5);
				box->Add(staticBox,1, wxALL, 5);
			}

		}
	}
}
