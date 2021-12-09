#pragma once
#include"wx/wx.h"
#include"MainFrame.h"
class Calculator : public wxApp
{
public:
	Calculator() = default;
	~Calculator()= default;

private:
	bool OnInit();
	MainFrame * frame = nullptr;
};

