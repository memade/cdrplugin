﻿#include "stdafx.h"

#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
 switch (ul_reason_for_call) {
 case DLL_PROCESS_ATTACH: {
  local::__gpHinstance = hModule;
  local::__gpGlobal = new local::Global();
 }break;
 case DLL_THREAD_ATTACH: {
 }break;
 case DLL_THREAD_DETACH: {
 }break;
 case DLL_PROCESS_DETACH: {
  SK_DELETE_PTR(local::__gpGlobal);
 }break;
 }
 return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


