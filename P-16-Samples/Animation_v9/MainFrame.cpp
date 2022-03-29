#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
EVT_MENU(ID_PLAY, MainFrame::OnPlay)
EVT_MENU(ID_SET_NULL_ANIMATION, MainFrame::OnSetNullAnimation)
EVT_MENU(ID_SET_INACTIVE_BITMAP, MainFrame::OnSetInactiveBitmap)
EVT_MENU(ID_SET_NO_AUTO_RESIZE, MainFrame::OnSetNoAutoResize)
EVT_MENU(ID_SET_BGCOLOR, MainFrame::OnSetBgColor)

EVT_MENU(wxID_STOP, MainFrame::OnStop)
EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
EVT_MENU(wxID_EXIT, MainFrame::OnQuit) 
EVT_UPDATE_UI(wxID_ANY, MainFrame::OnUpdateUI)

EVT_SIZE(MainFrame::OnSize)

#if wxUSE_FILEDLG
EVT_MENU(wxID_OPEN,MainFrame::OnOpen)
#endif // wxUSE_FILEDLG
#ifdef wxHAS_NATIVE_ANIMATIONCTRL
EVT_MENU(ID_USE_GENERIC,MainFrame::OnUseGeneric)
#endif // wxHAS_NATIVE_ANIMATIONCTRL


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

void MainFrame::OnOpen(wxCommandEvent& event)
{
}

void MainFrame::RecreateAnimation()
{
}
