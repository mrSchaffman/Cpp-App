#include "PageSettingDialogue.h"

wxBEGIN_EVENT_TABLE(PageSettingDialogue, wxPanel)
	EVT_COMBOBOX(ID_SIZE_CBOX,PageSettingDialogue::OnFormatUpdate)
	EVT_UPDATE_UI(ID_SOURCE_CBOX,PageSettingDialogue::OnSourceUpdate)
	EVT_UPDATE_UI(ID_MARGIN_LEFT,PageSettingDialogue::OnMarginLeftUpdate)
	EVT_UPDATE_UI(ID_MARGIN_TOP,PageSettingDialogue::OnMarginTopUpdate)
	EVT_UPDATE_UI(ID_MARGIN_RIGHT,PageSettingDialogue::OnMarginRightUpdate)
	EVT_UPDATE_UI(ID_MARGIN_BOTTOM,PageSettingDialogue::OnMarginBottomUpdate)
	EVT_RADIOBOX(ID_ORIENTATION,PageSettingDialogue::OnOrientationUpdate)

	EVT_BUTTON(wxID_EXIT, PageSettingDialogue::OnQuit)
	EVT_BUTTON(wxID_CANCEL, PageSettingDialogue::OnCancel)
	EVT_BUTTON(wxID_OK, PageSettingDialogue::OnOK)
	EVT_BUTTON(wxID_RESET, PageSettingDialogue::OnResetClick)

wxEND_EVENT_TABLE()

PageSettingDialogue::PageSettingDialogue(wxFrame * parent, wxWindowID id ,
	const wxString& caption ,
	const wxPoint& pos ,
	const wxSize& size ):wxDialog(parent,ID_PAGE_SETTING, caption, pos, size),m_parent(parent)
{

	Init();


	CreateControls();
}

