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
EVT_MENU(ID_LOG_WINDOW, MainFrame::OnLogWindow)
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

MainFrame::MainFrame(const wxString& caption):wxFrame(nullptr,wxID_ANY,caption,wxDefaultPosition,wxSize(500,680))
{
    SetMaxSize(wxSize(500, 680));
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
        menuWindow->Append(ID_LOG_WINDOW, "&Log Window\tCtrl+W", "Open the Log Window");

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
   delete wxLog::GetActiveTarget();
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

void MainFrame::OnLogWindow(wxCommandEvent& event)
{
    wxLogWindow* logTarget = (wxLogWindow*)wxLog::GetActiveTarget();
    logTarget->Show(true);
}

void MainFrame::OnUpdateUI(wxUpdateUIEvent& WXUNUSED(event))
{

    //GetMenuBar()->FindItem(wxID_STOP)->Enable(m_animationCtrl->IsPlaying());
    //GetMenuBar()->FindItem(ID_PLAY)->Enable(!m_animationCtrl->IsPlaying());
    //GetMenuBar()->FindItem(ID_SET_NO_AUTO_RESIZE)->Enable(!m_animationCtrl->IsPlaying());
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
        wxSizer* rowMaths = new wxBoxSizer(wxVERTICAL);
        {
            wxSizer* row1 = new wxBoxSizer(wxHORIZONTAL);
            {
                wxSizer* math1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Math1"));
                {
                    math1->Add(
                        new wxStaticText(this, wxID_ANY, _("Number of naturals divible by 3 and 5")),
                        0,
                        wxLEFT,
                        5
                    );
                    wxSizer* row1_2 = new wxBoxSizer(wxHORIZONTAL);
                    {
                        wxTextCtrl* input = new wxTextCtrl(this,
                            ID_TEXT_MATH1,
                            wxEmptyString,
                            wxDefaultPosition,
                            wxSize(175, 20));
                        input->SetInsertionPointEnd();
                        input->SetHint(_("Number"));
                        input->SetValidator(wxTextValidator(wxFILTER_DIGITS));
                        row1_2->Add(input, 1, wxALL | wxEXPAND, 1);

                        row1_2->Add(new wxButton(this,
                            ID_BTN_RUN,
                            _("Run"),
                            wxDefaultPosition,
                            wxSize(30, 20)), 0, wxALL, 1);
                    }

                    math1->Add(row1_2, 0, wxALL, 5);
                }
                wxSizer* math2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Math2"));
                {
                    math2->Add(
                        new wxStaticText(this, wxID_ANY, _("Greatest common divider")),
                        0,
                        wxLEFT,
                        5
                    );
                    wxSizer* row1_2 = new wxBoxSizer(wxHORIZONTAL);
                    {
                        wxTextCtrl* input1 = new wxTextCtrl(this,
                            ID_TEXT_1_MATH2,
                            wxEmptyString,
                            wxDefaultPosition,
                            wxSize(86, 20));
                        input1->SetInsertionPointEnd();
                        input1->SetHint(_("first number"));
                        input1->SetValidator(wxTextValidator(wxFILTER_DIGITS));
                        row1_2->Add(input1, 1, wxALL | wxEXPAND, 1);

                        wxTextCtrl* input2 = new wxTextCtrl(this,
                            ID_TEXT_2_MATH2,
                            wxEmptyString,
                            wxDefaultPosition,
                            wxSize(86, 20));
                        input2->SetInsertionPointEnd();
                        input2->SetHint(_("second number"));
                        input2->SetValidator(wxTextValidator(wxFILTER_DIGITS));
                        row1_2->Add(input2, 1, wxALL | wxEXPAND, 1);

                        row1_2->Add(new wxButton(this,
                            ID_BTN_RUN,
                            _("Run"),
                            wxDefaultPosition,
                            wxSize(30, 20)), 0, wxALL, 1);
                    }

                    math2->Add(row1_2, 0, wxALL, 5);
                }
                row1->Add(math1, 0, wxALL, 5);
                row1->Add(math2, 0, wxALL, 5);

            }
            rowMaths->Add(row1, 0);

        }

        wxSizer* lastRow = new wxBoxSizer(wxHORIZONTAL);
        {
            m_animationCtrl = new wxAnimationCtrl(this, wxID_ANY);
            m_animationCtrl->SetBackgroundColour(*wxWHITE);
             if (m_animationCtrl->LoadFile("hourglass.ani", wxANIMATION_TYPE_ANI))
             {
                 m_animationCtrl->Play();
             }
             lastRow->Add(
                 m_animationCtrl,
                 1,
                 wxRIGHT,
                 1
             );
             lastRow->Add(new wxTextCtrl(this,
                 ID_LOG_TEXT_CTRL,
                 wxEmptyString,
                 wxDefaultPosition,
                 wxSize(450,32),
                 wxTE_MULTILINE|wxTE_READONLY|wxBORDER_NONE),1);


        }
        sizer->Add(rowMaths, 1, wxALL, 5);
        sizer->Add(lastRow, 0, wxALL, 5);


         SetSizer(sizer);
    }
}

void MainFrame::RecreateAnimation()
{
}
