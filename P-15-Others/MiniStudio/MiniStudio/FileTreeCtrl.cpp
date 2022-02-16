#include "FileTreeCtrl.h"

FileTreeCtrl::FileTreeCtrl(wxWindow * parent, const wxWindowID id, const wxPoint & pos, const wxSize & size, long style) : wxTreeCtrl(parent, id, pos, size, style)
{
	CreateImageList();
}

void FileTreeCtrl::CreateImageList(int size)
{

}

void FileTreeCtrl::CreateButtonsImageList(int size)
{
}

void FileTreeCtrl::CreateStateImageList(bool del)
{
}