void PageSettingDialogue::CreateControls()
{
	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	{
		SetSizer(topSizer);

		wxBoxSizer* boxSizer = new wxBoxSizer(wxHORIZONTAL); 
		{
			topSizer->Add(boxSizer, wxALIGN_CENTER | wxALL, 10);

			wxBoxSizer* m_col1 = new wxBoxSizer(wxVERTICAL);
			{
				wxStaticBoxSizer* m_paper = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Paper"));
				{
					wxFlexGridSizer*paperSizer = new wxFlexGridSizer(2,2,5,5);
					{
						wxStaticText* Sizetxt = new wxStaticText(this, wxID_ANY, wxT("Size:"), wxDefaultPosition, wxSize(75, -1));
						wxComboBox* sizesCB = new wxComboBox(this, ID_SIZE_CBOX, wxT("A4"), wxDefaultPosition, wxSize(230, -1), m_sizes, wxCB_DROPDOWN | wxCB_READONLY);	 

						paperSizer->Add(Sizetxt, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);
						paperSizer->Add(sizesCB, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

						wxStaticText* Sourcetxt = new wxStaticText(this, wxID_ANY, wxT("Source:"), wxDefaultPosition, wxSize(75, -1));
						wxComboBox* sourceCB = new wxComboBox(this, ID_SOURCE_CBOX, wxT("Auto bin"), wxDefaultPosition, wxSize(230, -1), m_sources, wxCB_DROPDOWN | wxCB_READONLY);

						paperSizer->Add(Sourcetxt, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);
						paperSizer->Add(sourceCB, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);


						m_paper->Add(paperSizer, 0, wxALL, 5);
					}

				}

				m_col1->Add(5, 5, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

				
					wxFlexGridSizer* m_row2 = new wxFlexGridSizer(1, 2, 5, 5);
					{

						wxStaticBoxSizer* m_margings = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Margins(millimeters)"));
						{
							wxGridSizer*grid = new wxGridSizer(2, 4, 5, 5);
							{
								wxStaticText* leftTxt = new wxStaticText(this, wxID_STATIC, wxT("Left:"), wxDefaultPosition, wxSize(42, 20));
								wxTextCtrl* left = new wxTextCtrl(this, ID_MARGIN_LEFT, wxT("20"), wxDefaultPosition, wxSize(42, 20));
								wxStaticText* rightTxt = new wxStaticText(this, wxID_STATIC, wxT("Right:"), wxDefaultPosition, wxSize(42, 20));
								wxTextCtrl* right = new wxTextCtrl(this, ID_MARGIN_RIGHT, wxT("20"), wxDefaultPosition, wxSize(42, 20));
								wxStaticText* topTxt = new wxStaticText(this, wxID_STATIC, wxT("Top:"), wxDefaultPosition, wxSize(42, 20));
								wxTextCtrl* top = new wxTextCtrl(this, ID_MARGIN_TOP, wxT("20"), wxDefaultPosition, wxSize(42, 20));
								wxStaticText* bottomTxt = new wxStaticText(this, wxID_STATIC, wxT("Bottom:"), wxDefaultPosition, wxSize(42, 20));
								wxTextCtrl* bottom = new wxTextCtrl(this, ID_MARGIN_BOTTOM, wxT("20"), wxDefaultPosition, wxSize(42, 20));

								grid->Add(leftTxt, 1, wxALL, 5);
								grid->Add(left, 1, wxALL, 5);
								grid->Add(rightTxt, 1, wxALL, 5);
								grid->Add(right, 1, wxALL, 5);
								grid->Add(topTxt, 1, wxALL, 5);
								grid->Add(top, 1, wxALL, 5);
								grid->Add(bottomTxt, 1, wxALL, 5);
								grid->Add(bottom, 1, wxALL, 5);

								m_margings->Add(grid, 1, wxALIGN_CENTER | wxALL, 5);

							}
						}
						m_row2->Add(m_margings, 1, wxALIGN_LEFT | wxALL, 5);

						wxRadioBox *m_orientation = new wxRadioBox(this, ID_ORIENTATION, wxT("Orientation"), wxDefaultPosition, wxSize(90, 95), m_orientations, 1, wxRA_SPECIFY_COLS);
						m_row2->Add(m_orientation, 1, wxALL, 5);



					}


				wxStaticBoxSizer* style2 = new wxStaticBoxSizer(wxVERTICAL, this, wxT(""));
				{
					wxFlexGridSizer*m_row31 = new wxFlexGridSizer(2,2,5,5);
					{
						wxStaticText*headerTxt = new wxStaticText(this, wxID_STATIC, wxT("Header:"), wxDefaultPosition, wxSize(79, -1));
						wxTextCtrl* header = new wxTextCtrl(this, ID_HEADER, wxEmptyString, wxDefaultPosition, wxSize(230, -1));
						
						m_row31->Add(headerTxt, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);
						m_row31->Add(header, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

						wxStaticText*footerTxt = new wxStaticText(this, wxID_STATIC, wxT("Footer:"), wxDefaultPosition, wxSize(79, -1));
						wxTextCtrl* footer = new wxTextCtrl(this, ID_FOOTER, wxEmptyString, wxDefaultPosition, wxSize(230, -1));
						
						m_row31->Add(footerTxt, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);
						m_row31->Add(footer, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

					}
					style2->Add(m_row31, 0, wxALL, 5);

				}

				m_col1->Add(m_paper, 0);
				m_col1->Add(m_row2, 0);
				m_col1->Add(style2, 0);
				m_col1->Add(new wxHyperlinkCtrl(this, ID_MY_INPUT_VALUE, 
					wxT("see more: @Barth.Feudong"), 
					wxT("https://github.com/mrSchaffman"), 
					wxDefaultPosition, wxDefaultSize, 
					wxTE_AUTO_URL | wxTE_READONLY), 0, wxALIGN_RIGHT | wxALL, 5);
			}
			wxBoxSizer* m_col2 = new wxBoxSizer(wxVERTICAL);
			{
				wxStaticBoxSizer* m_preview = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Preview"));
				{

					Card* m_preview_win = new Card(this, ID_CARD, m_formats[0]);// m_current_format);
					m_preview->Add(m_preview_win, 1, wxCENTER);
				}
				wxBoxSizer* m_row42 = new wxBoxSizer(wxHORIZONTAL);
				{
					wxButton*btReset = new wxButton(this, wxID_RESET, wxT("Reset"),wxDefaultPosition, wxSize(50, 30));
					wxButton*btOK = new wxButton(this, wxID_OK, wxT("OK"), wxDefaultPosition, wxSize(50, 30));
					wxButton*btCancel = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxSize(50, 30));
					m_row42->Add(btReset, 1, wxALIGN_CENTER | wxALL, 5);
					m_row42->Add(btOK, 1, wxALIGN_CENTER | wxALL, 5);
					m_row42->Add(btCancel, 1, wxALIGN_CENTER | wxALL, 5);
				}

				m_col2->Add(m_preview, 0);
				m_col2->AddSpacer(10);
				m_col2->Add(m_row42, 0);

			}

			boxSizer->Add(m_col1, 0, wxALL, 5);
			boxSizer->Add(m_col2, 0, wxALL, 5);


		}



	}


}
bool PageSettingDialogue::TransferDataToWindow()	// setting the Dialog UI data using the Backend's data
{
	{
		{
			wxComboBox* sizesCB = (wxComboBox*)FindWindow(ID_SIZE_CBOX);
			wxComboBox* sourceCB = (wxComboBox*)FindWindow(ID_SOURCE_CBOX);

			sizesCB->SetSelection(m_size);
			sourceCB->SetSelection(m_source);
		}

		{
			wxRadioBox* orientationCtrl = (wxRadioBox*)FindWindow(ID_ORIENTATION);
			orientationCtrl->SetSelection(m_orientations.Index(wxT("Portrait")));
		}

		// the Margins
		{
			wxString left = wxString::Format(wxT("%i"), m_left);
			wxString right = wxString::Format(wxT("%i"), m_right);
			wxString top = wxString::Format(wxT("%i"), m_top);
			wxString buttom = wxString::Format(wxT("%i"), m_bottom);

			wxTextCtrl* leftCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_LEFT);
			leftCrtl->SetValidator(wxTextValidator(wxFILTER_DIGITS, &left));

			wxTextCtrl* rightCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_RIGHT);
			rightCrtl->SetValidator(wxTextValidator(wxFILTER_DIGITS, &right));

			wxTextCtrl* topCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_TOP);
			topCrtl->SetValidator(wxTextValidator(wxFILTER_DIGITS, &top));

			wxTextCtrl* bottomCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_BOTTOM);
			bottomCrtl->SetValidator(wxTextValidator(wxFILTER_DIGITS, &buttom));

			{
				leftCrtl->SetValue(left);
				rightCrtl->SetValue(right);
				topCrtl->SetValue(top);
				bottomCrtl->SetValue(buttom);

			}

		}
			
		{
			wxTextCtrl* headerCrtl = (wxTextCtrl*)FindWindow(ID_HEADER);
			wxTextCtrl* footerCrtl = (wxTextCtrl*)FindWindow(ID_FOOTER);
			headerCrtl->SetValue(m_header);
			footerCrtl->SetValue(m_footer);

		}

		// preview
		{
			Card* preview = (Card*)FindWindow(ID_CARD);

		}

	}


	return true;
}
bool PageSettingDialogue::TransferDataFromWindow() // Setting the backend's data using the dialog UI's data
{

	{
		{
			wxComboBox* sizesCB = (wxComboBox*)FindWindow(ID_SIZE_CBOX);
			wxComboBox* sourceCB = (wxComboBox*)FindWindow(ID_SOURCE_CBOX);

			m_size = sizesCB->GetSelection();
			m_source = sourceCB->GetSelection();
		}

		{
			wxRadioBox* orientationCtrl = (wxRadioBox*)FindWindow(ID_ORIENTATION);
			m_orientation = orientationCtrl->GetSelection();
		}

		// the Margins
		{
			wxTextCtrl* leftCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_LEFT);
			wxTextCtrl* rightCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_RIGHT);
			wxTextCtrl* topCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_TOP);
			wxTextCtrl* bottomCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_BOTTOM);

			{
				m_left = wxAtoi(leftCrtl->GetValue());
				m_right = wxAtoi(rightCrtl->GetValue());
				m_top = wxAtoi(topCrtl->GetValue());
				m_bottom = wxAtoi(bottomCrtl->GetValue());

			}

		}

		{
			wxTextCtrl* headerCrtl = (wxTextCtrl*)FindWindow(ID_HEADER);
			wxTextCtrl* footerCrtl = (wxTextCtrl*)FindWindow(ID_FOOTER);
			m_header = headerCrtl->GetValue();
			m_footer = footerCrtl->GetValue();

		}

		// preview
		{
			Card* preview = (Card*)FindWindow(ID_CARD);

		}

	}


	return true;
}


