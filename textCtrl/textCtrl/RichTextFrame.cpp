#include "RichTextFrame.h"
#include "wx/fontdlg.h"
#include "wx/colordlg.h"
#include "wx/tokenzr.h"

wxBEGIN_EVENT_TABLE(RichTextFrame, wxFrame)
	EVT_IDLE(RichTextFrame::OnIdle)
	EVT_MENU(RICHTEXT_CLOSE, RichTextFrame::OnClose)
	EVT_MENU(RICHTEXT_LEFT_ALIGN, RichTextFrame::OnLeftAlign)
	EVT_MENU(RICHTEXT_RIGHT_ALIGN, RichTextFrame::OnRightAlign)
	EVT_MENU(RICHTEXT_CENTRE, RichTextFrame::OnCentre)
	EVT_MENU(RICHTEXT_JUSTIFY, RichTextFrame::OnJustify)
	EVT_MENU(RICHTEXT_CHANGE_FONT, RichTextFrame::OnChangeFont)
	EVT_MENU(RICHTEXT_CHANGE_TEXT_COLOUR, RichTextFrame::OnChangeTextColour)
	EVT_MENU(RICHTEXT_CHANGE_BACKGROUND_COLOUR, RichTextFrame::OnChangeBackgroundColour)
	EVT_MENU(RICHTEXT_LEFT_INDENT, RichTextFrame::OnLeftIndent)
	EVT_MENU(RICHTEXT_RIGHT_INDENT, RichTextFrame::OnRightIndent)
	EVT_MENU(RICHTEXT_TAB_STOPS, RichTextFrame::OnTabStops)
wxEND_EVENT_TABLE()


