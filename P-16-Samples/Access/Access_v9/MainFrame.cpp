#include "MainFrame.h"

#if wxUSE_ACCESSIBILITY

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(ID_ABOUT, MainFrame::OnAbout)
EVT_MENU(ID_QUERY, MainFrame::OnQuery)
EVT_MENU(ID_QUIT, MainFrame::OnQuit)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
	: wxFrame(nullptr, wxID_ANY, caption, pos, size, style)
{
	LayoutControls();
}

void MainFrame::Init()
{
	// the initiliazation
}

bool MainFrame::Create(const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	Init();
	MainFrame(caption, pos, size, style);
	return true;
}

void MainFrame::LayoutControls()
{
	SetAccessible(new FrameAccessible(this));

#if wxUSE_MENUS

	wxMenu* menuFile = new wxMenu;
	{
		menuFile->Append(ID_QUERY, wxT("Query"), wxT("Query the Window hierachy"));
		menuFile->AppendSeparator();
		menuFile->Append(ID_QUIT, wxT("E&xit\tAlt-F4"), wxT("Exit the Program"));

	}
	wxMenu* menuHelp = new wxMenu;
	{
		menuHelp->Append(ID_ABOUT, wxT("&About"), wxT("Show the About dialog"));
	}

	wxMenuBar* menuBar = new wxMenuBar();
	{
		menuBar->Append(menuFile, wxT("&File"));
		menuBar->Append(menuHelp, wxT("&Help"));
	}

	SetMenuBar(menuBar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
	CreateStatusBar();
	SetStatusText(wxT("The Access Sample"));
#endif // wxUSE_STATUSBAR

	wxSplitterWindow* splitterWin = new wxSplitterWindow(this, wxID_ANY);
	{
		splitterWin->SetAccessible(new SplitterWindowAccessible(splitterWin));
		wxListBox* listBox = new wxListBox(splitterWin, wxID_ANY);
		{
			listBox->Append(wxT("Cabbages"));
			listBox->Append(wxT("Kings"));
			listBox->Append(wxT("Sealing wax"));
			listBox->Append(wxT("Strings"));
			listBox->SetHelpText("This is a sample wxWidgets listbox, with a number of items in it.");
		}
		m_logger = new wxTextCtrl(splitterWin,
			wxID_ANY, wxEmptyString, wxDefaultPosition,
			wxDefaultSize, wxTE_MULTILINE);
		m_logger->SetHelpText(wxT("a multiline text control."));
		m_logger->CreateAccessible();

		splitterWin->SplitHorizontally(listBox, m_logger, 150);

	}


}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxString msg;
	msg.Printf("About the Accessible Sample, version %s", wxVERSION_STRING);
	wxMessageBox(msg, wxT("About"), wxICON_INFORMATION | wxOK, this);
}

void MainFrame::OnQuery(wxCommandEvent& WXUNUSED(event))
{
	m_logger->Clear();
	IAccessible* accessibleFrame = NULL;
	if (S_OK != AccessibleObjectFromWindow((HWND)GetHWND(), (DWORD)OBJID_CLIENT,
		IID_IAccessible, (void**)&accessibleFrame))
	{
		LogMessageInTextCtrl("Could not get object.", m_logger);
		return;
	}
	if (accessibleFrame)
	{
		//Log("Got an IAccessible for the frame.");
		LogObject(0, accessibleFrame);
		LogMessageInTextCtrl("Checking children using AccessibleChildren()...", m_logger);

		// Now check the AccessibleChildren function works OK
		long childCount = 0;
		if (S_OK != accessibleFrame->get_accChildCount(&childCount))
		{
			LogMessageInTextCtrl("Could not get number of children.", m_logger);
			accessibleFrame->Release();
			return;
		}
		else if (childCount == 0)
		{
			LogMessageInTextCtrl("No children.", m_logger);
			accessibleFrame->Release();
			return;
		}


		long obtained = 0;
		VARIANT* var = new VARIANT[childCount];
		int i;
		for (i = 0; i < childCount; i++)
		{
			VariantInit(&(var[i]));
			var[i].vt = VT_DISPATCH;
		}

		if (S_OK == AccessibleChildren(accessibleFrame, 0, childCount, var, &obtained))
		{
			for (i = 0; i < childCount; i++)
			{
				IAccessible* childAccessible = NULL;
				if (var[i].pdispVal)
				{
					if (var[i].pdispVal->QueryInterface(IID_IAccessible, (LPVOID*)&childAccessible) == S_OK)
					{
						var[i].pdispVal->Release();

						wxString name, role;
						GetInfo(childAccessible, 0, name, role);
						wxString str;
						str.Printf("Found child %s/%s", name, role);
						LogMessageInTextCtrl(str, m_logger);
						childAccessible->Release();
					}
					else
					{
						var[i].pdispVal->Release();
					}
				}
			}
		}
		else
		{
			LogMessageInTextCtrl("AccessibleChildren failed.", m_logger);
		}
		delete[] var;


		accessibleFrame->Release();
	}

}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(this);
}

