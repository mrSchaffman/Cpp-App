#include "ArchiveApp.h"
#include"wx/wfstream.h"
#include"wx/zipstrm.h"
#include"wx/cmdline.h"

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
	wxFileInputStream fileInputStream(m_archiveFileName);
	if (!fileInputStream.IsOk())
		return 1;
	if (m_archiveClassFactory)
	{
		wxScopedPtr<wxArchiveInputStream> archiveInputStream(m_archiveClassFactory->NewStream(fileInputStream));
		wxPrintf("Archive: %s\n", m_archiveFileName);
		wxPrintf("Length		Date		Time		Name\n");
		wxPrintf("------------- ----------- ----------- ----\n");

		wxFileOffset totalSize = 0;
		int entryCount = 0;

		for (wxArchiveEntry* entry = archiveInputStream->GetNextEntry(); entry; entry = archiveInputStream->GetNextEntry())
		{
			totalSize = entry->GetSize();
			entryCount++;

			wxPrintf("%10lld %s %s %\n",
				entry->GetSize(),
				entry->GetDateTime().FormatISODate(), // ISO 8601 format "YYYY-MM-DD"
				entry->GetDateTime().FormatISOTime(), // ISO 8601 format "HH:MM:SS"
				entry->GetName());
		}        
		
		wxPrintf("----------                     -------\n");
		wxPrintf("%10lld                     %d files\n", totalSize, entryCount);
	}
	else
	{
		wxPrintf("Archive \"%s\" contains a single file named \"%s\"\n",
			m_archiveFileName, wxFileName(m_archiveFileName).GetName());
	}

	return 0;
}

int ArchiveApp::DoExtract()
{
	wxFileInputStream fileInputStream(m_archiveFileName);
	if (!fileInputStream.IsOk())
		return 1;

	if (m_archiveClassFactory)
	{
		wxScopedPtr<wxArchiveInputStream> archiveStream(m_archiveClassFactory->NewStream(fileInputStream));
		wxPrintf("Extracting from: %s\n", m_archiveFileName);
		for (wxArchiveEntry* entry = archiveStream->GetNextEntry(); entry;
			entry = archiveStream->GetNextEntry())
		{
			wxPrintf("Extracting: %s...\n", entry->GetName());
			wxTempFileOutputStream outputFileStream(entry->GetName());
			if (!CopyStreamData(*archiveStream, outputFileStream, entry->GetSize()))
				return 1;
			outputFileStream.Commit();
		}
		wxPrintf("Extracted all files\n");
	}
	else
	{
		wxScopedPtr<wxFilterInputStream> filterStream(m_filterClassFactory->NewStream(fileInputStream));
		wxPrintf("Extracting single file from: %s\n", m_archiveFileName);
		wxTempFileOutputStream outputFileStream(wxFileName(m_archiveFileName).GetName());
		if (!CopyStreamData(*filterStream, outputFileStream, -1))
			return 1;
		outputFileStream.Commit();
		wxPrintf("Extracted successfully\n");
	}

	return 0;
}

bool ArchiveApp::CopyStreamData(wxInputStream & inputStream, wxOutputStream & outputStream, wxFileOffset offset)
{
	wxChar buf[128 * 1024];
	int readSize = 128 * 1024;
	wxFileOffset sizeOfReadedData = 0;

	for (;;) // infinit loop
	{
		if (offset != wxInvalidOffset && sizeOfReadedData + readSize > offset)
			readSize = offset - sizeOfReadedData;
		inputStream.Read(buf, readSize);

		size_t lastReadSize = inputStream.LastRead();
		outputStream.Write(buf, lastReadSize);
		/*	virtual wxOutputStream & 	Write (const void *buffer, size_t size)
 			Writes up to the specified amount of bytes using the data of buffer
		*/

		if (outputStream.LastWrite()!=lastReadSize)
		{
			wxLogError("Failed to output all the readed data!");
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
			sizeOfReadedData += lastReadSize;
			if (sizeOfReadedData >= offset)
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
void ArchiveApp::OnInitCmdLine(wxCmdLineParser&parser)
{
	wxAppConsole::OnInitCmdLine(parser);

	parser.AddParam("command");
	parser.AddParam("archive_name");
	parser.AddParam("file_names", wxCMD_LINE_VAL_STRING,
		wxCMD_LINE_PARAM_MULTIPLE | wxCMD_LINE_PARAM_OPTIONAL);
	parser.AddSwitch("", "force-zip64", "Force ZIP64 format when creating ZIP archives");

	parser.AddUsageText("\ncommand:");
	for (const ArchiveCommandDesc* cmdDesc = s_cmdDesc; cmdDesc->type != CMD_NONE; cmdDesc++)
		parser.AddUsageText(wxString::Format("  %s: %s", cmdDesc->id, cmdDesc->desc));

	parser.AddUsageText("\nsupported formats: " + GetAllSupported(wxSTREAM_PROTOCOL));

}
bool ArchiveApp::OnCmdLineParsed(wxCmdLineParser&parser)
{
	m_command = CMD_NONE;
	wxString command = parser.GetParam();
	for (const ArchiveCommandDesc* cmdDesc = s_cmdDesc; cmdDesc->type != CMD_NONE; cmdDesc++)
	{
		if (cmdDesc->id == command)
			m_command = cmdDesc->type;
	}
	if (m_command == CMD_NONE)
	{
		wxLogError("Invalid command: %s", command);
		return false;
	}
	m_archiveFileName = parser.GetParam(1);
	for (size_t i = 2; i < parser.GetParamCount(); i++)
		m_fileNames.push_back(parser.GetParam(i));
	m_forceZip64 = parser.FoundSwitch("force-zip64") == wxCMD_SWITCH_ON;

	return wxAppConsole::OnCmdLineParsed(parser);

}