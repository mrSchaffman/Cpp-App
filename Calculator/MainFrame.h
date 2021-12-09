#pragma once
#include"wx/wx.h"

enum btn_Id
{
	bt0 = 0,
	bt1,
	bt2,
	bt3,
	bt4,
	bt5,
	bt6,
	bt7,
	bt8,
	bt9,
	btMulti,
	btPlus,
	btMinus,
	btEqual,
	btVirgul,
	btDivision,
	btX,
};
class MainFrame: public wxFrame
{
public:
	MainFrame(const wxString& title);
	~MainFrame();
	void OnButtonClick(wxCommandEvent &evt);

private:
	btn_Id btn_ID;
	wxTextCtrl * txt1 = nullptr;
	std::string cString;// = nullptr;
	//std::string cString;
	DECLARE_EVENT_TABLE()
};

