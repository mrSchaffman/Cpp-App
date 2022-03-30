#include "MainFrame.h"
#include"wx/aboutdlg.h"
#include"wx/filedlg.h"
#include"wx/colordlg.h"



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

MainFrame::MainFrame(const wxString& caption):wxFrame(nullptr,wxID_ANY,caption,wxDefaultPosition,wxSize(420,680))
{
	wxMenu* menuFile = new wxMenu;
	{
#if wxUSE_FILEDLG
		menuFile->Append(wxID_OPEN,"&Open Animation...\tCtrl+O","Loads an Animation");
#endif // wxUSE_FILEDLG
		menuFile->Append(wxID_EXIT);
	}
    wxMenu* menuEdit = new wxMenu;
    {

    }
    wxMenu* menuOptions = new wxMenu;
    {

    }
    wxMenu* menuTools = new wxMenu;
    {

    }
    wxMenu* menuWindow = new wxMenu;
    {

    }
	wxMenu* menuPlay = new wxMenu;
	{
        menuPlay->Append(ID_PLAY, "Play\tCtrl+P", "Play the animation");
        menuPlay->Append(wxID_STOP, "Stop\tCtrl+S", "Stop the animation");
        menuPlay->AppendSeparator();
        menuPlay->Append(ID_SET_NULL_ANIMATION, "Set null animation",
            "Sets the empty animation in the control");
        menuPlay->AppendCheckItem(ID_SET_INACTIVE_BITMAP, "Set inactive bitmap",
            "Sets an inactive bitmap for the control");
        menuPlay->AppendCheckItem(ID_SET_NO_AUTO_RESIZE, "Set no autoresize",
            "Tells the control not to resize automatically");
        menuPlay->Append(ID_SET_BGCOLOR, "Set background colour...",
            "Sets the background colour of the control");
#ifdef wxHAS_NATIVE_ANIMATIONCTRL
        menuPlay->AppendSeparator();
        menuPlay->AppendCheckItem(ID_USE_GENERIC, "Use &generic animation\tCtrl+G",
            "Selects whether native or generic version is used");
#endif // wxHAS_NATIVE_ANIMATIONCTRL
	}
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile,wxT("File"));
    menuBar->Append(menuEdit,wxT("Edit"));
    menuBar->Append(menuOptions,wxT("Option"));
    menuBar->Append(menuTools,wxT("Tools"));
    menuBar->Append(menuWindow,wxT("Window"));
    menuBar->Append(menuPlay,wxT("Play"));
    menuBar->Append(menuHelp,wxT("Help"));

    SetMenuBar(menuBar);
#if wxUSE_STATUSBAR
    CreateStatusBar();
#endif // wxUSE_STATUSBAR
    DisplayControls();

}

MainFrame::~MainFrame()
{
    wxLogMessage("The Destructor is called");
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxAboutDialogInfo info;
    info.SetName(_("wxAnimation and wxAnimationCtrl"));
    info.SetDescription(_("This is About the wxAnimationCtrl an the wxAnimation Classes"));
    info.SetCopyright("(C) 2022,Barth. Feudong");
    info.AddDeveloper("Barth. Feudong");

    wxAboutBox(info,this);
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    //wxLogWindow logWin(nullptr, "The log Window", true, true);


    Close();
}

void MainFrame::OnPlay(wxCommandEvent& event)
{
    //wxWindow* log = (wxWindow*)wxLog::GetActiveTarget();
    
    wxLogMessage("MenuItem %s selected ", event.GetString().c_str());

    if (!m_animationCtrl->Play())
    {
        wxLogError("Invalide Animation");
    }
}

void MainFrame::OnSetNullAnimation(wxCommandEvent& WXUNUSED(event))
{
}

void MainFrame::OnSetInactiveBitmap(wxCommandEvent& WXUNUSED(event))
{
}

void MainFrame::OnSetNoAutoResize(wxCommandEvent& WXUNUSED(event))
{
    m_animationCtrl->SetAnimation(wxNullAnimation);
}

void MainFrame::OnSetBgColor(wxCommandEvent& event)
{
    wxLogVerbose("MenuItem %s selected ",event.GetString().c_str());

    wxColour color = wxGetColourFromUser(this,
        m_animationCtrl->GetBackgroundColour(),
        "Choose the Background Color");

    if(color.IsOk())
    m_animationCtrl->SetBackgroundColour(color);
}

void MainFrame::OnStop(wxCommandEvent& WXUNUSED(event))
{
    wxLogMessage("MenuItem Stop selected ");

    m_animationCtrl->Stop();
}

void MainFrame::OnUpdateUI(wxUpdateUIEvent& WXUNUSED(event))
{

    GetMenuBar()->FindItem(wxID_STOP)->Enable(m_animationCtrl->IsPlaying());
    GetMenuBar()->FindItem(ID_PLAY)->Enable(!m_animationCtrl->IsPlaying());
    GetMenuBar()->FindItem(ID_SET_NO_AUTO_RESIZE)->Enable(!m_animationCtrl->IsPlaying());
}

#if wxUSE_FILEDLG
void MainFrame::OnOpen(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog dialog(this,
        wxT("Choose and Animation"),
        wxEmptyString,
        wxEmptyString,
        "*.gif;*.ani",
        wxFD_OPEN);
    if (dialog.ShowModal()== wxID_OK)
    {
        wxString filename = dialog.GetPath();
        wxAnimation tmp(m_animationCtrl->CreateAnimation());
        if (!tmp.LoadFile(filename))
        {
             wxLogError("Cannot load the File %s ",dialog.GetFilename());
        }

        m_animationCtrl->SetAnimation(tmp);
        m_animationCtrl->Play();
    }
    GetSizer()->Layout();
}
#endif // wxUSE_FILEDLG


void MainFrame::DisplayControls()
{
    wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    {
        sizer->Add(
            new wxStaticText(this,wxID_ANY,wxT("Animation")),
            1,
            wxALL||wxCENTER,
            5
        );
    

         m_animationCtrl = new wxAnimationCtrl(this, wxID_ANY);
         if (m_animationCtrl->LoadFile("hourglass.ani", wxANIMATION_TYPE_ANI))
         {
             m_animationCtrl->Play();
         }

         sizer->Add(
             m_animationCtrl,
             1,
             wxALL|wxCENTER,
             5
         );

         SetSizer(sizer);
    }
}

void MainFrame::RecreateAnimation()
{
}
