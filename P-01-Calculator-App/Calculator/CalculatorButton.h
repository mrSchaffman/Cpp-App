#pragma once
#include"wx/wx.h"

static const size_t kDefaultWidth = 50;
static const size_t kDefaultHeight = 50;
static size_t CalculatorButtonID = 10;



class CalculatorButton : public wxButton
{
public:
	
	

	virtual void OnButtonClick();
	virtual void setLabel(wxString label);
	virtual void setParent(wxWindow* & parent);
	virtual void actualizeDisplay(std::string & string) { string.append(m_label); }

	CalculatorButton() = default;
	CalculatorButton(wxWindow * parent,size_t ID, wxString label, wxSize size = wxSize(kDefaultWidth, kDefaultHeight));
	virtual ~CalculatorButton() = default;
private:

	wxString m_label;
	wxWindow * m_parent = nullptr;
	
	//const char* wxStringToChar(const wxString &label);
};

