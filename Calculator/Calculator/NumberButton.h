#pragma once
#include "CalculatorButton.h"

static size_t NumberButtonID = 20;

class NumberButton :public CalculatorButton
{
public:
	void remove(std::string & displaystring);
	void OnNumberButtonClick(wxCommandEvent &evt);
	void actualizeDisplay(std::string &displaystring)override;

	NumberButton() = default;
	NumberButton(wxWindow * parent,wxChar label ,wxSize size = wxSize(50, 50));
	~NumberButton() = default;
private:
	wxChar m_label;
	wxWindow * m_parent = nullptr;
	
};

