#pragma once
#include "../vec.hpp"

namespace fm {

    template <typename T>
    class _mat4x4 {
    public:

        T m_data[4][4];

        _mat4x4<T>();
        _mat4x4<T>(T i);
        _mat4x4<T>(T i[4][4]);
        _mat4x4<T>(
            T i00, T i01, T i02, T i03,
            T i04, T i05, T i06, T i07,
            T i08, T i09, T i10, T i11,
            T i12, T i13, T i14, T i15
        );
        inline static _mat4x4<T> identity() { return _mat4x4<T>(1); };
        T* data();

        _mat4x4<T> translated(_vec3<T> vec);
        _mat4x4<T>& translate(_vec3<T> vec);
        
        _mat4x4<T> scaled(_vec3<T> scale);
        _mat4x4<T>& scale(_vec3<T> scale);

        _mat4x4<T> rotatedAroundX(T degrees);
        _mat4x4<T>& rotateAroundX(T degrees);

        _mat4x4<T> rotatedAroundY(T degrees);
        _mat4x4<T>& rotateAroundY(T degrees);

        _mat4x4<T> rotatedAroundZ(T degrees);
        _mat4x4<T>& rotateAroundZ(T degrees);

        _mat4x4<T> rotated(_vec3<T> euler);
        _mat4x4<T>& rotate(_vec3<T> euler);

        _mat4x4<T> skewed(_vec3<T> v);
        _mat4x4<T>& skew(_vec3<T> v);

        _mat4x4<T> transposed();
        _mat4x4<T>& transpose();

        T& at(int row, int column);
        _mat4x4<T>& operator=(const _mat4x4<T>& m);
        _mat4x4<T>& operator*=(const _mat4x4<T>& m);
    };

    template <typename T>
    inline _mat4x4<T>::_mat4x4() {
        m_data[0][0] = 1; m_data[0][1] = 0; m_data[0][2] = 0; m_data[0][3] = 0;
        m_data[1][0] = 0; m_data[1][1] = 1; m_data[1][2] = 0; m_data[1][3] = 0;
        m_data[2][0] = 0; m_data[2][1] = 0; m_data[2][2] = 1; m_data[2][3] = 0;
        m_data[3][0] = 0; m_data[3][1] = 0; m_data[3][2] = 0; m_data[3][3] = 1;
    } 
    template <typename T>
    inline _mat4x4<T>::_mat4x4(T i) {
        m_data[0][0] = i; m_data[0][1] = 0; m_data[0][2] = 0; m_data[0][3] = 0;
        m_data[1][0] = 0; m_data[1][1] = i; m_data[1][2] = 0; m_data[1][3] = 0;
        m_data[2][0] = 0; m_data[2][1] = 0; m_data[2][2] = i; m_data[2][3] = 0;
        m_data[3][0] = 0; m_data[3][1] = 0; m_data[3][2] = 0; m_data[3][3] = i;
    }
    template <typename T>
    inline _mat4x4<T>::_mat4x4(T i[4][4]) {
        m_data[0][0] = i[0][0]; m_data[0][1] = i[0][1]; m_data[0][2] = i[0][2]; m_data[0][3] = i[0][3];
        m_data[1][0] = i[1][0]; m_data[1][1] = i[1][1]; m_data[1][2] = i[1][2]; m_data[1][3] = i[1][3];
        m_data[2][0] = i[2][0]; m_data[2][1] = i[2][1]; m_data[2][2] = i[2][2]; m_data[2][3] = i[2][3];
        m_data[3][0] = i[3][0]; m_data[3][1] = i[3][1]; m_data[3][2] = i[3][2]; m_data[3][3] = i[3][3];
    }
    template <typename T>
    inline _mat4x4<T>::_mat4x4(
            T i00, T i01, T i02, T i03,
            T i04, T i05, T i06, T i07,
            T i08, T i09, T i10, T i11,
            T i12, T i13, T i14, T i15) {
        m_data[0][0] = i00; m_data[0][1] = i01; m_data[0][2] = i02; m_data[0][3] = i03;
        m_data[1][0] = i04; m_data[1][1] = i05; m_data[1][2] = i06; m_data[1][3] = i07;
        m_data[2][0] = i08; m_data[2][1] = i09; m_data[2][2] = i10; m_data[2][3] = i11;
        m_data[3][0] = i12; m_data[3][1] = i13; m_data[3][2] = i14; m_data[3][3] = i15;
    }
    template <typename T>
    inline T* _mat4x4<T>::data() {
        return &m_data[0][0];
    } 

