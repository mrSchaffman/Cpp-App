#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString & title) :wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(580, 620))
{

	wxImage img(wxT("Icon.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmpIcon(img);

	wxIcon AppIcon;
	AppIcon.CopyFromBitmap(bmpIcon);
	SetIcon(AppIcon);

	SetTitle(m_filename + " - " + title);





#if wxUSE_STATUSBAR
	int m_widths[5] = { 250,120,30,80,80 };

	CreateStatusBar(5, wxSTB_DEFAULT_STYLE);
	SetStatusWidths(5, m_widths);

	SetStatusBarPane(0);
	wxString LinCol;
	LinCol.Printf("Ln %d, Col %d", m_ln, m_col);
	SetStatusText(LinCol, 1);
	SetStatusText(wxT("100%"), 2);
	SetStatusText(wxT("Win...(CRLF)"), 3);
	SetStatusText(wxT("UTF-8"), 4);
#endif // wxUSE_STATUSBAR


	// setting the Controls
	{
		wxBoxSizer*topSizer = new wxBoxSizer(wxVERTICAL);
		{
			SetSizer(topSizer);

			wxBoxSizer*box = new wxBoxSizer(wxHORIZONTAL);
			{
				topSizer->Add(box, 1);

				{
					wxTreeCtrl * m_tree = new wxTreeCtrl(this, ID_TREE, wxPoint(0, 0), wxSize(100, 620), wxTR_HAS_BUTTONS | wxTR_SINGLE | wxTR_NO_LINES);

					wxImageList*imageList = new wxImageList(10, 10); // from size(10,10)
					{
						wxIcon rootIcon;
						{
							wxImage img2(wxT("treeRoot.png"), wxBITMAP_TYPE_PNG);
							wxBitmap bmp2(img2);
							rootIcon.CopyFromBitmap(bmp2);
						}
						imageList->Add(rootIcon);

						wxIcon rootOpenIcon;
						{
							wxImage img3(wxT("folderClosed.png"), wxBITMAP_TYPE_PNG);
							wxBitmap bmp3(img3);
							rootOpenIcon.CopyFromBitmap(bmp3);

						}
						imageList->Add(rootOpenIcon);

						wxIcon fileIcon;
						{
							wxImage img3(wxT("header.png"), wxBITMAP_TYPE_PNG);
							wxBitmap bmp3(img3);
							fileIcon.CopyFromBitmap(bmp3);

						}
						imageList->Add(fileIcon);

					}
					m_tree->AssignImageList(imageList);

					wxTreeItemId rootId = m_tree->AddRoot(wxT("Root"), 1, 1);// , new ModelTreeItemData(wxT("Root Item")));
					wxTreeItemId itemId1 = m_tree->AppendItem(rootId, wxT("Model 1"), 0, 0);//, new ModelTreeItemData(wxT("File Item 1")));
					wxTreeItemId itemId2 = m_tree->AppendItem(rootId, wxT("Model 2"), 0, 0);// , new ModelTreeItemData(wxT("File Item 2")));
					wxTreeItemId itemId3 = m_tree->AppendItem(rootId, wxT("Model 3"), 1, 1);//, new ModelTreeItemData(wxT("File iten 3")));

					m_text_screen = new  TextCtrl(this);

					box->Add(m_text_screen, 1);
					box->Add(m_tree, 0);
				}

			}
		}

		m_menubar = new MenuBar(this, m_text_screen);
		SetMenuBar(m_menubar);


	}
}

