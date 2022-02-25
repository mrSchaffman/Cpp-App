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

	SetValue(wxT("Mechanik der Fl�ssigkeiten\n\n")
		wxT("Auf der Erde existieren drei Erscheinungsformen von Materie.Man bezeichnet diese als\n")
		wxT("Aggregatzust�nde und unterscheidet den festen, den fl�ssigen und den gasf�rmigen Zustand.\n")
		wxT("Als vierten Aggregatzustand bezeichnet man den ionisierte Gase beschreibenden\n")
		wxT("Plasmazustand.\n")
		wxT("Der fl�ssige Zustand unterscheidet sich vom gasf�rmigen Zustand dadurch, dass sich\n")
		wxT("die Molek�le eines fl�ssigen K�rpers nicht v�llig frei im Raum bewegen k�nnen, \n")
		wxT("sondern �hnlich zum festen K�rper noch eine gewisse Bindung zwischen ihnen existiert.Im\n")
		wxT("Gegensatz zum festen K�rper sind die einzelnen Molek�le einer Fl�ssigkeit jedoch frei\n")
		wxT("gegeneinander verschiebbar.Es existieren in diesem Zustand also keine Gleichgewichtslagen im Raum,\n")
		wxT("welche die Position der Molek�le untereinander festlegen.Aufgrund der\n")
		wxT("Tatsache, dass Fl�ssigkeiten und Gase die F�higkeit besitzen zu str�men, fasst man sie\n")
		wxT("unter dem Oberbegriff Fluide zusammen.Physikalisch gesehen beruht diese Eigenschaft\n")
		wxT("darauf, dass bei Fluiden aufgrund der Verschiebbarkeit der Molek�le, keine Scherkr�fte, \n")
		wxT("also keine Kr�fte tangential zur Oberfl�che, aufgenommen werden k�nnen[Hal09]\n")
		wxT("[Ger10](vgl.auch Abschn. 2.3.2).Die Kr�fte, welche eine Fl�ssigkeit zusammenhalten,\n")
		wxT("also ihre Molek�le untereinander verbinden, bezeichnet man als Koh�sionskr�fte.\n")
		wxT("In der\n")
		wxT("Regel sind dies van - der - Waals Kr�fte; aber auch andere Bindungskr�fte k�nnen je nach\n")
		wxT("Fl�ssigkeit hierzu entscheidend beitragen.So tr�gt in polaren Fl�ssigkeiten, wie z.B.bei\n")
		wxT("Wasser, auch die Dipol - Dipol - Wechselwirkung zur Bindung bei[Pau07].Im Gegensatz\n")
		wxT("dazu bezeichnet man Kr�fte, die an der Grenzschicht einer Fl�ssigkeit mit K�rpern der\n")
		wxT("Au�enwelt auftreten, als Adh�sionskr�fte.Mit diesen Begriffen l�sst sich eine wichtige\n"));

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