    template <typename T>
    inline _mat4x4<T> _mat4x4<T>::translated(_vec3<T> vec) {
        _mat4x4<T> _ = *this;
        _.m_data[3][0] += vec.x;
        _.m_data[3][1] += vec.y;
        _.m_data[3][2] += vec.z;
        return _;
    }

    template <typename T>
    inline _mat4x4<T>& _mat4x4<T>::translate(_vec3<T> vec) {
        *this = translated(vec);
        return *this;
    }
    template <typename T>
    inline _mat4x4<T> _mat4x4<T>::scaled(_vec3<T> scale) {
        _mat4x4<T> _ = *this;

        _.m_data[0][0] *= scale.x; _.m_data[0][1] *= scale.x; _.m_data[0][2] *= scale.x; _.m_data[0][3] *= scale.x;
        _.m_data[1][0] *= scale.y; _.m_data[1][1] *= scale.y; _.m_data[1][2] *= scale.y; _.m_data[1][3] *= scale.y;
        _.m_data[2][0] *= scale.z; _.m_data[2][1] *= scale.z; _.m_data[2][2] *= scale.z; _.m_data[2][3] *= scale.z;

        return _;
    }
    template <typename T>
    inline _mat4x4<T>& _mat4x4<T>::scale(_vec3<T> scale) {
        *this = scaled(scale);
        return *this;
    }
    template <typename T>
    inline _mat4x4<T> _mat4x4<T>::rotatedAroundX(T degrees) {
        _mat4x4<T> _ = *this;
        T rad = degreesToRadians(degrees);
        T c = std::cos(rad);
        T s = std::sin(rad);

        for (int i = 0; i < 4; ++i) {
            T y = _.m_data[1][i];
            T z = _.m_data[2][i];
            _.m_data[1][i] = y * c - z * s;
            _.m_data[2][i] = y * s + z * c;
        }
        return _;
    }
    template <typename T>
    inline _mat4x4<T>& _mat4x4<T>::rotateAroundX(T degrees) {
        *this = this->rotatedAroundX(degrees);
        return *this;
    }
    template <typename T>
    inline _mat4x4<T> _mat4x4<T>::rotatedAroundY(T degrees) {
        _mat4x4<T> _ = *this;
        T rad = degreesToRadians(degrees);
        T c = std::cos(rad);
        T s = std::sin(rad);

        for (int i = 0; i < 4; ++i) {
            T x = _.m_data[0][i];
            T z = _.m_data[2][i];
            _.m_data[0][i] = x * c - z * s;
            _.m_data[2][i] = x * s + z * c;
        }
        return _;
    }
    template <typename T>
    inline _mat4x4<T>& _mat4x4<T>::rotateAroundY(T degrees) {
        *this = this->rotatedAroundY(degrees);
        return *this;
    }
    template <typename T>
    inline _mat4x4<T> _mat4x4<T>::rotatedAroundZ(T degrees) {
        _mat4x4<T> _ = *this;
        T rad = degreesToRadians(degrees);
        T c = std::cos(rad);
        T s = std::sin(rad);

        for (int i = 0; i < 4; ++i) {
            T x = _.m_data[0][i];
            T y = _.m_data[1][i];
            _.m_data[0][i] = x * c + y * s;
            _.m_data[1][i] = -x * s + y * c;
        }
        return _;
    }
    template <typename T>
    inline _mat4x4<T>& _mat4x4<T>::rotateAroundZ(T degrees) {
        *this = this->rotatedAroundZ(degrees);
        return *this;
    }
    template <typename T>
    inline _mat4x4<T> _mat4x4<T>::rotated(_vec3<T> euler) {
        _mat4x4<T> _ = *this;
        _.rotateAroundY(euler.y);
        _.rotateAroundX(euler.x);
        _.rotateAroundZ(euler.z);
        return _;
    }
    template <typename T>
    inline _mat4x4<T>& _mat4x4<T>::rotate(_vec3<T> euler) {
        *this = this->rotated(euler);
        return *this;
    }
    template <typename T>
    inline _mat4x4<T> _mat4x4<T>::skewed(_vec3<T> v)  {
        _mat4x4<T> _ = *this;

        T skewX = std::tan(degreesToRadians(v.x));
        T skewY = std::tan(degreesToRadians(v.y));
        T skewZ = std::tan(degreesToRadians(v.z));

        for (int i = 0; i < 4; ++i) {
            T x = _.m_data[0][i];
            T y = _.m_data[1][i];
            T z = _.m_data[2][i];

            _.m_data[0][i] += y * skewX;
            _.m_data[1][i] += z * skewY;
            _.m_data[2][i] += x * skewZ;
        }

        return _;
    }
    template <typename T>
    inline _mat4x4<T>& _mat4x4<T>::skew(_vec3<T> v) {
        *this = this->skewed(v);
        return *this;
    }
    template <typename T>
    inline T& _mat4x4<T>::at(int row, int column) {
        return m_data[row][column];
    }

