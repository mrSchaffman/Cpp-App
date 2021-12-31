#pragma once
#include"wx/wx.h"
#include"MainFrame.h"

/*
 * Name:    ISBN_Validator
 * Purpose: validion of a international Standard book number
 * Author: Barth Feudong
 */
class App: public wxApp
{
public:
	App() = default;
	~App() = default;
	virtual bool OnInit() wxOVERRIDE;

private:
	MainFrame* frame = nullptr;
};

