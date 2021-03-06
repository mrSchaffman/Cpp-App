#pragma once
#include"wx/wx.h"
#include "wx/filedlg.h"
#include "wx/dirdlg.h"
#include "wx/txtstrm.h"
#include "wx/wfstream.h"
#include "wx/sysopt.h"
#include"PageSettingDialogue.h"
#include"FileTreeCtrl.h"
#include"SplitterItemWin.h"



enum {

	// menu file 
	M_NEW =1,
	M_NEW_PROJECT,
	M_NEW_WINDOW ,
	M_OPEN ,
	M_OPEN_FOLDER,
	M_SAVE ,
	M_SAVE_AS ,
	M_PAGE_SETUP ,
	M_PRINT ,
	M_EXIT ,

	//Menu edit
	M_UNDO ,
	M_CUT ,
	M_COPY ,
	M_PASTE,
	M_DELETE,
	M_SEARCH_WITH_BING ,
	M_FIND ,
	M_FIND_NEXT ,
	M_FIND_PREVIOUS ,
	M_REPLACE ,
	M_GOTO,
	M_SELECT_ALL ,
	M_TIME_DATE ,

	//menu format
	M_WRAP_WORD ,
	M_FONT ,

	//menu View
	M_ZOOM ,
	M_ZOOM_IN ,
	M_ZOOM_OUT ,
	M_ZOOM_RESTORE_DEFAULT ,
	M_STATUS_BAR ,

	//menu Help
	M_VIEW_HELP ,
	M_SEND_FEEDBACK ,
	M_ABOUT ,
};

class MenuBar : public wxMenuBar
{
public:
	MenuBar(wxFrame*parent, SplitterItemWin *splittermain = nullptr);
	virtual~MenuBar() = default;

	void OnNew(wxCommandEvent&evnt);
	void OnNewProject(wxCommandEvent&evnt);
	void OnOpen(wxCommandEvent&evnt);
	void OnOpenNewFolder(wxCommandEvent&evnt);
	void OnAbout(wxCommandEvent&evnt);
	void OnExit(wxCommandEvent&evnt);
	void OnSave(wxCommandEvent&evnt);
	void OnSaveAs(wxCommandEvent&evnt);
	void OnSetStatusBar(wxCommandEvent&evnt);

	void OnZoomIn(wxCommandEvent&event);
	void OnZoomOut(wxCommandEvent&event);
	void OnPageSettingDialog(wxCommandEvent&event);

private:

	wxTextCtrl*m_text = nullptr;
	FileTreeCtrl* m_tree = nullptr;

	wxFrame*m_parent = nullptr;
	SplitterItemWin* m_trees = nullptr;
	wxDECLARE_EVENT_TABLE();
};

