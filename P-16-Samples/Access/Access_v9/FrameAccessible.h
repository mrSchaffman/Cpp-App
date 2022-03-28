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
class FrameAccessible : public wxWindowAccessible
{
public:
    FrameAccessible(wxWindow* win) : wxWindowAccessible(win) {}

    // Gets the name of the specified object.
    virtual wxAccStatus GetName(int childId, wxString* name) wxOVERRIDE
    {
        if (childId == wxACC_SELF)
        {
            *name = "Barth's Frame";
            return wxACC_OK;
        }
        else
            return wxACC_NOT_IMPLEMENTED;
    }
};

#endif // wxUSE_ACCESSIBILITY

