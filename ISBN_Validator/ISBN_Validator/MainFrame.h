#pragma once
#include"wx/wx.h"
enum 
{
	BTN_CLEAR = wxID_CLEAR,
	BTN_VALIDATE = wxID_OK
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

