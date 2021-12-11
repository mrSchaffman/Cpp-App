#pragma once
#include"wx/wx.h"
#include"MainFrame.h"
class CalculatorApp : public wxApp
{
public:
	CalculatorApp() = default;
	~CalculatorApp()= default;

private:
	bool OnInit();
	MainFrame * frame = nullptr;
};

