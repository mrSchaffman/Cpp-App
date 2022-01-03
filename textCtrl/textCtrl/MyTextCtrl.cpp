#include "MyTextCtrl.h"

void MyTextCtrl::OnText(wxCommandEvent & event)
{
	wxLogMessage("OnText Evt");
}

void MyTextCtrl::OnTextEnter(wxCommandEvent & event)
{
	wxLogMessage("OnTextEnter Evt");
}

void MyTextCtrl::OnTextURL(wxTextUrlEvent & event)
{
	wxLogMessage("OnTextUrl Evt");
}

void MyTextCtrl::OnTextMaxLen(wxCommandEvent & event)
{
	wxLogMessage("OnTextMaxLen Evt");
}
