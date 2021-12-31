#include "MainFrame.h"
BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_BUTTON(BTN_CLEAR, MainFrame::OnClearButtonClick)
	EVT_BUTTON(BTN_VALIDATE, MainFrame::OnValidateButtonClick)
END_EVENT_TABLE()

void MainFrame::OnValidateButtonClick(wxCommandEvent & evt)
{
}

MainFrame::MainFrame(const wxString & title):wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(640,480))
{
	topSizer = new wxBoxSizer(wxVERTICAL);
}

void MainFrame::OnClearButtonClick(wxCommandEvent & evt)
{
}
