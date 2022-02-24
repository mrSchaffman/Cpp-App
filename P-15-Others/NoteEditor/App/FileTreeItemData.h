#pragma once
#include"wx/wx.h"
#include"wx/treectrl.h"

class FileTreeItemData : wxTreeItemData
{
public:

	FileTreeItemData(const wxString& desc) : m_desc(desc) {}

	//void ShowInfo(wxTreeCtrl *tree);

	const wxString& GetDesc() const { return m_desc; }
	//void SetValue(const wxString& value){m_data->}

private:

	wxString m_desc;
	wxTextCtrl* m_data{};

};