void PageSettingDialogue::OnOK(wxCommandEvent & event)
{
	if (Validate() && TransferDataFromWindow())
	{
		if (IsModal())
			EndModal(wxID_OK); // If modal
		else
		{
			SetReturnCode(wxID_OK);
			this->Show(false); // If modeless
		}
	}
}

void PageSettingDialogue::OnQuit(wxCommandEvent & event)
{
	//TransferDataToWindow();
	Close(this);
}

void PageSettingDialogue::OnResetClick(wxCommandEvent & event)
{
	Init();
	TransferDataToWindow();
}

void PageSettingDialogue::OnCancel(wxCommandEvent & event)
{
	TransferDataToWindow();
	Close(this);

}

void PageSettingDialogue::OnFormatUpdate(wxCommandEvent & event)
{
	Card * cardPreview = (Card*)FindWindow(ID_CARD);
	SetFormat(m_formats[event.GetSelection()]);

	if (GetOrientation() == 1)
	{
		// Landscape
		wxSize temp(m_format.GetHeight(), m_format.GetWidth());
		cardPreview->UpdateCard(temp);

	}
	else
	{
		cardPreview->UpdateCard(m_format);
	}

	//event.Skip();

}

void PageSettingDialogue::OnSourceUpdate(wxUpdateUIEvent & event)
{
}