void RichTextFrame::OnClose(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

void RichTextFrame::OnLeftAlign(wxCommandEvent& WXUNUSED(event))
{
	wxTextAttr attr;
	attr.SetAlignment(wxTEXT_ALIGNMENT_LEFT);

	long start, end;
	m_textCtrl->GetSelection(&start, &end);
	m_textCtrl->SetStyle(start, end, attr);

	m_currentPosition = -1;
}

void RichTextFrame::OnRightAlign(wxCommandEvent& WXUNUSED(event))
{
	wxTextAttr attr;
	attr.SetAlignment(wxTEXT_ALIGNMENT_RIGHT);

	long start, end;
	m_textCtrl->GetSelection(&start, &end);
	m_textCtrl->SetStyle(start, end, attr);

	m_currentPosition = -1;
}

void RichTextFrame::OnJustify(wxCommandEvent& WXUNUSED(event))
{
	wxTextAttr attr;
	attr.SetAlignment(wxTEXT_ALIGNMENT_JUSTIFIED);

	long start, end;
	m_textCtrl->GetSelection(&start, &end);
	m_textCtrl->SetStyle(start, end, attr);

	m_currentPosition = -1;
}

void RichTextFrame::OnCentre(wxCommandEvent& WXUNUSED(event))
{
	wxTextAttr attr;
	attr.SetAlignment(wxTEXT_ALIGNMENT_CENTRE);

	long start, end;
	m_textCtrl->GetSelection(&start, &end);
	m_textCtrl->SetStyle(start, end, attr);

	m_currentPosition = -1;
}

void RichTextFrame::OnChangeFont(wxCommandEvent& WXUNUSED(event))
{
	wxFontData data;

	wxFontDialog dialog(this, data);

	if (dialog.ShowModal() == wxID_OK)
	{
		wxFontData retData = dialog.GetFontData();
		wxFont font = retData.GetChosenFont();

		wxTextAttr attr;
		attr.SetFont(font);

		long start, end;
		m_textCtrl->GetSelection(&start, &end);
		m_textCtrl->SetStyle(start, end, attr);

		m_currentPosition = -1;
	}
}

void RichTextFrame::OnChangeTextColour(wxCommandEvent& WXUNUSED(event))
{
	wxColourData data;
	data.SetColour(*wxBLACK);
	data.SetChooseFull(true);
	for (int i = 0; i < 16; i++)
	{
		wxColour colour((unsigned char)(i * 16), (unsigned char)(i * 16), (unsigned char)(i * 16));
		data.SetCustomColour(i, colour);
	}

	wxColourDialog dialog(this, &data);
	dialog.SetTitle("Choose the text colour");
	if (dialog.ShowModal() == wxID_OK)
	{
		wxColourData retData = dialog.GetColourData();
		wxColour col = retData.GetColour();

		wxTextAttr attr;
		attr.SetTextColour(col);

		long start, end;
		m_textCtrl->GetSelection(&start, &end);
		m_textCtrl->SetStyle(start, end, attr);

		m_currentPosition = -1;
	}
}

void RichTextFrame::OnChangeBackgroundColour(wxCommandEvent& WXUNUSED(event))
{
	wxColourData data;
	data.SetColour(*wxWHITE);
	data.SetChooseFull(true);
	for (int i = 0; i < 16; i++)
	{
		wxColour colour((unsigned char)(i * 16), (unsigned char)(i * 16), (unsigned char)(i * 16));
		data.SetCustomColour(i, colour);
	}

	wxColourDialog dialog(this, &data);
	dialog.SetTitle("Choose the text background colour");
	if (dialog.ShowModal() == wxID_OK)
	{
		wxColourData retData = dialog.GetColourData();
		wxColour col = retData.GetColour();

		wxTextAttr attr;
		attr.SetBackgroundColour(col);

		long start, end;
		m_textCtrl->GetSelection(&start, &end);
		m_textCtrl->SetStyle(start, end, attr);

		m_currentPosition = -1;
	}
}

void RichTextFrame::OnLeftIndent(wxCommandEvent& WXUNUSED(event))
{
	wxString indentStr = wxGetTextFromUser
	(
		_("Please enter the left indent in tenths of a millimetre."),
		_("Left Indent"),
		wxEmptyString,
		this
	);
	if (!indentStr.IsEmpty())
	{
		int indent = wxAtoi(indentStr);

		wxTextAttr attr;
		attr.SetLeftIndent(indent);

		long start, end;
		m_textCtrl->GetSelection(&start, &end);
		m_textCtrl->SetStyle(start, end, attr);

		m_currentPosition = -1;
	}
}

void RichTextFrame::OnRightIndent(wxCommandEvent& WXUNUSED(event))
{
	wxString indentStr = wxGetTextFromUser
	(
		_("Please enter the right indent in tenths of a millimetre."),
		_("Right Indent"),
		wxEmptyString,
		this
	);
	if (!indentStr.IsEmpty())
	{
		int indent = wxAtoi(indentStr);

		wxTextAttr attr;
		attr.SetRightIndent(indent);

		long start, end;
		m_textCtrl->GetSelection(&start, &end);
		m_textCtrl->SetStyle(start, end, attr);

		m_currentPosition = -1;
	}
}

void RichTextFrame::OnTabStops(wxCommandEvent& WXUNUSED(event))
{
	wxString tabsStr = wxGetTextFromUser
	(
		_("Please enter the tab stop positions in tenths of a millimetre, separated by spaces.\nLeave empty to reset tab stops."),
		_("Tab Stops"),
		wxEmptyString,
		this
	);

	wxArrayInt tabs;

	wxStringTokenizer tokens(tabsStr, " ");
	while (tokens.HasMoreTokens())
	{
		wxString token = tokens.GetNextToken();
		tabs.Add(wxAtoi(token));
	}

	wxTextAttr attr;
	attr.SetTabs(tabs);

	long start, end;
	m_textCtrl->GetSelection(&start, &end);
	m_textCtrl->SetStyle(start, end, attr);

	m_currentPosition = -1;
}

void RichTextFrame::OnIdle(wxIdleEvent& WXUNUSED(event))
{
	long insertionPoint = m_textCtrl->GetInsertionPoint();
	if (insertionPoint != m_currentPosition)
	{
#if wxUSE_STATUSBAR
		wxTextAttr attr;
		if (m_textCtrl->GetStyle(insertionPoint, attr))
		{
			wxString msg;
			wxString facename("unknown");
			if (attr.GetFont().IsOk())
			{
				facename = attr.GetFont().GetFaceName();
			}
			wxString alignment("unknown alignment");
			if (attr.GetAlignment() == wxTEXT_ALIGNMENT_CENTRE)
				alignment = "centred";
			else if (attr.GetAlignment() == wxTEXT_ALIGNMENT_RIGHT)
				alignment = "right-aligned";
			else if (attr.GetAlignment() == wxTEXT_ALIGNMENT_LEFT)
				alignment = "left-aligned";
			else if (attr.GetAlignment() == wxTEXT_ALIGNMENT_JUSTIFIED)
				alignment = "justified";

			msg.Printf("Facename: %s", facename);

			if (attr.HasTextColour())
			{
				msg += wxString::Format(", colour: %s",
					attr.GetTextColour().GetAsString());
			}
			else
			{
				msg += ", no colour";
			}

			msg << ", " << alignment;

			if (attr.HasFont())
			{
				if (attr.GetFont().GetWeight() == wxFONTWEIGHT_BOLD)
					msg += " BOLD";
				else if (attr.GetFont().GetWeight() == wxFONTWEIGHT_NORMAL)
					msg += " NORMAL";

				if (attr.GetFont().GetStyle() == wxFONTSTYLE_ITALIC)
					msg += " ITALIC";

				if (attr.GetFont().GetUnderlined())
					msg += " UNDERLINED";
			}

			SetStatusText(msg);
		}
#endif // wxUSE_STATUSBAR
		m_currentPosition = insertionPoint;
	}
}
