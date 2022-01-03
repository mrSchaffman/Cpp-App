#include "App.h"
#include"MainFrame.h"
wxIMPLEMENT_APP(App);
bool App::OnInit()
{
	MainFrame * frame = new MainFrame("textCtrl", 500, 500);
	wxMenu *fileMenu = new wxMenu();
	fileMenu->Append(TEXT_SAVE, "&Save File\Ctrl-S", "Save the text control contents to file");
	fileMenu->Append(TEXT_LOAD, "&Load file\tCtrl-O","Load the sample file into text control");
	fileMenu->AppendSeparator();
	fileMenu->Append(TEXT_RICH_TEXT_TEST, "Show Rich Text Editor");
	fileMenu->AppendSeparator();
	fileMenu->Append(TEXT_ABOUT, "&About\tAlt-A");
	fileMenu->AppendSeparator();
	fileMenu->Append(TEXT_QUIT, "E&xit\tAlt-X", "Quit this sample");

	wxMenuBar *menuBar = new wxMenuBar(wxMB_DOCKABLE);
	menuBar->Append(fileMenu, "&File");
	frame->SetMenuBar(menuBar);

	frame->Show(true);
	return true;
}
