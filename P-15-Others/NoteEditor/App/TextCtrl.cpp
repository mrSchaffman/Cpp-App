#include "TextCtrl.h"

wxBEGIN_EVENT_TABLE(TextCtrl, wxTextCtrl)
	EVT_TEXT(TXT_CTRL,TextCtrl::OnTextChange)
	EVT_LEFT_DOWN(TextCtrl::OnMouseDown)
	//EVT_CHAR(TextCtrl::OnChar)

wxEND_EVENT_TABLE()

TextCtrl::TextCtrl(wxFrame * parent):wxTextCtrl(parent, TXT_CTRL,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE|wxTE_DONTWRAP|wxTE_NOHIDESEL|wxBORDER_NONE)
{
	m_parent = parent;
	SetBackgroundColour(wxColour(216, 243, 220));

}

void TextCtrl::OnTextChange(wxCommandEvent & event)
{
	m_txt_status = true;
	
}
void TextCtrl::OnMouseDown(wxMouseEvent & event)
{
	int x, y, xx, yy;
	event.GetPosition(&x, &y);
	wxString LinCol;
	LinCol.Printf("Ln %d, Col %d", x, y);


	m_parent->SetStatusText(LinCol, 1);


}
//void TextCtrl::OnChar(wxKeyEvent & event)
//{
//	wxPoint pt(event.GetPosition());
//
//	if (event.ControlDown()&&event.GetKeyCode()== WXK_UP)
//	{
//		wxString msg;
//		msg.Printf("This is my Own implementation of the existing Notepad \n Copyright(C) Barth. Feudong \t 2022");
//
//		wxMessageBox(msg, "About My NotePad", wxOK | wxICON_INFORMATION, this);
//
//	}
//}


