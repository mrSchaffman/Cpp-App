#include "MenuBar.h"

wxBEGIN_EVENT_TABLE(MenuBar,wxMenuBar)
	EVT_MENU(M_NEW,MenuBar::OnNew)
	EVT_MENU(M_ABOUT,MenuBar::OnAbout)
	EVT_MENU(M_EXIT,MenuBar::OnExit)
wxEND_EVENT_TABLE()

MenuBar::MenuBar()
{

	m_file = new wxMenu();
	{
		m_file->Append(M_NEW, wxT("New Snip \tCtrl+N"));
		m_file->AppendSeparator();
		m_file->Append(M_SAVE_AS, wxT("Save As... \tCtrl+S"));
		wxMenu *subMenu = new wxMenu();
		{
			subMenu->Append(M_EMAIL_TO, wxT("Email Recipient"));
			subMenu->Append(M_EMAIL_TO_ATTACHEMENT, wxT("Email Recipient (as attachement)"));
		}
		m_file->AppendSubMenu(subMenu, wxT("Send To..."));
		m_file->Append(M_PRINT, wxT("Print... \tCtrl+P"));
		m_file->AppendSeparator();
		m_file->Append(M_EXIT, wxT("Exit \tCtrl+N"));

	}
	m_edit = new wxMenu();
	{
		m_edit->Append(M_COPY, wxT("Copy \tCtrl+C"));
		m_edit->AppendSeparator();
		m_edit->Append(M_EDIT_3D, wxT("Edit with in 3D \tCtrl+E"));
	}
	m_tools = new wxMenu();
	{
		wxMenu *subMenu = new wxMenu();
		{
			subMenu->AppendRadioItem(M_EMAIL_TO, wxT("Red Pen"));
			subMenu->AppendRadioItem(M_EMAIL_TO_ATTACHEMENT, wxT("Greed Pen"));
			subMenu->AppendRadioItem(M_BLEUE_PEN, wxT("Bleue Pen"));
			subMenu->AppendRadioItem(M_COSTUM_PEN, wxT("Custom Pen"));
			subMenu->AppendSeparator();
			subMenu->AppendRadioItem(M_COSTUMIZE, wxT("Customize..."));
		}
		m_tools->AppendSubMenu(subMenu, wxT("Pen"));

		m_tools->Append(M_HIGHLIGHTER, wxT("Highlighter"));
		m_tools->Append(M_ERASER, wxT("Eraser"));
		m_tools->Append(M_OPTIONS, wxT("Options..."));
	}
	m_help = new wxMenu();
	{
		m_help -> Append(M_HELP, wxT("Help\tF1"));
		m_help->AppendSeparator();
		m_help -> Append(M_ABOUT, wxT("About"));
	}


	Append(m_file, wxT("File"));
	Append(m_edit, wxT("Edit"));
	Append(m_tools, wxT("Tools"));
	Append(m_help, wxT("Help"));
}

void MenuBar::OnNew(wxCommandEvent & evnt)
{
}

void MenuBar::OnAbout(wxCommandEvent & evnt)
{
	wxString msg;
	msg.Printf("This My Snipping Tool \n Copyright(C) Barth. Feudong \t 2022"
	);

	wxMessageBox(msg, "About My Snipping", wxOK | wxICON_INFORMATION, this);

}

void MenuBar::OnExit(wxCommandEvent & evnt)
{
	//auto parent = evnt.Get();
	//auto t = parent
}
