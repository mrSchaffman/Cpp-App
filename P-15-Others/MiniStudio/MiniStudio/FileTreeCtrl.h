#pragma once
#include"wx/treectrl.h"


class FileTreeCtrl : public wxTreeCtrl
{
public:
	enum
	{
		TreeCtrlIcon_File,				 // 0
		TreeCtrlIcon_FileSelected,		 // 1
		TreeCtrlIcon_Folder,
		TreeCtrlIcon_FolderSelected,
		TreeCtrlIcon_FolderOpened,
		TreeCtrlIcon_NodeClosed,
		TreeCtrlIcon_NodeSelected,
		TreeCtrlIcon_NodeOpened,
		TreeCtrlIcon_NodeMouseOver,
		TreeCtrlIcon_NodeSelectedMouseOver,
		TreeCtrlIcon_NodeOpenedMouseOver,
		TreeCtrlIcon_FileHeader,
		TreeCtrlIcon_FileCpp,
		TreeCtrlIcon_Validate,
		TreeCtrlIcon_locked,

	};

	FileTreeCtrl(wxWindow * parent, const wxWindowID id, const wxPoint& pos, const wxSize& size, long style);
	virtual~FileTreeCtrl() = default;

	void CreateImageList(int size = 16);
	void CreateButtonsImageList(int size = 11);
	void CreateStateImageList(bool del = false);


private:

};

