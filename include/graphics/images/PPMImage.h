#pragma once

#ifndef _PPM_IMAGE_HPP_
#define _PPM_IMAGE_HPP_

#include "math/Vector3.h"
#include "math/Rectangle.h"
#include <ostream>
#include <vector>

enum class Direction {
    Horizontal,
    Vertical,
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

    IRect rect() const {
        return { IVec2::Zero, IVec2(width(), height())};
    }

    inline size_t max_color_range() const {
        return m_MaxColorRange;
    }

    void write_single_color(Vec3 const& color, IRect const& rect);

    void write_2_colors_linear_gradient(Vec3 const& beg, Vec3 const& end,
                                        IRect const& rect, Direction dir);

    void write_4_corners_linear_gradient(Vec3 const& tl, Vec3 const& bl,
                                         Vec3 const& tr, Vec3 const& br,
                                         IRect const& rect);

    void flush(std::ostream& os) const;

private:

    size_t m_MaxColorRange;
    std::vector<std::vector<Vec3>> m_ColorTable;
};

#endif // _PPM_IMAGE_HPP_