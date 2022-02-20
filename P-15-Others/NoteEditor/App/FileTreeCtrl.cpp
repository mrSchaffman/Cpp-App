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
	CreateImageList(12);
	CreateStateImageList(false);

	//  TreeItemIcon_FolderBtnNormal,
	//	TreeItemIcon_FolderBtnExpanded,
	//	TreeItemIcon_FolderNormal,
	//	TreeItemIcon_FolderExpanded,
	//	TreeItemIcon_FileNormal,
	//	TreeItemIcon_FileSelected,

	wxTreeItemId rootFolderId =  AddRoot(wxT("Physic"), TreeItemIcon_FolderNormal, TreeItemIcon_FolderNormal);// , new ModelTreeItemData(wxT("Root Item")));
	{
		SetItemImage(rootFolderId, TreeItemIcon_FolderExpanded, wxTreeItemIcon_Expanded);
		wxTreeItemId itemFolderId1 = AppendItem(rootFolderId, wxT("chap1"), TreeItemIcon_FolderNormal, TreeItemIcon_FolderNormal);//, new ModelTreeItemData(wxT("File Item 1")));
		{
			SetItemImage(itemFolderId1, TreeItemIcon_FolderExpanded, wxTreeItemIcon_Expanded);
			SetItemBold(itemFolderId1, true);

			wxTreeItemId itemId1 = AppendItem(itemFolderId1, wxT("lecon1.txt"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new ModelTreeItemData(wxT("File Item 2")));
			wxTreeItemId itemId2 = AppendItem(itemFolderId1, wxT("lecon2.txt"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new ModelTreeItemData(wxT("File Item 2")));
			wxTreeItemId itemId3 = AppendItem(itemFolderId1, wxT("lecon3.txt"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new ModelTreeItemData(wxT("File Item 2")));
			wxTreeItemId itemId4 = AppendItem(itemFolderId1, wxT("lecon4.txt"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new ModelTreeItemData(wxT("File Item 2")));

		}
		wxTreeItemId itemFolderId2 = AppendItem(rootFolderId, wxT("chap2"), TreeItemIcon_FolderNormal, TreeItemIcon_FolderNormal);// , new ModelTreeItemData(wxT("Root Item")));
		{
			SetItemImage(itemFolderId2, TreeItemIcon_FolderExpanded, wxTreeItemIcon_Expanded);
			SetItemBold(itemFolderId2, true);

			wxTreeItemId itemId31 = AppendItem(itemFolderId2, wxT("lecon1.txt"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new ModelTreeItemData(wxT("File Item 2")));
			wxTreeItemId itemId32 = AppendItem(itemFolderId2, wxT("lecon2.txt"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new ModelTreeItemData(wxT("File Item 2")));
			wxTreeItemId itemId33 = AppendItem(itemFolderId2, wxT("lecon3.txt"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new ModelTreeItemData(wxT("File Item 2")));

			//{
			//	SetItemState(itemId31, TreeItemState_FileAdded);
			//	SetItemState(itemId32, TreeItemState_FileChanged);
			//	SetItemState(itemId33, TreeItemState_FileSaved);
			//}

		}
		wxTreeItemId itemFolderId3 = AppendItem(rootFolderId, wxT("chap3"), TreeItemIcon_FolderNormal, TreeItemIcon_FolderNormal);//, new ModelTreeItemData(wxT("File iten 3")));
		{
			SetItemImage(itemFolderId3, TreeItemIcon_FolderExpanded, wxTreeItemIcon_Expanded);
			SetItemBold(itemFolderId3, true);


		}
	}




	//m_text_screen = new  TextCtrl(this);

	SetIndent(10);
	SetFont(wxFont(12, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial"), wxFONTENCODING_SYSTEM));
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

	wxIcon icons[6];

	wxImage icon1(wxT("FolderBtnNormal.png"), wxBITMAP_TYPE_PNG);
	wxImage icon2(wxT("FolderBtnExpanded.png"), wxBITMAP_TYPE_PNG);
	wxImage icon3(wxT("FolderNormal.png"), wxBITMAP_TYPE_PNG);
	wxImage icon4(wxT("FolderExpanded.png"), wxBITMAP_TYPE_PNG);
	wxImage icon5(wxT("FileNormal.png"), wxBITMAP_TYPE_PNG);
	wxImage icon6(wxT("FileSelected.png"), wxBITMAP_TYPE_PNG);

	wxBitmap iconBmp1(icon1);
	wxBitmap iconBmp2(icon2);
	wxBitmap iconBmp3(icon3);
	wxBitmap iconBmp4(icon4);
	wxBitmap iconBmp5(icon5);
	wxBitmap iconBmp6(icon6);


	icons[TreeItemIcon_FolderBtnNormal].CopyFromBitmap(iconBmp1);
	icons[TreeItemIcon_FolderBtnExpanded].CopyFromBitmap(iconBmp2);
	icons[TreeItemIcon_FolderNormal].CopyFromBitmap(iconBmp3);
	icons[TreeItemIcon_FolderExpanded].CopyFromBitmap(iconBmp4);
	icons[TreeItemIcon_FileNormal].CopyFromBitmap(iconBmp5);
	icons[TreeItemIcon_FileSelected].CopyFromBitmap(iconBmp6);

	for (size_t i = 0; i < WXSIZEOF(icons); i++)
	{
	
		images->Add(icons[i]);
		
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
	wxImageList * states = new wxImageList(10, 10, true);

	// make an image list containing small icons
	wxBusyCursor wait;

	wxIcon icons[3];

	wxImage icon1(wxT("FileStateAdded.png"), wxBITMAP_TYPE_PNG);
	wxImage icon2(wxT("FileStateChanged.png"), wxBITMAP_TYPE_PNG);
	wxImage icon3(wxT("FileStateSaved.png"), wxBITMAP_TYPE_PNG);

	wxBitmap iconBmp1(icon1);
	wxBitmap iconBmp2(icon2);
	wxBitmap iconBmp3(icon3);

	icons[TreeItemState_FileAdded].CopyFromBitmap(iconBmp1);
	icons[TreeItemState_FileChanged].CopyFromBitmap(iconBmp2);
	icons[TreeItemState_FileSaved].CopyFromBitmap(iconBmp3);
	for (size_t i = 0; i < WXSIZEOF(states); i++)
	{

		states->Add(icons[i]);

	}

	AssignStateImageList(states);

}

void FileTreeCtrl::AddSampleItemsToTree(size_t numChildren, size_t depth)
{
	//int root = TreeCtrlIcon_TreeRoot;
	//wxTreeItemId rootId = AddRoot("Root", root, root);// , new FileTreeItemData("Root item"));

	//if (!HasFlag(wxTR_HIDE_ROOT))
	//{
	//	SetItemImage(rootId, TreeCtrlIcon_FolderOpened, wxTreeItemIcon_Expanded);

	//}
	//AddItemsRecursively(rootId, numChildren, depth, 0);
}
void FileTreeCtrl::AddItemsRecursively(const wxTreeItemId& idParent, size_t numChildren, size_t depth, size_t folder)
{
	//if (depth > 0)
	//{
	//	bool hasChildren = depth > 1;

	//	wxString str;
	//	for (size_t n = 0; n < numChildren; n++)
	//	{
	//		// at depth 1 elements won't have any more children
	//		if (hasChildren)
	//			str.Printf("%s child %u", "Folder", unsigned(n + 1));
	//		else
	//			str.Printf("%s child %u.%u", "File", unsigned(folder), unsigned(n + 1));

	//		// here we pass to AppendItem() normal and selected item images (we
	//		// suppose that selected image follows the normal one in the enum)
	//		int image, imageSel;
	//		//if (wxGetApp().ShowImages())
	//		//{
	//		image = depth == 1 ? TreeCtrlIcon_Header : TreeCtrlIcon_FolderClosed;
	//		imageSel = image + 1;
	//		//}
	//		//else
	//		//{
	//			//image = imageSel = -1;
	//		//}
	//		wxTreeItemId id = AppendItem(idParent, str, image, imageSel);// , new FileTreeItemData(str));

	//		//if (wxGetApp().ShowStates())
	//		SetItemState(id, 0);

	//		// and now we also set the expanded one (only for the folders)
	//		if (hasChildren)//&& wxGetApp().ShowImages())
	//		{
	//			SetItemImage(id, TreeCtrlIcon_FolderOpened, wxTreeItemIcon_Expanded);
	//		}

	//		AddItemsRecursively(id, numChildren, depth - 1, n + 1);
	//	}
	//}
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

}

void FileTreeCtrl::OnLMouseUp(wxMouseEvent & event)
{

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
			SetItemBackgroundColour(item, wxColour(216, 243, 220));
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
		SetItemBackgroundColour(item, wxColour(216, 243, 220));

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

