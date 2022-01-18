#pragma once
#include "CalculatorButton.h"
static size_t OperatorButtonID = 30;
class OperatorButton :public CalculatorButton
{
public:
	OperatorButton(wxWindow * parent,char label, wxSize size = wxSize(50, 50));
	void remove(std::string & displayString);
	void actualizeDisplay(std::string &displayString)override;
	void OnOperatorButtonClick(wxCommandEvent &evt);
	char getLabel() const;
	virtual ~OperatorButton() = default;
private:
	char m_label;
	size_t m_ID;
	wxWindow * m_parent = nullptr;
};

