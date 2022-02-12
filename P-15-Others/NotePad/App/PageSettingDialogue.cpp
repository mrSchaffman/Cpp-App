#include "PageSettingDialogue.h"

wxBEGIN_EVENT_TABLE(PageSettingDialogue, wxPanel)
	EVT_COMBOBOX(ID_SIZE_CBOX,PageSettingDialogue::OnSizeTypeChanged)
	EVT_TEXT(ID_MARGIN_LEFT,PageSettingDialogue::OnMarginLeftChanged)
	EVT_TEXT(ID_MARGIN_TOP,PageSettingDialogue::OnMarginTopChanged)
	EVT_TEXT(ID_MARGIN_RIGHT,PageSettingDialogue::OnMarginRightChanged)
	EVT_TEXT(ID_MARGIN_BOTTOM,PageSettingDialogue::OnMarginBottomChanged)
	EVT_RADIOBOX(ID_RADIOBOX,PageSettingDialogue::OnOrientationChanged)
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
		//SetSizerAndFit(topSizer);

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

				wxFlexGridSizer* m_row2 = new wxFlexGridSizer(1,2,5,5);
				{
				
					m_orientation = new wxRadioBox(this, ID_ORIENTATION, wxT("Orientation"), wxDefaultPosition, wxDefaultSize, m_orientations, 1, wxRA_SPECIFY_COLS);

					m_row2->Add(m_orientation, 1, wxALIGN_LEFT | wxALL, 5);

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
					m_row2->Add(m_margings, 1, wxALIGN_CENTER | wxALL, 5);


				}

				wxStaticBoxSizer* style = new wxStaticBoxSizer(wxVERTICAL, this, wxT(""));
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

						style->Add(m_row31, 0, wxALL, 5);

					}
				}

				m_col1->Add(m_paper, 0);
				m_col1->Add(m_row2, 0);
				m_col1->Add(style, 0);
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

					m_preview_win = new Card(this, ID_CARD);// m_current_format);
					m_preview->Add(m_preview_win, 1, wxCENTER);
				}
				wxBoxSizer* m_row42 = new wxBoxSizer(wxHORIZONTAL);
				{
					wxButton*btOK = new wxButton(this, wxID_OK);
					wxButton*btCancel = new wxButton(this, wxID_CANCEL);
					m_row42->Add(btOK, 1, wxALL, 5);
					m_row42->Add(btCancel, 1, wxALL, 5);
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
			wxTextCtrl* leftCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_LEFT);
			leftCrtl->SetValidator(wxTextValidator(wxFILTER_DIGITS, &m_left));

			wxTextCtrl* rightCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_RIGHT);
			rightCrtl->SetValidator(wxTextValidator(wxFILTER_DIGITS, &m_left));

			wxTextCtrl* topCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_TOP);
			topCrtl->SetValidator(wxTextValidator(wxFILTER_DIGITS, &m_left));

			wxTextCtrl* bottomCrtl = (wxTextCtrl*)FindWindow(ID_MARGIN_BOTTOM);
			bottomCrtl->SetValidator(wxTextValidator(wxFILTER_DIGITS, &m_left));

			{
				leftCrtl->SetValue(m_left);
				rightCrtl->SetValue(m_right);
				topCrtl->SetValue(m_top);
				bottomCrtl->SetValue(m_bottom);

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
			preview->SetBitmap(m_bmps[4]);

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
				m_left = leftCrtl->GetValue();
				m_right = rightCrtl->GetValue();
				m_top = topCrtl->GetValue();
				m_bottom = bottomCrtl->GetValue();

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
			m_current_bmp = preview->GetBitmap();

		}

	}


	return true;
}


void PageSettingDialogue::OnSizeTypeChanged(wxCommandEvent & event)
{
	m_current_format = m_formats[event.GetSelection()];

	if (isPortrait)
		m_preview_win->UpdateCard(m_current_format);
	else
	{
		wxSize landscape(m_current_format.GetY(), m_current_format.GetX());

		m_preview_win->UpdateCard(landscape);
	}

}

void PageSettingDialogue::OnMarginLeftChanged(wxCommandEvent & event)
{
	if (event.GetInt() > 0)
	{
		m_preview_win->SetMarginLeft(event.GetInt());

	}
}

void PageSettingDialogue::OnMarginTopChanged(wxCommandEvent & event)
{
	if (event.GetInt() > 0)
	{
		m_preview_win->SetMarginTop(event.GetInt());
	}

}

void PageSettingDialogue::OnMarginRightChanged(wxCommandEvent & event)
{
	if (event.GetInt() > 0)
	{
		m_preview_win->SetMarginRight(event.GetInt());

	}

}

void PageSettingDialogue::OnMarginBottomChanged(wxCommandEvent & event)
{
	if (event.GetInt() > 0)
	{
		m_preview_win->SetMarginBottom(event.GetInt());
	}

}

void PageSettingDialogue::OnOrientationChanged(wxCommandEvent & event)
{

	if (event.GetSelection()==0)
	{
		isPortrait = true;
		m_preview_win->UpdateCard(m_current_format);
	}
	else
	{
		isPortrait = false;

		wxSize landscape(m_current_format.GetY(), m_current_format.GetX());
		m_preview_win->UpdateCard(landscape);

	}

}

void PageSettingDialogue::Init()
{
	m_formats = {
	wxSize(132,187),
	wxSize(93,132),
	wxSize(66,93),
	wxSize(47,66),
	wxSize(33,47),
	wxSize(23,33) };

	m_bmps = { wxSize(132,187),
	wxSize(93,132),
	wxSize(66,93),
	wxSize(47,66),
	wxSize(33,47),
	wxSize(23,33) };

	m_sizes.Add(wxT("A0"));
	m_sizes.Add(wxT("A1"));
	m_sizes.Add(wxT("A2"));
	m_sizes.Add(wxT("A3"));
	m_sizes.Add(wxT("A4"));
	m_sizes.Add(wxT("A5"));

	m_left = wxT("20");
	m_right = wxT("20");
	m_top = wxT("20");
	m_bottom = wxT("20");

	m_sources.Add(wxT("Auto Bin"));
	m_sources.Add(wxT("..."));

	m_orientations.Add(wxT("Portrait"));
	m_orientations.Add(wxT("Landscape"));

	m_header = wxEmptyString;
	m_footer = wxEmptyString;
}
