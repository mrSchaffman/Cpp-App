#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& caption):wxFrame(nullptr,wxID_ANY,caption,wxDefaultPosition,wxSize(370,220))
{
}
