#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(wxWindow* parent,
	const wxWindowID id,
	const wxString& caption,
	const wxPoint& pos,
	const wxSize& size,
	const long style):wxFrame(nullptr,wxID_ANY,caption,wxDefaultPosition,wxSize(370,220))
{

}
