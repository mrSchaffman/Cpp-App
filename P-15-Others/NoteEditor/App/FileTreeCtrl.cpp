#include "FileTreeCtrl.h"

wxBEGIN_EVENT_TABLE(FileTreeCtrl,wxTreeCtrl)
EVT_TREE_ITEM_ACTIVATED(ID_TREE, FileTreeCtrl::OnItemActivated)
EVT_TREE_BEGIN_DRAG(ID_TREE, FileTreeCtrl::OnBeginDrag)
EVT_TREE_BEGIN_RDRAG(ID_TREE, FileTreeCtrl::OnBeginRDrag)
EVT_TREE_BEGIN_LABEL_EDIT(ID_TREE, FileTreeCtrl::OnBeginLabelEdit)
EVT_TREE_END_LABEL_EDIT(ID_TREE, FileTreeCtrl::OnEndLabelEdit)
EVT_TREE_DELETE_ITEM(ID_TREE, FileTreeCtrl::OnDeleteItem)
EVT_TREE_ITEM_MENU(ID_TREE, FileTreeCtrl::OnItemMenu)
EVT_TREE_GET_INFO(ID_TREE, FileTreeCtrl::OnGetInfo)
EVT_TREE_SET_INFO(ID_TREE, FileTreeCtrl::OnSetInfo)
EVT_TREE_ITEM_EXPANDED(ID_TREE, FileTreeCtrl::OnItemExpanded)
EVT_TREE_ITEM_EXPANDING(ID_TREE, FileTreeCtrl::OnItemExpanding)
EVT_TREE_ITEM_COLLAPSED(ID_TREE, FileTreeCtrl::OnItemCollapsed)
EVT_TREE_SEL_CHANGED(ID_TREE, FileTreeCtrl::OnSelectionChanged)
EVT_TREE_ITEM_COLLAPSING(ID_TREE, FileTreeCtrl::OnItemCollapsing)
EVT_TREE_SEL_CHANGING(ID_TREE, FileTreeCtrl::OnSelectionChanging)
EVT_TREE_KEY_DOWN(ID_TREE, FileTreeCtrl::OnTreeKeyDown)
EVT_TREE_SEL_CHANGED(ID_TREE, FileTreeCtrl::OnItemStateClick)
EVT_TREE_ITEM_RIGHT_CLICK(ID_TREE, FileTreeCtrl::OnItemRClick)
EVT_TREE_STATE_IMAGE_CLICK(ID_TREE, FileTreeCtrl::OnImageStateClick)

EVT_LEFT_DOWN(FileTreeCtrl::OnLMouseDown)
EVT_LEFT_UP(FileTreeCtrl::OnLMouseUp)
EVT_RIGHT_DOWN(FileTreeCtrl::OnRMouseDown)
EVT_RIGHT_UP(FileTreeCtrl::OnRMouseUp)
EVT_RIGHT_DCLICK(FileTreeCtrl::OnRMouseDClick)

EVT_CONTEXT_MENU(FileTreeCtrl::OnContextMenu)


wxEND_EVENT_TABLE()

