#include "PageSettingDialogue.h"

PageSettingDialogue::PageSettingDialogue(wxFrame * parent):wxDialog(parent,ID_PAGE_SETTING,wxT("Page Settings"),wxDefaultPosition,wxSize(550,360))
{
	m_parent = parent;
	wxBoxSizer* m_topSizer = new wxBoxSizer(wxHORIZONTAL);
	{
		wxBoxSizer* m_col1 = new wxBoxSizer(wxVERTICAL);
		{
			wxStaticBoxSizer* m_paper = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Paper"));
			{
				wxBoxSizer*sizeRow = new wxBoxSizer(wxHORIZONTAL);
				{
					wxStaticText* Sizetxt = new wxStaticText(this, wxID_ANY, wxT("Size:"), wxDefaultPosition, wxSize(75, 25));

					wxArrayString formats;
					formats.Add(wxT("A1"));
					formats.Add(wxT("A2"));
					formats.Add(wxT("A3"));
					formats.Add(wxT("A4"));
					formats.Add(wxT("A5"));
					wxComboBox* sizesCB = new wxComboBox(this, wxID_ANY, wxT("A4"), wxDefaultPosition, wxSize(251, 25), formats, wxCB_DROPDOWN | wxCB_READONLY);

					sizeRow->Add(Sizetxt, 0);
					sizeRow->Add(sizesCB, 0);
				}
				m_paper->Add(sizeRow, 0,wxALL,5);

				wxBoxSizer*sourceRow = new wxBoxSizer(wxHORIZONTAL);
				{
					{
						wxStaticText* Sourcetxt = new wxStaticText(this, wxID_ANY, wxT("Source:"), wxDefaultPosition, wxSize(75, 25));

						wxArrayString sources;
						sources.Add(wxT("Auto bin"));
						wxComboBox* sourceCB = new wxComboBox(this, wxID_ANY, wxT("Auto bin"), wxDefaultPosition, wxSize(251, 25), sources, wxCB_DROPDOWN | wxCB_READONLY);

						sourceRow->Add(Sourcetxt, 0);
						sourceRow->Add(sourceCB, 0);

					}


				}
				m_paper->Add(sourceRow, 0, wxALL, 5);

			}

			wxBoxSizer* m_row2 = new wxBoxSizer(wxHORIZONTAL);
			{
				wxStaticBoxSizer* m_orientation = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Orientation"));
				{
					
					
						wxRadioButton* portait = new wxRadioButton(this, ID_PORTRAIT, wxT("Portrait"), wxDefaultPosition,wxDefaultSize, wxRB_GROUP);
						portait->SetValue(true);
						wxRadioButton* Landscape = new wxRadioButton(this,ID_LANDSCAPE, wxT("Landscape"));
						m_orientation->Add(portait, 0,  wxALL, 5);
						m_orientation->AddSpacer(10);
						m_orientation->Add(Landscape, 0,  wxALL, 5);
					

				}
				m_row2->Add(m_orientation, 0, wxALL, 5);

				wxStaticBoxSizer* m_margings = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Margins(millimeters)"));
				{
					wxBoxSizer*margRow1 = new wxBoxSizer(wxHORIZONTAL);
					{
						wxStaticText* leftTxt = new wxStaticText(this, wxID_ANY, wxT("Left:"), wxDefaultPosition, wxSize(40, 20));
						wxTextCtrl* left = new wxTextCtrl(this, ID_MARGIN_LEFT, wxT("20"), wxDefaultPosition, wxSize(40, 20));
						wxStaticText* rightTxt = new wxStaticText(this, wxID_ANY, wxT("Right:"), wxDefaultPosition, wxSize(40, 20));
						wxTextCtrl* right = new wxTextCtrl(this, ID_MARGIN_RIGHT, wxT("20"), wxDefaultPosition, wxSize(40, 20));
						
						margRow1->Add(leftTxt, 1);
						margRow1->Add(left, 1);
						margRow1->Add(rightTxt, 1,wxLEFT,15 );
						margRow1->Add(right, 1, wxLEFT, 15);
					}
					m_margings->Add(margRow1, 0, wxALL, 5);

					wxBoxSizer*margRow2 = new wxBoxSizer(wxHORIZONTAL);
					{						
						wxStaticText* topTxt = new wxStaticText(this, wxID_ANY, wxT("Top:"), wxDefaultPosition, wxSize(40, 20));
						wxTextCtrl* top = new wxTextCtrl(this, ID_MARGIN_TOP, wxT("25"), wxDefaultPosition, wxSize(40, 20));
						wxStaticText* bottomTxt = new wxStaticText(this, wxID_ANY, wxT("Bottom:"), wxDefaultPosition, wxSize(40, 20));
						wxTextCtrl* bottom = new wxTextCtrl(this, ID_MARGIN_BOTTOM, wxT("25"), wxDefaultPosition, wxSize(40, 20));

						margRow2->Add(topTxt, 1);
						margRow2->Add(top, 1);
						margRow2->Add(bottomTxt, 1, wxLEFT, 15);
						margRow2->Add(bottom, 1, wxLEFT, 15);
					}
					m_margings->Add(margRow2, 0, wxALL, 5);

				}
				m_row2->Add(m_margings, 0, wxALL, 5);


			}

			wxStaticBoxSizer* style = new wxStaticBoxSizer(wxVERTICAL, this, wxT(""));
			{
				wxBoxSizer*m_row31 = new wxBoxSizer(wxHORIZONTAL);
				{
					wxStaticText*header = new wxStaticText(this, wxID_ANY, wxT("Header:"), wxDefaultPosition, wxSize(79, 25));
					m_header = new wxTextCtrl(this, ID_HEADER, wxEmptyString, wxDefaultPosition, wxSize(250, 25));
					m_row31->Add(header, 0);
					m_row31->Add(m_header, 1);

				}
				wxBoxSizer*m_row32 = new wxBoxSizer(wxHORIZONTAL);
				{
					wxStaticText*Footer = new wxStaticText(this, wxID_ANY, wxT("Footer:"), wxDefaultPosition, wxSize(79, 25));
					m_footer = new wxTextCtrl(this, ID_FOOTER,wxEmptyString, wxDefaultPosition, wxSize(250, 25));
					m_row32->Add(Footer, 0);
					m_row32->Add(m_footer, 1);


				}
				style->Add(m_row31, 0, wxALL, 5);
				style->Add(m_row32, 0, wxALL, 5);
				style->Add(new wxHyperlinkCtrl(this,ID_MY_INPUT_VALUE,wxT("see more: @Barth.Feudong"),wxT("https://github.com/mrSchaffman"),wxDefaultPosition,wxDefaultSize,wxTE_AUTO_URL|wxTE_READONLY), 0, wxLEFT, 84);
			}

			m_col1->Add(m_paper, 1,wxLEFT,5);
			m_col1->Add(m_row2, 1);
			m_col1->Add(style, 1, wxLEFT, 5);
		}
		wxBoxSizer* m_col2 = new wxBoxSizer(wxVERTICAL);
		{
			wxStaticBoxSizer* m_preview = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Preview"));
			{
				m_preview_win = new PreviewWin(this);
				m_preview->Add(m_preview_win, 1);
			}
			wxBoxSizer* m_row42 = new wxBoxSizer(wxHORIZONTAL);
			{
				wxButton*btOK = new wxButton(this, wxID_OK);// , wxT("IMAGE"), wxDefaultPosition, wxSize(152, 252));
				wxButton*btCancel = new wxButton(this, wxID_CANCEL);// , wxT("IMAGE"), wxDefaultPosition, wxSize(152, 252));
				m_row42->Add(btOK, 1, wxALL, 4);
				m_row42->Add(btCancel, 1, wxALL, 4);
			}

			m_col2->Add(m_preview, 0);
			m_col2->AddSpacer(10);
			m_col2->Add(m_row42, 0);

		}

		m_topSizer->Add(m_col1, 1, wxALL, 5);
		m_topSizer->Add(m_col2, 0, wxALL, 5);
	}


	//SetSizer(m_topSizer);
	SetSizerAndFit(m_topSizer);

}
