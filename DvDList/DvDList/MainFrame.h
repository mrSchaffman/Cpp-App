#pragma once
#include<wx/wx.h>
#include"DvDList.h"

enum
{
	//LIST_ABOUT = wxID_ABOUT,
	LIST_QUIT = wxID_EXIT,

	LIST_LIST_VIEW = wxID_HIGHEST,
	LIST_ICON_VIEW,
	LIST_ICON_TEXT_VIEW,
	LIST_SMALL_ICON_VIEW,
	LIST_SMALL_ICON_TEXT_VIEW,
	LIST_REPORT_VIEW,
	LIST_VIRTUAL_VIEW,
	LIST_SMALL_VIRTUAL_VIEW,
	LIST_SET_ITEMS_COUNT,

	LIST_DESELECT_ALL,
	LIST_SELECT_ALL,
	LIST_DELETE_ALL,
	LIST_DELETE,
	LIST_ADD,
	LIST_EDIT,
	LIST_SORT,
	LIST_FIND,
	LIST_SET_FG_COL,
	LIST_SET_BG_COL,
	LIST_ROW_LINES,
	LIST_ROW_LINES_ON_BLANK,
	LIST_CUSTOM_HEADER_ATTR,
	LIST_TOGGLE_MULTI_SEL,
	LIST_TOGGLE_HEADER,
	LIST_TOGGLE_BELL,
	LIST_TOGGLE_CHECKBOX,
	LIST_GET_CHECKBOX,
	LIST_TOGGLE_CHECKBOXES,
	LIST_TOGGLE_FIRST,
	LIST_SHOW_COL_INFO,
	LIST_SHOW_SEL_INFO,
	LIST_SHOW_VIEW_RECT,

	LIST_GOTO,
	LIST_FOCUS_LAST,
	LIST_FREEZE,
	LIST_THAW,
	LIST_TOGGLE_LINES,
	LIST_CHECKVISIBILITY,
};

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString & title);
	~MainFrame() = default;


	wxPanel *m_panel = nullptr;
	DvDList *m_listCtrl = nullptr;

	wxTextCtrl *m_logWindow = nullptr;
private:
	wxLog *m_logOld = nullptr;

	wxDECLARE_EVENT_TABLE();

};

