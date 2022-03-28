#pragma once
#include"wx/wx.h"
#include"wx/splitter.h"
#include"FrameAccessible.h"
#include"SplitterWindowAccessible.h"
#if wxUSE_ACCESSIBILITY
enum MenuID
{
	ID_ABOUT = 10,
	ID_QUERY,
	ID_QUIT,
};

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& caption,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxDEFAULT_FRAME_STYLE);
	MainFrame() = default;

	void Init();
	bool Create(const wxString& caption,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxDEFAULT_FRAME_STYLE);

	void LayoutControls();

	// event handlers
	void OnAbout(wxCommandEvent& event);
	void OnQuery(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);

	void Log(const wxString& message);
	void LogObject(int intent, IAccessible* object);

	// void GetInfo(IAccessible* accessible,int id, wxString& name, wxString&role);

private:

	wxTextCtrl* m_logger;
	wxDECLARE_EVENT_TABLE();
};


#endif // wxUSE_ACCESSIBILITY


