#pragma once
#include"wx/wx.h"
#include"TextCtrl.h"
#include"FileTreeCtrl.h"

class MainPanel: public wxPanel
{
public:

	MainPanel(wxFrame*frame);
	virtual ~MainPanel()=default;

	void OnPaint(wxPaintEvent&event);
	wxBitmap CreateLogo();
	wxBitmap CreateSideButtons();

	// Accessors
	void SetText(const wxString& value) { m_text->SetValue( value); }
	wxTextCtrl* GetText()const { return m_text; }

	void ControlLayout();

private:

	wxTextCtrl* m_text{};
	FileTreeCtrl*m_tree{};

	wxDECLARE_EVENT_TABLE();

};

