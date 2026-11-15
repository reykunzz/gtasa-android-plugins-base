#pragma once

namespace hdreflection {

struct Settings {
    float vehicleReflectionStrength = 0.42f;
    float glassReflectionStrength = 0.55f;
    float environmentBlend = 0.38f;
    float maxReflectionDistance = 65.0f;
    unsigned int maxNearbyVehicles = 4;
    bool reflectOnVehicles = true;
    bool reflectOnGlass = true;
    bool skipWhenCubemapUnavailable = true;
};

inline constexpr Settings kBalanced{};

} // namespace hdreflection
