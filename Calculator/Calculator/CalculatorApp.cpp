#pragma once
#include"CalculatorApp.h"

DECLARE_APP(CalculatorApp)
IMPLEMENT_APP(CalculatorApp)

bool CalculatorApp::OnInit()
{
	//
	frame = new MainFrame(wxString("CalculatorApp"));
	wxBoxSizer * topSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer * line = new wxBoxSizer(wxHORIZONTAL);


	frame->topSizer->Add(line, 0, wxALL);
	
	frame->Show(true);
	return true;
}