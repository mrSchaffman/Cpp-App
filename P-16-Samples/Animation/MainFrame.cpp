#include "MainFrame.h"
#include"wx/aboutdlg.h"
#include"wx/filedlg.h"
#include"wx/colordlg.h"
#include"wx/filename.h"
#include<algorithm>



wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
EVT_MENU(ID_PLAY, MainFrame::OnPlay)
EVT_MENU(ID_SET_NULL_ANIMATION, MainFrame::OnSetNullAnimation)
EVT_MENU(ID_SET_INACTIVE_BITMAP, MainFrame::OnSetInactiveBitmap)
EVT_MENU(ID_SET_NO_AUTO_RESIZE, MainFrame::OnSetNoAutoResize)
EVT_MENU(ID_SET_BGCOLOR, MainFrame::OnSetBgColor)

EVT_MENU(wxID_STOP, MainFrame::OnStop)
EVT_MENU(ID_LOG_WINDOW, MainFrame::OnLogWindow)
EVT_MENU(ID_OPEN_IN_NOTEPAD, MainFrame::OnOpenInNotepad)
EVT_MENU(ID_WRITE_REPORT, MainFrame::OnWriteReport)
EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
EVT_MENU(wxID_EXIT, MainFrame::OnQuit) 

EVT_BUTTON(ID_BTN_RUN_1, MainFrame::OnRun)
EVT_BUTTON(ID_BTN_RUN_2, MainFrame::OnRun)
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

MainFrame::MainFrame(const wxString& caption):wxFrame(nullptr,wxID_ANY,caption,wxDefaultPosition,wxSize(500,280))
{
    SetMaxSize(wxSize(500, 480));
	SetBackgroundColour(*wxWHITE);
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
        menuWindow->Append(ID_WRITE_REPORT, "&Write Report\tCtrl+R", "write the Log Messages to a file");
        menuWindow->Append(ID_OPEN_IN_NOTEPAD, "&See in Notepad\tCtrl+L", "Open in Notepad");

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
    wxLogMessage("MenuItem Play selected ");

    if (!m_animationCtrl->Play())
    {
        wxLogError("Invalide Animation");
    }
}

void MainFrame::OnSetNullAnimation(wxCommandEvent& event)
{
    wxLogMessage("MenuItem Set Null Animation selected ");

}

void MainFrame::OnSetInactiveBitmap(wxCommandEvent& event)
{
    wxLogMessage("MenuItem Set Inactive Bitmap selected ");
    if (event.IsChecked())
    {
        wxBitmap bmp = wxArtProvider::GetBitmap(wxART_MISSING_IMAGE);
        m_animationCtrl->SetInactiveBitmap(bmp);
    }
    else
        m_animationCtrl->SetInactiveBitmap(wxNullBitmap);

}

