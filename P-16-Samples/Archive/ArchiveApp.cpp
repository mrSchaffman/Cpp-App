#include "ArchiveApp.h"

wxIMPLEMENT_APP(ArchiveApp);

ArchiveApp::ArchiveApp()
{
}
int ArchiveApp::OnRun()
{
	m_archiveClassFactory = wxArchiveClassFactory::Find(m_archiveFileName, wxSTREAM_FILEEXT);
	if (!m_archiveClassFactory)
	{
		m_filterClassFactory = wxFilterClassFactory::Find(m_archiveFileName, wxSTREAM_FILEEXT);
		if (!m_filterClassFactory)
		{
			wxLogError("File \"%s\" has unsupported extension, support ones are: %s",
				m_archiveFileName,GetAllSupported(wxSTREAM_FILEEXT));
			return -1;
		}
	}

	int result = -1;

	switch (m_command)
	{
	case ArchiveApp::CMD_CREATE:
		result = DoCreate();
		break;
	case ArchiveApp::CMD_LIST:
		result = DoList();
		break;
	case ArchiveApp::CMD_EXTRACT:
		result = DoExtract();
		break;
	case ArchiveApp::CMD_NONE:
		break;
	default:
		break;
	}
}

int ArchiveApp::DoCreate()
{
	return 0;
}

int ArchiveApp::DoList()
{
	return 0;
}

int ArchiveApp::DoExtract()
{
	return 0;
}

bool ArchiveApp::CopyStreamData(wxInputStream & inputStream, wxOutputStream & outputStream, wxFileOffset offset)
{
	return false;
}

// helper function

template<typename T>
void AppendAllSupportedType(wxString&all,wxStreamProtocolType type)
{
	// getting all the Class of the Factory?
	for (const T* factory = T::GetFirst(); factory; factory->GetNext())
	{
		const wxChar* const* exts = factory->GetProtocols();
		while (*exts)
		{
			if (!all.empty())
				all += ", ";
			all += *exts++;
		}
	}
}
wxString GetAllSupported(wxStreamProtocolType type)
{
	wxString all;
	AppendAllSupportedType<wxArchiveClassFactory>(all, type);
	AppendAllSupportedType<wxFilterClassFactory>(all, type);

	return all;
}
