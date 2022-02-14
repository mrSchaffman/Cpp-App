#include "StatusBar.h"

//StatusBar::StatusBar(wxWindow * paren_win,long style):wxStatusBar()//paren_win,wxID_ANY,style)
//{
//	m_parent = paren_win;
//
//}

StatusBar::StatusBar(): wxStatusBar()
{
	int m_widths[5] = { 40,30,10,30,20 };

	SetStatusWidths(0, m_widths);

}
