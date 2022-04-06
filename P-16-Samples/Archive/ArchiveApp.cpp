#include "ArchiveApp.h"

wxIMPLEMENT_APP(ArchiveApp);

ArchiveApp::ArchiveApp()
{
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
