#pragma once

#if wxUSE_ACCESSIBILITY
#include"wx/access.h"
#endif // wxUSE_ACCESSIBILITY
#ifdef __WXMSW__
#include "windows.h"
#include <ole2.h>
#include <oleauto.h>

#if wxUSE_ACCESSIBILITY
#include <oleacc.h>
#endif // wxUSE_ACCESSIBILITY

#include "wx/msw/ole/oleutils.h"
#include "wx/msw/winundef.h"

#ifndef OBJID_CLIENT
#define OBJID_CLIENT 0xFFFFFFFC
#endif
#endif

#if wxUSE_ACCESSIBILITY

class SplitterWindowAccessible : public wxWindowAccessible
{
public:
	SplitterWindowAccessible(wxWindow* window) : wxWindowAccessible(window) {}

protected:


private:

};


#endif // wxUSE_ACCESSIBILITY

