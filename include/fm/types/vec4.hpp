#pragma once

namespace fm {
    
    template<typename T = float>
    class _vec4 {
    public:

        T x, y, z, w;
        _vec4<T>();
        _vec4<T>(T i);
        _vec4<T>(T ix, T iy);
        _vec4<T>(T ix, T iy, T iz);
        _vec4<T>(T ix, T iy, T iz, T iw);

        inline static const _vec4<T> zero() { return _vec4<T>(); }
        inline static const _vec4<T> one() { return _vec4<T>(1, 1, 1, 1); }
        inline static const _vec4<T> xAxis() { return _vec4<T>(1, 0, 0, 0); }
        inline static const _vec4<T> yAxis() { return _vec4<T>(0, 1, 0, 0); }
        inline static const _vec4<T> zAxis() { return _vec4<T>(0, 0, 1, 0); }
        inline static const _vec4<T> wAxis() { return _vec4<T>(0, 0, 0, 1); }
        
        T distanceTo(_vec4<T> to) const;
        _vec4<T> normalized() const;
        T length() const;
        T& operator[](int i) const;
        _vec4<T> lerp(_vec4<T> to, T scalar) const;
        T dot(_vec4<T> v) const;
        _vec4<T> cross(_vec4<T> v1, _vec4<T> v2) const;

        _vec4<T>& operator+=(const _vec4<T>& v) const;
        _vec4<T>& operator-=(const _vec4<T>& v) const;
        _vec4<T>& operator*=(double t) const;
        _vec4<T>& operator/=(double t) const;
    };

