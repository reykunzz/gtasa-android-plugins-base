#include <mod/amlmod.h>
#include <mod/logger.h>

#include "src/reflection_config.h"
#include "src/reflection_policy.h"

// AML registration pattern follows the public GTASA Android AML template.
// This plugin currently initializes policy only; no RenderWare hook is installed.
MYMOD(hdreflection.balanced, HDReflection, 0.2, HDReflection)

ON_MOD_LOAD() {
    logger->SetTag("HD Reflection");
    logger->Info("HD Reflection Balanced loaded (GTA SA 2.10 ARM64).");
    logger->Info("Renderer pass is not enabled; policy scaffold only.");
}
