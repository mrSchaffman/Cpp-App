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
	wxBoxSizer* line1 = nullptr;
	wxBoxSizer* line2 = nullptr;
	std::vector<wxSizer*> sizers;
};

