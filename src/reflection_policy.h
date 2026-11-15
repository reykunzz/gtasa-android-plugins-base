#pragma once

#include "reflection_config.h"

namespace hdreflection {

// Renderer-independent input. The future RenderWare adapter must populate these
// fields from verified engine objects; this policy does not inspect game memory.
struct VehicleCandidate {
    bool featureEnabled = false;
    bool materialSupportsEnvironment = false;
    bool cubemapReady = false;
    float distanceFromCamera = 0.0f;
    unsigned int alreadyProcessed = 0;
};

inline float Clamp01(float value) {
    if (value < 0.0f) return 0.0f;
    if (value > 1.0f) return 1.0f;
    return value;
}

inline bool ShouldRenderVehicleReflection(
    const Settings& settings,
    const VehicleCandidate& candidate
) {
    if (!settings.reflectOnVehicles || !candidate.featureEnabled) return false;
    if (!candidate.materialSupportsEnvironment) return false;
    if (candidate.alreadyProcessed >= settings.maxNearbyVehicles) return false;
    if (candidate.distanceFromCamera < 0.0f ||
        candidate.distanceFromCamera > settings.maxReflectionDistance) return false;

    // Safe fallback: skip this effect if no valid environment texture exists.
    if (!candidate.cubemapReady && settings.skipWhenCubemapUnavailable) return false;
    return candidate.cubemapReady;
}

inline float EffectiveVehicleReflectionStrength(const Settings& settings) {
    return Clamp01(settings.vehicleReflectionStrength) *
           Clamp01(settings.environmentBlend);
}

} // namespace hdreflection
