#include "MenuBar.h"

wxBEGIN_EVENT_TABLE(MenuBar,wxMenuBar)
	EVT_MENU(M_NEW,MenuBar::OnNew)
	EVT_MENU(M_NEW_PROJECT,MenuBar::OnNewProject)
	EVT_MENU(M_OPEN,MenuBar::OnOpen)
	EVT_MENU(M_OPEN_FOLDER,MenuBar::OnOpenNewFolder)
	EVT_MENU(M_SAVE,MenuBar::OnSave)
	EVT_MENU(M_SAVE_AS,MenuBar::OnSaveAs)
	EVT_MENU(M_STATUS_BAR,MenuBar::OnSetStatusBar)
	EVT_MENU(M_ABOUT,MenuBar::OnAbout)
	EVT_MENU(M_EXIT,MenuBar::OnExit)
	EVT_MENU(M_ZOOM_IN,MenuBar::OnZoomIn)
	EVT_MENU(M_ZOOM_OUT,MenuBar::OnZoomOut)
	EVT_MENU(M_PAGE_SETUP,MenuBar::OnPageSettingDialog)
wxEND_EVENT_TABLE()

MenuBar::MenuBar(wxFrame*parent, SplitterItemWin *treesWin): m_parent(parent), m_trees(treesWin)

{

	wxMenu*m_file = new wxMenu();
	{
		

		m_file->Append(M_NEW, wxT("New Project \tCtrl+N"), wxT("New File..."));
		m_file->Append(M_NEW_WINDOW, wxT("New Window \tCtrl+Shift+N"), wxT("Create new Window..."));
		wxMenu *subMenu = new wxMenu();
		{
			subMenu->Append(M_OPEN_FOLDER, wxT("Open Folder \t Ctrl+Plus"), wxT("Choose a Folder!"));
		}
		m_file->AppendSubMenu(subMenu, wxT("Open..."));

		//m_file->Append(M_OPEN, wxT("Open... \tCtrl+O"), wxT("Open File..."));
		m_file->Append(M_SAVE, wxT("Save \tCtrl+S"), wxT("Save File..."));
		m_file->Append(M_SAVE_AS, wxT("Save As... \tCtrl+Shift+S"), wxT("Save File as..."));
		m_file->AppendSeparator();
		m_file->Append(M_PAGE_SETUP, wxT("Page Setup... "), wxT("Settings..."));
		m_file->Append(M_PRINT, wxT("Print... \tCtrl+P"), wxT("Print File..."));
		m_file->AppendSeparator();
		m_file->Append(M_EXIT, wxT("Exit"), wxT("Exit the App..."));

	}
	wxMenu*m_edit = new wxMenu();
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
	wxMenu*m_format = new wxMenu();
	{
		m_format->Append(M_WRAP_WORD, wxT("Wrap Word"), wxT("Wrap word style"));
		m_format->Append(M_FONT, wxT("Font..."), wxT("Font styles"));
	}
	wxMenu*m_view = new wxMenu();
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
	wxMenu*m_help = new wxMenu();
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
	
}

void MenuBar::OnNewProject(wxCommandEvent & evnt)
{

}

