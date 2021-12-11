#pragma once
#include"CalculatorApp.h"

DECLARE_APP(CalculatorApp)
IMPLEMENT_APP(CalculatorApp)

bool CalculatorApp::OnInit()
{
	frame = new MainFrame(wxString("CalculatorApp"),3);
	frame->Show(true);
	return true;
}