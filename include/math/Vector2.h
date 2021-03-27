#pragma once

#ifndef _VEC2_HPP_
#define _VEC2_HPP_

#include "pragmas.h"
#include <cmath>

template <typename T>
struct Vector2 {
    Vector2()
        :x(0.0f), y(0.0) {}

    Vector2(T value)
        :x(value), y(value) {}

    Vector2(T _x, T _y)
        :x(_x), y(_y) {}

    inline bool operator==(Vector2 const& v) const {
        return (x == v.x) && (y == v.y);
    }

    inline bool operator!=(Vector2 const& v) const {
        return !operator==(v);
    }

    inline Vector2 operator-() const {
        return Vector2(-x, -y);
    }

    inline Vector2 operator+(Vector2 const& v) const {
        return Vector2(x + v.x, y + v.y);
    }

    inline Vector2 operator-(Vector2 const& v) const {
        return Vector2(x - v.x, y - v.y);
    }

    inline Vector2 operator*(float s) const {
        return Vector2(x * s, y * s);
    }

    inline Vector2 operator/(float s) const {
        return Vector2(x / s, y / s);
    }

    Vector2& operator+=(Vector2 const& v) {
        *this = *this + v;
        return *this;
    }

    Vector2& operator-=(Vector2 const& v) {
        *this = *this - v;
        return *this;
    }

    Vector2& operator*=(float s) {
        *this = *this * s;
        return *this;
    }

    Vector2& operator/=(float s) {
        *this = *this / s;
        return *this;
    }

    Vector2 nomalized() const {
        float mag = this->mag();
        return Vector2(x / mag, y / mag);
    }

    inline float mag() const {
        return std::sqrt(x * x + y * y);
    }

    inline float sqr_mag() const { 
        return (x * x + y * y);
    }

DISABLE_WARING_PUSH
DISABLE_NARROWING
    template <typename U>
    operator Vector2<U>() const {
        return Vector2<U>{
            static_cast<U>(x),
            static_cast<U>(y)
        };
    }
DISABLE_WARING_POP

    static const Vector2 Zero;
    static const Vector2 One;
    static const Vector2 Up;
    static const Vector2 Down;
    static const Vector2 Left;
    static const Vector2 Right;

    T x;
    T y;
};


template <typename T>
inline Vector2<T> operator*(float s, Vector2<T> const& v) {
    return v * s;
}

template <typename T>
inline Vector2<T> operator/(float s, Vector2<T> const& v) {
    return v / s;
}

template <typename T>
inline float dot(Vector2<T> const& a, Vector2<T> const& b) {
    return a.x * b.x + a.y * b.y;
}

template <typename T>
const Vector2<T> Vector2<T>::Zero = Vector2<T>{ static_cast<T>(0) };

template <typename T>
const Vector2<T> Vector2<T>::One = Vector2<T>{ static_cast<T>(1) };

template <typename T>
const Vector2<T> Vector2<T>::Up =
    Vector2<T>{
        static_cast<T>( 0),
        static_cast<T>( 1)
    };

template <typename T>
const Vector2<T> Vector2<T>::Down =
    Vector2<T>{
        static_cast<T>( 0),
        static_cast<T>(-1)
    };

template <typename T>
const Vector2<T> Vector2<T>::Left =
    Vector2<T>{
        static_cast<T>(-1),
        static_cast<T>( 0)
    };

template <typename T>
const Vector2<T> Vector2<T>::Right =
    Vector2<T>{
        static_cast<T>( 1),
        static_cast<T>( 0)
    };

using Vec2  = Vector2<float>;
using IVec2 = Vector2<int>;

#endif // _VEC2_HPP_