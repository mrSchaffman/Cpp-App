#include "TextCtrl.h"

TextCtrl::TextCtrl(wxFrame * parent):wxTextCtrl(parent,wxID_TOP,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE|wxTE_DONTWRAP|wxTE_NOHIDESEL|wxBORDER_NONE)
{

}
