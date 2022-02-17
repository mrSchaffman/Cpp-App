#pragma once
#include"wx/wx.h"
#include"wx/treectrl.h"

class FileTreeItemData : wxTreeItemData
{
public:

	FileTreeItemData(const wxString& desc) : m_desc(desc) {}

	//void ShowInfo(wxTreeCtrl *tree);

	const wxString& GetDesc() const { return m_desc; }

private:

	wxString m_desc;

};

