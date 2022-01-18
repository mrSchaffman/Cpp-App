#include "MainFrame.h"
#include"wx/statline.h"
BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_BUTTON(wxID_BACKWARD,MainFrame::OnBackwardBtnClick)
	EVT_BUTTON(wxID_FORWARD,MainFrame::OnForwardBtnClick)
	EVT_BUTTON(wxID_HOME,MainFrame::OnHomeBtnClick)
	EVT_BUTTON(wxID_REFRESH,MainFrame::OnRefreshBtnClick)
	EVT_BUTTON(wxID_APPLY,MainFrame::OnSearchBtnClick)
	EVT_BUTTON(wxID_SAVE,MainFrame::OnSaveBtnClick)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, wxBoxSizer * sizer, size_t numOfROws):wxFrame(nullptr,wxID_ANY,title,wxPoint(650,50),wxSize(711,810))
{
	
	SetMinSize(wxSize(711, 810));
	SetMaxSize(wxSize(711, 810));

	wxBoxSizer * m_topSizer = sizer;
	m_topSizer->Fit(this);
	m_topSizer->SetSizeHints(this);
	m_sizers.reserve(numOfROws);
	m_currentSizer = std::begin(m_sizers);

	/*wxStatusBar *statutBar = new wxStatusBar(this, wxID_ANY, wxST_SIZEGRIP);
	statutBar->SetStatusText(wxT("Ready"));
	this->SetStatusBar(statutBar);
    */

	// setting the menu bar
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(LIST_ABOUT, "&About");
	menuFile->AppendSeparator();
	menuFile->Append(LIST_QUIT, "E&xit\tAlt-X");
	
	wxMenu *menuView = new wxMenu;
	menuView->Append(LIST_LIST_VIEW, "&List view\tF1");
	menuView->Append(LIST_REPORT_VIEW, "&Report view\tF2");

	wxMenu *menuList = new wxMenu;
	menuList->Append(LIST_GOTO, "&Go to item #3\tCtrl-3");
	menuList->Append(LIST_FOCUS_LAST, "&Make last item current\tCtrl-L");

	wxMenu *menuCol = new wxMenu;
	menuCol->Append(LIST_SET_FG_COL, "&Foreground colour...");
	menuCol->Append(LIST_SET_BG_COL, "&Background colour...");

	wxMenuBar *menubar = new wxMenuBar;
	menubar->Append(menuFile, "&File");
	menubar->Append(menuView, "&View");
	menubar->Append(menuList, "&List");
	menubar->Append(menuCol, "&Color");
	SetMenuBar(menubar);

	m_panel = new wxPanel(this, wxID_ANY);
	//m_panel->SetMinSize(wxSize(500, 810));
	//m_panel->SetMaxSize(wxSize(500, 810));

	wxBoxSizer * sizer1 = new wxBoxSizer(wxHORIZONTAL);
	wxGridSizer * sizer2 = new wxGridSizer(2, 7, 1.5, 1.5);
	wxBoxSizer * sizer3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer * sizer4 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer * sizer5 = new wxBoxSizer(wxHORIZONTAL);

	creatFirstSizer(sizer1);
	m_topSizer->Add(sizer1, 0, wxEXPAND | wxALL, 3);
	m_topSizer->Add(new wxStaticLine(m_panel, wxID_STATIC, wxDefaultPosition, wxSize(800, -1), wxLI_HORIZONTAL), 0, wxEXPAND);

	creatSecondSizer(m_panel, sizer2);
	m_topSizer->Add(sizer2, 0, wxEXPAND | wxALL, 1.5);

	m_topSizer->Add(new wxStaticLine(m_panel, wxID_STATIC, wxDefaultPosition, wxSize(800, -1), wxLI_HORIZONTAL), 0, wxEXPAND);
	
	creatThirdSizer(m_panel, sizer4);
	m_topSizer->Add(sizer4, 0, wxEXPAND | wxALL, 3);
	
	m_topSizer->Add(new wxStaticLine(m_panel, wxID_STATIC, wxDefaultPosition, wxSize(800, -1), wxLI_HORIZONTAL), 0, wxEXPAND);
	creatLastSizer(m_panel, sizer5);
	m_topSizer->Add(sizer5, 0, wxEXPAND | wxALL, 3);
	m_log = wxLog::SetActiveTarget(new wxLogTextCtrl( m_logWindow));

	RecreateList(wxLC_REPORT | wxLC_SINGLE_SEL);

	//SetSizer(m_topSizer);
	m_panel->SetSizer(m_topSizer);
	SetClientSize(m_panel->GetBestSize());
}

void MainFrame::addSizers(std::vector<wxSizer*>& sizers)
{
	for (auto& sizer : sizers)
	{
		//m_topSizer->Add(sizer, 1, wxEXPAND |wxTOP|wxLEFT, 3);
	}
}

