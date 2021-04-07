#include <iostream>
#include <vector>

#include "graphics/Color.h"
#include "graphics/images/PPMImage.h"

int main() {
    constexpr float aspect_ratio = 16.0f / 9.0f;
    constexpr int H = 512;
    constexpr int W = H * aspect_ratio;
    constexpr int MAX_COLOR = 255;

    auto img = PPMImage(MAX_COLOR, W, H);

    auto [x, y] = img.rect().bottom_right;
    int hx = x / 2;
    int hy = y / 2;

    // img.write_single_color(Color::Red    , IRect{ IVec2::Zero    , IVec2{ hx, hy } });
    // img.write_single_color(Color::Green  , IRect{ IVec2{ hx, 0 } , IVec2{ x, hy }});
    // img.write_single_color(Color::Yellow , IRect{ IVec2{ 0, hy } , IVec2{ hx, y } });
    // img.write_single_color(Color::Blue   , IRect{ IVec2{ hx, hy }, IVec2{ x, y } });

    // img.write_2_colors_linear_gradient(Color::Red, Color::Green, img.rect(), Direction::Horizontal);

    auto c = Vec3(1.0f);
    c.mag();
    c.sqr_mag();
    c.nomalized();

    img.write_4_corners_linear_gradient(Color::Blue, Color::Yellow, Color::Yellow, Color::Blue, img.rect());

    for (int x = 100; x < 200; ++x)
        for (int y = 100; y < 200; ++y)
            img[x][y] = Color::Red;

    img.flush(std::cout);
}
