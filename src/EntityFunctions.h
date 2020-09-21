#pragma once

#include "../hooking/Hooking.h"
#include <iostream>

namespace ProjectNovigrad
{
  namespace TW3
  {
    class CEntity;
    namespace Functions
    {

      static hook::thiscall_stub<void(CEntity*)> CEntity_Destroy([]() {
        std::cout << "HOOK -> CEntity_Destroy hooked!" << std::endl;
        return hook::pattern("40 53 48 83 EC 20 48 8B 01 48 8B D9 FF 90 60 01")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      static hook::thiscall_stub<char* (CEntity*)> CEntity_GetName([]() {
        std::cout << "HOOK -> CEntity_GetName hooked!" << std::endl;
        return hook::pattern("48 8D 05 01 2D 97 02 C3")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      // 48 8B C4 48 89 58 08 48  89 70 10 48 89 78 18 55
      static hook::thiscall_stub<char* (CEntity*)> CEntity_GetDisplayName([]() {
        std::cout << "HOOK -> CEntity_GetDisplayName hooked!" << std::endl;
        return hook::pattern("40 53 48 83 EC 20 48 8B DA 48 8D 15 18 0F 97 02")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      //  48 89 5C 24 10 48 89 74  24 18 57 48 83 EC 50 48
      static hook::thiscall_stub<char* (CEntity*)> CEntity_GetFriendlyName([]() {
        std::cout << "HOOK -> CEntity_GetFriendlyName hooked!" << std::endl;
        return hook::pattern("48 89 5C 24 10 48 89 74 24 18 57 48 83 EC 50 48 8B 01")
          .count(1)
          .get(0)
          .get<void*>(0);
        });

      // 48 8B C4 48 89 58 08 48  89 70 10 48 89 78 18 55
      static hook::thiscall_stub<char* (CEntity*)> CEntity_GetUniqueName([]() {
        std::cout << "HOOK -> CEntity_GetUniqueName hooked!" << std::endl;
        return hook::pattern("48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55")
          .count(1)
          .get(0)
          .get<void*>(0);
        });
    }
  }
}
