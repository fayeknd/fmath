#pragma once
#include "types/vec2.hpp"
#include "types/vec3.hpp"
#include "types/vec4.hpp"
#include "degrad.hpp"

namespace fm {
    // vec<double>(x, y) returns a vec2
    template <typename T = float>
    _vec2<T> vec(T x, T y) {
        return _vec2<T>(x, y);
    } 
    template <typename T = float>
    _vec3<T> vec(T x, T y, T z) {
        return _vec3<T>(x, y, z);
    }
    template <typename T = float>
    _vec4<T> vec(T x, T y, T z, T w) {
        return _vec4<T>(x, y, z, w);
    }

}
