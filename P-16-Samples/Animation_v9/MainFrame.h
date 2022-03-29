#pragma once
#include"wx/wx.h"
#include"wx/animate.h"

#include"MathChallenge.h"
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

	 void OnUpdateUI(wxUpdateUIEvent& event);

#ifdef wxHAS_NATIVE_ANIMATIONCTRL
	 void OnUseGeneric(wxCommandEvent& event);
#endif // wxHAS_NATIVE_ANIMATIONCTRL

#if wxUSE_FILEDLG
	 void OnOpen(wxCommandEvent& event);
#endif // wxUSE_FILEDLG



private:

	void RecreateAnimation();
	wxAnimationCtrlBase* m_animationCtrl;
	wxDECLARE_EVENT_TABLE();
};

