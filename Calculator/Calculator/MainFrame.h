#pragma once
#include"wx/wx.h"
#include"CalculatorButton.h"
#include"OperatorButton.h"
#include"FunctionButton.h"
#include"NumberButton.h"
#include<initializer_list>

static const size_t X = 280;
static const size_t Y = 500;
static const size_t rowL2 = 4;
static const size_t columnL2 = 7;
static const size_t rowL3 = 4;
static const size_t columnL3 = 4;

class MainFrame : public wxFrame
{
public:
	wxBoxSizer *topSizer = nullptr;

	MainFrame(const wxString&title);
	MainFrame(const wxString&title,wxBoxSizer*& topSizer);
	MainFrame(std::vector<wxSizer*>&sizers, size_t Frameborder, wxOrientation orientation = wxVERTICAL);
	void addGrids(std::vector<wxGridSizer*> grids);
	void addSizers(std::vector<wxSizer*> sizers);
	void addLines(std::vector<wxBoxSizer*>&lines);

	void OnFunctionButtonClick(wxCommandEvent &evt);
	~MainFrame();

private:
	
	std::vector<wxSizer*>frameSizers;

	void OnOperatorButtonClick(wxCommandEvent &evt);
	void OnNumberButtonClick(wxCommandEvent &evt);
	

		DECLARE_EVENT_TABLE()
	};	