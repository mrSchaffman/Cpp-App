#pragma once
#include"wx/wx.h"
#include"wx/treectrl.h"
#include"FileTreeItemData.h"
#include<array>

static const int NUM_CHILDREN_PER_NODE = 5;
static const int NUM_LEVELS = 2;

class FileTreeCtrl : public wxTreeCtrl
{
public:
	enum
	{
		TreeCtrlIcon_TreeRoot,				 // 0
		TreeCtrlIcon_FolderClosed,
		TreeCtrlIcon_FolderSelected,
		TreeCtrlIcon_FolderOpened,
		TreeCtrlIcon_NodeClosed,
		TreeCtrlIcon_NodeSelected,
		TreeCtrlIcon_NodeOpened,
		TreeCtrlIcon_NodeMouseOver,
		TreeCtrlIcon_NodeSelectedMouseOver,
		TreeCtrlIcon_NodeOpenedMouseOver,
		TreeCtrlIcon_Header,
		TreeCtrlIcon_Cplusplus,
		TreeCtrlIcon_Validate,
		TreeCtrlIcon_Locked,

	};

	FileTreeCtrl(wxWindow * parent, const wxWindowID id, const wxPoint& pos, const wxSize& size, long style);
	virtual~FileTreeCtrl() = default;

	void CreateImageList(int size = 16);
	void CreateButtonsImageList(int size = 11);
	void CreateStateImageList(bool del = false);
	void AddSampleItemsToTree(size_t numChildren, size_t depth);
	void AddItemsRecursively(const wxTreeItemId& idParent, size_t numChildren, size_t depth, size_t folder);

	//void LoadIcons(const std::array)

private:
	int          m_imageSize;               // current size of images

};