    template <typename T>
    inline _vec4<T>::_vec4() {
        x = 0; y = 0; z = 0; w = 0;
    }
    template <typename T>
    inline _vec4<T>::_vec4(T i) {
        x = i; y = i; z = i; w = i;
    }
    template <typename T>
    inline _vec4<T>::_vec4(T ix, T iy) {
        x = ix, y = iy; z = 0; w = 0;
    }
    template <typename T>
    inline _vec4<T>::_vec4(T ix, T iy, T iz) {
        x = ix; y = iy; z = iz; w = 0;
    }
    template <typename T>
    inline _vec4<T>::_vec4(T ix, T iy, T iz, T iw) {
        x = ix; y = iy; z = iz; w = iw;
    }
    template <typename T>
    inline T _vec4<T>::distanceTo(_vec4<T> to) const {

        T cast_2 = static_cast<T>(2);
        T _x = (pow(x, cast_2) - pow(to.x, cast_2));
        T _y = (pow(y, cast_2) - pow(to.y, cast_2));
        T _z = (pow(z, cast_2) - pow(to.z, cast_2));
        T _w = (pow(w, cast_2) - pow(to.w, cast_2));

        return sqrt(_x + _y + _z + _w);
    } 
    template <typename T>
    inline _vec4<T> _vec4<T>::normalized() const {
        T len = length();
        return _vec4<T>(x / len, y / len, z / len, w / len);
    }
    template <typename T>
    inline T _vec4<T>::length() const {
        return sqrt((x * x) + (y * y) + (z * z) + (w * w));
    }
    template <typename T>
    inline T& _vec4<T>::operator[](int i) const { 
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
        case 3:
            return w;
            break;
        default:
            throw ERROR_INDEX_OUT_OF_BOUNDS;
            return x;
            break;
        }
    }
    template <typename T>
    inline _vec4<T> _vec4<T>::lerp(_vec4<T> to, T scalar) const {
        _vec4<T> v = *this;
        v->x = x + scalar * ( to.x - x ); 
        v->y = y + scalar * ( to.y - y );
        v->z = z + scalar * ( to.z - z );
        return v;
    }
    template <typename T>
    inline T _vec4<T>::dot(_vec4<T> v) const {
        return x * v.x + y * v.y + z * v.z * w + v.w;
    }
    template <typename T>
    inline _vec4<T> _vec4<T>::cross(_vec4<T> v1, _vec4<T> v2) const {
        return _vec4<T>(
            (y *(v1.z * v2.w - v1.w * v2.z) - z * (v1.y * v2.w - v1.w * v2.y) + w *(v1.y * v2.z - v1.z * v2.y)),
            -(x *(v1.z * v2.w - v1.w * v2.z) - z * (v1.x * v2.w - v1.w * v2.x) + w *(v1.x * v2.z - v1.z * v2.x)),
            (x *(v1.y * v2.w - v1.w * v2.z) - y * (v1.x * v2.w - v1.w * v2.x) + w *(v1.x * v2.y - v1.y * v2.x)),
            -(x *(v1.y * v2.w - v1.w * v2.z) - y * (v1.x * v2.w - v1.z * v2.x) + z *(v1.x * v2.y - v1.y * v2.x))
        );
    }


    template <typename T>
    inline _vec4<T>& _vec4<T>::operator+=(const _vec4<T>& v) const {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }

    template <typename T>
    inline _vec4<T>& _vec4<T>::operator-=(const _vec4<T>& v) const {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return *this;
    }

    template <typename T>
    inline _vec4<T>& _vec4<T>::operator*=(double t) const {
        x *= t;
        y *= t;
        z *= t;
        w *= t;
        return *this;
    }

    template <typename T>
    inline _vec4<T>& _vec4<T>::operator/=(double t) const {
        return *this *= (1 / t);
    }
    template <typename T>
    inline std::ostream& operator<<(std::ostream& out, const _vec4<T>& v) {
        return out << '(' << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ')';
    }
    template <typename T>
    inline _vec4<T> operator+(const _vec4<T>& u, const _vec4<T>& v) {
        return _vec4<T>(u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w);
    }
    template <typename T>
    inline _vec4<T> operator-(const _vec4<T>& u, const _vec4<T>& v) {
        return _vec4<T>(u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w);
    }
    template <typename T>
    inline _vec4<T> operator-(const _vec4<T>& v) {
        return _vec4<T>(-v.x, -v.y, -v.z, -v.w);
    }
    template <typename T>
    inline _vec4<T> operator*(const _vec4<T>& u, const _vec4<T>& v) {
        return _vec4<T>(u.x * v.x, u.y * v.y, u.z * v.z, u.w * v.w);
    }
    template <typename T>
    inline _vec4<T> operator^(const _vec4<T>& u, const _vec4<T>& v) {
        return _vec4<T>(u.x ^ v.x, u.y ^ v.y, u.z ^ v.z, u.w ^ v.w);
    }
    template <typename T>
    inline _vec4<T> operator/(const _vec4<T>& u, const _vec4<T>& v) {
        return _vec4<T>(u.x / v.x, u.y / v.y, u.z / v.z, u.w / v.w);
    }
    template <typename T>
    inline _vec4<T> operator*(T t, const _vec4<T>& v) {
        return _vec4<T>(t * v.x, t * v.y, t * v.z, t * v.w);
    }
    template <typename T>
    inline _vec4<T> operator*(const _vec4<T>& v, T t) {
        return t * v;
    }
    template <typename T>
    inline _vec4<T> operator/(const _vec4<T>& v, T t) {
        return (1 / t) * v;
    }
    template <typename T>
    inline _vec4<T> operator^(const _vec4<T>& v, T t) {
        return _vec4<T>(pow(v.x, t), pow(v.y, t), pow(v.z, t), pow(v.w, t));
    }
    template <typename T>
    inline _vec4<T> unit_vector(const _vec4<T>& v) {
        return v / v.length();

    };
    using vec4  = _vec4<float>;
    using ivec4 = _vec4<int>;
    using dvec4 = _vec4<double>;
    using bvec4 = _vec4<bool>;
    using lvec4 = _vec4<long>; 
    using svec4 = _vec4<short>;
}