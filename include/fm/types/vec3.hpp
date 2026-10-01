#pragma once
#include "../degrad.hpp"

namespace fm {

    template <typename T = float> 
    class _mat4x4;

    template <typename T = float>
    class _vec3 {
    public:

        T x, y, z;
        _vec3<T>();
        _vec3<T>(T i);
        _vec3<T>(T ix, T iy);
        _vec3<T>(T ix, T iy, T iz);

        inline static const _vec3<T> zero() { return _vec3<T>(); }
        inline static const _vec3<T> one() { return _vec3<T>(1, 1, 1); }
        inline static const _vec3<T> xAxis() { return _vec3<T>(1, 0, 0); }
        inline static const _vec3<T> yAxis() { return _vec3<T>(0, 1, 0); }
        inline static const _vec3<T> zAxis() { return _vec3<T>(0, 0, 1); }
        
        T distanceTo(_vec3<T> to) const;
        _vec3<T> normalized() const;
        T length() const;
        T& operator[](int i) const;
        _vec3<T> lerp(_vec3<T> to, T scalar) const;
        T dot(_vec3<T> v) const;
        _vec3<T> cross(_vec3<T> v) const;
        _vec3<T> transformed(const _mat4x4<T>& mat) const;
        _vec3<T> transform(const _mat4x4<T>& mat) const; 

        _vec3<T>& operator+=(const _vec3<T>& v);
        _vec3<T>& operator-=(const _vec3<T>& v);
        _vec3<T>& operator*=(double t);
        _vec3<T>& operator*=(const _vec3<T>& v);
        _vec3<T>& operator*=(const _mat4x4<T>& m);
        _vec3<T>& operator/=(double t);
    };
    template <typename T>
    inline _vec3<T>::_vec3() {
        x = 0; y = 0; z = 0;
    }
    template <typename T>
    inline _vec3<T>::_vec3(T i) {
        x = i; y = i; z = i;
    }
    template <typename T>
    inline _vec3<T>::_vec3(T ix, T iy) {
        x = ix; y = iy; z = 0;
    }
    template <typename T>
    inline _vec3<T>::_vec3(T ix, T iy, T iz) {
        x = ix, y = iy, z = iz;
    }
    template <typename T>
    inline T _vec3<T>::distanceTo(_vec3<T> to) const {

        T cast_2 = static_cast<T>(2);
        T _x = pow(x, cast_2) - pow(to.x, cast_2);
        T _y = pow(y, cast_2) - pow(to.y, cast_2);
        T _z = pow(z, cast_2) - pow(to.z, cast_2);

        return std::sqrt(_x + _y + _z);
    } 
    template <typename T>
    inline _vec3<T> _vec3<T>::normalized() const {
        T len = length();
        return _vec3<T>(x / len, y / len, z / len);
    }
    template <typename T>
    inline T _vec3<T>::length() const {
        return std::sqrt((x * x) + (y * y) + (z * z));
    }
    template <typename T>
    inline T& _vec3<T>::operator[](int i) const { 
        switch (i) {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            throw 474L;
            return x;
            break;
        }
    }
    template <typename T>
    inline _vec3<T> _vec3<T>::lerp(_vec3<T> to, T scalar) const {
        _vec3<T> v = *this;
        v->x = x + scalar * ( to.x - x ); 
        v->y = y + scalar * ( to.y - y );
        v->z = z + scalar * ( to.z - z );
        return v;
    }
    template <typename T>
    inline T _vec3<T>::dot(_vec3<T> v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    template <typename T>
    inline _vec3<T> _vec3<T>::cross(_vec3<T> v) const {
        return _vec3<T>(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }


    template <typename T>
    inline _vec3<T>& _vec3<T>::operator+=(const _vec3<T>& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }   
    template <typename T>
    inline _vec3<T>& _vec3<T>::operator-=(const _vec3<T>& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    template <typename T>
    inline _vec3<T>& _vec3<T>::operator*=(double t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    template <typename T>
    inline _vec3<T>& _vec3<T>::operator*=(const _vec3<T>& v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }
    template <typename T>
    inline _vec3<T>& _vec3<T>::operator*=(const _mat4x4<T>& m) {
        *this = this->transformed(m);
        return *this; 
    }
    template <typename T>
    inline _vec3<T>& _vec3<T>::operator/=(double t) {
        return *this *= (1 / t);
    }
    template <typename T>
    inline std::ostream& operator<<(std::ostream& out, const _vec3<T>& v) {
        return out << '(' << v.x << ", " << v.y << ", " << v.z << ')';
    }
    template <typename T>
    inline _vec3<T> operator+(const _vec3<T>& u, const _vec3<T>& v) {
        return _vec3<T>(u.x + v.x, u.y + v.y, u.z + v.z);
    }
    template <typename T>
    inline _vec3<T> operator-(const _vec3<T>& u, const _vec3<T>& v) {
        return _vec3<T>(u.x - v.x, u.y - v.y, u.z - v.z);
    }
    template <typename T>
    inline _vec3<T> operator-(const _vec3<T>& v) {
        return _vec3<T>(-v.x, -v.y, -v.z);
    }
    template <typename T>
    inline _vec3<T> operator*(const _vec3<T>& u, const _vec3<T>& v) {
        return _vec3<T>(u.x * v.x, u.y * v.y, u.z * v.z);
    }
    template <typename T>
    inline _vec3<T> operator*(const _vec3<T>& u, const _mat4x4<T> m) {
        return u.transformed(m);
    }
    template <typename T>
    inline _vec3<T> operator^(const _vec3<T>& u, const _vec3<T>& v) {
        return _vec3<T>(u.x ^ v.x, u.y ^ v.y, u.z ^ v.z);
    }
    template <typename T>
    inline _vec3<T> operator/(const _vec3<T>& u, const _vec3<T>& v) {
        return _vec3<T>(u.x / v.x, u.y / v.y, u.z / v.z);
    }
    template <typename T>
    inline _vec3<T> operator*(T t, const _vec3<T>& v) {
        return _vec3<T>(t * v.x, t * v.y, t * v.z);
    }
    template <typename T>
    inline _vec3<T> operator*(const _vec3<T>& v, T t) {
        return t * v;
    }
    template <typename T>
    inline _vec3<T> operator/(const _vec3<T>& v, T t) {
        return (1 / t) * v;
    }
    template <typename T>
    inline _vec3<T> operator^(const _vec3<T>& v, T t) {
        return _vec3<T>(pow(v.x, t), pow(v.y, t), pow(v.z, t));
    }
    template <typename T>
    inline _vec3<T> unit_vector(const _vec3<T>& v) {
        return v / v.length();
    }
    using vec3  = _vec3<float>;
    using ivec3 = _vec3<int>;
    using dvec3 = _vec3<double>;
    using bvec3 = _vec3<bool>;
    using lvec3 = _vec3<long>; 
    using svec3 = _vec3<short>;
}