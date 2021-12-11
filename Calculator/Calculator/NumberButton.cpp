#include "NumberButton.h"


void NumberButton::remove(std::string &displaystring)
{
	displaystring.pop_back();
}
void NumberButton::actualizeDisplay(std::string &displaystring)
{
	displaystring.push_back(m_label);
}
void NumberButton::OnNumberButtonClick(wxCommandEvent &evt)
{
	
}

NumberButton::NumberButton(wxWindow * parent, int label):CalculatorButton(parent, NumberButtonID, (char)label),m_parent(parent)
{
	//this->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &NumberButton::OnNumberButtonClick, parent);
	SetFont(this->GetFont().Scale(1.5));
	NumberButtonID++;
}
