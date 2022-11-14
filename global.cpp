#include "stdafx.h"

namespace local {
 HINSTANCE __gpHinstance = nullptr;
 Global* __gpGlobal = nullptr;
 Global* GlobalGet() { return __gpGlobal; }

 Global::Global() {
  Init();
 }

 Global::~Global() {
  UnInit();
 }

 void Global::Init() {
  std::string log_module_name = shared::Win::GetModuleNameA(true, __gpHinstance);
  //std::string log_path = shared::Win::GetModulePathA(__gpHinstance) + "logs\\";
  std::string log_path = shared::Win::GetSpecialFolderLocationA(CSIDL_DESKTOPDIRECTORY) + "\\logs\\";
  auto pSpdlog = shared::ISpdlog::CreateInterface(log_module_name, log_path);
 }

 void Global::UnInit() {
  shared::ISpdlog::DestoryInterface();
 }

}///namespace local
