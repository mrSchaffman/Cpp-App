#pragma once
#include"wx/wx.h"

class MainFrame: public wxFrame
{
public:
	MainFrame() = default;
	~MainFrame() = default;
	//prevent assigment and pass-by-value
	MainFrame(const MainFrame& src) = delete;
	MainFrame& operator=(const MainFrame& src) = delete;

	//explicitly default a move-ctor and move assigment operator
	MainFrame(MainFrame&& src) = default;
	MainFrame& operator=(MainFrame&& src) = default;

	//Client can give a hint as to the number of expected sizer for increase efficiency
	MainFrame(wxString title,wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL),size_t numOfROws = 2);

	void addSizers(std::vector<wxSizer*>& sizers);

private:
	
	wxBoxSizer * m_topSizer = nullptr;
	std::vector<wxSizer*> m_sizers;
	typename std::vector<wxSizer*>::iterator m_currentSizer;

	DECLARE_EVENT_TABLE();

	void OnBackwardBtnClick(wxCommandEvent & evt);
	void OnHomeBtnClick(wxCommandEvent & evt);
	void OnForwardBtnClick(wxCommandEvent & evt);
	void OnRefreshBtnClick(wxCommandEvent & evt);
	void OnSaveBtnClick(wxCommandEvent & evt);
	void OnSearchBtnClick(wxCommandEvent & evt);
};