void PageSettingDialogue::OnMarginLeftUpdate(wxUpdateUIEvent & event)
{
}

void PageSettingDialogue::OnMarginTopUpdate(wxUpdateUIEvent & event)
{
}

void PageSettingDialogue::OnMarginRightUpdate(wxUpdateUIEvent & event)
{
}

void PageSettingDialogue::OnMarginBottomUpdate(wxUpdateUIEvent & event)
{
}

void PageSettingDialogue::OnOrientationUpdate(wxCommandEvent & event)
{
	Card * cardPreview = (Card*)FindWindow(ID_CARD);

	SetOrientation(event.GetSelection());

	if (event.GetSelection() == 1)
	{

		wxSize temp(m_format.GetHeight(), m_format.GetWidth());
		cardPreview->UpdateCard(temp);
	}
	else
	{
		cardPreview->UpdateCard(m_format);
	}


}

void PageSettingDialogue::Init()
{
	m_orientation = false;
	m_formats = {
	wxSize(112,157),
	wxSize(100,132),
	wxSize(80,100)};

	m_format = m_formats[0];

	m_sizes.Add(wxT("A2"));
	m_sizes.Add(wxT("A3"));
	m_sizes.Add(wxT("A4"));

	m_left = 20;
	m_right = 20;
	m_top = 20;
	m_bottom = 20;

	m_sources.Add(wxT("Auto Bin"));
	m_sources.Add(wxT("..."));

	m_orientations.Add(wxT("Portrait"));
	m_orientations.Add(wxT("Landscape"));

	m_header = wxEmptyString;
	m_footer = wxEmptyString;

}
