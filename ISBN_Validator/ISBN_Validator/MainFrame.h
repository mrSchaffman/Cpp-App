#pragma once
#include"wx/wx.h"
#include"NumberTextCtrl.h"
#include<memory>
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
	wxBoxSizer * m_topSizer = nullptr;

	std::unique_ptr<wxString> m_ISBN;

	wxString *m_isbn = nullptr;

	NumberTextCtrl* m_t1 = nullptr;
	NumberTextCtrl* m_t2 = nullptr;
	NumberTextCtrl* m_t3 = nullptr;
	NumberTextCtrl* m_t4 = nullptr;

	wxTextCtrl* m_evtLog = nullptr;
	wxLog *m_LogOld = nullptr;

	DECLARE_EVENT_TABLE();
};

