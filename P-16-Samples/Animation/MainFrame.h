#pragma once
#include"wx/wx.h"
#include"wx/animate.h"
#include"wx/wfstream.h"
#include"wx/txtstrm.h"
#include"wx/artprov.h"
#include"MathFunctions.h"

#if !wxUSE_ANIMATIONCTRL
#error Cannot compile this sample if wxAnimationCtrl is not enabled
#endif

#ifdef wxHAS_NATIVE_ANIMATIONCTRL
#include "wx/generic/animate.h"
#endif

enum
{
	ID_PLAY = 1,
	ID_SET_NULL_ANIMATION,
	ID_SET_INACTIVE_BITMAP,
	ID_SET_NO_AUTO_RESIZE,
	ID_SET_BGCOLOR,
	ID_USE_GENERIC,
	ID_TEXT_MATH1,
	ID_BTN_RUN, 
	ID_BTN_RUN_1, 
	ID_BTN_RUN_2, 
	ID_BTN_RUN_3, 
	ID_BTN_RUN_4, 
	ID_BTN_RUN_5, 
	ID_BTN_RUN_6, 
	ID_BTN_RUN_7, 
	ID_LOG_WINDOW,
	ID_TEXT_1_MATH2,
	ID_TEXT_2_MATH2,
	ID_LOG_TEXT_CTRL,
	ID_OPEN_IN_NOTEPAD,
	ID_WRITE_REPORT
};


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& caption);

	 ~MainFrame();

	 // event Handlers
	 void OnAbout(wxCommandEvent& event);
	 void OnQuit(wxCommandEvent& event);
	 void OnPlay(wxCommandEvent& event);
	 void OnSetNullAnimation(wxCommandEvent& event);
	 void OnSetInactiveBitmap(wxCommandEvent& event);
	 void OnSetNoAutoResize(wxCommandEvent& event);
	 void OnSetBgColor(wxCommandEvent& event);
	 void OnStop(wxCommandEvent& event);
	 void OnLogWindow(wxCommandEvent& event);
	 void OnOpenInNotepad(wxCommandEvent& event);
	 void OnWriteReport(wxCommandEvent& event);
	 void OnRun(wxCommandEvent& event);

	 void OnUpdateUI(wxUpdateUIEvent& event);


#ifdef wxHAS_NATIVE_ANIMATIONCTRL
	 void OnUseGeneric(wxCommandEvent& event);
#endif // wxHAS_NATIVE_ANIMATIONCTRL

#if wxUSE_FILEDLG
	 void OnOpen(wxCommandEvent& event);
#endif // wxUSE_FILEDLG



private:

	//void WriteToTempFile(const wxString& functionName);
	void DisplayControls();
	void RecreateAnimation(long style);
	wxAnimationCtrlBase* m_animationCtrl;
	wxDECLARE_EVENT_TABLE();
};

