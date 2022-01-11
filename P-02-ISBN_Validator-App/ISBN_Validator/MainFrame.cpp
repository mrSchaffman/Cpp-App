#include "MainFrame.h"
#include"wx/statline.h"
#include<numeric>
#include<algorithm>
BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_BUTTON(BTN_CLEAR, MainFrame::OnClearButtonClick)
	EVT_BUTTON(BTN_VALIDATE, MainFrame::OnValidateButtonClick)
	/*EVT_TEXT(T1,)
	EVT_TEXT(T2,)
	EVT_TEXT(T3,)
	EVT_TEXT(T4,)*/
END_EVENT_TABLE()


MainFrame::MainFrame(const wxString & title) :wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480))
{
	m_topSizer = new wxBoxSizer(wxVERTICAL);
	SetMaxSize(wxSize(640, 480));


	wxBoxSizer* line1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* line2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* line3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* line4 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* line5 = new wxBoxSizer(wxHORIZONTAL);

	//m_isbn = new wxString();

	//Line 1
	{
		wxStaticText * Title = new wxStaticText(this, wxID_STATIC, wxString("ISBN Validator"), wxDefaultPosition, wxDefaultSize);
		Title->SetFont(Title->GetFont().Scale(2));
		line1->Add(Title, 0, wxCENTER|wxEXPAND);

	}

	//Line 2
	{
		{
			m_t1 = new NumberTextCtrl(this, T1, wxEmptyString,wxDefaultPosition,wxSize(75,40),wxTE_CENTER| wxTE_PROCESS_ENTER);
			m_t1->SetFont(m_t1->GetFont().Scale(2));
			m_t1->SetHint("0");
			m_t1->SetMaxLength(1);
			m_t1->SetDefaultStyle(wxTextAttr(*wxBLUE));
			line2->Add(m_t1, 1,wxEXPAND);
			line2->Add(new wxStaticLine(this, wxID_STATIC, wxDefaultPosition, wxSize(15, -1)), 0, wxCENTER);
			//line2->AddSpacer(15);
		}

		{
			m_t2 = new NumberTextCtrl(this, T2, wxEmptyString, wxDefaultPosition, wxSize(192, 40), wxTE_CENTER | wxTE_PROCESS_ENTER);
			m_t2->SetFont(m_t2->GetFont().Scale(2));
			m_t2->SetHint("0000");
			m_t2->SetMaxLength(4);
			line2->Add(m_t2, 1, wxEXPAND);
			line2->Add(new wxStaticLine(this, wxID_STATIC, wxDefaultPosition, wxSize(15, -1)), 0, wxCENTER);
		}

		{
			m_t3 = new NumberTextCtrl(this, T3, wxEmptyString, wxDefaultPosition, wxSize(192, 40), wxTE_CENTER | wxTE_PROCESS_ENTER);
			m_t3->SetFont(m_t3->GetFont().Scale(2));
			m_t3->SetHint("0000");
			m_t3->SetMaxLength(4);
			line2->Add(m_t3, 1, wxEXPAND);
			line2->Add(new wxStaticLine(this, wxID_STATIC, wxDefaultPosition, wxSize(15, -1)), 0, wxCENTER);
		}

		{
			m_t4 = new NumberTextCtrl(this, T4, wxEmptyString, wxDefaultPosition, wxSize(75, 40), wxTE_CENTER | wxTE_PROCESS_ENTER);
			m_t4->SetFont(m_t4->GetFont().Scale(2));
			m_t4->SetMaxLength(1);
			m_t4->SetHint("0");
			line2->Add(m_t4, 1, wxEXPAND);
		}

	}

	//Line 3
	{

		wxButton * btnClear = new wxButton(this, BTN_CLEAR, wxT("Clear"), wxDefaultPosition, wxSize(290, 40));
		wxButton * btnValidate = new wxButton(this, BTN_VALIDATE, wxT("Validate"), wxDefaultPosition, wxSize(290, 40));
		btnClear->SetFont(btnClear->GetFont().Scale(2));
		btnValidate->SetFont(btnValidate->GetFont().Scale(2));
		line3->Add(btnClear, 1, wxEXPAND);
		line3->AddSpacer(15);
		line3->Add(btnValidate, 1, wxEXPAND);
	}
	
	// Line 4
	{
		wxStaticText * evtLogtitle = new wxStaticText(this, wxID_STATIC, wxString("Event Log"), wxDefaultPosition, wxDefaultSize);
		evtLogtitle->SetFont(evtLogtitle->GetFont().Scale(1.5));
		line4->Add(evtLogtitle, 0, wxCENTER | wxEXPAND);

	}

	//line 5
	{
		m_evtLog = new wxTextCtrl(this, EVT_LOG, "This is the log window.\n", wxDefaultPosition, wxSize(620, 220),wxTE_MULTILINE|wxTE_READONLY);
		m_LogOld = wxLog::SetActiveTarget(new wxLogTextCtrl(m_evtLog));
		line5->Add(m_evtLog, 1, wxEXPAND);
	}

	m_topSizer->Add(line1, 0, wxALL | wxCENTER, 10);
	m_topSizer->Add(line2, 0, wxALL | wxCENTER, 10);
	m_topSizer->Add(line3, 0, wxALL | wxCENTER, 10);
	m_topSizer->Add(line4, 0, wxLEFT | wxRIGHT, 10);
	m_topSizer->Add(line5, 0, wxLEFT | wxRIGHT, 10);
	SetSizer(m_topSizer);
	//topSizer->SetSizeHints(this);*/

}

void MainFrame::OnValidateButtonClick(wxCommandEvent & evt)
{

	//NumberTextCtrl *txt = (NumberTextCtrl*)evt.GetClientObject();

	m_isbn += (m_t1->GetValue());
	m_isbn += (m_t2->GetValue());
	m_isbn += (m_t3->GetValue());
	m_isbn += (m_t4->GetValue());

	if (isISBN_10_valid(m_isbn))
	{
		m_t1->SetBackgroundColour(*wxGREEN);
		m_t2->SetBackgroundColour(*wxGREEN);
		m_t3->SetBackgroundColour(*wxGREEN);
		m_t4->SetBackgroundColour(*wxGREEN);
		wxLogMessage("%s is a valide isbn!",m_isbn);

	}	
	else
	{
		m_t1->SetBackgroundColour(*wxRED);
		m_t2->SetBackgroundColour(*wxRED);
		m_t3->SetBackgroundColour(*wxRED);
		m_t4->SetBackgroundColour(*wxRED);
		wxLogMessage("%s is not a valide isbn!", m_isbn);

	}
		
	
		
}

void MainFrame::OnClearButtonClick(wxCommandEvent & evt)
{
	m_t1->Clear();
	m_t2->Clear();
	m_t3->Clear();
	m_t4->Clear();

	m_t1->SetBackgroundColour(*wxWHITE);
	m_t2->SetBackgroundColour(*wxWHITE);
	m_t3->SetBackgroundColour(*wxWHITE);
	m_t4->SetBackgroundColour(*wxWHITE);
	/*m_isbn->clear();
	m_ISBN->clear();*/
}
bool MainFrame::isISBN_10_valid(const std::string& isbn)
{
	bool valid = false;
	auto checksum = count_if(cbegin(isbn), cend(isbn), isdigit);
	if (isbn.size() == 10 && checksum == 10)
	{
		int w = 10;
		auto sum = accumulate(cbegin(isbn), cend(isbn), 0,
			[&w](const int total, const char c) {
				return total + (w--) * (c - '0');
			});

		valid = !(sum % 11);
	}

	return valid;
}