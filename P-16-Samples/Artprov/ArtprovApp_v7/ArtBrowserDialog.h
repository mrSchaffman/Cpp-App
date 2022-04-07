#pragma once

#ifndef __ARTBROWSERDIALOG_H__
#define __ARTBROWSERDIALOG_H__

#include"wx/wx.h"
#include"wx/artprov.h"

class WXDLLIMPEXP_FWD_CORE wxListCtrl;
class WXDLLIMPEXP_FWD_CORE wxListEvent;

class ArtBrowserDialog : public wxDialog
{
public:
	ArtBrowserDialog(wxWindow *parent); // dependency

	void SetArtClient(const wxArtClient& client);// dependency
	void SetArtBitmap(const wxArtID& id, 
		const wxArtClient& client, 
		const wxSize& size = wxDefaultSize);

private:
	void OnSelectItem(wxListEvent &event); // dependency
	void OnChangeSize(wxCommandEvent &event);// dependency
	void OnChooseClient(wxCommandEvent &event);// dependency

	wxSize GetSelectedBitmapSize() const;

	wxListCtrl *m_list;		// compositiion
	wxStaticBitmap *m_canvas; // aggregation
	wxStaticText *m_text;	// aggregation
	wxString m_client;
	wxChoice *m_sizes;		// aggregation
	wxString m_currentArtId;

	wxDECLARE_EVENT_TABLE();

};


#endif // !__ARTBROWSERDIALOG_H__

