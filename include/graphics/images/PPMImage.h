#pragma once

#ifndef _PPM_IMAGE_HPP_
#define _PPM_IMAGE_HPP_

#include "math/Vector3.h"
#include "math/Rectangle.h"
#include <ostream>
#include <vector>

class PPMImage;

enum class Direction {
    Horizontal,
    Vertical,
};

class PPMImageRowProxy {
public:

    Vec3& operator[](size_t index) {
        return m_Row[index];
    }

    Vec3 const& operator[](size_t index) const {
        return m_Row[index];
    }

private:

    friend class PPMImage;
    
    PPMImageRowProxy(std::vector<Vec3>& row)
        : m_Row(row) {}

    std::vector<Vec3>& m_Row;
};

class PPMImageConstRowProxy {
public:

    Vec3 const& operator[](size_t index) const {
        return m_Row[index];
    }

private:

    friend class PPMImage;

    PPMImageConstRowProxy(std::vector<Vec3> const& row)
        : m_Row(row) {}

    std::vector<Vec3> const& m_Row;
};


class PPMImage {
public:

    PPMImage(size_t max_color_range, size_t width, size_t height) {
        using std::vector;
        m_MaxColorRange = max_color_range;
        m_ColorTable = vector<vector<Vec3>>(width, vector<Vec3>(height, Vec3::Zero));
    }

    inline size_t width() const {
        return m_ColorTable.size();
    }

    inline size_t height() const {
        return m_ColorTable.front().size();
    }

    URect rect() const {
        return { UVec2::Zero, UVec2(width(), height())};
    }

    inline size_t max_color_range() const {
        return m_MaxColorRange;
    }

    inline void set_max_color_range(size_t range) {
        m_MaxColorRange = range;
    }

    PPMImageRowProxy operator[](size_t index) {
        return PPMImageRowProxy(m_ColorTable[index]);
    }

    PPMImageConstRowProxy operator[](size_t index) const {
        return PPMImageConstRowProxy(m_ColorTable[index]);
    }

    void write_single_color(Vec3 const& color, URect const& rect);

    void write_2_colors_linear_gradient(Vec3 const& beg, Vec3 const& end,
                                        URect const& rect, Direction dir);

    void write_4_corners_linear_gradient(Vec3 const& tl, Vec3 const& bl,
                                         Vec3 const& tr, Vec3 const& br,
                                         URect const& rect);

    void flush(std::ostream& os) const;

private:

    size_t m_MaxColorRange;
    std::vector<std::vector<Vec3>> m_ColorTable;
};

#endif // _PPM_IMAGE_HPP_
