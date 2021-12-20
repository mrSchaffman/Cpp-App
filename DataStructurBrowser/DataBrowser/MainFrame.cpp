#include "MainFrame.h"
BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_BUTTON(wxID_BACKWARD,MainFrame::OnBackwardBtnClick)
	EVT_BUTTON(wxID_FORWARD,MainFrame::OnForwardBtnClick)
	EVT_BUTTON(wxID_HOME,MainFrame::OnHomeBtnClick)
	EVT_BUTTON(wxID_REFRESH,MainFrame::OnRefreshBtnClick)
	EVT_BUTTON(wxID_APPLY,MainFrame::OnSearchBtnClick)
	EVT_BUTTON(wxID_SAVE,MainFrame::OnSaveBtnClick)
END_EVENT_TABLE()

MainFrame::MainFrame(wxString title, wxBoxSizer * sizer, size_t numOfROws):wxFrame(nullptr,wxID_ANY,title,wxPoint(50,50),wxSize(600,610))
{
	this->SetMaxSize(wxSize(600, 600));
	this->SetMinSize(wxSize(600, 600));
	m_topSizer = sizer;
	m_sizers.reserve(numOfROws);
	m_currentSizer = std::begin(m_sizers);

	m_topSizer->Fit(this);
	
	m_topSizer->SetSizeHints(this);
	SetSizer(m_topSizer);
}

void MainFrame::addSizers(std::vector<wxSizer*>& sizers)
{
	for (auto& sizer : sizers)
	{
		m_topSizer->Add(sizer, 1, wxEXPAND |wxTOP|wxLEFT, 3);
	}
}

void MainFrame::OnBackwardBtnClick(wxCommandEvent & evt)
{
}

void MainFrame::OnHomeBtnClick(wxCommandEvent & evt)
{
}

void MainFrame::OnForwardBtnClick(wxCommandEvent & evt)
{
}

void MainFrame::OnRefreshBtnClick(wxCommandEvent & evt)
{
}

void MainFrame::OnSaveBtnClick(wxCommandEvent & evt)
{
}

void MainFrame::OnSearchBtnClick(wxCommandEvent & evt)
{
}