FileTreeCtrl::FileTreeCtrl(wxWindow * parent, const wxWindowID id, const wxPoint & pos, const wxSize & size, long style) : wxTreeCtrl(parent, id, pos, size, style)
{

	// Create a cursor from a stock identifier
	//wxCursor cursor(wxCURSOR_HAND);
	//SetCursor(wxCursor(wxCURSOR_RIGHT_ARROW));
	wxImageList*imageList = new wxImageList(12, 12); // from size(10,10)
	{
		wxIcon rootIcon;
		{
			wxImage img2(wxT("folderClosed.png"), wxBITMAP_TYPE_PNG);
			wxBitmap bmp2(img2);
			rootIcon.CopyFromBitmap(bmp2);
		}
		imageList->Add(rootIcon);

		wxIcon rootOpenIcon;
		{
			wxImage img3(wxT("folderOpened.png"), wxBITMAP_TYPE_PNG);
			wxBitmap bmp3(img3);
			rootOpenIcon.CopyFromBitmap(bmp3);

		}
		imageList->Add(rootOpenIcon);

		wxIcon fileIcon;
		{
			wxImage img3(wxT("textFile.png"), wxBITMAP_TYPE_PNG);
			wxBitmap bmp3(img3);
			fileIcon.CopyFromBitmap(bmp3);

		}
		imageList->Add(fileIcon);

	}
	AssignImageList(imageList);

	wxImageList*statesImagesList = new wxImageList(10, 10); // from size(10,10)
	{
		wxIcon validate;
		{
			wxImage img2(wxT("validate.png"), wxBITMAP_TYPE_PNG);
			wxBitmap bmp2(img2);
			validate.CopyFromBitmap(bmp2);
		}
		statesImagesList->Add(validate);

		wxIcon NodeClosed;
		{
			wxImage img2(wxT("NodeClosed.png"), wxBITMAP_TYPE_PNG);
			wxBitmap bmp2(img2);
			NodeClosed.CopyFromBitmap(bmp2);
		}
		statesImagesList->Add(NodeClosed);

		wxIcon NodeOpened;
		{
			wxImage img3(wxT("NodeOpened.png"), wxBITMAP_TYPE_PNG);
			wxBitmap bmp3(img3);
			NodeOpened.CopyFromBitmap(bmp3);

		}
		statesImagesList->Add(NodeOpened);

		wxIcon nodeClosedMouseOver;
		{
			wxImage img3(wxT("nodeClosedMouseOver.png"), wxBITMAP_TYPE_PNG);
			wxBitmap bmp3(img3);
			nodeClosedMouseOver.CopyFromBitmap(bmp3);

		}
		statesImagesList->Add(nodeClosedMouseOver);

		wxIcon nodeOpenedMouseOver;
		{
			wxImage img3(wxT("nodeOpenedMouseOver.png"), wxBITMAP_TYPE_PNG);
			wxBitmap bmp3(img3);
			nodeOpenedMouseOver.CopyFromBitmap(bmp3);

		}
		statesImagesList->Add(nodeOpenedMouseOver);

	}
	//
	AssignStateImageList(statesImagesList);

	wxTreeItemId rootId =  AddRoot(wxT("Project 1"), 0, 0);// , new ModelTreeItemData(wxT("Root Item")));
	{
		Expand(rootId);
		SetItemState(rootId, 1);
		SetItemImage(rootId, 1, wxTreeItemIcon_Expanded);
		// set the other image when the item is expanded using:
		// EVT_TREE_ITEM_EXPANDED(id, func):
		// The item has been expanded.Processes a wxEVT_TREE_ITEM_EXPANDED event type.

	}
	wxTreeItemId itemId1 = AppendItem(rootId, wxT("file1.txt"), 2, 2);//, new ModelTreeItemData(wxT("File Item 1")));
	{
		//SetItemBackgroundColour(itemId1, wxColour(216, 243, 220));
		{
			// use EVT_TREE_ITEM_ACTIVATED(id, func): to the set the ItemBackgroundColour
		}
		SetItemBold(itemId1, true);
		SetItemFont(itemId1, wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial"), wxFONTENCODING_ISO8859_1));

	}
	wxTreeItemId itemId2 = AppendItem(rootId, wxT("file2.txt"), 2, 2);// , new ModelTreeItemData(wxT("File Item 2")));
	{
		SetItemState(itemId2, 0);

	}
	wxTreeItemId itemId3 = AppendItem(rootId, wxT("Project 1.1"), 0, 1);//, new ModelTreeItemData(wxT("File iten 3")));
	wxTreeItemId itemId31 = AppendItem(itemId3, wxT("file11.txt"), 2, 2);// , new ModelTreeItemData(wxT("File Item 2")));
	wxTreeItemId itemId32 = AppendItem(itemId3, wxT("file12.txt"), 2, 2);// , new ModelTreeItemData(wxT("File Item 2")));
	wxTreeItemId itemId33 = AppendItem(itemId3, wxT("file13.txt"), 2, 2);// , new ModelTreeItemData(wxT("File Item 2")));





	//m_text_screen = new  TextCtrl(this);

	SetIndent(15);
	SetBackgroundColour(wxColour(183, 228, 199));
}

void FileTreeCtrl::CreateImageList(int size)
{
	if (size == -1)
	{
		SetImageList(nullptr);
		return;
	}
	if (size == 0)
		size = m_imageSize;
	else
		m_imageSize = size;

	// make an image list containing small icons
	wxImageList * images = new wxImageList(size, size, true);

	wxBusyCursor wait;

	std::array<wxIcon, 17> icons;


	wxImage icon1(wxT("treeRoot.png"), wxBITMAP_TYPE_PNG);
	wxImage icon2(wxT("folderClosed.png"), wxBITMAP_TYPE_PNG);
	//wxImage icon3(wxT("folderSelected.png"), wxBITMAP_TYPE_PNG);
	wxImage icon4(wxT("folderOpened.png"), wxBITMAP_TYPE_PNG);
	wxImage icon5(wxT("nodeClosed.png"), wxBITMAP_TYPE_PNG);
	//wxImage icon6(wxT("nodeSelected.png"), wxBITMAP_TYPE_PNG);
	wxImage icon7(wxT("nodeOpened.png"), wxBITMAP_TYPE_PNG);
	wxImage icon8(wxT("nodeClosedMouseOver.png"), wxBITMAP_TYPE_PNG);
	//wxImage icon9(wxT("nodeSelectedMouseOver.png"), wxBITMAP_TYPE_PNG);
	wxImage icon10(wxT("nodeOpenedMouseOver.png"), wxBITMAP_TYPE_PNG);
	wxImage icon11(wxT("header.png"), wxBITMAP_TYPE_PNG);
	wxImage icon12(wxT("cplusplus.png"), wxBITMAP_TYPE_PNG);
	wxImage icon13(wxT("validate.png"), wxBITMAP_TYPE_PNG);
	wxImage icon14(wxT("locked.png"), wxBITMAP_TYPE_PNG);

	wxBitmap iconBmp1(icon1);
	wxBitmap iconBmp2(icon2);
	//wxBitmap iconBmp3(icon3);
	wxBitmap iconBmp4(icon4);
	wxBitmap iconBmp5(icon5);
	//wxBitmap iconBmp6(icon6);
	wxBitmap iconBmp7(icon7);
	wxBitmap iconBmp8(icon8);
	//wxBitmap iconBmp9(icon9);
	wxBitmap iconBmp10(icon10);
	wxBitmap iconBmp11(icon11);
	wxBitmap iconBmp12(icon12);
	wxBitmap iconBmp13(icon13);
	wxBitmap iconBmp14(icon14);

	icons[TreeCtrlIcon_TreeRoot].CopyFromBitmap(iconBmp1);
	icons[TreeCtrlIcon_FolderClosed].CopyFromBitmap(iconBmp2);
	//icons[TreeCtrlIcon_FolderSelected].CopyFromBitmap(iconBmp3);
	icons[TreeCtrlIcon_FolderOpened].CopyFromBitmap(iconBmp4);
	icons[TreeCtrlIcon_NodeClosed].CopyFromBitmap(iconBmp5);
	//icons[TreeCtrlIcon_NodeSelected].CopyFromBitmap(iconBmp6);
	icons[TreeCtrlIcon_NodeOpened].CopyFromBitmap(iconBmp7);
	icons[TreeCtrlIcon_NodeMouseOver].CopyFromBitmap(iconBmp8);
	//icons[TreeCtrlIcon_NodeSelectedMouseOver].CopyFromBitmap(iconBmp9);
	icons[TreeCtrlIcon_NodeOpenedMouseOver].CopyFromBitmap(iconBmp10);
	icons[TreeCtrlIcon_Header].CopyFromBitmap(iconBmp11);
	icons[TreeCtrlIcon_Cplusplus].CopyFromBitmap(iconBmp12);
	icons[TreeCtrlIcon_Validate].CopyFromBitmap(iconBmp13);
	icons[TreeCtrlIcon_Locked].CopyFromBitmap(iconBmp14);

	for (const auto& i : icons)
	{
		images->Add(i);
	}

	AssignImageList(images);

}

void FileTreeCtrl::CreateButtonsImageList(int size)
{

}

void FileTreeCtrl::CreateStateImageList(bool del)
{
	if (del)
	{
		SetStateImageList(nullptr);
		return;
	}
	// make an image list containing small icons
	wxImageList * states = new wxImageList(16, 16, true);
	wxBusyCursor wait;

	std::array<wxIcon, 14> icons;


	wxImage icon2(wxT("folderClosed.png"), wxBITMAP_TYPE_PNG);
	wxImage icon5(wxT("nodeClosed.png"), wxBITMAP_TYPE_PNG);
	wxImage icon8(wxT("nodeMouseOver.png"), wxBITMAP_TYPE_PNG);

	wxImage icon11(wxT("header.png"), wxBITMAP_TYPE_PNG);
	wxImage icon12(wxT("cplusplus.png"), wxBITMAP_TYPE_PNG);
	wxImage icon13(wxT("validate.png"), wxBITMAP_TYPE_PNG);
	wxImage icon14(wxT("locked.png"), wxBITMAP_TYPE_PNG);

	wxImage icon3(wxT("folderSelected.png"), wxBITMAP_TYPE_PNG);
	wxImage icon6(wxT("nodeSelected.png"), wxBITMAP_TYPE_PNG);
	wxImage icon9(wxT("nodeSelectedMouseOver.png"), wxBITMAP_TYPE_PNG);

	wxImage icon4(wxT("folderOpened.png"), wxBITMAP_TYPE_PNG);
	wxImage icon7(wxT("nodeOpened.png"), wxBITMAP_TYPE_PNG);
	wxImage icon10(wxT("nodeOpenedMouseOver.png"), wxBITMAP_TYPE_PNG);


	wxBitmap iconBmp2(icon2);
	wxBitmap iconBmp3(icon3);
	wxBitmap iconBmp4(icon4);
	wxBitmap iconBmp5(icon5);
	wxBitmap iconBmp6(icon6);
	wxBitmap iconBmp7(icon7);
	wxBitmap iconBmp8(icon8);
	wxBitmap iconBmp9(icon9);
	wxBitmap iconBmp10(icon10);
	wxBitmap iconBmp11(icon11);
	wxBitmap iconBmp12(icon12);
	wxBitmap iconBmp13(icon13);
	wxBitmap iconBmp14(icon14);

	icons[TreeCtrlIcon_FolderClosed].CopyFromBitmap(iconBmp2);
	icons[TreeCtrlIcon_FolderSelected].CopyFromBitmap(iconBmp3);
	icons[TreeCtrlIcon_FolderOpened].CopyFromBitmap(iconBmp4);
	icons[TreeCtrlIcon_NodeClosed].CopyFromBitmap(iconBmp5);
	icons[TreeCtrlIcon_NodeSelected].CopyFromBitmap(iconBmp6);
	icons[TreeCtrlIcon_NodeOpened].CopyFromBitmap(iconBmp7);
	icons[TreeCtrlIcon_NodeMouseOver].CopyFromBitmap(iconBmp8);
	icons[TreeCtrlIcon_NodeSelectedMouseOver].CopyFromBitmap(iconBmp9);
	icons[TreeCtrlIcon_NodeOpenedMouseOver].CopyFromBitmap(iconBmp10);
	icons[TreeCtrlIcon_Header].CopyFromBitmap(iconBmp11);
	icons[TreeCtrlIcon_Cplusplus].CopyFromBitmap(iconBmp12);
	icons[TreeCtrlIcon_Validate].CopyFromBitmap(iconBmp13);
	icons[TreeCtrlIcon_Locked].CopyFromBitmap(iconBmp14);

	for (size_t i = 0; i <= icons.size(); i++)
	{
		states->Add(icons[i]);
	}

	AssignImageList(states);

}

void FileTreeCtrl::AddSampleItemsToTree(size_t numChildren, size_t depth)
{
	int root = TreeCtrlIcon_TreeRoot;
	wxTreeItemId rootId = AddRoot("Root", root, root);// , new FileTreeItemData("Root item"));

	if (!HasFlag(wxTR_HIDE_ROOT))
	{
		SetItemImage(rootId, TreeCtrlIcon_FolderOpened, wxTreeItemIcon_Expanded);

	}
	AddItemsRecursively(rootId, numChildren, depth, 0);
}
void FileTreeCtrl::AddItemsRecursively(const wxTreeItemId& idParent, size_t numChildren, size_t depth, size_t folder)
{
	if (depth > 0)
	{
		bool hasChildren = depth > 1;

		wxString str;
		for (size_t n = 0; n < numChildren; n++)
		{
			// at depth 1 elements won't have any more children
			if (hasChildren)
				str.Printf("%s child %u", "Folder", unsigned(n + 1));
			else
				str.Printf("%s child %u.%u", "File", unsigned(folder), unsigned(n + 1));

			// here we pass to AppendItem() normal and selected item images (we
			// suppose that selected image follows the normal one in the enum)
			int image, imageSel;
			//if (wxGetApp().ShowImages())
			//{
			image = depth == 1 ? TreeCtrlIcon_Header : TreeCtrlIcon_FolderClosed;
			imageSel = image + 1;
			//}
			//else
			//{
				//image = imageSel = -1;
			//}
			wxTreeItemId id = AppendItem(idParent, str, image, imageSel);// , new FileTreeItemData(str));

			//if (wxGetApp().ShowStates())
			SetItemState(id, 0);

			// and now we also set the expanded one (only for the folders)
			if (hasChildren)//&& wxGetApp().ShowImages())
			{
				SetItemImage(id, TreeCtrlIcon_FolderOpened, wxTreeItemIcon_Expanded);
			}

			AddItemsRecursively(id, numChildren, depth - 1, n + 1);
		}
	}
	//else: done!
}

void FileTreeCtrl::OnBeginDrag(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnBeginRDrag(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnEndDrag(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnBeginLabelEdit(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnEndLabelEdit(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnDeleteItem(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnContextMenu(wxContextMenuEvent & event)
{
}

void FileTreeCtrl::OnLMouseDown(wxMouseEvent & event)
{
	//wxTreeItemId item = HitTest(event.GetPosition());
	//if (item.IsOk())
	//{
	//	UnselectItem(item);
	//	SetItemBackgroundColour(item, wxColour(216, 243, 220));
	//	//wxMessageBox("Left mouse button down");

	//}

	//event.Skip();

}

void FileTreeCtrl::OnLMouseUp(wxMouseEvent & event)
{
	//event.Skip();

}

void FileTreeCtrl::OnItemMenu(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnGetInfo(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnSetInfo(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnItemExpanded(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnItemExpanding(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnItemCollapsed(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnItemCollapsing(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnSelectionChanged(wxTreeEvent & event)
{
	//wxTreeItemId item = event.GetItem();

	//if (!ItemHasChildren(item))
	//{
	//	if (GetItemBackgroundColour(item) == wxColour(216, 243, 220))
	//	{
	//		event.Skip();
	//	}
	//	else
	//	{
	//		SetItemBackgroundColour(item, wxColour(216, 243, 220));
	//	}

	//}
	//else
	//{
	//	if (IsExpanded(item))
	//	{
	//		CollapseAllChildren(item);
	//	}
	//	else
	//	{
	//		Expand(item);

	//	}

	//}
	//wxTreeItemId item = event.GetItem();
	////wxTreeItemId prevItem = GetPrevSibling(event.GetItem());
	//if (item.IsOk())
	//{
	//	UnselectItem(item);
	//	SetItemBackgroundColour(item, wxColour(0, 243, 220));

	//}
}

void FileTreeCtrl::OnSelectionChanging(wxTreeEvent & event)
{

}

void FileTreeCtrl::OnTreeKeyDown(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnItemActivated(wxTreeEvent & event)
{
	wxTreeItemId item = event.GetItem();

	if (!ItemHasChildren(item))
	{
		if (GetItemBackgroundColour(item) == wxColour(216, 243, 220))
		{
			event.Skip();
		}
		else
		{
			SetItemBackgroundColour(item, wxColour(183, 228, 199));
		}

	}
	else
	{
		if (IsExpanded(item))
		{
			CollapseAllChildren(item);
		}
		else
		{
			Expand(item);

		}

	}
}

void FileTreeCtrl::OnItemStateClick(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnItemRClick(wxTreeEvent & event)
{
}

void FileTreeCtrl::OnRMouseDown(wxMouseEvent & event)
{
	wxMessageBox("Right mouse button down");

	event.Skip();

}

void FileTreeCtrl::OnRMouseUp(wxMouseEvent & event)
{

}

void FileTreeCtrl::OnRMouseDClick(wxMouseEvent & event)
{
}

void FileTreeCtrl::OnImageStateClick(wxTreeEvent & event)
{
}

