#include"Calculator.h"
#include"MainFrame.h"

// Implements Calculator& GetApp()
DECLARE_APP(Calculator)

//Give wxWidgets the means to create a Calculator object
IMPLEMENT_APP(Calculator)


bool Calculator::OnInit()
{

	MainFrame *frame = new MainFrame(wxT("Calculator"));
	frame->Show(true);
	return true;
}