#include "NumberTextCtrl.h"
BEGIN_EVENT_TABLE(NumberTextCtrl,wxTextCtrl)
	EVT_TEXT(wxID_ANY, NumberTextCtrl::OnText)
	EVT_TEXT_ENTER(wxID_ANY, NumberTextCtrl::OnTextEnter)
	EVT_TEXT_URL(wxID_ANY, NumberTextCtrl::OnTextURL)
	EVT_TEXT_MAXLEN(wxID_ANY, NumberTextCtrl::OnTextMaxLen)
END_EVENT_TABLE()

void NumberTextCtrl::OnText(wxCommandEvent & event)
{
	wxLogMessage("OnText triggered: the Text has change	");
}

void NumberTextCtrl::OnTextEnter(wxCommandEvent & event)
{
	wxLogMessage("OnTextEnter triggered:	");
}

void NumberTextCtrl::OnTextURL(wxTextUrlEvent & event)
{
	wxLogMessage("OnTextURL triggered:	");
}

void NumberTextCtrl::OnTextMaxLen(wxCommandEvent & event)
{
	wxLogMessage("OnTextMaxLen triggered: Max length of the Text occured");
}
