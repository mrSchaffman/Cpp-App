#pragma once
#include"Calculator.h"

DECLARE_APP(Calculator)
IMPLEMENT_APP(Calculator)

bool Calculator::OnInit()
{
	frame = new MainFrame(wxString("Calculator"));
	frame->Show(true);
	return true;
}