#pragma once
#include "../degrad.hpp"

namespace fm {

    template <typename T = float>
    class _vec2 {
    public:

        T x, y;
        _vec2<T>();
        _vec2<T>(T i);
        _vec2<T>(T ix, T iy);

        inline static const _vec2<T> zero() { return _vec2<T>(); }
        inline static const _vec2<T> one() { return _vec2<T>(1, 1); }
        inline static const _vec2<T> xAxis() { return _vec2<T>(1, 0); }
        inline static const _vec2<T> yAxis() { return _vec2<T>(0, 1); }

        T distanceTo(_vec2<T> to) const;
        _vec2<T> normalized() const;
        T length() const;
        T& operator[](int i) const;
        _vec2<T>* rotatedBy(float degrees, _vec2<T> offset = _vec2(0)) const;
        _vec2<T> lerp(_vec2<T> to, T scalar) const;
        T dot(_vec2<T> v) const;
        T cross(_vec2<T> v) const;

        _vec2<T>& operator+=(const _vec2<T>& v);
        _vec2<T>& operator-=(const _vec2<T>& v);
        _vec2<T>& operator*=(double t);
        _vec2<T>& operator/=(double t);
    };
    template <typename T>
    inline _vec2<T>::_vec2() {
        x = 0; y = 0;
    }
    template <typename T>
    inline _vec2<T>::_vec2(T i) {
        x = i; y = i;
    }
    template <typename T>
    inline _vec2<T>::_vec2(T ix, T iy) {
        x = ix; y = iy;
    }
    template <typename T>
    inline T _vec2<T>::distanceTo(_vec2<T> to) const {

        T cast_2 = static_cast<T>(2);
        T _x = pow(x, cast_2) - pow(to.x, cast_2);
        T _y = pow(y, cast_2) - pow(to.y, cast_2);

        return sqrt(_x + _y);
    } 
    template <typename T>
    inline _vec2<T> _vec2<T>::normalized() const {
        T len = length();
        return _vec2<T>(x / len, y / len);
    }
    template <typename T>
    inline T _vec2<T>::length() const {
        return sqrt((x * x) + (y * y));
    }
    template <typename T>
    inline T& _vec2<T>::operator[](int i) const { 
        switch (i) {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        default:
            throw std::out_of_range("vec2 has two components!");;
            return x;
            break;
        }
    }
    template <typename T>
    inline _vec2<T>* _vec2<T>::rotatedBy(float degrees, _vec2<T> offset) const {
        _vec2<T> v = *this;
        float _x, _y;
        const float rad = degreesToRadians(degrees);
        const float c = std::cos(rad);
        const float s = std::sin(rad);

        v.x = x - offset.x;
        v.y = y - offset.y;

        _x = v.x * c - v.y * s;
        _y = v.x * s + v.y * c;

        v.x = x + offset.x;
        v.y = y + offset.y;

        return v;
    }
    template <typename T>
    inline _vec2<T> _vec2<T>::lerp(_vec2<T> to, T scalar) const {
        _vec2<T> v = *this;
        v->x = x + scalar * ( to.x - x ); 
        v->y = y + scalar * ( to.y - y );
        return v;
    }
    template <typename T>
    inline T _vec2<T>::dot(_vec2<T> v) const {
        return x * v.x + y * v.y;
    }
    template <typename T>
    inline T _vec2<T>::cross(_vec2<T> v) const {
        return x * v.y - y * v.x;
    }


    template <typename T>
    inline _vec2<T>& _vec2<T>::operator+=(const _vec2<T>& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    template <typename T>
    inline _vec2<T>& _vec2<T>::operator-=(const _vec2<T>& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    template <typename T>
    inline _vec2<T>& _vec2<T>::operator*=(double t) {
        x *= t;
        y *= t;
        return *this;
    }
    template <typename T>
    inline _vec2<T>& _vec2<T>::operator/=(double t) {
        return *this *= 1 / t;
    }
    template <typename T>
    inline std::ostream& operator<<(std::ostream& out, const _vec2<T>& v) {
        return out << '(' << v.x << ", " << v.y << ')';
    }
    template <typename T>
    inline _vec2<T> operator+(const _vec2<T>& u, const _vec2<T>& v) {
        return _vec2<T>(u.x + v.x, u.y + v.y);
    }
    template <typename T>
    inline _vec2<T> operator-(const _vec2<T>& u, const _vec2<T>& v) {
        return _vec2<T>(u.x - v.x, u.y - v.y);
    }
    template <typename T>
    inline _vec2<T> operator-(const _vec2<T>& v) {
        return _vec2<T>(-v.x, -v.y);
    }
    template <typename T>
    inline _vec2<T> operator*(const _vec2<T>& u, const _vec2<T>& v) {
        return _vec2<T>(u.x * v.x, u.y * v.y);
    }
    template <typename T>
    inline _vec2<T> operator^(const _vec2<T>& u, const _vec2<T>& v) {
        return _vec2<T>(u.x ^ v.x, u.y ^ v.y);
    }
    template <typename T>
    inline _vec2<T> operator/(const _vec2<T>& u, const _vec2<T>& v) {
        return _vec2<T>(u.x / v.x, u.y / v.y);
    }
    template <typename T>
    inline _vec2<T> operator*(T t, const _vec2<T>& v) {
        return _vec2<T>(t * v.x, t * v.y);
    }
    template <typename T>
    inline _vec2<T> operator*(const _vec2<T>& v, T t) {
        return t * v;
    }
    template <typename T>
    inline _vec2<T> operator/(const _vec2<T>& v, T t) {
        return (1 / t) * v;
    }
    template <typename T>
    inline _vec2<T> operator^(const _vec2<T>& v, T t) {
        return _vec2<T>(pow(v.x, t), pow(v.y, t));
    }
    template <typename T>
    inline _vec2<T> unit_vector(const _vec2<T>& v) {
        return v / v.length();
    }
    using vec2  = _vec2<float>;
    using ivec2 = _vec2<int>;
    using dvec2 = _vec2<double>;
    using bvec2 = _vec2<bool>;
    using lvec2 = _vec2<long>; 
    using svec2 = _vec2<short>;
}