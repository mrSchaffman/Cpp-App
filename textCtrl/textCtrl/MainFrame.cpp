#include "MainFrame.h"
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(TEXT_QUIT, MainFrame::OnQuit)
EVT_MENU(TEXT_ABOUT, MainFrame::OnAbout)
//EVT_MENU(TEXT_SAVE, MainFrame::OnFileSave)
//EVT_MENU(TEXT_LOAD, MainFrame::OnFileLoad)
//EVT_MENU(TEXT_RICH_TEXT_TEST, MainFrame::OnRichTextTest)
//
//EVT_MENU(TEXT_LOG_KEY, MainFrame::OnLogKey)
//EVT_MENU(TEXT_LOG_CHAR, MainFrame::OnLogChar)
//EVT_MENU(TEXT_LOG_MOUSE, MainFrame::OnLogMouse)
//EVT_MENU(TEXT_LOG_TEXT, MainFrame::OnLogText)
//EVT_MENU(TEXT_LOG_FOCUS, MainFrame::OnLogFocus)
//EVT_MENU(TEXT_LOG_CLIP, MainFrame::OnLogClip)
//#if wxUSE_LOG
//EVT_MENU(TEXT_CLEAR, MainFrame::OnLogClear)
//#endif // wxUSE_LOG
//
//#if wxUSE_TOOLTIPS
//EVT_MENU(TEXT_TOOLTIPS_SETDELAY, MainFrame::OnSetTooltipDelay)
//EVT_MENU(TEXT_TOOLTIPS_ENABLE, MainFrame::OnToggleTooltips)
//#endif // wxUSE_TOOLTIPS
//
//#if wxUSE_CLIPBOARD
//EVT_MENU(TEXT_CLIPBOARD_PASTE, MainFrame::OnPasteFromClipboard)
//EVT_MENU(TEXT_CLIPBOARD_COPY, MainFrame::OnCopyToClipboard)
//
//EVT_UPDATE_UI(TEXT_CLIPBOARD_PASTE, MainFrame::OnUpdatePasteFromClipboard)
//EVT_UPDATE_UI(TEXT_CLIPBOARD_COPY, MainFrame::OnUpdateCopyToClipboard)
//#endif // wxUSE_CLIPBOARD
//
//EVT_MENU(TEXT_REMOVE, MainFrame::OnRemoveText)
//EVT_MENU(TEXT_REPLACE, MainFrame::OnReplaceText)
//EVT_MENU(TEXT_SELECT, MainFrame::OnSelectText)
//EVT_MENU(TEXT_ADD_SOME, MainFrame::OnAddText)
//EVT_MENU(TEXT_ADD_FREEZE, MainFrame::OnAddTextFreeze)
//EVT_MENU(TEXT_ADD_LINE, MainFrame::OnAddTextLine)
//EVT_MENU(TEXT_MOVE_ENDTEXT, MainFrame::OnMoveToEndOfText)
//EVT_MENU(TEXT_GET_WINDOW_COORD, MainFrame::OnGetWindowCoordinates)
//EVT_MENU(TEXT_MOVE_ENDENTRY, MainFrame::OnMoveToEndOfEntry)
//
//EVT_MENU(TEXT_SET_EDITABLE, MainFrame::OnSetEditable)
//EVT_MENU(TEXT_SET_ENABLED, MainFrame::OnSetEnabled)
//
//EVT_MENU(TEXT_LINE_DOWN, MainFrame::OnScrollLineDown)
//EVT_MENU(TEXT_LINE_UP, MainFrame::OnScrollLineUp)
//EVT_MENU(TEXT_PAGE_DOWN, MainFrame::OnScrollPageDown)
//EVT_MENU(TEXT_PAGE_UP, MainFrame::OnScrollPageUp)
//
//EVT_MENU(TEXT_GET_LINE, MainFrame::OnGetLine)
//EVT_MENU(TEXT_GET_LINELENGTH, MainFrame::OnGetLineLength)
//
//EVT_MENU(TEXT_SET, MainFrame::OnSetText)
//EVT_MENU(TEXT_CHANGE, MainFrame::OnChangeText)
//
//EVT_IDLE(MainFrame::OnIdle)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, int x, int y):wxFrame(nullptr,wxID_ANY,title,wxPoint(x,y))
{
	CreateStatusBar(2);
	mPanel = new MainPanel(this, 10, 10, 700, 500);
	mPanel->GetSizer()->Fit(this);
}
void MainFrame::OnQuit(wxCommandEvent &evt)
{
	Close(true);
}
void MainFrame::OnAbout(wxCommandEvent &evt)
{

}