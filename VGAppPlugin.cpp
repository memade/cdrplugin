#include "stdafx.h"

namespace local {
 VGAppPlugin::VGAppPlugin() {

 }

 VGAppPlugin::~VGAppPlugin() {

 }

 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::GetTypeInfoCount(UINT* pctinfo) {
  LOGINFO("{}", __FUNCTION__);

  return E_NOTIMPL;
 }
 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::GetTypeInfo(
  UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) {
  LOGINFO("{}", __FUNCTION__);

  return E_NOTIMPL;
 }
 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::GetIDsOfNames(
  REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId) {
  LOGINFO("{}(DISPID({}),LPOLESTR({}))", __FUNCTION__, rgDispId ? *rgDispId : 0, rgszNames ? shared::IConv::WStringToMBytes(*rgszNames) : "");

  return E_NOTIMPL;
 }
 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::Invoke(
  DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) {
  HRESULT result = S_OK;
  switch (dispIdMember) {
  case 0x0008: {//!@ OnSave???

  }break;
  case 0x0011: {//!@ DISPID_APP_SELCHANGE

  }break;
  case 0x0012: {//!@ DISPID_APP_START
   LOGINFO("{}({})", __FUNCTION__, "DISPID_APP_START");
  }break;
  case 0x0014: {//!@ DISPID_APP_ONPLUGINCMD

  }break;
  case 0x0015: {//!@ DISPID_APP_ONPLUGINCMDSTATE

  }break;
  default:
   break;
  }
  LOGINFO("{}(dispIdMember=={})", __FUNCTION__, dispIdMember);
  return result;
 }

 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::raw_OnLoad(VGCore::IVGApplication* Application) {
  LOGINFO("{}", __FUNCTION__);

  HRESULT result = S_OK;
  do {
   m_pVGApplication = Application;
   if (m_pVGApplication)
    m_pVGApplication->AddRef();
  } while (0);
  return result;
 }
 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::raw_StartSession(void) {
  HRESULT result = S_OK;
  do {
   //VARIANT_BOOL success = VARIANT_TRUE;
   //VGCore::ICUICommandBarPtr pMainMenu = nullptr;
   //m_pVGApplication->get_MainMenu(&pMainMenu);
   //auto sss = pMainMenu->GetControls();
   //sss->AddCustomButton(_bstr_t("ClearFill"), _bstr_t("Clear Fill"), 0,success);

   //m_pVGApplication->raw_AddPluginCommand(_bstr_t("ClearFill"), _bstr_t("Clear Fill"), _bstr_t("Clears fill from selected objects"), &success);
   //LOGINFO("raw_AddPluginCommand({}) on ({})", success == VARIANT_TRUE ? "success" : "failed", __FUNCTION__);
   //auto pCmds = m_pVGApplication->GetCommandBars();
   //auto pCreate = pCmds->Add(_bstr_t("ClearFill"), VGCore::cuiBarPosition::cuiBarLeft, success);
   
   //m_pVGApplication->AddPluginCommand(_bstr_t("ClearFill"), _bstr_t("Clear Fill"), _bstr_t("Clears fill from selected objects"));
   //auto pControlPtr= m_pVGApplication->CommandBars->Item[_bstr_t("Standard")]->Controls->AddCustomButton(VGCore::cdrCmdCategoryPlugins, _bstr_t("ClearFill"), 0, VARIANT_TRUE);
   /*VGCore::CommandBarControlPtr ctl = */
   /*_bstr_t bstrPath(m_pVGApplication->Path + _bstr_t("Plugins\\ClearFill.bmp"));
   pControlPtr->SetCustomIcon(bstrPath);*/
   //m_lCookie = m_pVGApplication->AdviseEvents(this);

   m_lCookie = m_pVGApplication->AdviseEvents(this);

  } while (0);
  LOGINFO("{}({}({}))", __FUNCTION__, "m_lCookie", m_lCookie);
  return result;
 }
 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::raw_StopSession(void) {
  HRESULT result = S_OK;
  do {
   result = m_pVGApplication->UnadviseEvents(m_lCookie);
  } while (0);
  LOGINFO("{}", __FUNCTION__);
  return result;
 }
 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::raw_OnUnload(void) {
  HRESULT result = S_FALSE;
  do {
   if (!m_pVGApplication)
    break;
   m_pVGApplication->Release();
   m_pVGApplication = nullptr;
   result = S_OK;
  } while (0);
  LOGINFO("{}", __FUNCTION__);
  return result;
 }

 HRESULT STDMETHODCALLTYPE VGAppPlugin::QueryInterface(
  /* [in] */ REFIID riid,
  /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) {
  *ppvObject = nullptr;
  HRESULT result = S_OK;
  m_ulRefCount++;
  if (riid == IID_IUnknown)
  {
   *ppvObject = (IUnknown*)this;
   LOGINFO("{}({})", __FUNCTION__, R"(*ppvObject = (IUnknown*)this)");
  }
  else if (riid == IID_IDispatch)
  {
   *ppvObject = (IDispatch*)this;
   LOGINFO("{}({})", __FUNCTION__, R"(*ppvObject = (IDispatch*)this)");
  }
  else if (riid == __uuidof(VGCore::IVGAppPlugin))
  {
   *ppvObject = (VGCore::IVGAppPlugin*)this;
   LOGINFO("{}({})", __FUNCTION__, R"(*ppvObject = (VGCore::IVGAppPlugin*)this)");
  }
  else
  {
   m_ulRefCount--;
   result = E_NOINTERFACE;
   LOGINFO("{}({})", __FUNCTION__, R"(m_ulRefCount--)");
  }
  return result;
 }

 ULONG STDMETHODCALLTYPE VGAppPlugin::AddRef(void) {
  ULONG result = 0;
  do {
   result = m_ulRefCount++;
  } while (0);
  LOGINFO("{}", __FUNCTION__);
  return result;
 }

 ULONG STDMETHODCALLTYPE VGAppPlugin::Release(void) {
  ULONG result = 0;
  do {
   ULONG ulCount = --m_ulRefCount;
   if (ulCount <= 0)
    delete this;
   result = ulCount;
  } while (0);
  LOGINFO("{}", __FUNCTION__);
  return result;
 }

}///namespace local
