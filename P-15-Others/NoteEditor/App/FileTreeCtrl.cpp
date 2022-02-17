#include "FileTreeCtrl.h"

FileTreeCtrl::FileTreeCtrl(wxWindow * parent, const wxWindowID id, const wxPoint & pos, const wxSize & size, long style) : wxTreeCtrl(parent, id, pos, size, style)
{
	CreateImageList();
	AddSampleItemsToTree(NUM_CHILDREN_PER_NODE, NUM_LEVELS);

	SetBackgroundColour(wxColour(233, 236, 239));
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