void MainFrame::OnSetNoAutoResize(wxCommandEvent& event)
{
    wxLogMessage("MenuItem Set No Auto Resize selected ");

    // wxAC_DEFAULT_STYLE = wxBORDER_NONE
    long style = wxAC_DEFAULT_STYLE |
        (event.IsChecked() ? wxAC_NO_AUTORESIZE : 0);

    if (style != m_animationCtrl->GetWindowStyle())
    {
        RecreateAnimation(style);
    }

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

void MainFrame::OnOpenInNotepad(wxCommandEvent& event)
{
	
    wxExecute(wxT("c:\\windows\\notepad.exe tmp.txt"),wxEXEC_ASYNC);
}

void MainFrame::OnWriteReport(wxCommandEvent& event)
{
	wxMessageBox("Update to Pro to get this feature!");
}

void MainFrame::OnRun(wxCommandEvent& event)
{
	wxFileOutputStream output(wxT("tmp.txt"));
	wxTextOutputStream cout(output);
	wxString buf;
	int count = 0;
	size_t a = 0;
	size_t b = 0;
	size_t result = 0;
	std::vector<long> resluts;
	switch (event.GetId())
	{
	case ID_BTN_RUN_1:

		buf.Printf("  Integers Divisible by 3 and 5 smaller than %d are: ",
			wxAtol(((wxTextCtrl*)FindWindowById(ID_TEXT_MATH1))->GetValue()));
		
		wxLogMessage(buf);
		cout.WriteString(buf);
		cout << "\n";

		m_animationCtrl->Play();

		resluts = MathFunctions::IntegerDivibleBy3and5SmallerThan(wxAtol(((wxTextCtrl*)FindWindowById(ID_TEXT_MATH1))->GetValue()));
		
		for (const auto& i : resluts)
		{
			wxLogMessage("   %d", i);
			cout << wxString::Format("   %d", i) << ", ";
			if (count == 9)
			{
				cout << "\n";
				count = -1;
			}
			count++;
		}
		cout << "\n";

		break;
	case ID_BTN_RUN_2:

		result = MathFunctions::greaterCommonDivisorFrom(
			(wxAtoi(((wxTextCtrl*)FindWindowById(ID_TEXT_1_MATH2))->GetValue())),
			(wxAtoi(((wxTextCtrl*)FindWindowById(ID_TEXT_2_MATH2))->GetValue()))
		);

		buf.Printf("\t The Greatest common divider from %d and %d is %d",
			wxAtol(((wxTextCtrl*)FindWindowById(ID_TEXT_1_MATH2))->GetValue()),
			wxAtol(((wxTextCtrl*)FindWindowById(ID_TEXT_2_MATH2))->GetValue()),
			result);

		wxLogMessage("%s ",buf);
		cout << buf << endl;

		break;
	} 

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
    wxLogMessage("MenuItem Open Animation selected ");

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
                wxSizer* math1 = new wxStaticBoxSizer(wxVERTICAL, this );
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
                        input->SetHint(_("0"));
                        input->SetValidator(wxTextValidator(wxFILTER_DIGITS));
                        row1_2->Add(input, 1, wxALL | wxEXPAND, 1);

                        row1_2->Add(new wxButton(this,
                            ID_BTN_RUN_1,
                            _("Run"),
                            wxDefaultPosition,
                            wxSize(30, 20)), 0, wxALL, 1);
                    }

                    math1->Add(row1_2, 0, wxALL, 5);
                }
                wxSizer* math2 = new wxStaticBoxSizer(wxVERTICAL, this);
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
                            wxSize(86, 20),
							wxTE_PROCESS_TAB);
                        input1->SetInsertionPointEnd();
                        input1->SetHint(_("0"));
                        input1->SetValidator(wxTextValidator(wxFILTER_DIGITS));
                        row1_2->Add(input1, 1, wxALL | wxEXPAND, 1);

                        wxTextCtrl* input2 = new wxTextCtrl(this,
                            ID_TEXT_2_MATH2,
                            wxEmptyString,
                            wxDefaultPosition,
                            wxSize(86, 20),
							wxTE_PROCESS_TAB);
                        input2->SetInsertionPointEnd();
                        input2->SetHint(_("0"));
                        input2->SetValidator(wxTextValidator(wxFILTER_DIGITS));
                        row1_2->Add(input2, 1, wxALL | wxEXPAND, 1);

                        row1_2->Add(new wxButton(this,
                            ID_BTN_RUN_2,
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
                 m_animationCtrl->Stop();
             }
             lastRow->Add(
                 m_animationCtrl,
                 1,
                 wxRIGHT,
                 1
             );
             wxTextCtrl* logCtrl = new wxTextCtrl(this,
                 ID_LOG_TEXT_CTRL,
                 wxEmptyString,
                 wxDefaultPosition,
                 wxSize(450, 32),
                 wxTE_MULTILINE | wxTE_READONLY | wxBORDER_NONE);
             lastRow->Add(logCtrl,1);

             wxLog::SetActiveTarget(new wxLogTextCtrl(logCtrl));
             wxLog::SetActiveTarget(new wxLogWindow(this,"Log Window",false,true));
        }
        sizer->Add(rowMaths, 1, wxALL, 5);
        sizer->Add(lastRow, 0, wxALL, 5);


         SetSizer(sizer);
    }
}

void MainFrame::RecreateAnimation(long style)
{
    wxAnimation curr;
#ifdef wxHAS_NATIVE_ANIMATIONCTRL
    if (style != m_animationCtrl->GetWindowStyle())
        curr = m_animationCtrl->GetAnimation();
#endif // wxHAS_NATIVE_ANIMATIONCTRL

    wxBitmap inactiveBitmap = m_animationCtrl->GetInactiveBitmap();
    wxColour bg = m_animationCtrl->GetBackgroundColour();

    wxAnimationCtrlBase* oldCtrl = m_animationCtrl;
#ifdef wxHAS_NATIVE_ANIMATIONCTRL
    if (GetMenuBar()->IsChecked(ID_USE_GENERIC))
    {
        m_animationCtrl = new wxGenericAnimationCtrl(this,
            wxID_ANY,
            curr,
            wxDefaultPosition,
            wxDefaultSize,
            style)
    }
    else
#endif // wxHAS_NATIVE_ANIMATIONCTRL
        m_animationCtrl = new wxAnimationCtrl(this,
            wxID_ANY,
            curr,
            wxDefaultPosition,
            wxDefaultSize,
            style);

    GetSizer()->Replace(oldCtrl, m_animationCtrl);
    delete oldCtrl;


    m_animationCtrl->SetInactiveBitmap(inactiveBitmap);
    m_animationCtrl->SetBackgroundColour(bg);

    GetSizer()->Layout();
}
#ifdef wxHAS_NATIVE_ANIMATIONCTRL

void MainFrame::OnUseGeneric(wxCommandEvent& WXUNUSED(event))
{
    RecreateAnimation(m_animationCtrl->GetWindowStyle());
}

#endif // wxHAS_NATIVE_ANIMATIONCTRL
