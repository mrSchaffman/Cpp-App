#include "ArchiveApp.h"
#include"wx/wfstream.h"
#include"wx/zipstrm.h"

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
	if (m_fileNames.empty())
	{
		wxLogError("Need at least one file to add to archive");
		return -1;
	}

	wxTempFileOutputStream fileOutputStream(m_archiveFileName);
	if (m_archiveClassFactory && fileOutputStream.IsOk())
	{
		wxScopedPtr<wxArchiveOutputStream> archiveOutputStream(m_archiveClassFactory->NewStream(fileOutputStream));
		if (m_archiveClassFactory->GetProtocol().IsSameAs("zip",false)&&m_forceZip64)
			reinterpret_cast<wxZipOutputStream*>(archiveOutputStream.get())->SetFormat(wxZIP_FORMAT_ZIP64);
		wxVector<wxString>::iterator fileName;
		for (fileName = m_fileNames.begin(); fileName != m_fileNames.end(); fileName++)
		{
			wxFileName inputFileName(*fileName);
			wxPrintf("Adding %s...\n", inputFileName.GetFullName());
			wxFileInputStream inputFileStream(*fileName);
			if (!inputFileStream.IsOk())
			{
				wxLogError("Cannot open the file");
				return 1;
			}

			if (!archiveOutputStream->PutNextEntry(inputFileName.GetFullName(),
				wxDateTime::Now(),
				inputFileStream.GetLength()))
			{
				break;
			}
			if (!CopyStreamData(inputFileStream,*archiveOutputStream,inputFileStream.GetLength()))
			{
				return 1;
			}
		}
		if (!archiveOutputStream->Close());
		return 1;

		
	}
	else
	{
		if (m_fileNames.size() != 1)
		{
			wxLogError("Filter-based formats only support archives consisting og a single file.");
			return -1;
		}

		wxScopedPtr<wxFilterOutputStream> filterOutputStream(m_filterClassFactory->NewStream(fileOutputStream));
		wxFileInputStream inputFileStream(*m_fileNames.begin()); // get the only entry in the container.
		if (!inputFileStream.IsOk())
		{
			wxLogError("Cannot open the  file!");
			return -1;
		}
		if (!CopyStreamData(inputFileStream,*filterOutputStream,inputFileStream.GetLength()))
		{
			return 1;
		}

	}
	fileOutputStream.Commit();
	wxPrintf("Archive created successfuly!\n");






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
	wxChar buf[128 * 1024];
	int readSize = 128 * 1024;
	wxFileOffset copiedData = 0;

	for (;;) // infinit loop
	{
		if (offset != wxInvalidOffset && copiedData + readSize > offset)
			readSize = offset - copiedData;
		inputStream.Read(buf, readSize);

		size_t lastReadSize = inputStream.LastRead();
		outputStream.Write(buf, lastReadSize);
		/*	virtual wxOutputStream & 	Write (const void *buffer, size_t size)
 			Writes up to the specified amount of bytes using the data of buffer
		*/

		if (outputStream.LastWrite()!=lastReadSize)
		{
			wxLogError("Failed to output data!");
			return false;
		}
		if (offset == wxInvalidOffset)
		{
			if (inputStream.Eof())
			{
				break;
			}
		}
		else
		{
			copiedData += lastReadSize;
			if (copiedData >= offset)
			{
				break;
			}
		}
	}
	return true;
}

// helper function
// single responsability principle

template<typename T>
void AppendAllSupportedType(wxString&all,wxStreamProtocolType type)
{
	// getting all the Class of the Factory?
	for (const T* factory = T::GetFirst(); factory; factory->GetNext())
	{
		const wxChar* const* exts = factory->GetProtocols(type);
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
