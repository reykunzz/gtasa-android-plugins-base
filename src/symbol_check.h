#pragma once

#include <mod/amlmod.h>
#include <plugin-sdk/game_sa/plugin.h>

namespace hdreflection {

inline bool HasGameSymbol(const char* name) {
    if (!aml || !name) return false;

    void* handle = aml->GetLibHandle(BASE_GAME_LIBRARY);
    if (!handle) return false;

    return aml->GetSym(handle, name) != 0;
}

}
