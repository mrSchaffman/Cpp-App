#include "MainFrame.h"
#include"wx/statline.h"
BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_BUTTON(BTN_CLEAR, MainFrame::OnClearButtonClick)
	EVT_BUTTON(BTN_VALIDATE, MainFrame::OnValidateButtonClick)
END_EVENT_TABLE()


MainFrame::MainFrame(const wxString & title) :wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480))
{
	topSizer = new wxBoxSizer(wxVERTICAL);
	
	wxBoxSizer* line1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* line2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* line3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* line4 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* line5 = new wxBoxSizer(wxHORIZONTAL);

	//Line 1
	{
		wxStaticText * Title = new wxStaticText(this, wxID_STATIC, wxString("ISBN Validator"), wxDefaultPosition, wxDefaultSize);
		Title->SetFont(Title->GetFont().Scale(2));
		line1->Add(Title, 0, wxCENTER|wxEXPAND);

	}

	//Line 2
	{
		{
			wxTextCtrl* t1 = new wxTextCtrl(this, T1, wxEmptyString,wxDefaultPosition,wxSize(72,40));
			t1->SetFont(t1->GetFont().Scale(2));
			line2->Add(t1, 0,wxALL);
			line2->Add(new wxStaticLine(this, wxID_STATIC, wxDefaultPosition, wxSize(15, -1)), 0, wxCENTER);
			//line2->AddSpacer(15);
		}

		{
			wxTextCtrl* t2 = new wxTextCtrl(this, T2, wxEmptyString, wxDefaultPosition, wxSize(192, 40));
			t2->SetFont(t2->GetFont().Scale(2));
			line2->Add(t2, 0,wxALL);
			line2->Add(new wxStaticLine(this, wxID_STATIC, wxDefaultPosition, wxSize(15, -1)), 0, wxCENTER);
		}

		{
			wxTextCtrl* t3 = new wxTextCtrl(this, T3, wxEmptyString, wxDefaultPosition, wxSize(192, 40));
			t3->SetFont(t3->GetFont().Scale(2));
			line2->Add(t3, 0,wxALL);
			line2->Add(new wxStaticLine(this, wxID_STATIC, wxDefaultPosition, wxSize(15, -1)), 0, wxCENTER);
		}

		{
			wxTextCtrl* t4 = new wxTextCtrl(this, T4, wxEmptyString, wxDefaultPosition, wxSize(72, 40));
			t4->SetFont(t4->GetFont().Scale(2));
			line2->Add(t4, 0,wxALL);
		}

	}

	//Line 3
	{

		wxButton * btnClear = new wxButton(this, BTN_CLEAR, wxT("Clear"), wxDefaultPosition, wxSize(290, 40));
		wxButton * btnValidate = new wxButton(this, BTN_VALIDATE, wxT("Validate"), wxDefaultPosition, wxSize(290, 40));
		btnClear->SetFont(btnClear->GetFont().Scale(2));
		btnValidate->SetFont(btnValidate->GetFont().Scale(2));
		line3->Add(btnClear, 0);
		line3->AddSpacer(15);
		line3->Add(btnValidate, 0);
	}
	
	// Line 4
	{
		wxStaticText * evtLogtitle = new wxStaticText(this, wxID_STATIC, wxString("Event Log"), wxDefaultPosition, wxDefaultSize);
		evtLogtitle->SetFont(evtLogtitle->GetFont().Scale(1.5));
		line4->Add(evtLogtitle, 0, wxCENTER | wxEXPAND);

	}

	//line 5
	{
		wxTextCtrl* evtLog = new wxTextCtrl(this, EVT_LOG, wxEmptyString, wxDefaultPosition, wxSize(620, 220));
		line5->Add(evtLog, 0, wxALL);
	}

	topSizer->Add(line1, 0, wxALL | wxCENTER, 10);
	topSizer->Add(line2, 0, wxALL | wxCENTER, 10);
	topSizer->Add(line3, 0, wxALL | wxCENTER, 10);
	topSizer->Add(line4, 0, wxLEFT|wxRIGHT, 10);
	topSizer->Add(line5, 0, wxLEFT | wxRIGHT, 10);
	SetSizer(topSizer);
	//topSizer->SetSizeHints(this);*/

}

void MainFrame::OnValidateButtonClick(wxCommandEvent & evt)
{
}

void MainFrame::OnClearButtonClick(wxCommandEvent & evt)
{
}
