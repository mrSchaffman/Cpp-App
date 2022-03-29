#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& caption):wxFrame(nullptr,wxID_ANY,caption,wxDefaultPosition,wxSize(370,220))
{

}

MainFrame::~MainFrame()
{
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
}

void MainFrame::OnQuit(wxCommandEvent& event)
{
}

void MainFrame::OnPlay(wxCommandEvent& event)
{
}

void MainFrame::OnSetNullAnimation(wxCommandEvent& event)
{
}

void MainFrame::OnSetInactiveBitmap(wxCommandEvent& event)
{
}

void MainFrame::OnSetNoAutoResize(wxCommandEvent& event)
{
}

void MainFrame::OnSetBgColor(wxCommandEvent& event)
{
}

void MainFrame::OnStop(wxCommandEvent& event)
{
}

void MainFrame::OnUpdateUI(wxUpdateUIEvent& event)
{
}

void MainFrame::RecreateAnimation()
{
}