void MainFrame::LogMessageInTextCtrl(const wxString& message, wxTextCtrl* logger)
{
	m_logger = logger;
	if (m_logger)
	{
		m_logger->SetInsertionPointEnd();
		m_logger->WriteText(CreateText(message));
	}
	else
	{
		//wxLogError()
	}
}
wxString MainFrame::CreateText(const wxString& message)
{
	wxString text(message);
	text.Replace("\n", " ");
	text.Replace("\t", " ");

	return text + "\n";
}


void MainFrame::LogObject(int indent, IAccessible* obj)
{
	wxString name, role;
	if (indent == 0)
	{
		GetInfo(obj, 0, name, role);

		wxString str;
		str.Printf("Name = %s; Role = %s", name, role);
		str.Pad(indent, ' ', false);
		LogMessageInTextCtrl(str,m_logger);
	}

	long childCount = 0;
	if (S_OK == obj->get_accChildCount(&childCount))
	{
		wxString str;
		str.Printf("There are %d children.", (int)childCount);
		str.Pad(indent, ' ', false);
		LogMessageInTextCtrl(str, m_logger);
		LogMessageInTextCtrl("", m_logger);
	}

	int i;
	for (i = 1; i <= childCount; i++)
	{
		GetInfo(obj, i, name, role);

		wxString str;
		str.Printf("%d) Name = %s; Role = %s", i, name, role);
		str.Pad(indent, ' ', false);
		LogMessageInTextCtrl(str, m_logger);

		VARIANT var;
		VariantInit(&var);
		var.vt = VT_I4;
		var.lVal = i;
		IDispatch* pDisp = NULL;
		IAccessible* childObject = NULL;

		if (S_OK == obj->get_accChild(var, &pDisp) && pDisp)
		{
			str.Printf("This is a real object.");
			str.Pad(indent + 4, ' ', false);
			LogMessageInTextCtrl(str, m_logger);

			if (pDisp->QueryInterface(IID_IAccessible, (LPVOID*)&childObject) == S_OK)
			{
				LogObject(indent + 4, childObject);
				childObject->Release();
			}
			pDisp->Release();
		}
		else
		{
			str.Printf("This is an element.");
			str.Pad(indent + 4, ' ', false);
			LogMessageInTextCtrl(str, m_logger);
		}
		// Log("");
	}

}

void MainFrame::GetInfo(IAccessible* accessible, int id, wxString& name, wxString& role)
{
	VARIANT var;
	VariantInit(&var);
	var.vt = VT_I4;
	var.lVal = id;

	BSTR bStrName = 0;
	HRESULT hResult = accessible->get_accName(var, &bStrName);

	if (hResult == S_OK)
	{
		name = wxConvertStringFromOle(bStrName);
		SysFreeString(bStrName);
	}
	else
	{
		name = "NO NAME";
	}

	VARIANT varRole;
	VariantInit(&varRole);

	hResult = accessible->get_accRole(var, &varRole);

	if (hResult == S_OK && varRole.vt == VT_I4)
	{
		wxChar buf[256];
		GetRoleText(varRole.lVal, buf, 256);

		role = buf;
	}
	else
	{
		role = "NO ROLE";
	}
}


#endif // wxUSE_ACCESSIBILITY
