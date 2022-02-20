#pragma once
#include"wx/wx.h"
#include"wx/treectrl.h"
#include"TextCtrl.h"
#include"FileTreeItemData.h"
#include<array>

static const int NUM_CHILDREN_PER_NODE = 5;
static const int NUM_LEVELS = 2;
enum 
{
	ID_TREE,

};

class FileTreeCtrl : public wxTreeCtrl
{
public:
	enum 
	{
		TreeItemIcon_FolderBtnNormal,
		TreeItemIcon_FolderBtnExpanded,
		TreeItemIcon_FolderNormal,
		TreeItemIcon_FolderExpanded,
		TreeItemIcon_FileNormal,
		TreeItemIcon_FileSelected,
	};
	enum 
	{
		TreeItemState_FileAdded,
		TreeItemState_FileChanged,
		TreeItemState_FileSaved,

	};

	FileTreeCtrl(wxWindow * parent, const wxWindowID id, const wxPoint& pos, const wxSize& size, long style = wxTR_NO_BUTTONS/*wxTR_HAS_BUTTONS*/| wxTR_FULL_ROW_HIGHLIGHT | wxTR_SINGLE | wxTR_NO_LINES | wxBORDER_NONE);
	virtual~FileTreeCtrl() = default;

	void CreateImageList(int size = 16);
	void CreateButtonsImageList(int size = 11);
	void CreateStateImageList(bool del = false);
	void AddSampleItemsToTree(size_t numChildren, size_t depth);
	void AddItemsRecursively(const wxTreeItemId& idParent, size_t numChildren, size_t depth, size_t folder);

	//void LoadIcons(const std::array)
	void OnBeginDrag(wxTreeEvent& event);
	void OnBeginRDrag(wxTreeEvent& event);
	void OnEndDrag(wxTreeEvent& event);
	void OnBeginLabelEdit(wxTreeEvent& event);
	void OnEndLabelEdit(wxTreeEvent& event);
	void OnDeleteItem(wxTreeEvent& event);
	void OnItemMenu(wxTreeEvent& event);
	void OnGetInfo(wxTreeEvent& event);
	void OnSetInfo(wxTreeEvent& event);
	void OnItemExpanded(wxTreeEvent& event);
	void OnItemExpanding(wxTreeEvent& event);
	void OnItemCollapsed(wxTreeEvent& event);
	void OnItemCollapsing(wxTreeEvent& event);
	void OnSelectionChanged(wxTreeEvent& event);
	void OnSelectionChanging(wxTreeEvent& event);
	void OnTreeKeyDown(wxTreeEvent& event);
	void OnItemActivated(wxTreeEvent& event);
	void OnItemStateClick(wxTreeEvent& event);
	void OnItemRClick(wxTreeEvent& event);
	void OnImageStateClick(wxTreeEvent& event);

	void OnContextMenu(wxContextMenuEvent& event);
	void OnLMouseDown(wxMouseEvent& event);
	void OnLMouseUp(wxMouseEvent& event);
	void OnRMouseDown(wxMouseEvent& event);
	void OnRMouseUp(wxMouseEvent& event);
	void OnRMouseDClick(wxMouseEvent& event);


private:
	int          m_imageSize{};               // current size of images
	wxWindow * m_parent{};

	wxDECLARE_EVENT_TABLE();
};

