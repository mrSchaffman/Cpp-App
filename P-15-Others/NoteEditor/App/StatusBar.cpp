#include "StatusBar.h"

//StatusBar::StatusBar(wxWindow * paren_win,long style):wxStatusBar()//paren_win,wxID_ANY,style)
//{
//	m_parent = paren_win;
//
//}

StatusBar::StatusBar(): wxStatusBar()
{
	int m_widths[5] = { 250,120,30,80,80 };


	SetStatusWidths(0, m_widths);

	//SetStatusBarPane(0);
	wxString LinCol;
	LinCol.Printf("Ln %d, Col %d");// , m_ln, m_col);
	SetStatusText(LinCol, 1);
	SetStatusText(wxT("100%"), 2);
	SetStatusText(wxT("Win...(CRLF)"), 3);
	SetStatusText(wxT("UTF-8"), 4);

}
