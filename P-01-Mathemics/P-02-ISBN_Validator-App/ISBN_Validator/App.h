/**
 * @file source.cpp
 * @author Barth.Feudong (https://github.com/mrSchaffman)
 * @brief 
 * @version 0.1
 * @date 2022-01-18
 * This is free software; see the source for copying conditions.  There is NO
 * warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * @copyright Barth.Feudong (c) 2021
 *
 */
#pragma once
#include"wx/wx.h"
#include"MainFrame.h"

/*
 * ISBN: International Standard Book Number
 * in this challenge, let's us use a 10 digit isbn
 *
 * The last of the 10 digits is a checksum. This digit is
 * chosen so that the sum of all the ten digits,
 * each multiplied by its (integer) weight,
 * descending from 10 to 1, is a multiple of 11.
 * @author Barth.Feudong (https://github.com/mrSchaffman)
 * @version 0.1
 * @date 2021-12-30
 * @copyright Barth.Feudong (c) 2021
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

