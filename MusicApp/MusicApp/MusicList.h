#pragma once
#include "wx/listctrl.h"

enum {

	LIST_ABOUT = wxID_ABOUT,
	LIST_CTRL = 1000
};

class MusicList :public wxListCtrl
{
public:
	MusicList(wxWindow * parent, std::vector<wxString>& listHeader,const wxSize& size);
	~MusicList() = default;

	void OnColClick(wxListEvent& event);
	void OnColRightClick(wxListEvent& event);
	void OnColBeginDrag(wxListEvent& event);
	void OnColDragging(wxListEvent& event);
	void OnColEndDrag(wxListEvent& event);
	void OnBeginDrag(wxListEvent& event);
	void OnBeginRDrag(wxListEvent& event);
	void OnBeginLabelEdit(wxListEvent& event);
	void OnEndLabelEdit(wxListEvent& event);
	void OnDeleteItem(wxListEvent& event);
	void OnDeleteAllItems(wxListEvent& event);
	void OnSelected(wxListEvent& event);
	void OnDeselected(wxListEvent& event);
	void OnListKeyDown(wxListEvent& event);
	void OnActivated(wxListEvent& event);
	void OnFocused(wxListEvent& event);
	void OnItemRightClick(wxListEvent& event);
	void OnChecked(wxListEvent& event);
	void OnUnChecked(wxListEvent& event);
	void OnCacheHint(wxListEvent& event);

	void setHeaders(const std::vector<wxString>& list);
	void setPlayList();
private:

	virtual wxListItemAttr * OnGetItemAttr(long item) const override;

	virtual wxListItemAttr * OnGetItemColumnAttr(long item, long column) const override;

	virtual int OnGetItemColumnImage(long item, long column) const override;

	virtual int OnGetItemImage(long item) const override;

	virtual wxString OnGetItemText(long item, long column) const override;

	wxWindow * m_parent = nullptr;

	wxDECLARE_EVENT_TABLE();


};

