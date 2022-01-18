#pragma once
#include"wx/wx.h"
#include"MainFrame.h"

class MusicApp : public wxApp
{
public:
	MusicApp() = default;
	~MusicApp() = default;

private:

	virtual bool OnInit()override;
	MainFrame * m_frame = nullptr;

};
