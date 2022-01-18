#pragma once
#include"wx/wx.h"
#include"DVDListCtrl.h"
enum {
	BTN_CLOSE = wxID_CLOSE,
	BTN_CANCEL = wxID_CANCEL
};

enum {
	LIST_LIST_VIEW = wxID_VIEW_LIST,
	LIST_REPORT_VIEW,
	LIST_GOTO,
	LIST_FOCUS_LAST,
	LIST_SET_FG_COL,
	LIST_SET_BG_COL,
	LIST_QUIT
};
class MainFrame: public wxFrame
{
public:
	MainFrame() = default;
	virtual~MainFrame() = default;
	//prevent assigment and pass-by-value
	MainFrame(const MainFrame& src) = delete;
	MainFrame& operator=(const MainFrame& src) = delete;

	//explicitly default a move-ctor and move assigment operator
	MainFrame(MainFrame&& src) = default;
	MainFrame& operator=(MainFrame&& src) = default;

	//Client can give a hint as to the number of expected sizer for increase efficiency
	MainFrame(const wxString& title,wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL),size_t numOfROws = 2);

	void addSizers(std::vector<wxSizer*>& sizers);
	
	wxPanel * m_panel = nullptr;
	wxBoxSizer * m_topSizer = nullptr;
	DVDListCtrl * m_dvdListCtrl = nullptr;
	wxTextCtrl* m_logWindow = nullptr;
private:
	// number of items to initialize list
	size_t m_numOfItems = 2;
	wxLog * m_log = nullptr;

	
	std::vector<wxSizer*> m_sizers;
	typename std::vector<wxSizer*>::iterator m_currentSizer;

	void creatFirstSizer(wxBoxSizer*& sizer);
	void creatSecondSizer(wxPanel *& panel, wxGridSizer*& sizer);
	void creatThirdSizer(wxPanel *& panel, wxBoxSizer*& sizer);
	void creatLastSizer(wxPanel *& panel,wxBoxSizer*& sizer);

	// recreate the list control with the new flags
	void RecreateList(long flags, bool withText = true);
	void InitWithListItems();
	DECLARE_EVENT_TABLE();

	void OnBackwardBtnClick(wxCommandEvent & evt);
	void OnHomeBtnClick(wxCommandEvent & evt);
	void OnForwardBtnClick(wxCommandEvent & evt);
	void OnRefreshBtnClick(wxCommandEvent & evt);
	void OnSaveBtnClick(wxCommandEvent & evt);
	void OnSearchBtnClick(wxCommandEvent & evt);
};

