#pragma once
#include "wx/wx.h"
#include"MyTextCtrl.h"

class MainPanel : public wxPanel
{
public:
	MainPanel(wxFrame *frame, int x, int y, int w, int h);
	virtual ~MainPanel() {
		//delegate wxLog::SetActiveTarget(mLogOld);
	}
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
	MyTextCtrl    *mText;
	MyTextCtrl    *mPassword;
	MyTextCtrl    *mEnter;
	MyTextCtrl    *mTab;
	MyTextCtrl    *mReadonly;
	MyTextCtrl    *mLimited;

	MyTextCtrl* mMultiText;
	MyTextCtrl    *mHorizontal;

	MyTextCtrl    *mTextrich;
	wxTextCtrl    *mLog;
	wxLog *mLogOld;
private:
	wxTextCtrl* GetFocusedText()const;
	
};

