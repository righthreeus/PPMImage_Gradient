#include "graphics/images/PPMImage.h"
#include "math/Rectangle.h"
#include "math/Vector2.h"

void PPMImage::write_single_color(Vec3 const& color, URect const& rect) {
    for (int x = rect.top_left.x; x < rect.bottom_right.x; ++x) {
        for (int y = rect.top_left.y; y < rect.bottom_right.y; ++y) {
            m_ColorTable[x][y] = color;
        }
    }
}

void PPMImage::write_2_colors_linear_gradient(Vec3 const& beg, Vec3 const& end,
                                              URect const& rect, Direction dir) {
    auto rect_tl = Vec2(rect.top_left);
    auto rect_br = Vec2(rect.bottom_right);
    float width  = rect.width() - 1.0f;
    float height = rect.height() - 1.0f;

    if (dir == Direction::Horizontal) {
        for (int x = rect_tl.x; x < rect_br.x; ++x) {
            float t = static_cast<float>(x - rect_tl.x) / width;
            auto col = (1.0f - t) * beg + t * end;

            for (int y = rect_tl.y; y < rect_br.y; ++y)
                m_ColorTable[x][y] = col;
        }
    } else if (dir == Direction::Vertical) {
        for (int y = rect_tl.y; y < rect_br.y; ++y) {
            float t = static_cast<float>(y - rect_tl.y) / height;
            auto col = (1.0f - t) * beg + t * end;

            for (int x = rect_tl.x; x < rect_br.x; ++x)
                m_ColorTable[x][y] = col;
        }
    }
}

void PPMImage::write_4_corners_linear_gradient(Vec3 const& tl, Vec3 const& bl,
                                               Vec3 const& tr, Vec3 const& br,
                                               URect const& rect) {
    auto rect_tl = Vec2(rect.top_left);
    auto rect_br = Vec2(rect.bottom_right);
    float width  = rect.width() - 1.0f;
    float height = rect.height() - 1.0f;

    for (int x = rect_tl.x; x < rect_br.x; ++x) {
        float tx = float(x - rect_tl.x) / width;
        for (int y = rect_tl.y; y < rect_br.y; ++y) {
            float ty = float(y - rect_tl.y) / height;
            m_ColorTable[x][y] =
                    (1.0f - tx) * (1.0f - ty) * tl +
                    tx          * (1.0f - ty) * tr +
                    (1.0f - tx) * ty          * bl +
                    tx          * ty          * br;
        }
    }
}

void PPMImage::flush(std::ostream& os) const {
    os << "P3\n" << width() << ' ' << height() << '\n' << m_MaxColorRange << '\n';
    for (size_t y = 0; y < height(); ++y)
        for (size_t x = 0; x < width(); ++x) {
            auto c = IVec3(m_ColorTable[x][y] * static_cast<float>(256));
            os << c.x << ' ' << c.y << ' ' << c.z << '\n';
        }
    std::flush(os);
}
