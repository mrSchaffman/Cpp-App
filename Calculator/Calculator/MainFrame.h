#pragma once
#include"wx/wx.h"
static const size_t X = 300;
static const size_t Y = 500;

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString&title);
	~MainFrame();

private:
	size_t row1 = 3;
	size_t column1 = 6;
	size_t row2 = 4;
	size_t column2 = 4;
	wxButton **btns = nullptr;
	wxBoxSizer * topSizer = nullptr;
	wxTextCtrl * display = nullptr;

	wxBoxSizer * firstSizer = nullptr;
	wxGridSizer * secondSizer = nullptr;
	wxBoxSizer * thirdSizer = nullptr;
	std::vector<wxString> labels;
	std::vector<wxString> labels2;

	void SetFrameSizer(wxBoxSizer * sizer);
	void SetDisplay(wxTextCtrl * display);
	void SetBoxSizer(wxBoxSizer * sizer, wxOrientation orientation);
	DECLARE_EVENT_TABLE()
};

