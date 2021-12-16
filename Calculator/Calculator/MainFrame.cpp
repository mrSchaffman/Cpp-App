#include "MainFrame.h"
BEGIN_EVENT_TABLE(MainFrame, wxFrame)
  EVT_BUTTON(wxID_OK,OnOperatorButtonClick)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString&title):wxFrame(NULL,wxID_ANY,title,wxPoint(300,300),wxSize(X,Y))
{
	SetMaxSize(wxSize(X, Y));
	topSizer = new wxBoxSizer(wxVERTICAL);

	// test
	// wxButton * btn = new wxButton(this, wxID_OK, "&Ok",wxDefaultPosition, wxSize(40,40));
	
	topSizer->Fit(this);
	topSizer->SetSizeHints(this);
	SetSizer(topSizer);
}

MainFrame::MainFrame(const wxString & title, wxBoxSizer *& topSizer) :wxFrame(NULL, wxID_ANY, title, wxPoint(300, 300), wxSize(X, Y))
{
	this->topSizer = topSizer;
	
}
MainFrame::MainFrame(std::vector<wxSizer*>& sizers, size_t frameborder, wxOrientation orientation)
{
	frameSizers = sizers;
	topSizer = new  wxBoxSizer(orientation);
	for (auto& sizer : sizers)
	{
		topSizer->Add(sizer, 0, wxALL, frameborder);
	}
}
//wxGridSizer* MainFrame::addGrid(std::initializer_list<wxString> list)
//{
//	
//	wxGridSizer * grid = new wxGridSizer(5, 5,0,0);
//	for (auto& label : list)
//	{
//		FunctionButton * btn = new FunctionButton(this, label);
//		btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &OnFunctionButtonClick, this);
//		grid->Add(btn, 0, wxALL);
//	}
//	
//	return grid;
//}
//wxGridSizer* MainFrame::addGrid(const size_t column, std::vector<wxString> labelList)
//{
//	//wxGridSizer * grid = new wxGridSizer(row, column, 0, 0);
//	wxGridSizer * grid = new wxGridSizer(column); // grid with 6 columns
//	for (auto& label : labelList)
//	{
//		FunctionButton * btn = new FunctionButton(this, label);
//		btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &OnFunctionButtonClick, this);
//		grid->Add(btn, 0, wxALL);
//	}
//	return grid;
//}

void MainFrame::addGrids(std::vector<wxGridSizer*> grids)
{
	for (auto& grid : grids)
	{
		topSizer->Add(grid, 0, wxALL);
	}
}

void MainFrame::addSizers(std::vector<wxSizer*> sizers)
{
	for (auto& sizer : sizers)
	{
		topSizer->Add(sizer, 0, wxCENTER | wxBOTTOM, 3);
	}
}

void MainFrame::addLines(std::vector<wxBoxSizer*> &lines)
{
	for (auto& line : lines)
	{
		topSizer->Add(line,0,wxALL);
	}
	
}

MainFrame::~MainFrame()
{

}
	

void MainFrame::OnNumberButtonClick(wxCommandEvent &evt)
{


	//display->AppendText(wxString("${}",evt.GetId()));
}
void MainFrame::OnFunctionButtonClick(wxCommandEvent & evt)
{

}
void MainFrame::OnOperatorButtonClick(wxCommandEvent &evt)
{

	//OperatorButton::OnOperatorButtonClick(evt);

	//display->AppendText(wxString("t",evt.GetId()));
}