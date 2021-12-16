#pragma once
#include"CalculatorApp.h"

DECLARE_APP(CalculatorApp)
IMPLEMENT_APP(CalculatorApp)

bool CalculatorApp::OnInit()
{
	//
	frame = new MainFrame(wxString("CalculatorApp"));

	auto numberGrid = std::make_unique<wxGridSizer>(4, 4, 1, 1);
	auto operatorBox = std::make_unique<wxBoxSizer>(wxVERTICAL);
	auto operatorBoxEqual = std::make_unique<wxBoxSizer>(wxVERTICAL);

	std::vector<wxSizer*> sizers = { new wxBoxSizer(wxHORIZONTAL),new wxGridSizer(3,6,1,1),new wxBoxSizer(wxHORIZONTAL) };
	std::vector<wxSizer*> Line3 = {new wxBoxSizer(wxVERTICAL),new wxBoxSizer(wxVERTICAL) };
	std::vector<wxString> labelLine1 = { "CE","DRG","2ndF","OFF","ON/C" };
	std::vector<wxString> labelLine2 = { "EXP","y^x","rac",">Deg","ln","log","hyp","sin","cos","tan","(",")","->","a","b","x^2","F-E","x->M" };
	std::vector<wxChar> labelLine3 = { '7','8','9','6','5','6','1','2','3','0' };

	for (auto label : labelLine1)
	{
		FunctionButton * btn = new FunctionButton(frame, label);
		//btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &frame->OnFunctionButtonClick, frame);
		sizers[0]->Add(btn,wxALL,2);
	}
	for (auto label : labelLine2)
	{
		sizers[1]->Add(new FunctionButton(frame, label),wxALL,2);
	}
	for (auto label : labelLine3)
	{
	    //numberGrid[0]->Add(new NumberButton(frame, label),wxALL,2);
	}
	for (size_t x = 0; x < 4; x++)
	{
		for (size_t y = 0; y < 4; y++)
		{
			numberGrid[y*4+x]->Add(new NumberButton(frame, labelLine3[y*4+x]), wxALL, 2);
		}
	}
	//sizers[2]->Add(
	//new wxBoxSizer(wxHORIZONTAL)->Add()
	//);
	frame->addSizers(sizers);	
	frame->Show(true);
	return true;
}