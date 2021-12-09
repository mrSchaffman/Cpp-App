#include "MainFrame.h"
BEGIN_EVENT_TABLE(MainFrame, wxFrame)

END_EVENT_TABLE()
MainFrame::MainFrame(const wxString&title):wxFrame(NULL,wxID_ANY,title,wxPoint(300,300),wxSize(X,Y))
{
	SetMaxSize(wxSize(X, Y));
	labels = { "EXP","hyp","->","y^x","sin","a","Rac","cos","b","DEG","tan","x^2","Ln","(","F-E","log",")","x-M" };
	labels2 = { "7","4","1","0","8","5","2",".","9","6","3","+/-","/","X","-","+" };
	topSizer = new wxBoxSizer(wxVERTICAL);

	//SetFrameSizer(topSizer);
	//SetDisplay(display);
	//SetBoxSizer(firstSizer, wxHORIZONTAL);
	display = new wxTextCtrl(this, 1001, wxEmptyString, wxPoint(10, 10), wxSize(250, 40), wxTE_RIGHT | wxTE_WORDWRAP);
	display->SetEditable(false);
	display->SetFont(GetFont().Scale(2));
	
	
	firstSizer = new wxBoxSizer(wxHORIZONTAL);
	wxButton *btnCE = new wxButton(this, 1002, "CE", wxDefaultPosition, wxSize(40, 40));
	wxButton *btnDGR = new wxButton(this, 1003, "DGR", wxDefaultPosition, wxSize(40, 40));
	wxButton *btn2nd = new wxButton(this, 1004, "2nd", wxDefaultPosition, wxSize(60, 40));
	wxButton *btnOFF = new wxButton(this, 1005, "OFF", wxDefaultPosition, wxSize(40, 40));
	wxButton *btnON = new wxButton(this, 1006, "ON", wxDefaultPosition, wxSize(40, 40));
	firstSizer->Add(btnCE, 0,   wxALL,5);
	firstSizer->Add(btnDGR, 0,  wxALL,5);
	firstSizer->Add(btn2nd, 0, wxALL, 5);
	firstSizer->Add(btnOFF, 0,  wxALL,5);
	firstSizer->Add(btnON, 0,  wxALL,5);
	firstSizer->Fit(this);

	btns = new wxButton*[row1*column1];
	secondSizer = new wxGridSizer(3, 6, 5, 5);

	
	
		for (size_t x = 0; x < row1; x++)
		{
			for (size_t y = 0; y < column1; y++)
			{

				btns[y*row1 + x] = new wxButton(this, 1007 + (y*row1 + x), labels[y*row1 + x], wxDefaultPosition, wxSize(50, 35));
				btns[y*row1 + x]->SetFont(GetFont().Scale(1.5));
				secondSizer->Add(btns[y*row1 + x], 0, wxEXPAND | wxALL);


			}
		}
	
		thirdSizer = new wxBoxSizer(wxHORIZONTAL);
		wxGridSizer * grid2 = new wxGridSizer(4, 4, 5, 5);
		for (size_t x = 0; x < row2; x++)
		{
			for (size_t y = 0; y < column2; y++)
			{

				btns[y*row2 + x] = new wxButton(this, 1007 + (y*row2 + x), labels2[y*row2 + x], wxDefaultPosition, wxSize(50, 50));
				btns[y*row2 + x]->SetFont(GetFont().Scale(2));
				grid2->Add(btns[y*row2 + x], 0, wxEXPAND | wxALL);

			}
		}
		wxBoxSizer * box = new wxBoxSizer(wxVERTICAL);
		wxButton *btnMR = new wxButton(this, 1002, "MR", wxDefaultPosition, wxSize(50, 50));
		wxButton *btnMplus = new wxButton(this, 1002, "M+", wxDefaultPosition, wxSize(50, 50));
		wxButton *btnEqual = new wxButton(this, 1002, "=", wxDefaultPosition, wxSize(50, 90));
		btnMR->SetFont(GetFont().Scale(2));
		btnMplus->SetFont(GetFont().Scale(2));
		btnEqual->SetFont(GetFont().Scale(2));

		box->Add(btnMR, 0, wxBOTTOM,5);
		box->Add(btnMplus, 0, wxBOTTOM, 5);
		box->Add(btnEqual, 0, wxALL);

		thirdSizer->Add(grid2, 0, wxALL);
		thirdSizer->Add(box, 0, wxLEFT, 5);

	topSizer->Add(display, 0, wxALL | wxEXPAND, 10);
	topSizer->Add(firstSizer, 0, wxALIGN_CENTER| wxALL, 5 );
	topSizer->Add(secondSizer, 0, wxALIGN_CENTER|wxALL,5);
	topSizer->Add(thirdSizer, 0, wxALIGN_CENTER| wxALL,5 );
	topSizer->Fit(this);
	topSizer->SetSizeHints(this);
	SetSizer(topSizer);
}
MainFrame::~MainFrame()
{

}
void MainFrame::SetFrameSizer(wxBoxSizer * sizer)
{
	
	sizer = new wxBoxSizer(wxVERTICAL);
	
}
void MainFrame::SetDisplay(wxTextCtrl * display)
{
	display = new wxTextCtrl(this, 1001, wxEmptyString, wxPoint(10,10), wxSize(300, 40), wxTE_RIGHT | wxTE_WORDWRAP);
	display->SetEditable(false);
	display->SetFont(GetFont().Scale(1.5));
}
void MainFrame::SetBoxSizer(wxBoxSizer * sizer, wxOrientation orientation)
{
	sizer = new wxBoxSizer(orientation);
	wxButton *btnCE = new wxButton(this, 1002, "CE", wxDefaultPosition, wxSize(40, 40));
	wxButton *btnDGR = new wxButton(this, 1003, "DGR", wxDefaultPosition, wxSize(40, 40));
	wxButton *btn2nd = new wxButton(this, 1004, "2nd", wxDefaultPosition, wxSize(50, 40));
	wxButton *btnOFF = new wxButton(this, 1005, "OFF", wxDefaultPosition, wxSize(40, 40));
	wxButton *btnON = new wxButton(this, 1006, "ON", wxDefaultPosition, wxSize(40, 40));
	sizer->Add(btnCE,0,wxEXPAND|wxALL,0);
	sizer->Add(btnDGR,0,wxEXPAND|wxALL,0);
	sizer->Add(btn2nd,0,wxEXPAND|wxALL,0);
	sizer->Add(btnOFF,0,wxEXPAND|wxALL,0);
	sizer->Add(btnON,0,wxEXPAND|wxALL,0);
	
}