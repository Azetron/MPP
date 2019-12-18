
// Tema4-ex2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTema4ex2App:
// See Tema4-ex2.cpp for the implementation of this class
//

class CTema4ex2App : public CWinApp
{
public:
	CTema4ex2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTema4ex2App theApp;
