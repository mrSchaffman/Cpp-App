#pragma once
#include"wx/wx.h"

enum MyTextCrlID {
	TXT_CTRL = 100,
};
class TextCtrl : public wxTextCtrl
{
public:

	TextCtrl(wxFrame*parent);
	virtual ~TextCtrl() = default;

	void OnTextChange(wxCommandEvent&event);
	bool asChanged() { return m_txt_status; }

	void OnMouseDown(wxMouseEvent &event);
	//void OnChar(wxKeyEvent& event);


private:

	wxFrame* m_parent = nullptr;
	bool m_txt_status;

	wxDECLARE_EVENT_TABLE();

};

