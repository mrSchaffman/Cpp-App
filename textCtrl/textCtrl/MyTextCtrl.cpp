#include "MyTextCtrl.h"
wxBEGIN_EVENT_TABLE(MyTextCtrl, wxTextCtrl)
//EVT_KEY_DOWN(MyTextCtrl::OnKeyDown)
//EVT_KEY_UP(MyTextCtrl::OnKeyUp)
EVT_CHAR(MyTextCtrl::OnChar)

EVT_TEXT(wxID_ANY, MyTextCtrl::OnText)
EVT_TEXT_ENTER(wxID_ANY, MyTextCtrl::OnTextEnter)
EVT_TEXT_URL(wxID_ANY, MyTextCtrl::OnTextURL)
EVT_TEXT_MAXLEN(wxID_ANY, MyTextCtrl::OnTextMaxLen)
//EVT_TEXT_CUT(wxID_ANY, MyTextCtrl::OnTextCut)
//EVT_TEXT_COPY(wxID_ANY, MyTextCtrl::OnTextCopy)
//EVT_TEXT_PASTE(wxID_ANY, MyTextCtrl::OnTextPaste)

//EVT_MOUSE_EVENTS(MyTextCtrl::OnMouseEvent)
//EVT_CONTEXT_MENU(MyTextCtrl::OnContextMenu)

//EVT_SET_FOCUS(MyTextCtrl::OnSetFocus)
//EVT_KILL_FOCUS(MyTextCtrl::OnKillFocus)
wxEND_EVENT_TABLE()

void MyTextCtrl::OnText(wxCommandEvent & event)
{
	MyTextCtrl *win = (MyTextCtrl *)event.GetEventObject();
	const wxString changeVerb = win->IsModified() ? "changed": "set by program";
	const wxChar *data = (const wxChar *)(win->GetClientData());

	if (data)
	{
		wxLogMessage("Text %s in control \"%s\"", changeVerb, data);
	}
	else
	{
		wxLogMessage("Text %s in some control", changeVerb);
	}
}

void MyTextCtrl::OnTextEnter(wxCommandEvent & event)
{
	MyTextCtrl *win = (MyTextCtrl *)event.GetEventObject();
	const wxChar *data = (const wxChar *)(win->GetClientData());
	if (data)
	{
		wxLogMessage("Enter pressed in control '%s'", data);
	}
	else
	{
		wxLogMessage("Enter pressed in some control");
	}
}

void MyTextCtrl::OnTextURL(wxTextUrlEvent & event)
{
	long start = event.GetURLStart(),
		end = event.GetURLEnd();

	wxLogMessage("Mouse event over URL '%s': %s");
		/*GetValue().Mid(start, end - start),
		GetMouseEventDesc(ev));*/
}

void MyTextCtrl::OnTextMaxLen(wxCommandEvent & event)
{
	wxLogMessage("OnTextMaxLen Evt");
}
