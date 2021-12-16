#pragma once
#include"wx/wx.h"
#include"CalculatorButton.h"
#include"OperatorButton.h"
#include"FunctionButton.h"
#include"NumberButton.h"
#include<initializer_list>

static const size_t X = 280;
static const size_t Y = 450;
static const size_t rowL2 = 4;
static const size_t columnL2 = 7;
static const size_t rowL3 = 4;
static const size_t columnL3 = 4;

class MainFrame : public wxFrame
{
public:
	wxBoxSizer *topSizer = nullptr;

	MainFrame()= default;
	MainFrame(const wxString&title,wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL),wxSize size = wxSize(280,470));
	void addGrids(std::vector<wxGridSizer*> grids);
	void addSizers(std::vector<wxSizer*> sizers);
	void addLines(std::vector<wxBoxSizer*>&lines);

	void OnFunctionButtonClick(wxCommandEvent &evt);
	void OnOperatorButtonClick(wxCommandEvent &evt);
	void OnNumberButtonClick(wxCommandEvent &evt);
	~MainFrame() = default;

private:
	
	std::vector<wxSizer*>frameSizers;
	wxSize size = wxSize(280, 470);

	wxTextCtrl * display = nullptr;

		DECLARE_EVENT_TABLE()
};	