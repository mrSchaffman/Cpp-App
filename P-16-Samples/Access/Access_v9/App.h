#pragma once
#include"wx/wx.h"
#include"MainFrame.h"


class App: public wxApp
{
public:
	App() = default;
	virtual~App() = default;

	bool OnInit();

private:
};

