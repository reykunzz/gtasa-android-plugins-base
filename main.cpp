#include <mod/amlmod.h>
#include <mod/logger.h>

#include "src/reflection_config.h"
#include "src/reflection_policy.h"
#include "src/symbol_check.h"

MYMOD(hdreflection.balanced, HDReflection, 0.2, HDReflection)

ON_MOD_LOAD() {
    logger->SetTag("HD Reflection");
    logger->Info("HD Reflection Balanced loaded.");

    if (hdreflection::HasGameSymbol("_ZN14CCarFXRenderer10InitialiseEv"))
        logger->Info("CarFX Initialise: FOUND");
    else
        logger->Info("CarFX Initialise: NOT FOUND");

    if (hdreflection::HasGameSymbol("_ZN14CCarFXRenderer15RegisterPluginsEv"))
        logger->Info("CarFX RegisterPlugins: FOUND");
    else
        logger->Info("CarFX RegisterPlugins: NOT FOUND");

    if (hdreflection::HasGameSymbol("_ZN24CCustomCarEnvMapPipeline10CreatePipeEv"))
        logger->Info("EnvMap CreatePipe: FOUND");
    else
        logger->Info("EnvMap CreatePipe: NOT FOUND");

    if (hdreflection::HasGameSymbol("_ZN24CCustomCarEnvMapPipeline14RegisterPluginEv"))
        logger->Info("EnvMap RegisterPlugin: FOUND");
    else
        logger->Info("EnvMap RegisterPlugin: NOT FOUND");

    logger->Info("Symbol check completed. Renderer unchanged.");
}
