#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)

	EVT_MENU(MENU_EXIT, MainFrame::OnExit)
	EVT_MENU(MENU_OPEN,MainFrame::OnOpen)
	EVT_MENU(MENU_ABOUT,MainFrame::OnAbout)
	EVT_MENU(MENU_SAVE,MainFrame::OnSave)
	EVT_MENU(MENU_SAVE_AS,MainFrame::OnSaveAs)
	EVT_MENU(MENU_SETTINGS,MainFrame::OnSettings)
	EVT_MENU(MENU_NEW,MainFrame::OnNew)

wxEND_EVENT_TABLE()
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(620, 580))
{

	CreateStatusBar(2);
	//SetBackgroundColour(*wxBLACK);

	wxMenuBar *menubar = new wxMenuBar();
	{
		wxMenu *File = new wxMenu;
		{
			File->Append(MENU_NEW, "New\tF1");
			File->AppendSeparator();
			File->Append(MENU_SAVE, "Save", wxEmptyString, wxITEM_NORMAL);
			File->Append(MENU_SAVE_AS, "Save As...\tCtrl+S");
			File->AppendSeparator();
			File->Append(MENU_SETTINGS, "Settings", "the settings of the App", wxITEM_DROPDOWN);
			File->Append(MENU_ABOUT, "About", "About the Author of the App");
			File->AppendSeparator();
			File->Append(MENU_EXIT, "Exit", "Exit the programm");

		}
		wxMenu *Edit = new wxMenu;
		{
			//
		}
		wxMenu *View = new wxMenu;
		{
			//
		}
		menubar->Append(File, wxT("File"));
		menubar->Append(Edit, wxT("Edit"));
		menubar->Append(View, wxT("View"));
		SetMenuBar(menubar);

	}


	std::vector<wxString> list{ wxString("Author"),
		wxString("Title"),
		wxString("Content Distributor"),
		wxString("Genre"),
		wxString("Provider"),
		wxString("Track Number"),
		wxString("Copyright"),
		wxString("Language"),
		wxString("Encoding Time"),
		wxString("Producer"),
		wxString("Writer"),
		wxString("Picture"),
		wxString("Unique File Id"),
		wxString("Author Url"),
		wxString("Conductor"),
		wxString("Lyrics") };

	//SetIcon(wxICON(sample));
	m_panel = new MainPanel(this);


	// wxLog
	m_logWindow = new wxTextCtrl(m_panel, LIST_CTRL, "Event log window!", wxDefaultPosition, wxSize(600, 100), wxTE_MULTILINE | wxTE_READONLY);
	m_log = wxLog::SetActiveTarget(new wxLogTextCtrl(m_logWindow));

	wxBoxSizer*column2 = new wxBoxSizer(wxVERTICAL);
	std::vector<wxString> labels = { wxString("<Play>"),
		wxString("Shuffle"),
		wxString("Love"),
		wxString("->"),
		wxString("<-"),
		wxString("View"),
		wxString("Share") 
	};

	for (const auto & label: labels)
	{
		wxButton *btn = new wxButton(m_panel, wxID_OK, label, wxDefaultPosition, wxSize(75, 55),wxBORDER_NONE);
		column2->Add(btn, 1, wxRIGHT | wxBOTTOM | wxEXPAND, 5);
	}

	wxBoxSizer *row1 = new wxBoxSizer(wxHORIZONTAL);
	m_playlist = new MusicList(m_panel, list, wxSize(500, 480));

	row1->Add(m_playlist, 1, wxALL|wxEXPAND,5);
	row1->Add(column2, 0, wxALL,5);


	m_topSizer = new wxBoxSizer(wxVERTICAL);
	{
		m_topSizer->Add(row1, 1, wxEXPAND);
		m_topSizer->Add(m_logWindow, 0, wxALL | wxEXPAND, 5);

		m_panel->Fit();
		m_panel->SetSizer(m_topSizer);
	}

}

void MainFrame::OnAbout(wxCommandEvent & event)
{
	wxString message;
	message.Printf(wxT("This App is a Sample that \ndemonstrate the use of list with %s"),wxVERSION_STRING);
	wxMessageBox(message,wxT("Music playlist Application by Barth.Feudong"), wxOK | wxICON_INFORMATION);
}

void MainFrame::OnExit(wxCommandEvent & event)
{
	Close(this);
}

void MainFrame::OnSave(wxCommandEvent & event)
{
}

void MainFrame::OnSaveAs(wxCommandEvent & event)
{
}

void MainFrame::OnSettings(wxCommandEvent & event)
{
}

void MainFrame::OnNew(wxCommandEvent & event)
{
}

void MainFrame::OnOpen(wxCommandEvent & event)
{
}
