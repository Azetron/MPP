
// Tema2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTema2App:
// See Tema2.cpp for the implementation of this class
//

class CTema2App : public CWinApp
{
public:
	CTema2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTema2App theApp;
