#include"DVDListCtrl.h"
wxBEGIN_EVENT_TABLE(DVDListCtrl, wxListCtrl)
//EVT_LIST_BEGIN_DRAG(LIST_CTRL, DVDListCtrl::OnBeginDrag)
//EVT_LIST_BEGIN_RDRAG(LIST_CTRL, DVDListCtrl::OnBeginRDrag)
//EVT_LIST_BEGIN_LABEL_EDIT(LIST_CTRL, DVDListCtrl::OnBeginLabelEdit)
//EVT_LIST_END_LABEL_EDIT(LIST_CTRL, DVDListCtrl::OnEndLabelEdit)
//EVT_LIST_DELETE_ITEM(LIST_CTRL, DVDListCtrl::OnDeleteItem)
//EVT_LIST_DELETE_ALL_ITEMS(LIST_CTRL, DVDListCtrl::OnDeleteAllItems)
//EVT_LIST_ITEM_SELECTED(LIST_CTRL, DVDListCtrl::OnSelected)
//EVT_LIST_ITEM_DESELECTED(LIST_CTRL, DVDListCtrl::OnDeselected)
//EVT_LIST_KEY_DOWN(LIST_CTRL, DVDListCtrl::OnListKeyDown)
//EVT_LIST_ITEM_ACTIVATED(LIST_CTRL, DVDListCtrl::OnActivated)
//EVT_LIST_ITEM_FOCUSED(LIST_CTRL, DVDListCtrl::OnFocused)
//EVT_LIST_ITEM_CHECKED(LIST_CTRL, DVDListCtrl::OnChecked)
//EVT_LIST_ITEM_UNCHECKED(LIST_CTRL, DVDListCtrl::OnUnChecked)
//EVT_LIST_ITEM_RIGHT_CLICK(LIST_CTRL, DVDListCtrl::OnItemRightClick)
//
//EVT_LIST_COL_CLICK(LIST_CTRL, DVDListCtrl::OnColClick)
//EVT_LIST_COL_RIGHT_CLICK(LIST_CTRL, DVDListCtrl::OnColRightClick)
//EVT_LIST_COL_BEGIN_DRAG(LIST_CTRL, DVDListCtrl::OnColBeginDrag)
//EVT_LIST_COL_DRAGGING(LIST_CTRL, DVDListCtrl::OnColDragging)
//EVT_LIST_COL_END_DRAG(LIST_CTRL, DVDListCtrl::OnColEndDrag)
//EVT_LIST_CACHE_HINT(LIST_CTRL, DVDListCtrl::OnCacheHint)

//EVT_CHAR(DVDListCtrl::OnChar)
//EVT_RIGHT_DOWN(DVDListCtrl::OnRightClick)
wxEND_EVENT_TABLE()
void DVDListCtrl::ShowContextMenu(const wxPoint & pos, long item)
{
	wxMenu menu;
	menu.Append(wxID_ANY, wxString::Format("Menu for dvd %ld", item));
	menu.Append(wxID_ABOUT, "&About");
	menu.AppendSeparator();
	menu.Append(wxID_EXIT, "E&xit");

	PopupMenu(&menu, pos.x, pos.y);
}
void DVDListCtrl::SetColumnImage(int col, int image)
{
	wxListItem item;
	item.SetMask(wxLIST_MASK_IMAGE);
	item.SetImage(image);
	SetColumn(col, item);
}
void DVDListCtrl::LogEvent(const wxListEvent & evt, const wxString & evtName)
{
	wxLogMessage("dvd %ld: %s()dvd title = %s, data= %ld",
		evt.GetIndex(), 
		evtName, 
		evt.GetText(),
		static_cast<long>(evt.GetData()));
}
void DVDListCtrl::LogColEvent(const wxListEvent & evt, const wxString & evtName)
{
	const int col = evt.GetColumn();

	wxLogMessage("%s: column %d (width = %d or %d)",
		evtName,
		col,
		evt.GetItem().GetWidth(),
		GetColumnWidth(col));
}
void DVDListCtrl::InsertItemInReportView(int i)
{
	wxString buf;
	buf.Printf("%d",i);
	long tmp = InsertItem(i, buf, 0);
	SetItemData(tmp, i);

	buf.Printf("Title", i);
	SetItem(tmp, 1,buf);

	buf.Printf("Title", i);
	SetItem(tmp, 2,buf);

	buf.Printf("Title", i);
	SetItem(tmp, 3,buf);

	buf.Printf("Star 1", i);
	SetItem(tmp, 4,buf);

	buf.Printf("Producer", i);
	SetItem(tmp, 5,buf);

	buf.Printf("Producer Compagny", i);
	SetItem(tmp, 6,buf);

	buf.Printf("Director", i);
	SetItem(tmp, 7,buf);

	buf.Printf("Nbr in Stock", i);
	SetItem(tmp, 8,buf);
}
bool DVDListCtrl::searchDVD(const DVD & dvd) const
{
	bool found = false;
	//while (cIter != std::cend() && !found)
	//{
	//	if (cIter->getTitle() == dvd.getTitle)
	//	{
	//		found = true;
	//	}

	//}

	return found;
}
wxString DVDListCtrl::OnGetItemText(long item, long column)const
{
	return wxString::Format("DVD: %ld of item %ld", column, item);
}
wxItemAttr* DVDListCtrl::OnGetItemAttr(long item)const
{
	if (item == m_updated)
	{
		static wxItemAttr s_attrHighlight(*wxRED, wxNullColour, wxNullFont);
		return &s_attrHighlight;
	}

	return wxListCtrl::OnGetItemAttr(item);
}
bool DVDListCtrl::OnGetItemIsChecked(long item)const
{
	return IsItemChecked(item);
}
int DVDListCtrl::OnGetItemColumnImage(long item, long column)const
{
	if (!column)
		return 0;
	if (!(item % 3) && column == 1)
		return	0;
	return -1;
}
void DVDListCtrl::CheckItem(long item, bool check)
{
	if (IsVirtual())//checking the list control mode:
	{
		m_checked.SelectItem(item, check);
		RefreshItem(item);
	}
	else
	{
		wxListCtrl::CheckItem(item, check);
	}
}
bool DVDListCtrl::IsItemChecked(long item)const
{
	if (IsVirtual())
	{
		return m_checked.IsSelected(item);
	}
	else
	{
		return wxListCtrl::IsItemChecked(item);
	}
}

