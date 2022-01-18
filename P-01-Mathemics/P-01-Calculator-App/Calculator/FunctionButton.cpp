#include "FunctionButton.h"
FunctionButton::FunctionButton(wxWindow * parent ,wxString label, wxSize size):CalculatorButton(parent,FunctionButtonID, label, size),m_parent(parent),m_label(label)
{
	//this->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FunctionButton::OnFunctionButtonClick,parent);
	SetFont(this->GetFont().Scale(1.2));
	FunctionButtonID++;
}

void FunctionButton::actualizeDisplay(std::string &displayString)
{

}

void FunctionButton::OnFunctionButtonClick(wxCommandEvent &evt)
{

}
