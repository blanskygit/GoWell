// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "GoWell_i.h"
#include "dllmain.h"

CGoWellModule _AtlModule;


/************************ Removed because another one was defined according to example in GoWell.cpp *******

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved); 
}
*/
