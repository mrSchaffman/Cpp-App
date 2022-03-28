#pragma once
#include"wx/wx.h"
#include"wx/splitter.h"

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
    // Gets the name of the specified object.
    virtual wxAccStatus GetName(int childId, wxString* name) wxOVERRIDE;

    // Can return either a child object, or an integer
    // representing the child element, starting from 1.
    virtual wxAccStatus HitTest(const wxPoint& pt, int* childId, wxAccessible** childObject) wxOVERRIDE;

    // Returns the rectangle for this object (id = 0) or a child element (id > 0).
    virtual wxAccStatus GetLocation(wxRect& rect, int elementId) wxOVERRIDE;

    // Navigates from fromId to toId/toObject.
    virtual wxAccStatus Navigate(wxNavDir navDir, int fromId,
        int* toId, wxAccessible** toObject) wxOVERRIDE;

    // Gets the number of children.
    virtual wxAccStatus GetChildCount(int* childCount) wxOVERRIDE;

    // Gets the specified child (starting from 1).
    // If *child is NULL and return value is wxACC_OK,
    // this means that the child is a simple element and
    // not an accessible object.
    virtual wxAccStatus GetChild(int childId, wxAccessible** child) wxOVERRIDE;

    // Gets the parent, or NULL.
    virtual wxAccStatus GetParent(wxAccessible** parent) wxOVERRIDE;

    // Performs the default action. childId is 0 (the action for this object)
    // or > 0 (the action for a child).
    // Return wxACC_NOT_SUPPORTED if there is no default action for this
    // window (e.g. an edit control).
    virtual wxAccStatus DoDefaultAction(int childId) wxOVERRIDE;

    // Gets the default action for this object (0) or > 0 (the action for a child).
    // Return wxACC_OK even if there is no action. actionName is the action, or the empty
    // string if there is no action.
    // The retrieved string describes the action that is performed on an object,
    // not what the object does as a result. For example, a toolbar button that prints
    // a document has a default action of "Press" rather than "Prints the current document."
    virtual wxAccStatus GetDefaultAction(int childId, wxString* actionName) wxOVERRIDE;

    // Returns the description for this object or a child.
    virtual wxAccStatus GetDescription(int childId, wxString* description) wxOVERRIDE;

    // Returns help text for this object or a child, similar to tooltip text.
    virtual wxAccStatus GetHelpText(int childId, wxString* helpText) wxOVERRIDE;

    // Returns the keyboard shortcut for this object or child.
    // Return e.g. ALT+K
    virtual wxAccStatus GetKeyboardShortcut(int childId, wxString* shortcut) wxOVERRIDE;

    // Returns a role constant.
    virtual wxAccStatus GetRole(int childId, wxAccRole* role) wxOVERRIDE;

    // Returns a state constant.
    virtual wxAccStatus GetState(int childId, long* state) wxOVERRIDE;

    // Returns a localized string representing the value for the object
    // or child.
    virtual wxAccStatus GetValue(int childId, wxString* strValue) wxOVERRIDE;

    // Selects the object or child.
    virtual wxAccStatus Select(int childId, wxAccSelectionFlags selectFlags) wxOVERRIDE;

    // Gets the window with the keyboard focus.
    // If childId is 0 and child is NULL, no object in
    // this subhierarchy has the focus.
    // If this object has the focus, child should be 'this'.
    virtual wxAccStatus GetFocus(int* childId, wxAccessible** child) wxOVERRIDE;

    // Gets a variant representing the selected children
    // of this object.
    // Acceptable values:
    // - a null variant (IsNull() returns true)
    // - a list variant (GetType() == "list")
    // - an integer representing the selected child element,
    //   or 0 if this object is selected (GetType() == "long")
    // - a "void*" pointer to a wxAccessible child object
    virtual wxAccStatus GetSelections(wxVariant* selections) wxOVERRIDE;

};


#endif // wxUSE_ACCESSIBILITY

