#pragma once
#include"wx/wx.h"
//#include"PageSettingDialogue.h"


enum {

	// menu file 
	M_NEW = 1,
	M_NEW_WINDOW,
	M_OPEN,
	M_SAVE,
	M_SAVE_AS,
	M_PAGE_SETUP,
	M_PRINT,
	M_EXIT,

	//Menu edit
	M_UNDO,
	M_CUT,
	M_COPY,
	M_PASTE,
	M_DELETE,
	M_SEARCH_WITH_BING,
	M_FIND,
	M_FIND_NEXT,
	M_FIND_PREVIOUS,
	M_REPLACE,
	M_GOTO,
	M_SELECT_ALL,
	M_TIME_DATE,

	//menu format
	M_WRAP_WORD,
	M_FONT,

	//menu View
	M_ZOOM,
	M_ZOOM_IN,
	M_ZOOM_OUT,
	M_ZOOM_RESTORE_DEFAULT,
	M_STATUS_BAR,

	//menu Help
	M_VIEW_HELP,
	M_SEND_FEEDBACK,
	M_ABOUT,
};

class MenuBar : public wxMenuBar
{
public:
	MenuBar(wxFrame*parent, wxTextCtrl*text = nullptr);
	virtual~MenuBar() = default;/* {
		delete m_file;
		delete m_edit;
		delete m_format;
		delete m_view;
		delete m_help;
	};*/

	void OnNew(wxCommandEvent&evnt);
	void OnAbout(wxCommandEvent&evnt);
	void OnExit(wxCommandEvent&evnt);
	void OnSave(wxCommandEvent&evnt);

	void OnZoomIn(wxCommandEvent&event);
	void OnZoomOut(wxCommandEvent&event);
	void OnPageSettingDialog(wxCommandEvent&event);

private:

	wxMenu * m_file = nullptr;
	wxMenu * m_edit = nullptr;
	wxMenu * m_format = nullptr;
	wxMenu * m_view = nullptr;
	wxMenu * m_help = nullptr;
	wxTextCtrl*m_text = nullptr;

	wxFrame*m_parent = nullptr;
	//PageSettingDialogue* m_page_setting_dialog = nullptr;

	wxDECLARE_EVENT_TABLE();
};

