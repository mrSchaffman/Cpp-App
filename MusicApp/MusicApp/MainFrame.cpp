#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)

// TODO

wxEND_EVENT_TABLE()
MainFrame::MainFrame(const wxString title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(620, 580))
{
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
	//m_panel = new wxPanel(this,wxID_ANY);
	m_topSizer = new wxBoxSizer(wxVERTICAL);
	m_playlist = new MusicList(this, list,wxSize(500,480));
	m_logMessageWindow = new wxTextCtrl(this, LIST_CTRL, wxEmptyString, wxDefaultPosition, wxSize(600, 100), wxTE_MULTILINE | wxTE_READONLY);
	m_log = wxLog::SetActiveTarget(new wxLogTextCtrl(m_logMessageWindow));

	wxBoxSizer*column2 = new wxBoxSizer(wxVERTICAL);
	std::vector<wxString> labels = { wxString("<Play>"),
		wxString("Shuffle"),
		wxString("Love"),
		wxString("->"),
		wxString("<-"),
		wxString("View"),
		wxString("Share") };

	for (const auto & label: labels)
	{
		wxButton *btn = new wxButton(this, wxID_OK, label, wxDefaultPosition, wxSize(75, 55),wxBORDER_NONE);

		column2->Add(btn, 0, wxALL | wxEXPAND,5);
	}
	wxBoxSizer *row1 = new wxBoxSizer(wxHORIZONTAL);
	row1->Add(m_playlist, 1, wxALL|wxEXPAND,5);
	row1->Add(column2, 0, wxALL,5);

	m_topSizer->Add(row1, 1, wxALL|wxEXPAND,2);
	m_topSizer->Add(m_logMessageWindow, 0,wxALL| wxEXPAND,5);

	//m_panel->Fit();
	//m_panel->SetSizer(m_topSizer);
	//SetClientSize(m_panel -> GetBestSize());

	SetSizer(m_topSizer);
	m_topSizer->Fit(this);
	m_topSizer->SetSizeHints(this);
}
