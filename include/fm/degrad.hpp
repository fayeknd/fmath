#pragma once
#include <iostream>
#include <cmath>

namespace fm {

    constexpr double PI = 3.141592653589793;
    constexpr double TAU = 6.283185307179586;

    inline float degreesToRadians(float d) {
        return d * (PI / 180.0);
    }
    inline float radiansToDegrees(float r) {
        return r * (180.0 / PI);
    }
}