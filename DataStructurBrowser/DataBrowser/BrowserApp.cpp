#include "BrowserApp.h"
#include"wx/statline.h"

DECLARE_APP(BrowserApp)
IMPLEMENT_APP(BrowserApp)

bool BrowserApp::OnInit()
{
	frame = new MainFrame(wxString("Data Structure Browser"));

	line1 = new wxBoxSizer(wxHORIZONTAL);
	sizers.push_back(line1);

	wxStatusBar *statutBar = new wxStatusBar(frame, wxID_ANY, wxST_SIZEGRIP);
	statutBar->SetStatusText(wxT("Ready"));
	frame->SetStatusBar(statutBar);


	//wxBitmap bitmapBtnBack(wxT("home.png"), wxBITMAP_TYPE_PNG);
	wxButton *backBtn = new wxButton(frame, wxID_BACKWARD, L"<-", wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxButton *forwardBtn = new wxButton(frame, wxID_FORWARD, L"->", wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxButton *homeBtn = new wxButton(frame, wxID_HOME, "Hm", wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxButton *refreshBtn = new wxButton(frame, wxID_REFRESH, "rfh", wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxButton *searchBtn = new wxButton(frame, wxID_APPLY, "sch", wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxButton *saveBtn = new wxButton(frame, wxID_APPLY, "sav", wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxStaticText* searchLabel = new wxStaticText(frame, wxID_ANY,"Name:");
	wxTextCtrl * searchText = new wxTextCtrl(frame, wxID_STATIC, wxEmptyString, wxDefaultPosition, wxSize(180, 30), wxTE_WORDWRAP|wxTE_PROCESS_ENTER);
	searchText->SetFont(searchText->GetFont().Scale(1.5));


	line1->Add(backBtn, 0, wxALL);
	line1->Add(forwardBtn, 0, wxALL);
	line1->Add(homeBtn, 0, wxALL);
	line1->Add(refreshBtn, 0, wxALL);
	line1->Add(searchLabel, 0, wxALIGN_CENTER|wxLEFT,10);
	line1->Add(searchText, 0,wxLEFT,3);
	line1->Add(searchBtn, 0, wxALL);
	line1->AddSpacer(70);
	line1->Add(saveBtn, 0, wxALL);

	line2 = new wxBoxSizer(wxHORIZONTAL);
	sizers.push_back(line2);
	line2->Add(new wxStaticLine(frame, wxID_STATIC, wxDefaultPosition, wxSize(590, -1), wxLI_HORIZONTAL), 0,wxEXPAND);
	//line1->Add(choice, 0, wxEXPAND| wxTOP,2);
	wxGridSizer * grid = new wxGridSizer(2,10,2,2);
	sizers.push_back(grid);
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			wxButton * btn = new wxButton(frame, 1000 + (y * 1 + x), std::to_string((y * 1 + x)), wxDefaultPosition,wxSize(50,40));
			grid->Add(btn, 0, wxALL|wxEXPAND);
		}
	}

	wxBoxSizer* line4 = new wxBoxSizer(wxHORIZONTAL);
	sizers.push_back(line4);
	line4->Add(new wxStaticLine(frame, wxID_STATIC, wxDefaultPosition, wxSize(590, -1), wxLI_HORIZONTAL), 0, wxEXPAND);
	
	wxBoxSizer* line5 = new wxBoxSizer(wxHORIZONTAL);
	sizers.push_back(line5);

	wxBoxSizer* labelLine = new wxBoxSizer(wxHORIZONTAL);
	labelLine->Add(new wxStaticText(frame, wxID_STATIC, "Root:  "),0,wxALIGN_CENTER);
	labelLine->AddSpacer(30);
	labelLine->Add(new wxStaticText(frame, wxID_STATIC, "Name:    "),0, wxALIGN_CENTER);
	labelLine->AddSpacer(70);
	labelLine->Add(new wxStaticText(frame, wxID_STATIC, "Type:    "),0, wxALIGN_CENTER);
	labelLine->AddSpacer(130);
	labelLine->Add(new wxStaticText(frame, wxID_STATIC, "Anträge:   "),0, wxALIGN_CENTER);

	wxBoxSizer* line6 = new wxBoxSizer(wxVERTICAL);
	line6->Add(labelLine, 0, wxEXPAND);

	wxArrayString strings;
	strings.Add(wxT("MAIN"));
	strings.Add(wxT("GRAPHIC_SLOT"));
	strings.Add(wxT("MODEL_SLOT"));

	wxListBox * listBox = new wxListBox(frame, wxID_VIEW_LIST, wxDefaultPosition, wxSize(450, 350), strings, wxLB_SINGLE| wxLB_ALWAYS_SB);
	line6->Add(listBox, 0, wxEXPAND);

	line5->Add(line6, 0, wxEXPAND);

	
	wxGridSizer * grid2 = new wxGridSizer(6, 1, 4, 4);
	wxBoxSizer* line7 = new wxBoxSizer(wxVERTICAL);
	line7->Add(new wxStaticText(frame, wxID_STATIC, "Show Options"), 0, wxALIGN_CENTER);
	for (int x = 0; x < 5; x++)
	{
			wxButton * btn = new wxButton(frame, 2000 + x, std::to_string(x), wxDefaultPosition,wxSize(105,40));
			line7->AddSpacer(5);
			line7->Add(btn, 1, wxEXPAND);
		
	}
	
	//line7->Add(grid2, 0,wxEXPAND);
	
	line5->Add(new wxStaticLine(frame, wxID_STATIC, wxDefaultPosition, wxSize(-1, 50), wxLI_VERTICAL), 0, wxEXPAND);
	line5->AddSpacer(10);
	line5->Add(line7, 0, wxALL);

	wxBoxSizer* line8 = new wxBoxSizer(wxHORIZONTAL);
	sizers.push_back(line8);
	line8->Add(new wxStaticLine(frame, wxID_STATIC, wxDefaultPosition, wxSize(590, -1), wxLI_HORIZONTAL), 0, wxEXPAND);

	wxBoxSizer* line9 = new wxBoxSizer(wxHORIZONTAL);
	sizers.push_back(line9);
	line9->Add(new wxButton(frame, 1020, "Close", wxDefaultPosition, wxSize(80, 30)), 0, wxBOTTOM,5);
	line9->AddSpacer(10);
	line9->Add(new wxButton(frame, 1020, "End", wxDefaultPosition, wxSize(80, 30)), 0, wxBOTTOM, 5);

	frame->addSizers(sizers);
	frame->Show(true);
	return true;
}
