#pragma once
#include "wx/wx.h"
#include"MyTextCtrl.h"

class MainPanel : public wxPanel
{
public:
	MainPanel(wxFrame *frame, int x, int y, int w, int h);
	virtual ~MainPanel() {
#if wxUSE_LOG
		delete wxLog::SetActiveTarget(mLogOld);
#endif // wxUSE_LOG
	}
#if wxUSE_CLIPBOARD
	void DoPasteFromClipboard();
	void DoCopyToClipboard();
#endif // wxUSE_CLIPBOARD
	void DoRemoveText();
	void DoReplaceText();
	void DoSelectText();
	void DoMoveToEndOfText();
	void DoMoveToEndOfEntry();
	void DoGetWindowCoordinates();

	bool HasSelection()const
	{
		long from, to;
		GetFocusedText()->GetSelection(&from, &to);
	}
	MyTextCtrl    *mText = nullptr;
	MyTextCtrl    *mPassword = nullptr;
	MyTextCtrl    *mEnter = nullptr;
	MyTextCtrl    *mTab = nullptr;
	MyTextCtrl    *mReadonly = nullptr;
	MyTextCtrl    *mLimited = nullptr;

	MyTextCtrl* mMultiText = nullptr;
	MyTextCtrl    *mHorizontal = nullptr;

	MyTextCtrl    *mTextrich = nullptr;
#if wxUSE_LOG
	wxTextCtrl    *mLog = nullptr;
	wxLog         *mLogOld = nullptr;
#endif // wxUSE_LOG
	
private:
	wxTextCtrl* GetFocusedText()const;
	
};

