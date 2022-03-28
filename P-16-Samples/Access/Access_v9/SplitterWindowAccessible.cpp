#include "SplitterWindowAccessible.h"
#if wxUSE_ACCESSIBILITY
// Gets the name of the specified object.
wxAccStatus SplitterWindowAccessible::GetName(int childId, wxString* name)
{
    if (childId == wxACC_SELF)
    {
        *name = "Splitter window";
        return wxACC_OK;
    }
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter)
    {
        if (splitter->IsSplit())
        {
            // Two windows, and the sash.
            if (childId == 1 || childId == 3)
                return wxACC_NOT_IMPLEMENTED;
            else if (childId == 2)
            {
                *name = "Sash";
                return wxACC_OK;
            }
        }
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Can return either a child object, or an integer
// representing the child element, starting from 1.
wxAccStatus SplitterWindowAccessible::HitTest(const wxPoint& pt, int* childId, wxAccessible** WXUNUSED(childObject))
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter)
    {
        if (splitter->IsSplit())
        {
            wxPoint clientPt = splitter->ScreenToClient(pt);
            if (splitter->SashHitTest(clientPt.x, clientPt.y))
            {
                // We're over the sash
                *childId = 2;
                return wxACC_OK;
            }
        }
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Returns the rectangle for this object (id = 0) or a child element (id > 0).
wxAccStatus SplitterWindowAccessible::GetLocation(wxRect& rect, int elementId)
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter && elementId == 2 && splitter->IsSplit())
    {
        wxSize clientSize = splitter->GetClientSize();
        if (splitter->GetSplitMode() == wxSPLIT_VERTICAL)
        {
            rect.x = splitter->GetSashPosition();
            rect.y = 0;
            rect.SetPosition(splitter->ClientToScreen(rect.GetPosition()));
            rect.width = splitter->GetSashSize();
            rect.height = clientSize.y;
        }
        else
        {
            rect.x = 0;
            rect.y = splitter->GetSashPosition();
            rect.SetPosition(splitter->ClientToScreen(rect.GetPosition()));
            rect.width = clientSize.x;
            rect.height = splitter->GetSashSize();
        }
        return wxACC_OK;
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Navigates from fromId to toId/toObject.
wxAccStatus SplitterWindowAccessible::Navigate(wxNavDir navDir, int fromId,
    int* toId, wxAccessible** toObject)
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter && splitter->IsSplit())
    {
        switch (navDir)
        {
        case wxNAVDIR_DOWN:
        {
            if (splitter->GetSplitMode() != wxSPLIT_VERTICAL)
            {
                if (fromId == 1)
                {
                    *toId = 2;
                    *toObject = NULL;
                    return wxACC_OK;
                }
                else if (fromId == 2)
                {
                    *toId = 3;
                    *toObject = splitter->GetWindow2()->GetAccessible();
                    return wxACC_OK;
                }
            }
            return wxACC_FALSE;
#if 0
            // below line is not executed due to earlier return
            break;
#endif
        }
        case wxNAVDIR_FIRSTCHILD:
        {
            if (fromId == 2)
                return wxACC_FALSE;
        }
        break;

        case wxNAVDIR_LASTCHILD:
        {
            if (fromId == 2)
                return wxACC_FALSE;
        }
        break;

        case wxNAVDIR_LEFT:
        {
            if (splitter->GetSplitMode() != wxSPLIT_HORIZONTAL)
            {
                if (fromId == 3)
                {
                    *toId = 2;
                    *toObject = NULL;
                    return wxACC_OK;
                }
                else if (fromId == 2)
                {
                    *toId = 1;
                    *toObject = splitter->GetWindow1()->GetAccessible();
                    return wxACC_OK;
                }
            }
            return wxACC_FALSE;
        }
#if 0
        // below line is not executed due to earlier return
        break;
#endif

        case wxNAVDIR_NEXT:
        {
            if (fromId == 1)
            {
                *toId = 2;
                *toObject = NULL;
                return wxACC_OK;
            }
            else if (fromId == 2)
            {
                *toId = 3;
                *toObject = splitter->GetWindow2()->GetAccessible();
                return wxACC_OK;
            }
            return wxACC_FALSE;
        }
#if 0
        // below line is not executed due to earlier return
        break;
#endif

        case wxNAVDIR_PREVIOUS:
        {
            if (fromId == 3)
            {
                *toId = 2;
                *toObject = NULL;
                return wxACC_OK;
            }
            else if (fromId == 2)
            {
                *toId = 1;
                *toObject = splitter->GetWindow1()->GetAccessible();
                return wxACC_OK;
            }
            return wxACC_FALSE;
        }
#if 0
        // below line is not executed due to earlier return
        break;
#endif

        case wxNAVDIR_RIGHT:
        {
            if (splitter->GetSplitMode() != wxSPLIT_HORIZONTAL)
            {
                if (fromId == 1)
                {
                    *toId = 2;
                    *toObject = NULL;
                    return wxACC_OK;
                }
                else if (fromId == 2)
                {
                    *toId = 3;
                    *toObject = splitter->GetWindow2()->GetAccessible();
                    return wxACC_OK;
                }
            }
            // Can't go right spatially if split horizontally.
            return wxACC_FALSE;
        }
#if 0
        // below line is not executed due to earlier return
        break;
#endif

        case wxNAVDIR_UP:
        {
            if (splitter->GetSplitMode() != wxSPLIT_VERTICAL)
            {
                if (fromId == 3)
                {
                    *toId = 2;
                    return wxACC_OK;
                }
                else if (fromId == 2)
                {
                    *toId = 1;
                    *toObject = splitter->GetWindow1()->GetAccessible();
                    return wxACC_OK;
                }
            }

            // Can't go up spatially if split vertically.
            return wxACC_FALSE;
#if 0
            // below line is not executed due to earlier return
            break;
#endif
        }
        }

    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Gets the number of children.
wxAccStatus SplitterWindowAccessible::GetChildCount(int* childCount)
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter)
    {
        if (splitter->IsSplit())
        {
            // Two windows, and the sash.
            *childCount = 3;
            return wxACC_OK;
        }
        else
        {
            // No sash -- 1 or 0 windows.
            if (splitter->GetWindow1() || splitter->GetWindow2())
            {
                *childCount = 1;
                return wxACC_OK;
            }
            else
            {
                *childCount = 0;
                return wxACC_OK;
            }
        }
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Gets the specified child (starting from 1).
// If *child is NULL and return value is wxACC_OK,
// this means that the child is a simple element and
// not an accessible object.
wxAccStatus SplitterWindowAccessible::GetChild(int childId, wxAccessible** child)
{
    if (childId == wxACC_SELF)
    {
        *child = this;
        return wxACC_OK;
    }

    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter)
    {
        if (splitter->IsSplit())
        {
            // Two windows, and the sash.
            if (childId == 1)
            {
                *child = splitter->GetWindow1()->GetAccessible();
            }
            else if (childId == 2)
            {
                *child = NULL; // Sash
            }
            else if (childId == 3)
            {
                *child = splitter->GetWindow2()->GetAccessible();
            }
            else
            {
                return wxACC_FAIL;
            }
            return wxACC_OK;
        }
        else
        {
            // No sash -- 1 or 0 windows.
            if (childId == 1)
            {
                if (splitter->GetWindow1())
                {
                    *child = splitter->GetWindow1()->GetAccessible();
                    return wxACC_OK;
                }
                else if (splitter->GetWindow2())
                {
                    *child = splitter->GetWindow2()->GetAccessible();
                    return wxACC_OK;
                }
                else
                {
                    return wxACC_FAIL;
                }
            }
            else
                return wxACC_FAIL;
        }
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Gets the parent, or NULL.
wxAccStatus SplitterWindowAccessible::GetParent(wxAccessible** WXUNUSED(parent))
{
    return wxACC_NOT_IMPLEMENTED;
}

// Performs the default action. childId is 0 (the action for this object)
// or > 0 (the action for a child).
// Return wxACC_NOT_SUPPORTED if there is no default action for this
// window (e.g. an edit control).
wxAccStatus SplitterWindowAccessible::DoDefaultAction(int WXUNUSED(childId))
{
    return wxACC_NOT_IMPLEMENTED;
}

// Gets the default action for this object (0) or > 0 (the action for a child).
// Return wxACC_OK even if there is no action. actionName is the action, or the empty
// string if there is no action.
// The retrieved string describes the action that is performed on an object,
// not what the object does as a result. For example, a toolbar button that prints
// a document has a default action of "Press" rather than "Prints the current document."
wxAccStatus SplitterWindowAccessible::GetDefaultAction(int childId, wxString* WXUNUSED(actionName))
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter && splitter->IsSplit() && childId == 2)
    {
        // No default action for the splitter.
        return wxACC_FALSE;
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Returns the description for this object or a child.
wxAccStatus SplitterWindowAccessible::GetDescription(int childId, wxString* description)
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter)
    {
        if (splitter->IsSplit())
        {
            if (childId == 2)
            {
                *description = _("The splitter window sash.");
                return wxACC_OK;
            }
        }
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Returns help text for this object or a child, similar to tooltip text.
wxAccStatus SplitterWindowAccessible::GetHelpText(int childId, wxString* helpText)
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter)
    {
        if (splitter->IsSplit())
        {
            if (childId == 2)
            {
                *helpText = _("The splitter window sash.");
                return wxACC_OK;
            }
        }
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Returns the keyboard shortcut for this object or child.
// Return e.g. ALT+K
wxAccStatus SplitterWindowAccessible::GetKeyboardShortcut(int childId, wxString* WXUNUSED(shortcut))
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter && splitter->IsSplit() && childId == 2)
    {
        // No keyboard shortcut for the splitter.
        return wxACC_FALSE;
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Returns a role constant.
wxAccStatus SplitterWindowAccessible::GetRole(int childId, wxAccRole* role)
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter)
    {
        if (splitter->IsSplit())
        {
            if (childId == 2)
            {
                *role = wxROLE_SYSTEM_GRIP;
                return wxACC_OK;
            }
        }
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Returns a state constant.
wxAccStatus SplitterWindowAccessible::GetState(int childId, long* state)
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter && splitter->IsSplit() && childId == 2)
    {
        // No particular state. Not sure what would be appropriate here.
        *state = wxACC_STATE_SYSTEM_UNAVAILABLE;
        return wxACC_OK;
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Returns a localized string representing the value for the object
// or child.
wxAccStatus SplitterWindowAccessible::GetValue(int childId, wxString* strValue)
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter && splitter->IsSplit() && childId == 2)
    {
        // The sash position is the value.
        wxString pos;
        pos << splitter->GetSashPosition();
        *strValue = pos;

        return wxACC_OK;
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Selects the object or child.
wxAccStatus SplitterWindowAccessible::Select(int childId, wxAccSelectionFlags WXUNUSED(selectFlags))
{
    wxSplitterWindow* splitter = wxDynamicCast(GetWindow(), wxSplitterWindow);
    if (splitter && splitter->IsSplit() && childId == 2)
    {
        // Can't select the sash.
        return wxACC_FALSE;
    }
    // Let the framework handle the other cases.
    return wxACC_NOT_IMPLEMENTED;
}

// Gets the window with the keyboard focus.
// If childId is 0 and child is NULL, no object in
// this subhierarchy has the focus.
// If this object has the focus, child should be 'this'.
wxAccStatus SplitterWindowAccessible::GetFocus(int* WXUNUSED(childId), wxAccessible** WXUNUSED(child))
{
    return wxACC_NOT_IMPLEMENTED;
}

// Gets a variant representing the selected children
// of this object.
// Acceptable values:
// - a null variant (IsNull() returns true)
// - a list variant (GetType() == "list")
// - an integer representing the selected child element,
//   or 0 if this object is selected (GetType() == "long")
// - a "void*" pointer to a wxAccessible child object
wxAccStatus SplitterWindowAccessible::GetSelections(wxVariant* WXUNUSED(selections))
{
    return wxACC_NOT_IMPLEMENTED;
}

#endif // wxUSE_ACCESSIBILITY

