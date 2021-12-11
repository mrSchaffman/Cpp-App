#include "FunctionButton.h"
FunctionButton::FunctionButton(wxWindow * parent ,wxString label):CalculatorButton(parent,FunctionButtonID, label,40,40),m_parent(parent),m_label(label)
{
	//this->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FunctionButton::OnFunctionButtonClick,parent);
	SetFont(this->GetFont().Scale(1.5));
	FunctionButtonID++;
}

void FunctionButton::actualizeDisplay(std::string &displayString)
{

}

void FunctionButton::OnFunctionButtonClick(wxCommandEvent &evt)
{

}
