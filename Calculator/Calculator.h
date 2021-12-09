#pragma once
#include"wx/wx.h"


class Calculator: public wxApp
{
public:
	Calculator() = default;
	~Calculator() = default;

private:
	virtual bool OnInit();
};


