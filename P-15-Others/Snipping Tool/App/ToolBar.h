#pragma once
#include"wx/wx.h"

enum {
	ID_NEW = 40,
	ID_MODE,
	ID_DELAY,
	ID_CANCEL,
	ID_TOOLS,
	ID_COMBOBOX,

};

class ToolBar:public wxToolBar
{
public:

	ToolBar(wxFrame*frameParent);
	virtual~ToolBar() = default;
private:

	void OnNew(wxCommandEvent& event);
	void OnMode(wxCommandEvent& event);
	void OnDelay(wxCommandEvent& event);
	void OnCancel(wxCommandEvent& event);
	void OnTools(wxCommandEvent& event);
	void OnCombo(wxCommandEvent& event);
	std::unique_ptr<wxFrame> m_parent;

	wxDECLARE_EVENT_TABLE();
};

