#pragma once
#include "wx/wx.h"

//this wxPanel is for laying out controls 
//Because some platforms do not allow direct painting on a frame, and to
//support keyboard navigation between child controls, you should create an
//intermediate wxPanel
class MainPanel :public wxPanel
{
public:
	MainPanel(wxFrame*frame) :wxPanel(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize) {}
	virtual ~MainPanel() = default;// { delete wxLog::SetActiveTarget(mLogOld); }
	
	wxTextCtrl * mLogWindow = nullptr;

private:
	wxLog *mLogOld = nullptr;
};

