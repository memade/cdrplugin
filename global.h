#if !defined(INC_H___8D0C84E6_38D1_4AD2_88F9_865E277E2414__HEAD__)
#define INC_H___8D0C84E6_38D1_4AD2_88F9_865E277E2414__HEAD__

namespace local {
 class Global final {
 public:
  Global();
  ~Global();
 private:
  void Init();
  void UnInit();
 private:

 };

 extern Global* __gpGlobal;
 extern Global* GlobalGet();
 extern HINSTANCE __gpHinstance;

}///namespace lcoal
/// /*新生®（上海）**/
/// /*2022_11_14T09:41:47.4866471Z**/
/// /*_ _ _ _ _ _ _ www.skstu.com _ _ _ _ _ _ _**/
#endif ///INC_H___8D0C84E6_38D1_4AD2_88F9_865E277E2414__HEAD__