void MenuBar::OnOpen(wxCommandEvent & evnt)
{
	// ToDo
	//wxString filename = m_parent->GetFilename();
	//if (...current content has not been saved...)
	//{
	//	if (wxMessageBox(_("Current content has not been saved! Proceed?"), _("Please confirm"),
	//		wxICON_QUESTION | wxYES_NO, this) == wxNO)
	//		return;
	//	//else: proceed asking to the user the new file to open
	//}
	wxString caption = wxT("Choose a file");
	wxString wildcard = wxT("Text Files(*.txt)|*.txt");
	wxString defaultDir = wxT("c:\\temp");

	wxString defaultFilename = wxEmptyString;

	//wxSystemOptions::SetOption(wxT("NodeEditor"),1);
	wxFileDialog dialog(this, caption, defaultDir, defaultFilename, wildcard, wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if (dialog.ShowModal() == wxID_OK)
	{
		wxString path = dialog.GetPath();
		int filterIndex = dialog.GetFilterIndex();
	}

	// proceed loading the file chosen by the user;
	wxFileInputStream input_stream(dialog.GetPath());
	if (!input_stream.IsOk())
	{
		wxLogError("Cannot open file '%s'.", dialog.GetPath());
		return;
	}

	// read the file and write in the GUI
	{
		//wxMessageBox(dialog.GetFilename());
		wxString buf;
		buf.Printf("%s - NoteEditor", dialog.GetFilename());
		m_parent->SetTitle(buf);
	}

}

void MenuBar::OnOpenNewFolder(wxCommandEvent & evnt)
{

	wxString defaultPath = wxT("c:\\temp");
	wxDirDialog dialog(this, wxT("Select Directory"), defaultPath, wxDD_DEFAULT_STYLE|wxDD_NEW_DIR_BUTTON);

	if (dialog.ShowModal() == wxID_CANCEL)
		return;
	{
		wxString title = dialog.GetPath();
		//wxMessageBox(path);

		FileTreeCtrl *tree = m_trees->GetFirstTree();
		tree->DeleteAllItems();
		wxTreeItemId rootFolderId = tree->AddRoot(title, TreeItemIcon_FolderNormal, TreeItemIcon_FolderNormal);// , new ModelTreeItemData(wxT("Root Item")));

		tree->SetItemImage(rootFolderId, TreeItemIcon_FolderExpanded, wxTreeItemIcon_Expanded);
		tree->SetItemTextColour(rootFolderId, *wxWHITE);
		//m_previous = rootFolderId;
		{
			wxTreeItemId itemFolderId1 = tree->AppendItem(rootFolderId, wxT("Chap1"), TreeItemIcon_FolderNormal, TreeItemIcon_FolderNormal);//, new ModelTreeItemData(wxT("File Item 1")));
			{
				tree->SetItemImage(itemFolderId1, TreeItemIcon_FolderExpanded, wxTreeItemIcon_Expanded);
				tree->SetItemBold(itemFolderId1, true);
				tree->SetItemTextColour(itemFolderId1, *wxWHITE);

				FileTreeItemData* data1 = new FileTreeItemData("hello");
				wxTreeItemId itemId1 = tree->AppendItem(itemFolderId1, wxT("lesson1"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new FileTreeItemData("lesson1"));
				tree->SetItemTextColour(itemId1, *wxWHITE);
				//SetItemData(itemId1, data1);

				wxTreeItemId itemId2 = tree->AppendItem(itemFolderId1, wxT("lesson2"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new ModelTreeItemData(wxT("File Item 2")));
				tree->SetItemTextColour(itemId2, *wxWHITE);

				wxTreeItemId itemId3 = tree->AppendItem(itemFolderId1, wxT("lesson3"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new ModelTreeItemData(wxT("File Item 2")));
				tree->SetItemTextColour(itemId3, *wxWHITE);

				wxTreeItemId itemId4 = tree->AppendItem(itemFolderId1, wxT("lesson4"), TreeItemIcon_FileNormal, TreeItemIcon_FileSelected);// , new ModelTreeItemData(wxT("File Item 2")));
				tree->SetItemTextColour(itemId4, *wxWHITE);

			}

		}
	}
}

void MenuBar::OnAbout(wxCommandEvent & evnt)
{
	wxString msg;
	msg.Printf("This is my Own implementation of the existing Notepad called NoteEditor \n Copyright(C) Barth. Feudong \t 2022");

	wxMessageBox(msg, "About NoteEditor", wxOK | wxICON_INFORMATION, this);

}

void MenuBar::OnExit(wxCommandEvent & evnt)
{
	m_parent->Close(true);
}

void MenuBar::OnSave(wxCommandEvent & evnt)
{
	//wxString filename = m_parent->GetFilename();
	wxString caption = wxT("Save the Current File");
	wxString wildcard = wxT("Text Files (*.txt)|*.txt ");// | *.bmp | GIF files(*.gif) | *.gif");
	wxString defaultDir = wxT("c:\\temp");

	wxString defaultFilename = wxT("Untitled");
	wxFileDialog dialog(this, caption, defaultDir, defaultFilename,wildcard, wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if (dialog.ShowModal() == wxID_CANCEL)
		return;
	
		wxFileOutputStream stream(dialog.GetPath());
		wxTextOutputStream file(stream);

		file << m_text->GetValue();

	
}

void MenuBar::OnSaveAs(wxCommandEvent & evnt)
{
	wxString caption = wxT("Save the file as");
	wxString wildcard = wxT("Text Files (*.txt)|*.txt ");// | *.bmp | GIF files(*.gif) | *.gif");
	wxString defaultDir = wxT("c:\\temp");

	wxString defaultFilename = wxEmptyString;

	wxSystemOptions::SetOption(wxT("NodeEditor"), 1);
	wxFileDialog dialog(this, caption, defaultDir, defaultFilename, wildcard, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (dialog.ShowModal() == wxID_OK)
	{
		wxString path = dialog.GetPath();
		int filterIndex = dialog.GetFilterIndex();
	}

	// proceed loading the file chosen by the user;
	wxFileOutputStream output_stream(dialog.GetPath());
	if (!output_stream.IsOk())
	{
		wxLogError("Cannot Save the file '%s'.", dialog.GetPath());
		return;
	}

	// write in File.txt
	{
		//output_stream << m_text;
		//wxMessageBox(dialog.GetFilename());
		wxString buf;
		buf.Printf("%s - NoteEditor", dialog.GetFilename());
		m_parent->SetTitle(buf);
	}

}

void MenuBar::OnSetStatusBar(wxCommandEvent & evnt)
{
	if(!evnt.IsChecked());
	{
		m_parent->SetStatusBar(nullptr);
		m_parent->Refresh();
	}
}

void MenuBar::OnZoomIn(wxCommandEvent & event)
{
	m_text->SetFont(m_text->GetFont().Scale(1.1));
}

void MenuBar::OnZoomOut(wxCommandEvent & event)
{
	m_text->SetFont(m_text->GetFont().Scale(0.9));
}

void MenuBar::OnPageSettingDialog(wxCommandEvent & event)
{

	//m_page_setting_dialog = new;

	PageSettingDialogue m_page_setting_dialog(m_parent);
	
	if (m_page_setting_dialog.ShowModal() ==  wxID_OK)
	{

	}
}
