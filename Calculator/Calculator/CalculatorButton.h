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
	virtual void setWidth(size_t width);
	virtual void setParent(wxWindow* & parent);
	virtual void setHeight(size_t height);
	virtual void actualizeDisplay(std::string & string) { string.append(m_label); }
	virtual size_t getWidth()const { return m_Width; }
	virtual size_t getHeight()const { return m_Height; }

	CalculatorButton() = default;
	CalculatorButton(wxWindow * parent,size_t ID, wxString label, size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	virtual ~CalculatorButton() = default;
private:
	size_t m_Width;
	size_t m_Height;
	wxString m_label;
	wxWindow * m_parent = nullptr;
	
	//const char* wxStringToChar(const wxString &label);
};

