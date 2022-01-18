#pragma once
#include"wx/wx.h"
#include"MainFrame.h"
class BrowserApp :public wxApp
{
public:
	
	BrowserApp() = default;
	~BrowserApp() = default;
private:
	virtual bool OnInit()override;
	MainFrame * frame = nullptr;
	std::vector<wxSizer*> sizers;
};

