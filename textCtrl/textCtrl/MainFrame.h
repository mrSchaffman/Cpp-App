#pragma once
#include "wx/wx.h"
#include"MainPanel.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#if wxUSE_CLIPBOARD
#include "wx/dataobj.h"
#include "wx/clipbrd.h"
#endif

#if wxUSE_FILE
#include "wx/file.h"
#endif

#if wxUSE_TOOLTIPS
#include "wx/tooltip.h"
#endif

// We test for wxUSE_DRAG_AND_DROP also, because data objects may not be
// implemented for compilers that can't cope with the OLE parts in
// wxUSE_DRAG_AND_DROP.
#if !wxUSE_DRAG_AND_DROP
#undef wxUSE_CLIPBOARD
#define wxUSE_CLIPBOARD 0
#endif

enum
{
	TEXT_QUIT = wxID_EXIT,
	TEXT_ABOUT = wxID_ABOUT,
	//TEXT_LOAD = 101,
	//TEXT_SAVE,
};
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, int x, int y);
	void OnQuit(wxCommandEvent &evt);
	void OnAbout(wxCommandEvent &evt);
#if wxUSE_TOOLTIPS
	void OnSetTooltipDelay(wxCommandEvent& event);
	void OnToggleTooltips(wxCommandEvent& event);
#endif // wxUSE_TOOLTIPS

#if wxUSE_CLIPBOARD
	void OnPasteFromClipboard(wxCommandEvent& WXUNUSED(event))
	{
		wxLogMessage("Pasting text from clipboard.");
		mPanel->DoPasteFromClipboard();
	}
	void OnCopyToClipboard(wxCommandEvent& WXUNUSED(event))
	{
		wxLogMessage("Copying text to clipboard.");
		mPanel->DoCopyToClipboard();
	}

	void OnUpdatePasteFromClipboard(wxUpdateUIEvent& event)
	{
		wxClipboardLocker lockClip;

		event.Enable(wxTheClipboard->IsSupported(wxDF_TEXT));
	}

	void OnUpdateCopyToClipboard(wxUpdateUIEvent& event)
	{
		event.Enable(mPanel->HasSelection());
	}
#endif // wxUSE_CLIPBOARD

	void OnAddTextLine(wxCommandEvent& WXUNUSED(event))
	{
		static int s_n = 0;
		mPanel->mTextrich->AppendText(wxString::Format("Line %d\n", ++s_n));
	}

	void OnAddTextFreeze(wxCommandEvent& WXUNUSED(event))
	{
		DoAddText(true);
	}
	void OnAddText(wxCommandEvent& WXUNUSED(event))
	{
		DoAddText(false);
	}
	void OnRemoveText(wxCommandEvent& WXUNUSED(event))
	{
		mPanel->DoRemoveText();
	}
	void OnReplaceText(wxCommandEvent& WXUNUSED(event))
	{
		mPanel->DoReplaceText();
	}
	void OnSelectText(wxCommandEvent& WXUNUSED(event))
	{
		mPanel->DoSelectText();
	}

	void OnMoveToEndOfText(wxCommandEvent& WXUNUSED(event))
	{
		mPanel->DoMoveToEndOfText();
	}

	void OnGetWindowCoordinates(wxCommandEvent& WXUNUSED(event))
	{
		mPanel->DoGetWindowCoordinates();
	}

	void OnMoveToEndOfEntry(wxCommandEvent& WXUNUSED(event))
	{
		mPanel->DoMoveToEndOfEntry();
	}

	void OnScrollLineDown(wxCommandEvent& WXUNUSED(event))
	{
		if (!mPanel->mTextrich->LineDown())
		{
			wxLogMessage("Already at the bottom");
		}
	}

	void OnScrollLineUp(wxCommandEvent& WXUNUSED(event))
	{
		if (!mPanel->mTextrich->LineUp())
		{
			wxLogMessage("Already at the top");
		}
	}

	void OnScrollPageDown(wxCommandEvent& WXUNUSED(event))
	{
		if (!mPanel->mTextrich->PageDown())
		{
			wxLogMessage("Already at the bottom");
		}
	}

	void OnScrollPageUp(wxCommandEvent& WXUNUSED(event))
	{
		if (!mPanel->mTextrich->PageUp())
		{
			wxLogMessage("Already at the top");
		}
	}

	void OnGetLine(wxCommandEvent& WXUNUSED(event))
	{
		/*long nLine = wxGetNumberFromUser("Which line would you like to get?",
			"Enter which line you would like to get",
			"Get a line from the tabbed multiline text control");

		wxMessageBox(m_panel->mTab->GetLineText(nLine));*/
	}

	void OnGetLineLength(wxCommandEvent& WXUNUSED(event))
	{
	/*	long nLine = wxGetNumberFromUser("Which line would you like to get?",
			"Enter which line you would like to get",
			"Get length of a line from the tabbed multiline text control");

		wxMessageBox(wxString::Format("Length of line %i is:%i",
			(int)nLine,
			m_panel->mTab->GetLineLength(nLine))
		);*/
	}

#if wxUSE_LOG
	void OnLogClear(wxCommandEvent& event);
#endif // wxUSE_LOG
	void OnFileSave(wxCommandEvent& event);
	void OnFileLoad(wxCommandEvent& event);
	void OnRichTextTest(wxCommandEvent& event);

	void OnSetEditable(wxCommandEvent& event);
	void OnSetEnabled(wxCommandEvent& event);

	void OnLogKey(wxCommandEvent& event)
	{
		MyTextCtrl::msLogKey = event.IsChecked();
	}

	void OnLogChar(wxCommandEvent& event)
	{
		MyTextCtrl::msLogChar = event.IsChecked();
	}

	void OnLogMouse(wxCommandEvent& event)
	{
		MyTextCtrl::msLogMouse = event.IsChecked();
	}

	void OnLogText(wxCommandEvent& event)
	{
		MyTextCtrl::msLogText = event.IsChecked();
	}

	void OnLogFocus(wxCommandEvent& event)
	{
		MyTextCtrl::msLogFocus = event.IsChecked();
	}

	void OnLogClip(wxCommandEvent& event)
	{
		MyTextCtrl::msLogClip = event.IsChecked();
	}

	void OnSetText(wxCommandEvent& WXUNUSED(event))
	{
		mPanel->mText->SetValue("Hello, world! (what else did you expect?)");
	}

	void OnChangeText(wxCommandEvent& WXUNUSED(event))
	{
		mPanel->mText->ChangeValue("Changed, not set: no event");
	}

	void OnIdle(wxIdleEvent& event);
private:
	MainPanel * mPanel = nullptr;

	void DoAddText(bool freeze)
	{
		wxTextCtrl * const text = mPanel->mTextrich;

		if (freeze)
			text->Freeze();

		text->Clear();

		for (int i = 0; i < 100; i++)
		{
			text->AppendText(wxString::Format("Line %i\n", i));
		}

		text->SetInsertionPoint(0);

		if (freeze)
			text->Thaw();
	}

	wxDECLARE_EVENT_TABLE();
};