    template <typename T>
    inline _mat4x4<T>& _mat4x4<T>::operator=(const _mat4x4<T>& m) {
        m_data[0][0] = m.m_data[0][0]; m_data[0][1] = m.m_data[0][1]; m_data[0][2] = m.m_data[0][2]; m_data[0][3] = m.m_data[0][3];
        m_data[1][0] = m.m_data[1][0]; m_data[1][1] = m.m_data[1][1]; m_data[1][2] = m.m_data[1][2]; m_data[1][3] = m.m_data[1][3];
        m_data[2][0] = m.m_data[2][0]; m_data[2][1] = m.m_data[2][1]; m_data[2][2] = m.m_data[2][2]; m_data[2][3] = m.m_data[2][3];
        m_data[3][0] = m.m_data[3][0]; m_data[3][1] = m.m_data[3][1]; m_data[3][2] = m.m_data[3][2]; m_data[3][3] = m.m_data[3][3];
        return *this;
    }
    template <typename T>
    inline _mat4x4<T> operator*(const _mat4x4<T>& m1, const _mat4x4<T>& m2) {
        _mat4x4<T> _;
        for (int col = 0; col < 4; ++col) {
            for (int row = 0; row < 4; ++row) {
                _.m_data[col][row] = 
                    m1.m_data[0][row] * m2.m_data[col][0] +
                    m1.m_data[1][row] * m2.m_data[col][1] +
                    m1.m_data[2][row] * m2.m_data[col][2] +
                    m1.m_data[3][row] * m2.m_data[col][3];
            }
        }
        return _;
    }
    template <typename T>
    inline _mat4x4<T>& _mat4x4<T>::operator*=(const _mat4x4<T>& m) {
        *this = *this * m;
        return *this;
    }
    template <typename T>
    inline _mat4x4<T> operator*(_mat4x4<T> m, T t) { // Removed 'const' and '&'
        m.m_data[0][0] *= t; m.m_data[1][0] *= t; m.m_data[2][0] *= t; m.m_data[3][0] *= t;
        m.m_data[0][1] *= t; m.m_data[1][1] *= t; m.m_data[2][1] *= t; m.m_data[3][1] *= t;
        m.m_data[0][2] *= t; m.m_data[1][2] *= t; m.m_data[2][2] *= t; m.m_data[3][2] *= t;
        m.m_data[0][3] *= t; m.m_data[1][3] *= t; m.m_data[2][3] *= t; m.m_data[3][3] *= t;
        return m;
    } 
    template <typename T>
    inline _mat4x4<T> model(_vec3<T> pos, _vec3<T> scale, _vec3<T> rotation, _vec3<T> skew = {0}) {
        return _mat4x4<T>::identity().scale(scale).skew(skew).rotate(rotation).translate(pos);
    }
    template <typename T>
    inline _mat4x4<T> lookAt(_vec3<T> pos, _vec3<T> target, _vec3<T> up = {0.0f, 1.0f, 0.0f}) {
        _mat4x4<T> _;
        _vec3<T> f = (target - pos).normalized();
        _vec3<T> r = up.cross(f).normalized();
        _vec3<T> u = r.cross(f);
        
        _.m_data[0][0] = r.x; _.m_data[1][0] = r.y; _.m_data[2][0] = r.z; _.m_data[3][0] = -r.dot(pos); 
        _.m_data[0][1] = u.x; _.m_data[1][1] = u.y; _.m_data[2][1] = u.z; _.m_data[3][1] = -u.dot(pos); 
        _.m_data[0][2] =-f.x; _.m_data[1][2] =-f.y; _.m_data[2][2] =-f.z; _.m_data[3][2] =  f.dot(pos); 

        return _;
    }
    template <typename T>
    inline _mat4x4<T> perspective(T fov, T aspect, T nearClip = static_cast<T>(0.1), T farClip = static_cast<T>(1000)) {
        _mat4x4<T> _(static_cast<T>(0));

        T tanr = std::tan(degreesToRadians(fov) / static_cast<T>(2));
        T scale_y = static_cast<T>(1) / tanr;
        T scale_x = scale_y / aspect;

        _.m_data[0][0] = scale_x;
        _.m_data[1][1] = scale_y;
        _.m_data[2][2] = -(farClip + nearClip) / (farClip - nearClip);
        _.m_data[3][2] = -(static_cast<T>(2) * farClip * nearClip) / (farClip - nearClip);
        _.m_data[2][3] = static_cast<T>(-1);

        return _;
    }
    template <typename T> 
    inline _mat4x4<T> orthographic(T left, T right, T bottom, T top, T nearClip, T farClip) {
        _mat4x4<T> _;
        T cast_2 = static_cast<T>(2);

        _.m_data[0][0] = cast_2 / (right - left);
        _.m_data[1][1] = cast_2 / (top - bottom);
        _.m_data[2][2] =-cast_2 / (farClip - nearClip);

        _.m_data[3][0] =-(right + left) / (right - left);
        _.m_data[3][1] =-(top + bottom) / (top - bottom);
        _.m_data[3][2] =-(farClip + nearClip) / (farClip - nearClip);

        return _;
    }
    template <typename T>
    inline _vec3<T> _vec3<T>::transformed(const _mat4x4<T>& mat) const {
        _vec3<T> _;
        _.x = x * mat.m_data[0][0] + y * mat.m_data[1][0] + z * mat.m_data[2][0] + 1.0f * mat.m_data[3][0];
        _.y = x * mat.m_data[0][1] + y * mat.m_data[1][1] + z * mat.m_data[2][1] + 1.0f * mat.m_data[3][1];
        _.z = x * mat.m_data[0][2] + y * mat.m_data[1][2] + z * mat.m_data[2][2] + 1.0f * mat.m_data[3][2];
        
        return _;
    }
    template <typename T>
    inline _vec3<T> _vec3<T>::transform(const _mat4x4<T>& mat) const {
        *this = this->transformed(mat);
        return *this;
    }
    template <typename T>
    inline _mat4x4<T> _mat4x4<T>::transposed() {
        _mat4x4<T> _;
        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 4; ++c) {
                _.m_data[c][r] = m_data[r][c];
            }
        }
        return _;
    }
    template <typename T>
    inline _mat4x4<T>& _mat4x4<T>::transpose() {
        *this = this->transposed();
        return *this;
    }
    using mat4  = _mat4x4<float>;
    using imat4 = _mat4x4<bool>;
    using dmat4 = _mat4x4<double>;
    using bmat4 = _mat4x4<bool>;
    using lmat4 = _mat4x4<long>;
    using smat4 = _mat4x4<short>; 
}