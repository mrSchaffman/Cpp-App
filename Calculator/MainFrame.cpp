#include "MainFrame.h"
#include<memory>

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(0,MainFrame::OnButtonClick)
	EVT_BUTTON(1,MainFrame::OnButtonClick)
	EVT_BUTTON(2,MainFrame::OnButtonClick)
	EVT_BUTTON(3,MainFrame::OnButtonClick)
	EVT_BUTTON(4,MainFrame::OnButtonClick)
	EVT_BUTTON(5,MainFrame::OnButtonClick)
	EVT_BUTTON(6,MainFrame::OnButtonClick)
	EVT_BUTTON(7,MainFrame::OnButtonClick)
	EVT_BUTTON(8,MainFrame::OnButtonClick)
	EVT_BUTTON(9,MainFrame::OnButtonClick)
	EVT_BUTTON(10,MainFrame::OnButtonClick)
	EVT_BUTTON(11,MainFrame::OnButtonClick)
	EVT_BUTTON(12,MainFrame::OnButtonClick)
	EVT_BUTTON(13,MainFrame::OnButtonClick)
	EVT_BUTTON(14,MainFrame::OnButtonClick)
	EVT_BUTTON(15,MainFrame::OnButtonClick)
	EVT_BUTTON(16,MainFrame::OnButtonClick)
	EVT_BUTTON(17,MainFrame::OnButtonClick)