void MainFrame::creatFirstSizer(wxBoxSizer*& sizer)
{
	
	
	wxButton *backBtn = new wxButton(m_panel, wxID_BACKWARD, L"<-", wxDefaultPosition, wxSize(48, 30), wxBU_AUTODRAW);
	wxButton *forwardBtn = new wxButton(m_panel, wxID_FORWARD, L"->", wxDefaultPosition, wxSize(48, 30), wxBU_AUTODRAW);
	wxButton *homeBtn = new wxButton(m_panel, wxID_HOME, "Hm", wxDefaultPosition, wxSize(48, 30), wxBU_AUTODRAW);
	wxButton *refreshBtn = new wxButton(m_panel, wxID_REFRESH, "rfh", wxDefaultPosition, wxSize(48, 30), wxBU_AUTODRAW);
	wxButton *searchBtn = new wxButton(m_panel, wxID_APPLY, "sch", wxDefaultPosition, wxSize(48, 30), wxBU_AUTODRAW);
	wxButton *saveBtn = new wxButton(m_panel, wxID_APPLY, "sav", wxDefaultPosition, wxSize(48, 30), wxBU_AUTODRAW);
	//wxStaticText* searchLabel = new wxStaticText(m_panel, wxID_ANY, "Name:");
	wxTextCtrl * searchText = new wxTextCtrl(m_panel, wxID_STATIC, wxEmptyString, wxDefaultPosition, wxSize(202, 30), wxTE_WORDWRAP | wxTE_PROCESS_ENTER);
	searchText->SetFont(searchText->GetFont().Scale(1.5));

	sizer->Add(backBtn, 0, wxALL,1.5);
	sizer->Add(forwardBtn, 0, wxALL, 1.5);
	sizer->Add(homeBtn, 0, wxALL, 1.5);
	sizer->Add(refreshBtn, 0, wxALL, 1.5);
	//sizer->Add(searchLabel, 0, wxALIGN_CENTER);
	sizer->Add(searchText, 1, wxALL, 1.5);
	sizer->Add(searchBtn, 0, wxALL, 1.5);
	sizer->AddSpacer(48);
	sizer->Add(saveBtn, 0, wxALL, 1.5);

	
}

void MainFrame::creatSecondSizer(wxPanel *& panel, wxGridSizer *& sizer)
{
	
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			wxButton * btn = new wxButton(panel, 1000 + (y * 1 + x), std::to_string((y * 1 + x)), wxDefaultPosition, wxSize(99, 30));
			sizer->Add(btn, 0, wxEXPAND);
		}
	}
	
}

void MainFrame::creatThirdSizer(wxPanel *& panel, wxBoxSizer *& sizer)
{
	wxBoxSizer * sizer3_1 = new wxBoxSizer(wxVERTICAL);
	wxGridSizer * sizer3_1_1 = new wxGridSizer(2, 2, 1.5, 1.5);
	wxBoxSizer * sizer3_2 = new wxBoxSizer(wxVERTICAL);

	{
		
		wxStaticText * root = new wxStaticText(panel, wxID_ANY, wxString("Root:"), wxDefaultPosition, wxSize(99, 30));
		wxStaticText * name = new wxStaticText(panel, wxID_ANY, wxString("Name:"), wxDefaultPosition, wxSize(99, 30));
		wxStaticText * type = new wxStaticText(panel, wxID_ANY, wxString("Type"), wxDefaultPosition, wxSize(99, 30));
		wxStaticText * total = new wxStaticText(panel, wxID_ANY, wxString("Total"), wxDefaultPosition, wxSize(99, 30));
		sizer3_1_1->Add(root, 0, wxEXPAND);
		sizer3_1_1->Add(name, 0, wxEXPAND);
		sizer3_1_1->Add(type, 0, wxEXPAND);
		sizer3_1_1->Add(total, 0, wxEXPAND);


		wxStaticText * txtMsgLog = new wxStaticText(panel, wxID_ANY, wxString("Message Log"), wxDefaultPosition, wxSize(300, 30));
		m_dvdListCtrl = new DVDListCtrl(panel, LIST_CTRL, wxDefaultPosition, wxSize(580, 400), wxLC_REPORT | wxLC_SINGLE_SEL);
		m_logWindow = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(580, 100), wxTE_READONLY | wxTE_MULTILINE | wxSUNKEN_BORDER);


		sizer3_1->Add(sizer3_1_1, 0, wxEXPAND | wxALL, 1.5);
		sizer3_1->Add(m_dvdListCtrl, 0, wxEXPAND | wxALL, 1.5);
		sizer3_1->Add(txtMsgLog, 0, wxEXPAND | wxALL, 1.5);
		sizer3_1->Add(m_logWindow, 0, wxEXPAND | wxALL, 1.5);

		
		sizer3_2->AddSpacer(10);
		sizer3_2->Add(new wxStaticText(panel, wxID_ANY, wxString("Options"), wxDefaultPosition, wxSize(99, 50)), 0, wxCENTER);
		for (size_t i = 0; i < 12; i++)
		{
			wxButton * btn = new wxButton(panel, 2000 + i * 2, std::to_string(i), wxDefaultPosition, wxSize(99, 30));
			sizer3_2->Add(btn, 0, wxEXPAND | wxALL, 1.5);
		}

	}
	

	sizer->Add(sizer3_1, 0, wxEXPAND);
	sizer->AddSpacer(3);
	sizer->Add(new wxStaticLine(panel, wxID_STATIC, wxDefaultPosition, wxSize(-1, 400), wxLI_VERTICAL), 0, wxEXPAND);
	sizer->AddSpacer(3);
	sizer->Add(sizer3_2, 0, wxEXPAND);
	

}

void MainFrame::creatLastSizer(wxPanel *& panel, wxBoxSizer *& sizer)
{
	
	sizer->Add(new wxButton(panel, BTN_CLOSE, "Close", wxDefaultPosition, wxSize(80, 30)), 0);
	sizer->AddSpacer(10);
	sizer->Add(new wxButton(panel, BTN_CANCEL, "End", wxDefaultPosition, wxSize(80, 30)), 0);
}

void MainFrame::RecreateList(long flags, bool withText)
{
	InitWithListItems();
}

void MainFrame::InitWithListItems()
{
	for (size_t i = 0; i < m_numOfItems; i++)
	{
		//m_dvdListCtrl->InsertItem(i, wxString::Format("o", i));
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
