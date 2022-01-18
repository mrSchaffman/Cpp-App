#include "DvDList.h"

wxBEGIN_EVENT_TABLE(DvDList, wxListCtrl)
EVT_LIST_BEGIN_DRAG(LIST_CTRL, DvDList::OnBeginDrag)
EVT_LIST_BEGIN_RDRAG(LIST_CTRL, DvDList::OnBeginRDrag)
EVT_LIST_BEGIN_LABEL_EDIT(LIST_CTRL, DvDList::OnBeginLabelEdit)
EVT_LIST_END_LABEL_EDIT(LIST_CTRL, DvDList::OnEndLabelEdit)
EVT_LIST_DELETE_ITEM(LIST_CTRL, DvDList::OnDeleteItem)
EVT_LIST_DELETE_ALL_ITEMS(LIST_CTRL, DvDList::OnDeleteAllItems)
EVT_LIST_ITEM_SELECTED(LIST_CTRL, DvDList::OnSelected)
EVT_LIST_ITEM_DESELECTED(LIST_CTRL, DvDList::OnDeselected)
EVT_LIST_KEY_DOWN(LIST_CTRL, DvDList::OnListKeyDown)
EVT_LIST_ITEM_ACTIVATED(LIST_CTRL, DvDList::OnActivated)
EVT_LIST_ITEM_FOCUSED(LIST_CTRL, DvDList::OnFocused)
EVT_LIST_ITEM_CHECKED(LIST_CTRL, DvDList::OnChecked)
EVT_LIST_ITEM_UNCHECKED(LIST_CTRL, DvDList::OnUnChecked)
EVT_LIST_ITEM_RIGHT_CLICK(LIST_CTRL, DvDList::OnItemRightClick)

EVT_LIST_COL_CLICK(LIST_CTRL, DvDList::OnColClick)
EVT_LIST_COL_RIGHT_CLICK(LIST_CTRL, DvDList::OnColRightClick)
EVT_LIST_COL_BEGIN_DRAG(LIST_CTRL, DvDList::OnColBeginDrag)
EVT_LIST_COL_DRAGGING(LIST_CTRL, DvDList::OnColDragging)
EVT_LIST_COL_END_DRAG(LIST_CTRL, DvDList::OnColEndDrag)
EVT_LIST_CACHE_HINT(LIST_CTRL, DvDList::OnCacheHint)
wxEND_EVENT_TABLE()

void DvDList::OnColClick(wxListEvent & event)
{
}
void DvDList::InsertItemInReportView(int i)
{
	wxString buf;
	buf.Printf("dvd [%d]", i);
	long tmp = InsertItem(i, buf, 0);
	SetItemData(tmp, i);

	buf.Printf("start 1, item %d", i);
	SetItem(tmp, 1, buf);

	buf.Printf("Item %d in start 2", i);
	SetItem(tmp, 2, buf);

	buf.Printf("Item %d in Producer", i);
	SetItem(tmp, 3, buf);

	buf.Printf("Item %d in Compagny", i);
	SetItem(tmp, 4, buf);

	buf.Printf("Item %d in Director", i);
	SetItem(tmp, 5, buf);
	buf.Printf("Item %d in Total", i);
	SetItem(tmp, 6, buf);
}


void DvDList::OnColRightClick(wxListEvent & event)
{
}

void DvDList::OnColBeginDrag(wxListEvent & event)
{
}

void DvDList::OnColDragging(wxListEvent & event)
{
}

void DvDList::OnColEndDrag(wxListEvent & event)
{
}

void DvDList::OnBeginDrag(wxListEvent & event)
{
}

void DvDList::OnBeginRDrag(wxListEvent & event)
{
}

void DvDList::OnBeginLabelEdit(wxListEvent & event)
{
}

void DvDList::OnEndLabelEdit(wxListEvent & event)
{
}

void DvDList::OnDeleteItem(wxListEvent & event)
{
}

void DvDList::OnDeleteAllItems(wxListEvent & event)
{
}

void DvDList::OnSelected(wxListEvent & event)
{
}

void DvDList::OnDeselected(wxListEvent & event)
{
}

void DvDList::OnListKeyDown(wxListEvent & event)
{
}

void DvDList::OnActivated(wxListEvent & event)
{
}

void DvDList::OnFocused(wxListEvent & event)
{
}

void DvDList::OnItemRightClick(wxListEvent & event)
{
}

void DvDList::OnChecked(wxListEvent & event)
{
}

void DvDList::OnUnChecked(wxListEvent & event)
{
}

void DvDList::OnCacheHint(wxListEvent & event)
{
}

