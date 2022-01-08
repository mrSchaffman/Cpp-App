#include "MusicList.h"


wxBEGIN_EVENT_TABLE(MusicList, wxListCtrl)

EVT_LIST_BEGIN_DRAG(LIST_CTRL, MusicList::OnBeginDrag)
EVT_LIST_BEGIN_RDRAG(LIST_CTRL, MusicList::OnBeginRDrag)
EVT_LIST_BEGIN_LABEL_EDIT(LIST_CTRL, MusicList::OnBeginLabelEdit)
EVT_LIST_END_LABEL_EDIT(LIST_CTRL, MusicList::OnEndLabelEdit)
EVT_LIST_DELETE_ITEM(LIST_CTRL, MusicList::OnDeleteItem)
EVT_LIST_DELETE_ALL_ITEMS(LIST_CTRL, MusicList::OnDeleteAllItems)
EVT_LIST_ITEM_SELECTED(LIST_CTRL, MusicList::OnSelected)
EVT_LIST_ITEM_DESELECTED(LIST_CTRL, MusicList::OnDeselected)
EVT_LIST_KEY_DOWN(LIST_CTRL, MusicList::OnListKeyDown)
EVT_LIST_ITEM_ACTIVATED(LIST_CTRL, MusicList::OnActivated)
EVT_LIST_ITEM_FOCUSED(LIST_CTRL, MusicList::OnFocused)
EVT_LIST_ITEM_CHECKED(LIST_CTRL, MusicList::OnChecked)
EVT_LIST_ITEM_UNCHECKED(LIST_CTRL, MusicList::OnUnChecked)
EVT_LIST_ITEM_RIGHT_CLICK(LIST_CTRL, MusicList::OnItemRightClick)

EVT_LIST_COL_CLICK(LIST_CTRL, MusicList::OnColClick)
EVT_LIST_COL_RIGHT_CLICK(LIST_CTRL, MusicList::OnColRightClick)
EVT_LIST_COL_BEGIN_DRAG(LIST_CTRL, MusicList::OnColBeginDrag)
EVT_LIST_COL_DRAGGING(LIST_CTRL, MusicList::OnColDragging)
EVT_LIST_COL_END_DRAG(LIST_CTRL, MusicList::OnColEndDrag)
EVT_LIST_CACHE_HINT(LIST_CTRL, MusicList::OnCacheHint)

wxEND_EVENT_TABLE()


MusicList::MusicList(wxWindow * parent, std::vector<wxString>& headerList,const wxSize& size):wxListCtrl(parent,wxID_ANY,wxDefaultPosition,size , wxBORDER_THEME |wxLC_REPORT)
{
	//SetFont(*wxITALIC_FONT);

	// the header
	setHeaders(headerList);
	setPlayList();
}

void MusicList::OnColClick(wxListEvent & event)
{
}

void MusicList::OnColRightClick(wxListEvent & event)
{
}

void MusicList::OnColBeginDrag(wxListEvent & event)
{
}

void MusicList::OnColDragging(wxListEvent & event)
{
}

void MusicList::OnColEndDrag(wxListEvent & event)
{
}

void MusicList::OnBeginDrag(wxListEvent & event)
{
}

void MusicList::OnBeginRDrag(wxListEvent & event)
{
}

void MusicList::OnBeginLabelEdit(wxListEvent & event)
{
}

void MusicList::OnEndLabelEdit(wxListEvent & event)
{
}

void MusicList::OnDeleteItem(wxListEvent & event)
{
}

void MusicList::OnDeleteAllItems(wxListEvent & event)
{
}

void MusicList::OnSelected(wxListEvent & event)
{
}

void MusicList::OnDeselected(wxListEvent & event)
{
}

void MusicList::OnListKeyDown(wxListEvent & event)
{
}

void MusicList::OnActivated(wxListEvent & event)
{
}

void MusicList::OnFocused(wxListEvent & event)
{
}

void MusicList::OnItemRightClick(wxListEvent & event)
{
}

void MusicList::OnChecked(wxListEvent & event)
{
}

void MusicList::OnUnChecked(wxListEvent & event)
{
}

void MusicList::OnCacheHint(wxListEvent & event)
{
}

void MusicList::setHeaders(const std::vector<wxString>& list)
{
	wxListItem rootId;
	rootId.SetText("Root");
	rootId.SetAlign(wxLIST_FORMAT_LEFT);
	rootId.SetWidth(40);
	InsertColumn(0, rootId);

	int columnIndex = 1;
	for (auto& label : list)
	{
		// create and design the column
		wxListItem column;
		column.SetText(label);
		//column.SetTextColour(*wxBLUE);
		//column.SetFont(*wxITALIC_FONT);
		column.SetAlign(wxLIST_FORMAT_CENTER);

		// insert the created column
		InsertColumn(columnIndex, column);

		columnIndex++;
	}
}

void MusicList::setPlayList()
{
	int id = 0;
	wxListItem item;


	for (size_t i = 0; i <= 100; i++)
	{

		long index = InsertItem(id,item);

		wxString label;
		label.Printf("%d", id);
		SetItem(index, 0, label);

		label.Printf("Author %d", id);
		SetItem(index, 1, label);

		label.Printf("Title %d", i);
		SetItem(index, 2, label);

		label.Printf("Content Distributor %d", i);
		SetItem(index, 3, label);

		label.Printf("Genre %d", i);
		SetItem(index, 4, label);

		label.Printf("Provider %d", i);
		SetItem(index, 5, label);

		label.Printf("Track Number %d", i);
		SetItem(index, 6, label);

		label.Printf("Copyright %d", i);
		SetItem(index, 7, label);

		label.Printf("Language %d", i);
		SetItem(index, 8, label);

		label.Printf("Encoding Time %d", i);
		SetItem(index, 9, label);

		label.Printf("Producer %d", i);
		SetItem(index, 10, label);

		label.Printf("Writer %d", i);
		SetItem(index, 11, label);

		label.Printf("Picture %d", i);
		SetItem(index, 12, label);
		
		label.Printf("Unique File Id %d",i);
		SetItem(index, 13, label);

		label.Printf("Author Url %d", i);
		SetItem(index, 14, label);

		label.Printf("Conductor %d", i);
		SetItem(index, 15, label);

		label.Printf("Lyrics %d", i);
		SetItem(index, 16, label);

		id++;
	}
}

wxListItemAttr * MusicList::OnGetItemAttr(long item) const
{
	return nullptr;
}

wxListItemAttr * MusicList::OnGetItemColumnAttr(long item, long column) const
{
	return nullptr;
}

int MusicList::OnGetItemColumnImage(long item, long column) const
{
	return 0;
}

int MusicList::OnGetItemImage(long item) const
{
	return 0;
}

wxString MusicList::OnGetItemText(long item, long column) const
{
	return wxString();
}
