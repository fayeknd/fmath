#pragma once
#include "types/mat4x4.hpp"
namespace fm {

    template<typename T = float>
    inline _vec2<T> degreesToRadians(_vec2<T> v) {
        return _vec2<T>(degreesToRadians(v.x), degreesToRadians(v.y));
    }
    template<typename T = float>
    inline _vec3<T> degreesToRadians(_vec3<T> v) {
        return _vec3<T>(degreesToRadians(v.x), degreesToRadians(v.y), degreesToRadians(v.z));
    }
    template<typename T = float>
    inline _vec4<T> degreesToRadians(_vec4<T> v) {
        return _vec4<T>(degreesToRadians(v.x), degreesToRadians(v.y), degreesToRadians(v.z), degreesToRadians(v.w));
    }

    template<typename T = float>
    inline _vec2<T> radiansToDegrees(_vec2<T> v) {
        return _vec2<T>(radiansToDegrees(v.x), radiansToDegrees(v.y));
    }
    template<typename T = float>
    inline _vec3<T> radiansToDegrees(_vec3<T> v) {
        return _vec3<T>(radiansToDegrees(v.x), radiansToDegrees(v.y), radiansToDegrees(v.z));
    }
    template<typename T = float>
    inline _vec4<T> radiansToDegrees(_vec4<T> v) {
        return _vec4<T>(radiansToDegrees(v.x), radiansToDegrees(v.y), radiansToDegrees(v.z), radiansToDegrees(v.w));
    }
}
#ifdef FMT_VERSION
#include <fmt/format.h>
namespace fmt {

    template <typename T>
    struct formatter<fm::_vec4<T>> {
        constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
            return ctx.begin();
        }

        template <typename fCtx>
        inline auto format(const fm::_vec4<T>& vec, fCtx& ctx) const -> decltype(ctx.out()) {
            return fmt::format_to(ctx.out(), "({}, {}, {}, {})", vec.x, vec.y, vec.z, vec.w);
        }
    };

    template <typename T>
    struct fmt::formatter<fm::_vec3<T>> {
        constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
            return ctx.begin();
        }

        template <typename fCtx>
        inline auto format(const fm::_vec3<T>& vec, fCtx& ctx) const -> decltype(ctx.out()) {
            return fmt::format_to(ctx.out(), "({}, {}, {})", vec.x, vec.y, vec.z);
        }
    };

    template <typename T>
    struct fmt::formatter<fm::_vec2<T>> {
        constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
            return ctx.begin();
        }

        template <typename fCtx>
        inline auto format(const fm::_vec2<T>& vec, fCtx& ctx) const -> decltype(ctx.out()) {
            return fmt::format_to(ctx.out(), "({}, {})", vec.x, vec.y);
        }
    };
    
    template <typename T>
    struct fmt::formatter<fm::_mat4x4<T>> {
        constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
            return ctx.begin();
        }

        template <typename fCtx>
        inline auto format(const fm::_mat4x4<T>& mat, fCtx& ctx) const -> decltype(ctx.out()) {
            return fmt::format_to(ctx.out(), "[{}, {}, {}, {}]\n[{}, {}, {}, {}]\n[{}, {}, {}, {}]\n[{}, {}, {}, {}]",
                mat.m_data[0][0], mat.m_data[1][0], mat.m_data[2][0], mat.m_data[3][0],
                mat.m_data[0][1], mat.m_data[1][1], mat.m_data[2][1], mat.m_data[3][1],
                mat.m_data[0][2], mat.m_data[1][2], mat.m_data[2][2], mat.m_data[3][2],
                mat.m_data[0][3], mat.m_data[1][3], mat.m_data[2][3], mat.m_data[3][3]
            );
        }
    };
}
#endif