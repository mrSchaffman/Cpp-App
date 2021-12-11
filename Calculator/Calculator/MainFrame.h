#pragma once
#include"wx/wx.h"
static const size_t X = 300;
static const size_t Y = 500;
static const size_t rowL2 = 4;
static const size_t columnL2 = 7;
static const size_t rowL3 = 4;
static const size_t columnL3 = 4;

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString&title);
	~MainFrame();

private:
	wxBoxSizer *topSizer = nullptr;

	wxTextCtrl * display = nullptr;

	wxBoxSizer * line0 = nullptr;

	wxBoxSizer * line1 = nullptr;

	wxGridSizer * line2 = nullptr;
	wxButton** btnsLine2 = nullptr;

	wxBoxSizer * line3 = nullptr;
	wxGridSizer * line3_1 = nullptr;
	wxButton** btnsLine3_1 = nullptr;
	wxBoxSizer * line3_2 = nullptr;

	std::vector<wxSizer*>frameSizers;

	std::vector<wxString> labelsLine2;
	std::vector<wxString> labelsLine3_1;
	std::vector<wxString> labelsLine3_2;

	void OnButtonOperatorClick(wxCommandEvent &evt);
	void OnButtonNumberClick(wxCommandEvent &evt);

	std::vector<wxOrientation>orientation;
		DECLARE_EVENT_TABLE()
	};	