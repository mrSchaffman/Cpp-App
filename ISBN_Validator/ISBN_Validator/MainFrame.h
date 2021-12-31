#pragma once
#include"wx/wx.h"
enum
{
	BTN_CLEAR = wxID_CLEAR,
	BTN_VALIDATE = wxID_OK,
	T1 = 1000,
	T2 ,
	T3 ,
	T4 ,
	EVT_LOG = 1500
};
class MainFrame:public wxFrame
{
public:
	MainFrame(const wxString& title);
	~MainFrame()= default;

	void OnValidateButtonClick(wxCommandEvent & evt);
	void OnClearButtonClick(wxCommandEvent & evt);

private:
	wxWindow* parent = nullptr;
	wxBoxSizer * topSizer = nullptr;

	DECLARE_EVENT_TABLE();
};

