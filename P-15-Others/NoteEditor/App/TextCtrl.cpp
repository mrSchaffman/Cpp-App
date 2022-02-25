#include "TextCtrl.h"

wxBEGIN_EVENT_TABLE(TextCtrl, wxTextCtrl)
	EVT_TEXT(TXT_CTRL,TextCtrl::OnTextChange)
	//EVT_LEFT_DOWN(TextCtrl::OnMouseDown)
	//EVT_CHAR(TextCtrl::OnChar)

wxEND_EVENT_TABLE()

TextCtrl::TextCtrl(wxWindow * parent):wxTextCtrl(parent, TXT_CTRL,wxEmptyString,wxDefaultPosition, wxDefaultSize,wxTE_MULTILINE|wxTE_NOHIDESEL|wxBORDER_NONE)
{
	m_parent = parent;
	//SetBackgroundColour(wxColour(216, 216, 216));

	SetValue(wxT("Mechanik der Flüssigkeiten\n\n")
		wxT("Auf der Erde existieren drei Erscheinungsformen von Materie.Man bezeichnet diese als\n")
		wxT("Aggregatzustände und unterscheidet den festen, den flüssigen und den gasförmigen Zustand.\n")
		wxT("Als vierten Aggregatzustand bezeichnet man den ionisierte Gase beschreibenden\n")
		wxT("Plasmazustand.\n")
		wxT("Der flüssige Zustand unterscheidet sich vom gasförmigen Zustand dadurch, dass sich\n")
		wxT("die Moleküle eines flüssigen Körpers nicht völlig frei im Raum bewegen können, \n")
		wxT("sondern ähnlich zum festen Körper noch eine gewisse Bindung zwischen ihnen existiert.Im\n")
		wxT("Gegensatz zum festen Körper sind die einzelnen Moleküle einer Flüssigkeit jedoch frei\n")
		wxT("gegeneinander verschiebbar.Es existieren in diesem Zustand also keine Gleichgewichtslagen im Raum,\n")
		wxT("welche die Position der Moleküle untereinander festlegen.Aufgrund der\n")
		wxT("Tatsache, dass Flüssigkeiten und Gase die Fähigkeit besitzen zu strömen, fasst man sie\n")
		wxT("unter dem Oberbegriff Fluide zusammen.Physikalisch gesehen beruht diese Eigenschaft\n")
		wxT("darauf, dass bei Fluiden aufgrund der Verschiebbarkeit der Moleküle, keine Scherkräfte, \n")
		wxT("also keine Kräfte tangential zur Oberfläche, aufgenommen werden können[Hal09]\n")
		wxT("[Ger10](vgl.auch Abschn. 2.3.2).Die Kräfte, welche eine Flüssigkeit zusammenhalten,\n")
		wxT("also ihre Moleküle untereinander verbinden, bezeichnet man als Kohäsionskräfte.\n")
		wxT("In der\n")
		wxT("Regel sind dies van - der - Waals Kräfte; aber auch andere Bindungskräfte können je nach\n")
		wxT("Flüssigkeit hierzu entscheidend beitragen.So trägt in polaren Flüssigkeiten, wie z.B.bei\n")
		wxT("Wasser, auch die Dipol - Dipol - Wechselwirkung zur Bindung bei[Pau07].Im Gegensatz\n")
		wxT("dazu bezeichnet man Kräfte, die an der Grenzschicht einer Flüssigkeit mit Körpern der\n")
		wxT("Außenwelt auftreten, als Adhäsionskräfte.Mit diesen Begriffen lässt sich eine wichtige\n"));

	// i need consolas font regular
	SetFont(wxFont(11, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial"), wxFONTENCODING_SYSTEM));
	SetForegroundColour(wxColour(20, 20, 20));
	SetMargins(wxPoint(10, 20));
}

void TextCtrl::OnTextChange(wxCommandEvent & event)
{
	m_txt_status = true;
	
}
void TextCtrl::OnMouseDown(wxMouseEvent & event)
{
	int x, y, xx, yy;
	event.GetPosition(&x, &y);
	wxString LinCol;
	LinCol.Printf("Ln %d, Col %d", x, y);


	//m_parent->SetStatusText(LinCol, 1);


}
//void TextCtrl::OnChar(wxKeyEvent & event)
//{
//	wxPoint pt(event.GetPosition());
//
//	if (event.ControlDown()&&event.GetKeyCode()== WXK_UP)
//	{
//		wxString msg;
//		msg.Printf("This is my Own implementation of the existing Notepad \n Copyright(C) Barth. Feudong \t 2022");
//
//		wxMessageBox(msg, "About My NotePad", wxOK | wxICON_INFORMATION, this);
//
//	}
//}


