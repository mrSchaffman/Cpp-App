#pragma once
#include<wx/wx.h>
#include"MainFrame.h"

class App: public wxApp
{
public:
	App() = default;
	~App() = default;
private:
	virtual bool OnInit()wxOVERRIDE;
	MainFrame* frame = nullptr;
};

