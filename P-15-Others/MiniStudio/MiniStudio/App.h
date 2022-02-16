#pragma once
#include"wx/wx.h"
#include "resource.h"
class App : public wxApp
{
public:
	App()=default;
	virtual~App() = default;

	bool OnInit()override;
private:

};

