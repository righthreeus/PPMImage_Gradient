#pragma once

#ifndef _VECTOR3_HPP_
#define _VECTOR3_HPP_

#include <cmath>
#include "pragmas.h"

template <typename T>
struct Vector3 {
    Vector3()
        :x(0.0f), y(0.0), z(0.0) {}

    Vector3(T value)
        :x(value), y(value), z(value) {}

    Vector3(T _x, T _y, T _z)
        :x(_x), y(_y), z(_z) {}

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

    inline Vector3 operator*(float s) const {
        return Vector3(x * s, y * s, z * s);
    }

    inline Vector3 operator/(float s) const {
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

    Vector3& operator*=(float s) {
        *this = *this * s;
        return *this;
    }

    Vector3& operator/=(float s) {
        *this = *this / s;
        return *this;
    }

    Vector3 nomalized() const {
        float mag = this->mag();
        return vec3(x / mag, y / mag, z / mag);
    }

    inline float mag() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    inline float sqr_mag() const { 
        return (x * x + y * y + z * z);
    }

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
inline Vector3<T> operator*(float s, Vector3<T> const& v) {
    return v * s;
}

template <typename T>
inline Vector3<T> operator/(float s, Vector3<T> const& v) {
    return v / s;
}

template <typename T>
inline float dot(Vector3<T> const& a, Vector3<T> const& b) {
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

using Vec3  = Vector3<float>;
using IVec3 = Vector3<int>;

#endif // _VECTOR3_HPP_