#pragma once
#include"wx/wx.h"
#include"wx/archive.h"
class ArchiveApp: public wxAppConsole
{
public:
	ArchiveApp();
	virtual~ArchiveApp() = default;

	virtual void OnInitCmdLine(wxCmdLineParser&parser)wxOVERRIDE;
	virtual bool OnCmdLineParsed(wxCmdLineParser&parser)wxOVERRIDE;
	virtual int OnRun()wxOVERRIDE;

private:
	enum ArchiveCommandType
	{
		CMD_CREATE,
		CMD_LIST,
		CMD_EXTRACT,
		CMD_NONE
	};
	struct ArchiveCommandDesc
	{
		ArchiveCommandType type;
		const char* id;
		const char*desc;
	};
	
	ArchiveCommandType m_command;
	wxString m_archiveFileName;
	wxVector<wxString> m_fileNames;
	bool m_forceZip64;
	static ArchiveCommandDesc s_cmdDesc[];
	
	const wxArchiveClassFactory* m_archiveClassFactory;
	const wxFilterClassFactory* m_filterClassFactory;

	int DoCreate();
	int DoList();
	int DoExtract();
	bool CopyStreamData(wxInputStream& inputStream, wxOutputStream& outputStream, wxFileOffset offset);


};

