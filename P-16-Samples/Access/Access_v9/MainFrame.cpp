#include "MainFrame.h"
wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & caption, const wxPoint & pos, const wxSize & size, long style)
	: wxFrame(nullptr,wxID_ANY, caption, pos,size,style)
{

}

void MainFrame::Init()
{
	// the initiliazation
}

bool MainFrame::Create(const wxString & caption, const wxPoint & pos, const wxSize & size, long style)
{
	Init();
	MainFrame(caption, pos, size, style);
	return true;
}
