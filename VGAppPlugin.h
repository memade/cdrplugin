#if !defined(INC_H___3E548501_2719_447B_8FD7_CEEC7C097AC7__HEAD__)
#define INC_H___3E548501_2719_447B_8FD7_CEEC7C097AC7__HEAD__

namespace local {
 class VGAppPlugin final : public VGCore::IVGAppPlugin {
 public:
  VGAppPlugin();
  virtual ~VGAppPlugin();
 private:
  long m_lCookie = 0;
  unsigned long m_ulRefCount = 1;
  VGCore::IVGApplication* m_pVGApplication = nullptr;
 protected:
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE GetTypeInfoCount(
   UINT* pctinfo) override final;
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE GetTypeInfo(
   UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) override final;
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE GetIDsOfNames(
   REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId) override final;
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE Invoke(
   DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
   DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) override final;

  HRESULT STDMETHODCALLTYPE QueryInterface(
   /* [in] */ REFIID riid,
   /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override final;
  ULONG STDMETHODCALLTYPE AddRef(void) override final;
  ULONG STDMETHODCALLTYPE Release(void) override final;

  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE raw_OnLoad(
   VGCore::IVGApplication* Application) override final;
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE raw_StartSession(void) override final;
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE raw_StopSession(void) override final;
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE raw_OnUnload(void) override final;

  //HRESULT __stdcall raw_SaveAs(
  // /*[in]*/ BSTR FileName,
  // /*[in]*/ struct IVGStructSaveAsOptions* Options) override final;
 };
}///namespace local

/// /*新生®（上海）**/
/// /*2022_11_14T09:15:30.5143843Z**/
/// /*_ _ _ _ _ _ _ www.skstu.com _ _ _ _ _ _ _**/
#endif ///INC_H___3E548501_2719_447B_8FD7_CEEC7C097AC7__HEAD__