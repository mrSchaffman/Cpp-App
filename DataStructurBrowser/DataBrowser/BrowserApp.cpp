#include "BrowserApp.h"
#include"wx/statline.h"

DECLARE_APP(BrowserApp)
IMPLEMENT_APP(BrowserApp)

bool BrowserApp::OnInit()
{
	frame = new MainFrame(wxString("Data Structure Browser"));

	line1 = new wxBoxSizer(wxHORIZONTAL);
	sizers.push_back(line1);

	wxBitmap bitmapBtnBack(wxT("home.png"), wxBITMAP_TYPE_PNG);
	wxBitmapButton *backBtn = new wxBitmapButton(frame, wxID_BACKWARD, bitmapBtnBack, wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxBitmapButton *forwardBtn = new wxBitmapButton(frame, wxID_FORWARD, bitmapBtnBack, wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxBitmapButton *homeBtn = new wxBitmapButton(frame, wxID_HOME, bitmapBtnBack, wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxBitmapButton *refreshBtn = new wxBitmapButton(frame, wxID_REFRESH, bitmapBtnBack, wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxBitmapButton *searchBtn = new wxBitmapButton(frame, wxID_APPLY, bitmapBtnBack, wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxBitmapButton *saveBtn = new wxBitmapButton(frame, wxID_APPLY, bitmapBtnBack, wxDefaultPosition, wxSize(30, 30), wxBU_AUTODRAW);
	wxStaticText* searchLabel = new wxStaticText(frame, wxID_ANY,"Name:");
	wxTextCtrl * searchText = new wxTextCtrl(frame, wxID_STATIC, wxEmptyString, wxDefaultPosition, wxSize(180, 30), wxTE_WORDWRAP|wxTE_PROCESS_ENTER);
	searchText->SetFont(searchText->GetFont().Scale(1.5));
	
	//wxBitmap bitmap("something.png");
	//wxStaticBitmap* staticBitmap = new wxStaticBitmap(frame, wxID_STATIC,bitmap);
	//wxArrayString strings;
	//strings.Add(wxT("one"));
	//strings.Add(wxT("two"));
	//strings.Add(wxT("three"));
	//wxChoice* choice = new wxChoice(frame, wxID_ANY,wxDefaultPosition,wxSize(60,40),strings);


	line1->Add(backBtn, 0, wxALL);
	line1->Add(forwardBtn, 0, wxALL);
	line1->Add(homeBtn, 0, wxALL);
	line1->Add(refreshBtn, 0, wxALL);
	line1->Add(searchLabel, 0, wxALIGN_CENTER|wxLEFT,10);
	line1->Add(searchText, 0,wxLEFT,3);
	line1->Add(searchBtn, 0, wxALL);
	line1->Add(saveBtn, 0, wxLEFT,25);

	line2 = new wxBoxSizer(wxHORIZONTAL);
	sizers.push_back(line2);
	line2->Add(new wxStaticLine(frame, wxID_STATIC, wxDefaultPosition, wxSize(590, -1), wxLI_HORIZONTAL), 0,wxEXPAND);
	//line1->Add(choice, 0, wxEXPAND| wxTOP,2);

	wxStatusBar *statutBar = new wxStatusBar(frame, wxID_ANY, wxST_SIZEGRIP);
	statutBar->SetStatusText(wxT("Ready"));
	frame->SetStatusBar(statutBar);

	frame->addSizers(sizers);
	frame->Show(true);
	return true;
}
