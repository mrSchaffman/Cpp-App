#include "MainPanel.h"

MainPanel::MainPanel(wxFrame * frame, int x, int y, int w, int h) : wxPanel(frame, wxID_ANY, wxPoint(x, y), wxSize(w, h))
{
	mLog = new wxTextCtrl(this, wxID_ANY, "This is the log window.\n", wxPoint(5, 260), wxSize(630, 100), wxTE_MULTILINE | wxTE_READONLY);
	mLogOld = wxLog::SetActiveTarget(new wxLogTextCtrl(mLog));
	
	mText = new MyTextCtrl(this, wxID_ANY, "Single line.", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
	mText->SetForegroundColour(*wxBLUE);
	mText->SetBackgroundColour(*wxLIGHT_GREY);
	(*mText) << " Appended.";
	mText->SetInsertionPoint(0);
	mText->WriteText("Prepended. ");

	mPassword = new MyTextCtrl(this, wxID_ANY, "",wxPoint(10, 50), wxSize(140, wxDefaultCoord), wxTE_PASSWORD);
	mPassword->SetHint("Don't use 12345 here");

	mLimited = new MyTextCtrl(this, wxID_ANY, "",wxPoint(10, 90), wxDefaultSize);
	mLimited->SetHint("Max 8 ch");
	mLimited->SetMaxLength(8);
	wxSize size2 = mLimited->GetSizeFromTextSize(mLimited->GetTextExtent("WWWWWWWW"));
	mLimited->SetSizeHints(size2, size2);

	wxTextCtrl* upperOnly = new MyTextCtrl(this, wxID_ANY, "Only upper case",wxDefaultPosition, wxDefaultSize);
	upperOnly->ForceUpper();

	// multi line text controls

	wxString string3L("Read only\nMultiline\nFitted size");
	mReadonly = new MyTextCtrl(this, wxID_ANY, string3L, wxPoint(10, 120), wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
	wxWindowDC dc(mReadonly);
	size2 = mReadonly->GetSizeFromTextSize(dc.GetMultiLineTextExtent(string3L));
	mReadonly->SetMinSize(size2);

	mHorizontal = new MyTextCtrl(this, wxID_ANY, "Multiline text control with a horizontal scrollbar.\n", wxPoint(10, 170), wxSize(140, 70), wxTE_MULTILINE | wxHSCROLL);
	mHorizontal->SetHint("Enter multiline text here");

	mMultiText = new MyTextCtrl(this, wxID_ANY, "Multi line without vertical scrollbar.", wxPoint(180, 10), wxSize(200, 70), wxTE_MULTILINE | wxTE_NO_VSCROLL);
	mMultiText->SetFont(*wxITALIC_FONT);

	(*mMultiText) << " Appended.";

	mMultiText->SetInsertionPoint(0);
	mMultiText->WriteText("Prepended. ");
	mMultiText->SetForegroundColour(*wxYELLOW);
	mMultiText->SetBackgroundColour(*wxLIGHT_GREY);

	mTab = new MyTextCtrl(this, 100, "Multiline, allow <TAB> processing.",	wxPoint(180, 90), wxSize(200, 70), wxTE_MULTILINE | wxTE_PROCESS_TAB);
	mTab->SetClientData(const_cast<void*>(static_cast<const void*>(wxS("tab"))));

	mEnter = new MyTextCtrl(this, 100, "Multiline, allow <ENTER> processing.",	wxPoint(180, 170), wxSize(200, 70), wxTE_MULTILINE | wxTE_PROCESS_ENTER);
	mEnter->SetClientData(const_cast<void*>(static_cast<const void*>(wxS("enter"))));

	mTextrich = new MyTextCtrl(this, wxID_ANY, "Allows more than 30Kb of text\n"
		"(on all Windows versions)\n"
		"and a very very very very very "
		"very very very long line to test "
		"wxHSCROLL style\n"
		"\nAnd here is a link in quotation marks to "
		"test wxTE_AUTO_URL: \"http://www.wxwidgets.org\"",
		wxPoint(450, 10), wxSize(200, 230),
		wxTE_RICH | wxTE_MULTILINE | wxTE_AUTO_URL);

	mTextrich->SetStyle(0, 10, *wxRED);
	mTextrich->SetStyle(10, 20, *wxBLUE);
	mTextrich->SetStyle(30, 40,wxTextAttr(*wxGREEN, wxNullColour, *wxITALIC_FONT));
	mTextrich->SetDefaultStyle(wxTextAttr());
	mTextrich->AppendText("\n\nFirst 10 characters should be in red\n");
	mTextrich->AppendText("Next 10 characters should be in blue\n");
	mTextrich->AppendText("Next 10 characters should be normal\n");
	mTextrich->AppendText("And the next 10 characters should be green and italic\n");
	mTextrich->SetDefaultStyle(wxTextAttr(*wxCYAN, *wxBLUE));
	mTextrich->AppendText("This text should be cyan on blue\n");
	mTextrich->SetDefaultStyle(wxTextAttr(*wxBLUE, *wxWHITE));
	mTextrich->AppendText("And this should be in blue and the text you type should be in blue as well.\n");
	mTextrich->SetDefaultStyle(wxTextAttr());

	wxTextAttr attr = mTextrich->GetDefaultStyle();
	attr.SetFontUnderlined(true);
	mTextrich->SetDefaultStyle(attr);
	mTextrich->AppendText("\nAnd there");
	attr.SetFontUnderlined(false);
	mTextrich->SetDefaultStyle(attr);
	mTextrich->AppendText(" is a ");
	attr.SetFontUnderlined(wxTEXT_ATTR_UNDERLINE_SPECIAL, *wxRED);
	mTextrich->SetDefaultStyle(attr);
	mTextrich->AppendText("mispeled");
	attr.SetFontUnderlined(false);
	mTextrich->SetDefaultStyle(attr);
	mTextrich->AppendText(" word.");
	attr.SetFontUnderlined(wxTEXT_ATTR_UNDERLINE_DOUBLE, *wxGREEN);
	const long endPos = mTextrich->GetLastPosition();
	mTextrich->SetStyle(endPos - 4, endPos - 2, attr);

	// lay out the controls
	wxBoxSizer *column1 = new wxBoxSizer(wxVERTICAL);
	column1->Add(mText, 0, wxALL | wxEXPAND, 10);
	column1->Add(mPassword, 0, wxALL | wxEXPAND, 10);
	column1->Add(mReadonly, 0, wxALL, 10);
	column1->Add(mLimited, 0, wxALL, 10);
	column1->Add(upperOnly, 0, wxALL, 10);
	column1->Add(mHorizontal, 1, wxALL | wxEXPAND, 10);

	wxBoxSizer *column2 = new wxBoxSizer(wxVERTICAL);
	column2->Add(mMultiText, 1, wxALL | wxEXPAND, 10);
	column2->Add(mTab, 0, wxALL | wxEXPAND, 10);
	column2->Add(mEnter, 1, wxALL | wxEXPAND, 10);

	wxBoxSizer *row1 = new wxBoxSizer(wxHORIZONTAL);
	row1->Add(column1, 0, wxALL | wxEXPAND, 10);
	row1->Add(column2, 1, wxALL | wxEXPAND, 10);
	row1->Add(mTextrich, 1, wxALL | wxEXPAND, 10);

	wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);


	topSizer->Add(row1, 2, wxALL | wxEXPAND, 10);
	topSizer->Add(mLog, 1, wxALL | wxEXPAND, 10);
	SetSizer(topSizer);
}

wxTextCtrl * MainPanel::GetFocusedText() const
{
	wxWindow* win = FindFocus();
	wxTextCtrl *text = win ? wxDynamicCast(win, wxTextCtrl) : nullptr;
		return text?text:mMultiText;
}
