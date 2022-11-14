#if !defined(INC_H___B53E9AF8_00D4_4038_BE7C_A364EC84A2D7__HEAD__)
#define INC_H___B53E9AF8_00D4_4038_BE7C_A364EC84A2D7__HEAD__

#if defined(SHARED_API)
#define __shared_api_ extern "C" __declspec(dllexport)
#else
#define __shared_api_ extern "C" __declspec(dllimport)
#endif

__shared_api_ void* __stdcall api_object_init(const void*, unsigned long);
__shared_api_ void __stdcall api_object_uninit();

__shared_api_ DWORD __stdcall AttachPlugin(void** pCorelDrawPlugin);

/// /*新生®（上海）**/
/// /*2022_09_07T08:12:56.2549115Z**/
/// /*_ _ _ _ _ _ _ www.skstu.com _ _ _ _ _ _ _**/
#endif ///INC_H___B53E9AF8_00D4_4038_BE7C_A364EC84A2D7__HEAD__
