#include "CalculatorButton.h"
//char* CalculatorButton::wxStringToChar(const wxString &label)
//{
//	char *chrs = label.ToStdString();
//}
void CalculatorButton::OnButtonClick()
{

}
void CalculatorButton::setLabel(wxString label)
{
	m_label = label;
}

void CalculatorButton::setParent(wxWindow *& parent)
{
	m_parent = parent;
}

CalculatorButton::CalculatorButton(wxWindow * parent, size_t ID, wxString label, wxSize size):wxButton(parent,ID,label,wxDefaultPosition, size)
{
	setParent( parent);
	setLabel(label);
	
}


