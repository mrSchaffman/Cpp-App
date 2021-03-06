#pragma once
#include"wx/wx.h"
#include"MainFrame.h"
#include"wx/cshelp.h"

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



class App: public wxApp
{
public:
	App() = default;
	virtual~App() = default;

	bool OnInit();

private:
};

