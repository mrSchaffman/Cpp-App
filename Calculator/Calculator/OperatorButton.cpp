#include "OperatorButton.h"
OperatorButton::OperatorButton(wxWindow * parent, char label):CalculatorButton(parent,OperatorButtonID, label),m_parent(parent),m_label(label), m_ID(OperatorButtonID)
{
	//this->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &OperatorButton::OnOperatorButtonClick,parent);
	SetFont(this->GetFont().Scale(1.5));
	OperatorButtonID++;
}

void OperatorButton::remove(std::string & displayString)
{
	auto lastChar = displayString[displayString.length()];
	if (getLabel() == lastChar )
		displayString.pop_back();
	else
		return;

}
void OperatorButton::OnOperatorButtonClick(wxCommandEvent &evt)
{

}
char OperatorButton::getLabel() const
{
	return m_label;
}
void OperatorButton::actualizeDisplay(std::string &displayString)
{
	auto lastChar = displayString[displayString.length()];
	if (getLabel() == lastChar)
		return;
	else
		displayString.push_back(m_label);
}