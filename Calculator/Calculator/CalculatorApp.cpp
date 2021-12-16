#pragma once
#include"CalculatorApp.h"

DECLARE_APP(CalculatorApp)
IMPLEMENT_APP(CalculatorApp)

bool CalculatorApp::OnInit()
{
	//
	frame = new MainFrame(wxString("CalculatorApp"));



	std::vector<wxSizer*> sizers = { new wxBoxSizer(wxHORIZONTAL), new wxBoxSizer(wxHORIZONTAL),new wxGridSizer(3,6,1,1) };
	std::vector<wxSizer*> Line3 = {new wxBoxSizer(wxVERTICAL),new wxBoxSizer(wxVERTICAL) };
	std::vector<wxString> labelLine1 = { "CE","DRG","2ndF","OFF","ON/C" };
	std::vector<wxString> labelLine2 = { "EXP","y^x","rac",">Deg","ln","log","hyp","sin","cos","tan","(",")","->","a","b","x^2","F-E","x->M" };
	std::vector<wxChar> labelLine3 = { '7','8','9','6','5','6','1','2','3','0' };
	std::vector<wxChar> labelLine4 = { '/','*','-','+' };


	wxGridSizer *numberGrid = new wxGridSizer(4, 3, 1, 1);
	wxBoxSizer* operatorBox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* operatorBoxEqual = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* line3 = new wxBoxSizer(wxHORIZONTAL);

	line3->Add(numberGrid,0, wxRIGHT, 2);
	line3->Add(operatorBox,0, wxRIGHT, 2);
	line3->Add(operatorBoxEqual,0, wxALL);
	for (auto label : labelLine3)
	{
		numberGrid->Add(new NumberButton(frame, label),0, wxALL);
	}
	numberGrid->Add(new FunctionButton(frame, ".", wxSize(50, 50)), 0, wxALL);
	numberGrid->Add(new FunctionButton(frame, "+/-", wxSize(50, 50)), 0, wxALL);
	for (auto label : labelLine4)
	{
		operatorBox->Add(new OperatorButton(frame, label),0, wxCENTER);
	}
	operatorBoxEqual->Add(new FunctionButton(frame, "MR",wxSize(50, 50)),0, wxCENTER);
	operatorBoxEqual->Add(new FunctionButton(frame, "M+", wxSize(50, 50)),0, wxCENTER);
	FunctionButton *eqaulBtn = new FunctionButton(frame, "=",wxSize(50,100));
	eqaulBtn->SetFont(eqaulBtn->GetFont().Scale(2));
	operatorBoxEqual->Add(eqaulBtn,0, wxCENTER);

	sizers.push_back(line3);

	for (auto label : labelLine1)
	{
		FunctionButton * btn = new FunctionButton(frame, label,wxSize(50,40));
		//btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &frame->OnFunctionButtonClick, frame);
		sizers[1]->Add(btn,0, wxCENTER);
	}
	for (auto label : labelLine2)
	{
		sizers[2]->Add(new FunctionButton(frame, label),0, wxALL,1);
	}
	sizers[0]->Add(new wxTextCtrl(frame, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(260, 50)));
	
	
	frame->addSizers(sizers);	
	frame->Show(true);
	return true;
}