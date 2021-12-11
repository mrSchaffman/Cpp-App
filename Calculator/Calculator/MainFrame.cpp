#include "MainFrame.h"
BEGIN_EVENT_TABLE(MainFrame, wxFrame)

END_EVENT_TABLE()
MainFrame::MainFrame(const wxString&title):wxFrame(NULL,wxID_ANY,title,wxPoint(300,300),wxSize(X,Y))
{
	SetMaxSize(wxSize(X, Y));
	
	topSizer = new wxBoxSizer(wxVERTICAL);

	line0 = new wxBoxSizer(wxVERTICAL);
	line1 = new wxBoxSizer(wxHORIZONTAL);

	line2 = new wxGridSizer(rowL2, columnL2, 5, 5);
	btnsLine2 = new wxButton*[rowL2*columnL2];

	line3 = new wxBoxSizer(wxHORIZONTAL);
	line3_1 = new wxGridSizer(rowL3, columnL3, 5, 5);
	btnsLine3_1 = new wxButton*[rowL3*columnL3];
	line3_2 = new wxBoxSizer(wxVERTICAL);

	frameSizers = { line0 ,line1,line2,line3 };

	labelsLine2 = { "EXP","hyp","->","y^x","sin","a","Rac","cos","b","DEG","tan","x^2","Ln","(","F-E","log",")","x-M" };
	labelsLine3_1 = { "7","4","1","0","8","5","2",".","9","6","3","+/-","/","*","-","+" };
	labelsLine3_2 = { "MR","M+","="};


	for (size_t line = 0; line <= 3; line++)
	{
		if (line == 0)
		{
			display = new wxTextCtrl(this, 1000, wxEmptyString, wxDefaultPosition, wxSize(300, 40), wxTE_RIGHT || wxTE_WORDWRAP);
			display->SetEditable(false);
			display->SetFont(GetFont().Scale(1.5));
		
			frameSizers[line]->Add(display, 0, wxALL,5);
		}
		if (line == 1)
		{

		}
		if (line == 2)
		{
			/*for (size_t x = 0; x < rowL2; x++)
			{
				for (size_t y = 0; y < columnL2; y++)
				{
					btnsLine2[y*rowL2 + x] = new wxButton(this, 2000 + (y*rowL2 + x), labelsLine2[y*rowL2 + x], wxDefaultPosition, wxSize(30, 30));
					btnsLine2[y*rowL2 + x]->SetFont(GetFont().Scale(1.3));
					line2->Add(btnsLine2[y*rowL2 + x], 0, wxALL);
				}
			}

			frameSizers[line]->Add(line2, 0, wxALIGN_CENTER);*/
		}
		if (line == 3)
		{
			for (size_t x = 0; x < rowL3; x++)
			{
				for (size_t y = 0; y < columnL3; y++)
				{
					btnsLine3_1[y*rowL3 + x] = new wxButton(this, 3010 + (y*rowL3 + x), labelsLine3_1[y*rowL3 + x], wxDefaultPosition, wxSize(50, 50));
					btnsLine3_1[y*rowL3 + x]->SetFont(GetFont().Scale(2));
					line3_1->Add(btnsLine3_1[y*rowL3 + x], 0, wxALL);
					btnsLine3_1[y*rowL3 + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnButtonNumberClick, this);
				}
			}
			frameSizers[line]->Add(line3_1, 0, wxALL);
			for (size_t line32 = 0; line32 < 2; line32++)
			{
				wxButton *btn32 = new wxButton(this, 3020 + line32, labelsLine3_2[line32],wxDefaultPosition,wxSize(50,50));
				btn32->SetFont(GetFont().Scale(2));
				line3_2->Add(btn32, 0, wxBOTTOM,5);
				btn32->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnButtonOperatorClick, this); // Handler to modify.
			}
			// the Equal button
			wxButton *btn32 = new wxButton(this, 3022, labelsLine3_2[2], wxDefaultPosition, wxSize(50, 105));
			btn32->SetFont(GetFont().Scale(2));
			line3_2->Add(btn32, 0, wxBOTTOM, 5);
			btn32->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnButtonOperatorClick, this);
			frameSizers[line]->Add(line3_2, 0,wxLEFT,5);
		}
		
		topSizer->Add(frameSizers[line], 0, wxALIGN_CENTER);
	}
	topSizer->Fit(this);
	topSizer->SetSizeHints(this);
	SetSizer(topSizer);
}
MainFrame::~MainFrame()
{

}
	

void MainFrame::OnButtonNumberClick(wxCommandEvent &evt)
{


	display->AppendText(wxString("${}",evt.GetId()));
}
void MainFrame::OnButtonOperatorClick(wxCommandEvent &evt)
{


	display->AppendText(wxString("t",evt.GetId()));
}