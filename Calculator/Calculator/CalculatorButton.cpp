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

void CalculatorButton::setWidth(size_t width)
{
	m_Width = width;
}
void CalculatorButton::setParent(wxWindow *& parent)
{
	m_parent = parent;
}
void CalculatorButton::setHeight(size_t height)
{
	m_Height = height;
}

CalculatorButton::CalculatorButton(wxWindow * parent, size_t ID, wxString label, size_t width, size_t height):wxButton(parent,ID,label,wxDefaultPosition,wxSize(width,height))
{
	setParent( parent);
	setHeight( height);
	setWidth(width);
	setLabel(label);
	
}


