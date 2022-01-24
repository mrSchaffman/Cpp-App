#pragma once
#include"wx/statusbr.h"
class StatusBar : public wxStatusBar
{
public:
	StatusBar();
	//StatusBar(wxWindow * frame, long style = wxSTB_SIZEGRIP);
	virtual~StatusBar() = default;


private:
	wxWindow* m_parent = nullptr;
};

//Styles
//
//wxSTB_SIZEGRIP: Displays a gripper at the right - hand side of the status bar which can be used to resize the parent window.
//wxSTB_SHOW_TIPS : Displays tooltips for those panes whose status text has been ellipsized / truncated because the status text doesn't fit the pane width. Note that this style has effect only on wxGTK (with GTK+ >= 2.12) currently.
//wxSTB_ELLIPSIZE_START : Replace the beginning of the status texts with an ellipsis when the status text widths exceed the status bar pane's widths (uses wxControl::Ellipsize).
//wxSTB_ELLIPSIZE_MIDDLE : Replace the middle of the status texts with an ellipsis when the status text widths exceed the status bar pane's widths (uses wxControl::Ellipsize).
//wxSTB_ELLIPSIZE_END : Replace the end of the status texts with an ellipsis when the status text widths exceed the status bar pane's widths (uses wxControl::Ellipsize).
//wxSTB_DEFAULT_STYLE : The default style : includes wxSTB_SIZEGRIP | wxSTB_SHOW_TIPS | wxSTB_ELLIPSIZE_END | wxFULL_REPAINT_ON_RESIZE.