END_EVENT_TABLE()
MainFrame::MainFrame(const wxString& title):wxFrame(NULL,wxID_ANY,title,wxDefaultPosition, wxDefaultSize,wxDEFAULT_FRAME_STYLE)
{
	SetMaxSize(wxSize(300,390));
	wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *btnLineSizer = new wxBoxSizer(wxVERTICAL);
	cString = "";
	

	txt1 = new wxTextCtrl(this, 1001,wxEmptyString, wxDefaultPosition, wxSize(250, 50), wxTE_NO_VSCROLL|wxTE_RIGHT |wxTE_WORDWRAP);
	txt1->SetFont(txt1->GetFont().Scale(2.5));
	txt1->SetEditable(false);

	// creating the buttons
	wxButton * bt0 = new wxButton(this, 0, "0",wxDefaultPosition,wxSize(40,50));
	wxButton * bt1 = new wxButton(this, 1, "1",wxDefaultPosition,wxSize(40,50));
	wxButton * bt2 = new wxButton(this, 2, "2",wxDefaultPosition,wxSize(40,50));
	wxButton * bt3 = new wxButton(this, 3, "3",wxDefaultPosition,wxSize(40,50));
	wxButton * bt4 = new wxButton(this, 4, "4",wxDefaultPosition,wxSize(40,50));
	wxButton * bt5 = new wxButton(this, 5, "5",wxDefaultPosition,wxSize(40,50));
	wxButton * bt6 = new wxButton(this, 6, "6",wxDefaultPosition,wxSize(40,50));
	wxButton * bt7 = new wxButton(this, 7, "7",wxDefaultPosition,wxSize(40,50));
	wxButton * bt8 = new wxButton(this, 8, "8",wxDefaultPosition,wxSize(40,50));
	wxButton * bt9 = new wxButton(this, 9, "9",wxDefaultPosition,wxSize(40,50));
	wxButton * btMulti = new wxButton(this, 10, "*",wxDefaultPosition,wxSize(40,50));
	wxButton * btPlus = new wxButton(this, 11, "+",wxDefaultPosition,wxSize(40,50));
	wxButton * btMinus = new wxButton(this, 12, "-",wxDefaultPosition,wxSize(40,50));
	wxButton * btDivision = new wxButton(this, 13, "/", wxDefaultPosition, wxSize(40, 50));
	wxButton * btVirgul = new wxButton(this, 14, ".",wxDefaultPosition,wxSize(40,50));
	wxButton * btX = new wxButton(this, 15, "+/-",wxDefaultPosition,wxSize(40,50));
	wxButton * btCe = new wxButton(this, 16, "CE",wxDefaultPosition,wxSize(40,50));
	wxButton * btEqual = new wxButton(this, 17, "=", wxDefaultPosition, wxDefaultSize);


	bt0->SetFont(bt0->GetFont().Scale(2));
	bt1->SetFont(bt1->GetFont().Scale(2));
	bt2->SetFont(bt2->GetFont().Scale(2));
	bt3->SetFont(bt3->GetFont().Scale(2));
	bt4->SetFont(bt4->GetFont().Scale(2));
	bt5->SetFont(bt5->GetFont().Scale(2));
	bt6->SetFont(bt6->GetFont().Scale(2));
	bt7->SetFont(bt7->GetFont().Scale(2));
	bt8->SetFont(bt8->GetFont().Scale(2));
	bt9->SetFont(bt9->GetFont().Scale(2));
	btMulti->SetFont(btMulti->GetFont().Scale(2));
	btPlus->SetFont(btPlus->GetFont().Scale(2));
	btMinus->SetFont(btMinus->GetFont().Scale(2));
	btEqual->SetFont(btEqual->GetFont().Scale(2));
	btVirgul->SetFont(btVirgul->GetFont().Scale(2));
	btDivision->SetFont(btDivision->GetFont().Scale(2));
	btX->SetFont(btX->GetFont().Scale(2));
	btCe->SetFont(btCe->GetFont().Scale(2));

	

	//creating the 4 Line for the Buttons
	wxBoxSizer *line1Sizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *line2Sizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *line3Sizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *line4Sizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *line5Sizer = new wxBoxSizer(wxHORIZONTAL);


	// creating the lines of buttons
	//Line 1
	line1Sizer->Add(bt7, 1, wxEXPAND | wxALL, 0);
	line1Sizer->Add(bt8, 1, wxEXPAND | wxALL, 0);
	line1Sizer->Add(bt9, 1, wxEXPAND | wxALL, 0);
	line1Sizer->Add(btDivision, 1, wxEXPAND | wxALL, 0);

	//Line 2
	line2Sizer->Add(bt4, 1, wxEXPAND | wxALL, 0);
	line2Sizer->Add(bt5, 1, wxEXPAND | wxALL, 0);
	line2Sizer->Add(bt6, 1, wxEXPAND | wxALL, 0);
	line2Sizer->Add(btMulti, 1, wxEXPAND | wxALL, 0);

	//Line 3
	line3Sizer->Add(bt1, 1, wxEXPAND | wxALL, 0);
	line3Sizer->Add(bt2, 1, wxEXPAND | wxALL, 0);
	line3Sizer->Add(bt3, 1, wxEXPAND | wxALL, 0);
	line3Sizer->Add(btMinus, 1, wxEXPAND | wxALL, 0);
	

	//Line 4
	line4Sizer->Add(bt0, 1, wxEXPAND | wxALL, 0);
	line4Sizer->Add(btVirgul, 1, wxEXPAND | wxALL, 0);
	line4Sizer->Add(btX, 1, wxEXPAND | wxALL, 0);
	line4Sizer->Add(btPlus, 1, wxEXPAND | wxALL, 0);

	//Line 5
	line5Sizer->Add(btCe, 0, wxEXPAND | wxALL, 0);
	line5Sizer->Add(btEqual,1, wxEXPAND | wxALL, 0);
	

	btnLineSizer->Add(line1Sizer, 1, wxEXPAND | wxALL, 0);
	btnLineSizer->Add(line2Sizer, 1, wxEXPAND | wxALL, 0);
	btnLineSizer->Add(line3Sizer, 1, wxEXPAND | wxALL, 0);
	btnLineSizer->Add(line4Sizer, 1, wxEXPAND | wxALL, 0);
	btnLineSizer->Add(line5Sizer, 1, wxEXPAND | wxALL, 0);

	topSizer->Add(txt1, 0, wxEXPAND | wxALL, 10);
	topSizer->Add(btnLineSizer, 1, wxEXPAND | wxALL, 10);

	SetSizer(topSizer);

	topSizer->Fit(this);
	topSizer->SetSizeHints(this);
};
MainFrame::~MainFrame()
{

}
void MainFrame::OnButtonClick(wxCommandEvent &evt)
{
	
	int btnValue = evt.GetId();


	switch (btnValue)
	{
	case 0:
		if (txt1->IsEmpty() && btnValue == 0)
			break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		cString.append( std::to_string(btnValue));
		break;
	case 10:
		if (cString.back() == '*' || cString.back() == '+' || cString.back() == '/' || cString.back() == '-')
			return;
	
		cString.append("*");
		break;
	case 11:
		if (cString.back() == '*' || cString.back() == '+' || cString.back() == '/' || cString.back() == '-')
			return;
		
		cString.append("+");

		break;
	case 12:
		if (cString.back() == '*' || cString.back() == '+' || cString.back() == '/' || cString.back() == '-')
	    	return;
		
		cString.append("-");
		break;
	case 13:
		if (cString.back() == '*' || cString.back() == '+' || cString.back() == '/' || cString.back() == '-')
			return;
		
		cString.append("/");
			
		break;
	case 14:
		if (cString.back() == '.' || cString.back() == '*' || cString.back() == '+' || cString.back() == '/' || cString.back() == '-')
			return;
		
		cString.append(".");
		
		break;
	case 15:
		if (cString.back() == ' ')
			return;
		
		//+/-
		break;
	case 16:
		cString.pop_back();
		break;
	case 17:
		// =
		break;
	default:
		break;
	}
	
	txt1->SetLabelText(cString);
}