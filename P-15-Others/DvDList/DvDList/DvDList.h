#pragma once

//#include "resource.h"
#include"wx/wx.h"
#include"DvD.h"
#include<vector>
#include<fstream>
#include"wx/listctrl.h"


enum
{
	LIST_ABOUT = wxID_ABOUT,
	LIST_CTRL = 1000
};

class DvDList : public wxListCtrl
{
public:
	DvDList (wxWindow * parent,const wxWindowID id,const wxPoint& pos,const wxSize &size,long style):wxListCtrl(parent,id,pos,size,style){}
	~DvDList() = default;

	// add one item to the dvdList in reported view.
	void InsertItemInReportView(int i);

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

	void setDvDList(wxString && filenName);
	void setDvDHeaderList(std::ifstream &inFile);

	std::vector<DvD*> getDvDList()const { return DvDs; }
	std::vector<wxString> getDvDHeaderList()const  { return DvDsHeaders; }


private:
	virtual wxListItemAttr * 	OnGetItemAttr(long item) const override;
	virtual wxListItemAttr * 	OnGetItemColumnAttr(long item, long column) const override;
	virtual int 	OnGetItemImage(long item) const override;
	virtual int 	OnGetItemColumnImage(long item, long column) const override;
	virtual wxString OnGetItemText(long item, long column) const override;

	
	std::vector<DvD*> DvDs;
//	std::map<int, DvD*> dvds;
	std::vector<wxString> DvDsHeaders;


	wxDECLARE_EVENT_TABLE();
};
