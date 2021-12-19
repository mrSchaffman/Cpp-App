#pragma once
#include"wx/wx.h"
#include"MainFrame.h"

class WindowsApp : public wxApp
{
public:

private:
	MainFrame * frame = nullptr;
	virtual bool OnInit()override;
	
};

