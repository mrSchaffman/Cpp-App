#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)

// TODO

wxEND_EVENT_TABLE()
MainFrame::MainFrame(const wxString title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(620, 580))
{

	CreateStatusBar(2);
	wxMenuBar *menubar = new wxMenuBar();
	wxMenu *File = new wxMenu;
	wxMenu *Edit = new wxMenu;
	wxMenu *View = new wxMenu;

	{
		
		File->Append(NEW, "New\tF1");
		File->AppendSeparator();
		File->Append(SAVE, "Save", wxEmptyString, wxITEM_NORMAL);
		File->Append(SAVE_AS, "Save As...\tCtrl+S");
		File->AppendSeparator();
		File->Append(SETTINGS, "Settings", "the settings of the App", wxITEM_DROPDOWN);
		File->Append(ABOUT, "About", "About the Author of the App");
		File->AppendSeparator();
		File->Append(EXIT, "Exit", "Exit the programm");

	}

	menubar->Append(File,wxT("File"));
	menubar->Append(Edit,wxT("Edit"));
	menubar->Append(View,wxT("View"));
	SetMenuBar(menubar);

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

	m_topSizer = new wxBoxSizer(wxVERTICAL);
	m_playlist = new MusicList(m_panel, list,wxSize(500,480));

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
	row1->Add(m_playlist, 1, wxALL|wxEXPAND,5);
	row1->Add(column2, 0, wxALL,5);

	m_topSizer->Add(row1, 1, wxALL|wxEXPAND,2);
	m_topSizer->Add(m_logWindow, 0,wxALL| wxEXPAND,5);

	m_panel->Fit();
	m_panel->SetSizer(m_topSizer);

}
