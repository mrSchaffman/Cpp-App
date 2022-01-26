#include "MenuBar.h"

wxBEGIN_EVENT_TABLE(MenuBar,wxMenuBar)
	EVT_MENU(M_NEW,MenuBar::OnNew)
	EVT_MENU(M_ABOUT,MenuBar::OnAbout)
	EVT_MENU(M_EXIT,MenuBar::OnExit)
	EVT_MENU(M_ZOOM_IN,MenuBar::OnZoomIn)
	EVT_MENU(M_ZOOM_OUT,MenuBar::OnZoomOut)
wxEND_EVENT_TABLE()

MenuBar::MenuBar(wxTextCtrl*text):m_text(text)
{

	m_file = new wxMenu();
	{
		

		m_file->Append(M_NEW, wxT("New \tCtrl+N"), wxT("New File..."));
		m_file->Append(M_NEW_WINDOW, wxT("New Window \tCtrl+Shift+N"), wxT("Create new Window..."));
		m_file->Append(M_OPEN, wxT("Open... \tCtrl+O"), wxT("Open File..."));
		m_file->Append(M_SAVE, wxT("Save \tCtrl+S"), wxT("Save File..."));
		m_file->Append(M_SAVE_AS, wxT("Save As... \tCtrl+Shift+S"), wxT("Save File as..."));
		m_file->AppendSeparator();
		m_file->Append(M_PAGE_SETUP, wxT("Page Setup... "), wxT("Settings..."));
		m_file->Append(M_PRINT, wxT("Print... \tCtrl+P"), wxT("Print File..."));
		m_file->AppendSeparator();
		m_file->Append(M_EXIT, wxT("Exit"), wxT("Exit the App..."));

	}
	m_edit = new wxMenu();
	{
		m_edit->Append(M_UNDO, wxT("Undo \tCtrl+Z"), wxT("Undo"));
		m_edit->AppendSeparator();
		m_edit->Append(M_CUT, wxT("Cut \tCtrl+X"), wxT("Cut"));
		m_edit->Append(M_COPY, wxT("Copy \tCtrl+C"), wxT("Copy"));
		m_edit->Append(M_PASTE, wxT("Paste \tCtrl+V"), wxT("Paste"));
		m_edit->Append(M_DELETE, wxT("Delete \tDel"), wxT("Delete"));

		m_edit->AppendSeparator();
		m_edit->Append(M_SEARCH_WITH_BING, wxT("Cut \tCtrl+E"), wxT("Search with Bing"));
		m_edit->Append(M_FIND, wxT("Find... \tCtrl+F"), wxT("Find"));
		m_edit->Append(M_FIND_NEXT, wxT("Find Next \tF3"), wxT("Find next"));
		m_edit->Append(M_FIND_PREVIOUS, wxT("Find Previous \tShift+F3"), wxT("Find Previous"));
		m_edit->Append(M_REPLACE, wxT("Replace... \tCtrl+H"), wxT("Replace"));
		m_edit->Append(M_GOTO, wxT("Go to... \tCtrl+G"), wxT("Go to"));

		m_edit->AppendSeparator();
		m_edit->Append(M_SELECT_ALL, wxT("Select All \tCtrl+A"), wxT("Undo"));
		m_edit->Append(M_TIME_DATE, wxT("Time/Date \tF5"), wxT("Undo"));

	}
	m_format = new wxMenu();
	{
		m_format->Append(M_WRAP_WORD, wxT("Wrap Word"), wxT("Wrap word style"));
		m_format->Append(M_FONT, wxT("Font..."), wxT("Font styles"));
	}
	m_view = new wxMenu();
	{
		wxMenu *subMenu = new wxMenu();
		{
			subMenu->Append(M_ZOOM_IN, wxT("Zoom In\t Ctrl+Plus"), wxT("Zoom in the window!"));
			subMenu->Append(M_ZOOM_OUT, wxT("Zoom Out\t Ctrl+Minus"), wxT("Zoom out the window!"));
			subMenu->Append(M_ZOOM_RESTORE_DEFAULT, wxT("Restore default Zoom In\t Ctrl+0"), wxT(" restore the default Zoom of the window!"));
		}
		m_view->AppendSubMenu(subMenu, wxT("Zoom"));
		m_view->AppendCheckItem(M_STATUS_BAR, wxT("Status Bar"),wxT("Show Status Bar"))->Check();
	}
	m_help = new wxMenu();
	{
		m_help -> Append(M_VIEW_HELP, wxT("View Help"),wxT("need Help?"));
		m_help -> Append(M_SEND_FEEDBACK, wxT("Send Feedback"),wxT("send some Feedbacks"));
		m_help->AppendSeparator();
		m_help -> Append(M_ABOUT, wxT("About"),wxT("About this App."));
	}


	Append(m_file, wxT("File"));
	Append(m_edit, wxT("Edit"));
	Append(m_format, wxT("Format"));
	Append(m_view, wxT("View"));
	Append(m_help, wxT("Help"));
}

void MenuBar::OnNew(wxCommandEvent & evnt)
{
	wxString msg;
	msg.Printf("Ctrl+N was pressed");

	wxMessageBox(msg, "About My NotePad", wxOK | wxICON_INFORMATION, this);

}

void MenuBar::OnAbout(wxCommandEvent & evnt)
{
	wxString msg;
	msg.Printf("This is my Own implementation of the existing Notepad \n Copyright(C) Barth. Feudong \t 2022"
	);

	wxMessageBox(msg, "About My NotePad", wxOK | wxICON_INFORMATION, this);

}

void MenuBar::OnExit(wxCommandEvent & evnt)
{
	//auto parent = evnt.Get();
	//auto t = parent
}

void MenuBar::OnZoomIn(wxCommandEvent & event)
{
	m_text->SetFont(m_text->GetFont().Scale(1.1));
}

void MenuBar::OnZoomOut(wxCommandEvent & event)
{
	m_text->SetFont(m_text->GetFont().Scale(0.9));
}
