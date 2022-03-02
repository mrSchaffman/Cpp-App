#pragma once
#include"wx/splitter.h"
#include"wx/wx.h"
#include"wx/listCtrl.h"
#include"FileTreeCtrl.h"

class SplitterItemWin: public wxSplitterWindow
{

public:
	SplitterItemWin() = default;
	SplitterItemWin(wxWindow*parent);
	virtual~SplitterItemWin() = default;
private:
	//FileTreeCtrl * m_tree1 = nullptr;
	//FileTreeCtrl * m_tree2 = nullptr;
	wxDECLARE_EVENT_TABLE();


};

