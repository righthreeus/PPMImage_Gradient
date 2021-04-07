#pragma once

#ifndef _VECTOR3_HPP_
#define _VECTOR3_HPP_

#include "pragmas.h"
#include <cmath>
#include <type_traits>

template <typename T>
struct Vector3 {

    using floating_type = typename std::common_type<float, T>::type;

    Vector3()
        :x{ static_cast<T>(0) },
         y{ static_cast<T>(0) },
         z{ static_cast<T>(0) } {}

    explicit Vector3(T value)
        :x{ value }, y{ value }, z{ value } {}

    Vector3(T _x, T _y, T _z)
        :x{ _x }, y{ _y }, z{ _z } {}

DISABLE_WARING_PUSH
DISABLE_NARROWING
    template <typename U>
    operator Vector3<U>() const {
        return Vector3<U> {
            static_cast<U>(x),
            static_cast<U>(y),
            static_cast<U>(z)
        };
    }
DISABLE_WARING_POP

    inline bool operator==(Vector3 const& v) const {
        return (x == v.x) && (y == v.y) && (z == v.z);
    }

    inline bool operator!=(Vector3 const& v) const {
        return !operator==(v);
    }

    inline Vector3 operator-() const {
        return Vector3(-x, -y, -z);
    }

    inline Vector3 operator+(Vector3 const& v) const {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    inline Vector3 operator-(Vector3 const& v) const {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    inline Vector3 operator*(floating_type s) const {
        return Vector3(x * s, y * s, z * s);
    }

    inline Vector3 operator/(floating_type s) const {
        return Vector3(x / s, y / s, z / s);
    }

    Vector3& operator+=(Vector3 const& v) {
        *this = *this + v;
        return *this;
    }

    Vector3& operator-=(Vector3 const& v) {
        *this = *this - v;
        return *this;
    }

    Vector3& operator*=(floating_type s) {
        *this = *this * s;
        return *this;
    }

    Vector3& operator/=(floating_type s) {
        *this = *this / s;
        return *this;
    }

    Vector3 nomalized() const {
        auto c = Vector3<floating_type>(*this);
        c /= mag();
        return Vector3<T>(c);
    }

    inline T sqr_mag() const { 
        return (x * x + y * y + z * z);
    }

    inline floating_type mag() const {
        auto c = Vector3<floating_type>(*this);
        return std::sqrt(c.x * c.x + c.y * c.y + c.z * c.z);
    }

    static const Vector3 Zero;
    static const Vector3 One;
    static const Vector3 Up;
    static const Vector3 Down;
    static const Vector3 Left;
    static const Vector3 Right;
    static const Vector3 Front;
    static const Vector3 Back;

    T x;
    T y;
    T z;
};

template <typename T>
inline Vector3<T> operator*(typename Vector3<T>::floating_type s, Vector3<T> const& v) {
    return v * s;
}

template <typename T>
inline Vector3<T> operator/(typename Vector3<T>::floating_type s, Vector3<T> const& v) {
    return v / s;
}

template <typename T>
inline typename Vector3<T>::floating_type dot(Vector3<T> const& a, Vector3<T> const& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

template <typename T>
inline Vector3<T> cross(Vector3<T> const& a, Vector3<T> const& b) {
    return Vector3<T>(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x);
}

template <typename T>
const Vector3<T> Vector3<T>::Zero = Vector3<T>{ static_cast<T>(0) };

template <typename T>
const Vector3<T> Vector3<T>::One = Vector3<T>{ static_cast<T>(1) };

template <typename T>
const Vector3<T> Vector3<T>::Up =
    Vector3<T>{
        static_cast<T>( 0),
        static_cast<T>( 1),
        static_cast<T>( 0)
    };

template <typename T>
const Vector3<T> Vector3<T>::Down =
    Vector3<T>{
        static_cast<T>( 0),
        static_cast<T>(-1),
        static_cast<T>( 0)
    };

template <typename T>
const Vector3<T> Vector3<T>::Left =
    Vector3<T>{
        static_cast<T>(-1),
        static_cast<T>( 0),
        static_cast<T>( 0)
    };

template <typename T>
const Vector3<T> Vector3<T>::Right =
    Vector3<T>{
        static_cast<T>( 1),
        static_cast<T>( 0),
        static_cast<T>( 0)
    };

template <typename T>
const Vector3<T> Vector3<T>::Front =
    Vector3<T>{
        static_cast<T>( 0),
        static_cast<T>( 0),
        static_cast<T>( 1)
    };

template <typename T>
const Vector3<T> Vector3<T>::Back =
    Vector3<T>{
        static_cast<T>( 0),
        static_cast<T>( 0),
        static_cast<T>(-1)
    };

using  Vec3 = Vector3<float>;
using DVec3 = Vector3<double>;
using IVec3 = Vector3<int>;
using UVec3 = Vector3<size_t>;
using BVec3 = Vector3<bool>;

#endif // _VECTOR3_HPP_
