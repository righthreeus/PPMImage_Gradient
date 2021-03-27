#pragma once

#ifndef _RECT_HPP_
#define _RECT_HPP_

#include "math/Vector2.h"

template <typename T>
struct Rectangle {

    inline T width() const {
        return bottom_right.x - top_left.x;
    }

    inline T height() const {
        return bottom_right.y - top_left.y;
    }

    inline Vector2<T> size() const {
        return Vector2<T>{ width(), height() };
    }

    inline T area() const {
        return width() * height();
    }

    Vector2<T> top_left;
    Vector2<T> bottom_right;
};

using  Rect = Rectangle<float>;
using IRect = Rectangle<int>;

#endif