#pragma once
#include "CalculatorButton.h"
static size_t FunctionButtonID = 40;

class FunctionButton :public CalculatorButton
{
public:
	FunctionButton() = default;
	FunctionButton(wxWindow * parent, wxString label, wxSize size = wxSize(40, 40));
	~FunctionButton() = default;
	void OnFunctionButtonClick(wxCommandEvent &evt);
	void actualizeDisplay(std::string &displayString)override;

private:
	wxString m_label;
	wxWindow * m_parent = nullptr;
	//wxSize size =  wxSize(50,50);
};

