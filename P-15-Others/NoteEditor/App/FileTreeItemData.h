#pragma once
#include"wx/wx.h"
#include"wx/file.h"
#include"wx/textfile.h"
//#include"wx/treectrl.h"
#include "wx/treebase.h"

class FileTreeItemData : wxTreeItemData
{
public:

	FileTreeItemData(const wxString& filename = wxT("Untitled")) : m_file_name(filename)
	{
		//m_lines = data->GetNumberOfLines();
		//m_data = new wxTextCtrl()
	}
	virtual ~FileTreeItemData() = default;
	//void ShowInfo(wxTreeCtrl *tree);

	// Accessors
	void SetData(const wxString& value) { m_data->SetValue(value); }
	void SetFilename(const wxString& value) { m_file_name = value; }
	wxString GetFilename() { return m_file_name; }

	bool SaveDataInFile() 
	{
		wxFile file;
		if (!file.Open(m_file_name, wxFile::write))
			return false;
		bool ok;
		for (size_t line = 0; ok && line < m_lines; line++)
		{
			ok = file.Write(m_data->GetLineText(line) + wxTextFile::GetEOL());
		}
		file.Close();
		return ok;
	};
	void FilePrepend(const wxString& text)
	{
		wxTextFile file;
		if (file.Open(m_file_name))
		{
			size_t i;
			for (i = 0; i < file.GetLineCount(); i++)
			{
				file[i] = text + file[i];
			}
			file.Write();
		}
	}
private:

	wxTextCtrl* m_data{};
	int m_lines{};
	wxString m_file_name{};

};

