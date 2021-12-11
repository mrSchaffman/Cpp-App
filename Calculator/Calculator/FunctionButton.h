#pragma once
#include "CalculatorButton.h"
static size_t FunctionButtonID = 40;

class FunctionButton :public CalculatorButton
{
public:
	FunctionButton() = default;
	FunctionButton(wxWindow * parent,wxString label);
	~FunctionButton() = default;
	void OnFunctionButtonClick(wxCommandEvent &evt);
	void actualizeDisplay(std::string &displayString)override;

private:
	wxString m_label;
	wxWindow * m_parent = nullptr;
};

