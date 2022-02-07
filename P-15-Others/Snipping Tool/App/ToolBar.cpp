#include "ToolBar.h"
wxBEGIN_EVENT_TABLE(ToolBar,wxToolBar)

	EVT_TOOL(ID_NEW,ToolBar::OnNew)
	EVT_TOOL(ID_MODE,ToolBar::OnMode)
	EVT_TOOL(ID_DELAY,ToolBar::OnDelay)
	EVT_TOOL(ID_CANCEL,ToolBar::OnCancel)
	EVT_TOOL(ID_TOOLS,ToolBar::OnTools)

wxEND_EVENT_TABLE()

ToolBar::ToolBar(wxFrame * frameParent):wxToolBar(frameParent,wxID_ANY,wxDefaultPosition,wxDefaultSize, wxTB_HORZ_TEXT | wxTB_NODIVIDER |wxNO_BORDER)
{
	wxImage::AddHandler(new wxPNGHandler);
	wxImage im1(wxT("new.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpNew(im1);
	wxImage im2(wxT("mode.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpMode(im2);
	wxImage im3(wxT("delay.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpDelay(im3);
	wxImage im4(wxT("cancel.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpCancel(im4);
	wxImage im5(wxT("tool.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpTool(im5);
	//wxArrayString strings;
	//strings.Add(wxT("Free-Form-Snip"));
	//wxComboBox* comboBox = new wxComboBox(this, ID_COMBOBOX,wxT("&Mode"),wxDefaultPosition,wxSize(60,40), strings,wxCB_READONLY| wxCB_DROPDOWN);


	AddTool(ID_NEW, wxT("&New"), bmpNew);
	AddTool(ID_MODE, wxT("&Mode"), bmpMode);
	AddTool(ID_DELAY, wxT("&Delay"), bmpDelay);
	AddTool(ID_CANCEL, wxT("&Cancel"), bmpCancel);
	AddTool(ID_TOOLS, wxT("&Tools"), bmpTool);
	//AddControl(comboBox);

	Realize();

}

void ToolBar::OnNew(wxCommandEvent & event)
{
}

void ToolBar::OnMode(wxCommandEvent & event)
{
}

void ToolBar::OnDelay(wxCommandEvent & event)
{
}

void ToolBar::OnCancel(wxCommandEvent & event)
{
}

void ToolBar::OnTools(wxCommandEvent & event)
{
}

void ToolBar::OnCombo(wxCommandEvent & event)
{
}
