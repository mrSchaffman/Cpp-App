#include "ArtBrowserDialog.h"
wxBEGIN_EVENT_TABLE(ArtBrowserDialog,wxDialog)


wxEND_EVENT_TABLE()

ArtBrowserDialog::ArtBrowserDialog(wxWindow * parent)
{
}

void ArtBrowserDialog::SetArtClient(const wxArtClient & client)
{
}

void ArtBrowserDialog::SetArtBitmap(const wxArtID & id, const wxArtClient & client, const wxSize & size)
{
}

void ArtBrowserDialog::OnSelectItem(wxListEvent & event)
{
}

void ArtBrowserDialog::OnChangeSize(wxCommandEvent & event)
{
}

void ArtBrowserDialog::OnChooseClient(wxCommandEvent & event)
{
}

wxSize ArtBrowserDialog::GetSelectedBitmapSize() const
{
	return wxSize();
}