void DvDList::setDvDList(wxString && fileName)
{

	//fileName.ToStdString();

	std::ifstream inFile(fileName.ToStdString());

	if (!inFile.good())
	{
		wxLogMessage("Unable to read the file!");
		return;
	}

	// read the headers in the database and set the headers of the table 
	setDvDHeaderList(inFile);

	std::string Title, Star1, Star2, Producer, Compagny, Director;
	int total;
	int dvdCount = 0;
	char ch;


	while (inFile.good() && !inFile.eof())
	{
		//Title1 Star11 Star021 Producer1 Compagny1 Director1 10
		DvD *dvd = new DvD();
		dvdCount++;

		inFile >> Title; dvd->setTitle(wxString(Title));
		inFile >> Star1; dvd->setStar1(wxString(Star1));
		inFile >> Star2; dvd->setStar2(wxString(Star2));
		inFile >> Producer;  dvd->setProducer(wxString(Producer));
		inFile >> Compagny;  dvd->setProductionCompagnie(wxString(Compagny));
		inFile >> Director;  dvd->setDirector(wxString(Director));
		inFile >> total; dvd->setNumOfCopiesInStock(total);
		//inFile >> num; dvd->setNumOfCopiesInStock(num);
		inFile.get(ch);

		if (!inFile.bad())
		{
			/*auto paire = std::make_pair(dvdCount, dvd);
			dvds.insert(paire);*/
			DvDs.push_back(dvd);
		}
		else if (inFile.eof())
			break;


	}

	// create every rows of the DvD list -> OK
	
	//int count = 0;
	//for (const auto& dvd : DvDs)
	//{

	//	wxString buf;
	//
	//	long tmp =  InsertItem(count, dvd->getTitle(), 0); // return the index of the successfully new inserted item
	//	SetItemData(tmp, count);

	//	// now designing the whole row of the item
	//	SetItem(tmp, 0, dvd->getTitle());
	//	SetItem(tmp, 1, dvd->getStar2());

	//	SetItem(tmp, 2, dvd->getStar2());

	//	SetItem(tmp, 3, dvd->getProducer());

	//	SetItem(tmp, 4, dvd->getProductionCompagnie());

	//	SetItem(tmp, 5, dvd->getDirector());

	//	buf.Printf("%d", dvd->getNumOfCopiesInStock());
	//	SetItem(tmp, 6, buf);


	//}

	wxListItem item;
	for (const auto& dvd : DvDs)
	{
	
		//insert the item
		long index = InsertItem(item);

		// set the columns of the item

		wxString rootId;
		rootId.Printf("[%d]", item.GetId());
		SetItem(index, 0, rootId);

		SetItem(index, 1, dvd->getTitle());

		SetItem(index, 2, dvd->getStar2());

		SetItem(index, 3, dvd->getStar2());

		SetItem(index, 4, dvd->getProducer());

		SetItem(index, 5, dvd->getProductionCompagnie());

		SetItem(index, 6, dvd->getDirector());

		wxString total;
		total.Printf("%d", dvd->getNumOfCopiesInStock());
		SetItem(index, 7, total);

	}

}

void DvDList::setDvDHeaderList(std::ifstream &inFile)
{
	
	std::string Title, Star1, Star2, Producer, Compagny, Director, Total;

	// read the first line of the database and set DvD headers
	{
		wxListItem itemCol;

		inFile >> Title;
		DvDsHeaders.push_back(Title);

		inFile >> Star1;
		DvDsHeaders.push_back(Star1);

		inFile >> Star2;
		DvDsHeaders.push_back(Star2);

		inFile >> Producer;
		DvDsHeaders.push_back(Producer);

		inFile >> Compagny;
		DvDsHeaders.push_back(Compagny);

		inFile >> Director;
		DvDsHeaders.push_back(Director);

		inFile >> Total;
		DvDsHeaders.push_back(Total);

	}

	// insert a column for the root Id
	wxListItem rootId;
	rootId.SetText("Root");
	rootId.SetAlign(wxLIST_FORMAT_LEFT);
	rootId.SetWidth(40);
	InsertColumn(0, rootId);

	int columnIndex = 1;
	for (const auto& header : DvDsHeaders)
	{
		// create and design the column
		wxListItem column;
		column.SetText(header);
		column.SetTextColour(*wxBLUE);
		column.SetFont(*wxITALIC_FONT);
		column.SetAlign(wxLIST_FORMAT_CENTER);

		// insert the created column
		InsertColumn(columnIndex, column);

		columnIndex++;
	}

	// insert the Header


}


wxListItemAttr * DvDList::OnGetItemAttr(long item) const
{
	return nullptr;
}

wxListItemAttr * DvDList::OnGetItemColumnAttr(long item, long column) const
{
	return nullptr;
}

int DvDList::OnGetItemImage(long item) const
{
	return 0;
}

int DvDList::OnGetItemColumnImage(long item, long column) const
{
	return 0;
}

wxString DvDList::OnGetItemText(long item, long column) const
{
	return wxString();
}
