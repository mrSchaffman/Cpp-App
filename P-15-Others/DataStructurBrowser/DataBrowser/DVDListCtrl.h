#pragma once
//#include<list>
#include"wx/wx.h"
#include"wx/listctrl.h"
#include"wx/selstore.h" // wxSelectionStore
#include"DVD.h"

enum {
	LIST_ABOUT = wxID_ABOUT,
	LIST_CTRL = 1000
};
class DVDListCtrl :public wxListCtrl
{
private:
	void ShowContextMenu(const wxPoint& pos, long item);
	void SetColumnImage(int col, int image);
	void LogEvent(const wxListEvent& evt, const wxString& evtName);
	void LogColEvent(const wxListEvent& evt, const wxString& evtName);

	virtual wxString OnGetItemText(long item, long column)const wxOVERRIDE;
	virtual wxItemAttr* OnGetItemAttr(long item)const wxOVERRIDE;
	virtual bool OnGetItemIsChecked(long item)const wxOVERRIDE;
	virtual int OnGetItemColumnImage(long item, long column)const wxOVERRIDE;


	long m_updated;
	wxSelectionStore m_checked;

	wxDECLARE_NO_COPY_CLASS(DVDListCtrl);
	wxDECLARE_EVENT_TABLE();
public:
	// the iterators
	/*std::list<DVD>::const_iterator cIter;
	std::list<DVD>::iterator iter;*/
	DVDListCtrl(wxWindow *parent, 
		const wxWindowID id, 
		const wxPoint& pos, 
		const wxSize& size, 
		long style) :wxListCtrl(parent, id, pos, size, style)
	{
		m_updated = -1;
	}
	void InsertItemInReportView(int i);
	bool searchDVD(const DVD& dvd)const;
	// event Handlers
	//Item of the List related
	void OnItemActivated(wxListEvent&event);
	void OnItemDeselected(wxListEvent&event);
	void OnItemSelected(wxListEvent&event);
	void OnItemFocused(wxListEvent&event);

	//The middle mouse button has been clicked on an item. 
	//This is only supported by the generic control. 
	//Processes a wxEVT_LIST_ITEM_MIDDLE_CLICK event type. 
	void OnItemMiddleClick(wxListEvent&event);

	//List related
	//Begin dragging with the left mouse button. Processes a wxEVT_LIST_BEGIN_DRAG event type. 
	void OnListBeginDrag(wxListEvent&event);
	//Begin dragging with the right mouse button. Processes a wxEVT_LIST_BEGIN_RDRAG event type. 
	void OnListBeginRDrag(wxListEvent&event);
	void OnListBeginLabelEdit(wxListEvent&event);
	void OnListEndLabelEdit(wxListEvent&event);
	void OnListDeleteItem(wxListEvent&event);
	void OnListDeleteAllItems(wxListEvent&event);
	void OnListKeyDown(wxListEvent&event);
	void OnListInsertItem(wxListEvent&event);

	//A column (m_col) has been left-clicked. Processes a wxEVT_LIST_COL_CLICK event type. 
	void OnListColumnClick(wxListEvent&event);
	void OnListColumnRightClick(wxListEvent&event);
	//The user started resizing a column - can be vetoed. Processes a wxEVT_LIST_COL_BEGIN_DRAG event type. 
	void OnListColumnBeginDrag(wxListEvent&event);
	void OnListColumnDragging(wxListEvent&event);
	void OnListColumnEndDrag(wxListEvent&event);

	//Prepare cache for a virtual list control.Processes a wxEVT_LIST_CACHE_HINT event type.
	void OnListCacheHint(wxListEvent&event);

	//Hardware Event
	void OnChar(wxKeyEvent& event);
	void OnRightClick(wxMouseEvent& event);

	virtual void CheckItem(long item, bool check) wxOVERRIDE;
	virtual bool IsItemChecked(long item)const wxOVERRIDE;
	
};

