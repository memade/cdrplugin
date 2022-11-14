#include "stdafx.h"
#include "export.h"

__shared_api_ void* __stdcall api_object_init(const void* route, unsigned long nroute) {
 void* result = nullptr;
 do {

 } while (0);
 return result;
}

__shared_api_ void __stdcall api_object_uninit() {

}

/*
// 暴露AttachPlugin函数，这是CDR调用CPG插件的入口
extern "C" __declspec(dllexport) DWORD APIENTRY AttachPlugin(VGCore::IVGAppPlugin * *CorelDrawPlugin) {
 MessageBoxW(NULL, _bstr_t("Hello Martell!"), _bstr_t("https://skstu.com"), MB_OK);
 return 0x100;
}
*/
__shared_api_ DWORD __stdcall AttachPlugin(void** pCorelDrawPlugin) {
 VGCore::IVGAppPlugin* CorelDrawPlugin = nullptr;
 *pCorelDrawPlugin = new local::VGAppPlugin();
 LOGINFO("{}", __FUNCTION__);
 //MessageBoxW(NULL, _bstr_t("Hello Martell!"), _bstr_t("https://skstu.com"), MB_OK);
 return 0x100;
}
