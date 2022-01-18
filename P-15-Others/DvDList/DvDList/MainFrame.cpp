#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)

wxEND_EVENT_TABLE()


MainFrame::MainFrame(const wxString & title) :wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(600, 480))
{
	SetIcon(wxICON(sample));
	SetMinSize(wxSize(600, 480));
	m_panel = new wxPanel(this, wxID_ANY);
	wxBoxSizer * const topSizer = new wxBoxSizer(wxVERTICAL);

	 // Make a menubar
	{
		wxMenu *menuFile = new wxMenu;
		menuFile->Append(LIST_ABOUT, "&About");
		menuFile->AppendSeparator();
		menuFile->Append(LIST_QUIT, "E&xit\tAlt-X");

		wxMenu *menuView = new wxMenu;
		menuView->Append(LIST_LIST_VIEW, "&List view\tF1");
		menuView->Append(LIST_REPORT_VIEW, "&Report view\tF2");
		menuView->Append(LIST_ICON_VIEW, "&Icon view\tF3");
		menuView->Append(LIST_ICON_TEXT_VIEW, "Icon view with &text\tF4");
		menuView->Append(LIST_SMALL_ICON_VIEW, "&Small icon view\tF5");
		menuView->Append(LIST_SMALL_ICON_TEXT_VIEW, "Small icon &view with text\tF6");
		menuView->Append(LIST_VIRTUAL_VIEW, "&Virtual view\tF7");
		menuView->Append(LIST_SMALL_VIRTUAL_VIEW, "Small virtual vie&w\tF8");
		menuView->AppendSeparator();
		menuView->Append(LIST_SET_ITEMS_COUNT, "Set &number of items");

		wxMenu *menuList = new wxMenu;
		menuList->Append(LIST_GOTO, "&Go to item #3\tCtrl-3");
		menuList->Append(LIST_FOCUS_LAST, "&Make last item current\tCtrl-L");
		menuList->Append(LIST_TOGGLE_FIRST, "To&ggle first item\tCtrl-G");
		menuList->Append(LIST_DESELECT_ALL, "&Deselect All\tCtrl-D");
		menuList->Append(LIST_SELECT_ALL, "S&elect All\tCtrl-A");
		menuList->AppendSeparator();
		menuList->Append(LIST_SHOW_COL_INFO, "Show &column info\tCtrl-C");
		menuList->Append(LIST_SHOW_SEL_INFO, "Show &selected items\tCtrl-S");
		menuList->Append(LIST_SHOW_VIEW_RECT, "Show &view rect");
		menuList->AppendSeparator();
		menuList->Append(LIST_SORT, "Sor&t\tCtrl-T");
		menuList->Append(LIST_FIND, "Test Find() performance");
		menuList->AppendSeparator();
		menuList->Append(LIST_ADD, "&Append an item\tCtrl-P");
		menuList->Append(LIST_EDIT, "&Edit the item\tCtrl-E");
		menuList->Append(LIST_DELETE, "&Delete first item\tCtrl-X");
		menuList->Append(LIST_DELETE_ALL, "Delete &all items");
		menuList->AppendSeparator();
		menuList->Append(LIST_FREEZE, "Free&ze\tCtrl-Z");
		menuList->Append(LIST_THAW, "Tha&w\tCtrl-W");
		menuList->AppendSeparator();

		// check items
		menuList->AppendCheckItem(LIST_TOGGLE_LINES, "Toggle &lines\tCtrl-I");
		menuList->AppendCheckItem(LIST_TOGGLE_MULTI_SEL, "&Multiple selection\tCtrl-M");
		menuList->Check(LIST_TOGGLE_MULTI_SEL, true);
		menuList->AppendCheckItem(LIST_TOGGLE_HEADER, "Toggle &header\tCtrl-H");
		menuList->Check(LIST_TOGGLE_HEADER, true);
		menuList->AppendCheckItem(LIST_TOGGLE_BELL, "Toggle &bell on no match");
		menuList->Append(LIST_CHECKVISIBILITY, "Check if lines 2 and 9 are visible");
		menuList->AppendSeparator();
		menuList->AppendCheckItem(LIST_TOGGLE_CHECKBOXES, "&Enable Checkboxes");
		menuList->Check(LIST_TOGGLE_CHECKBOXES, true);
		menuList->Append(LIST_TOGGLE_CHECKBOX, "Toggle the item checkbox state");
		menuList->Append(LIST_GET_CHECKBOX, "Get the item checkbox state");

		wxMenu *menuCol = new wxMenu;
		menuCol->Append(LIST_SET_FG_COL, "&Foreground colour...");
		menuCol->Append(LIST_SET_BG_COL, "&Background colour...");
		menuCol->AppendCheckItem(LIST_ROW_LINES, "Alternating colours");
		menuCol->AppendCheckItem(LIST_ROW_LINES_ON_BLANK, "Extend to whole window");
		menuCol->AppendCheckItem(LIST_CUSTOM_HEADER_ATTR, "&Custom header attributes");

		wxMenuBar *menubar = new wxMenuBar;
		menubar->Append(menuFile, "&File");
		menubar->Append(menuView, "&View");
		menubar->Append(menuList, "&List");
		menubar->Append(menuCol, "&Colour");
		SetMenuBar(menubar);
	}

	
	// wxLC_REPORT for one or many columns
	m_listCtrl = new DvDList(m_panel, LIST_CTRL, wxDefaultPosition,wxSize(580, 380),wxBORDER_THEME | wxLC_REPORT);
	m_listCtrl->setDvDList("database.txt");
		

	m_logWindow = new wxTextCtrl(m_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(580, 100), wxTE_READONLY | wxTE_MULTILINE);
	m_logOld = wxLog::SetActiveTarget(new wxLogTextCtrl(m_logWindow));

	topSizer->Add(m_listCtrl, 1,  wxALL|wxEXPAND,5);
	topSizer->Add(m_logWindow, 0,  wxALL | wxEXPAND,5);

	m_panel->Fit();
	m_panel->SetSizer(topSizer);
	SetClientSize(m_panel->GetBestSize());
}
