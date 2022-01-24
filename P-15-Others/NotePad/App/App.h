#pragma once

#include"wx/wx.h"
#include"MainFrame.h"
class App : public wxApp
{
public:
	App() = default;
	virtual ~App() = default;


	virtual bool OnInit() override;
private:
	MainFrame * m_frame = nullptr;
	//MainPanel * m_panel = nullptr;
};
