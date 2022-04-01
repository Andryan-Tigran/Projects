#include "EdgeDetectionFilter.h"
#include "GrayscaleFilter.h"
#include "MatrixFilter.h"
GrayscaleFilter filter;
static const std::vector<std::vector<double>> MATRIX_ARR = {{0.0,  -1.0, 0.0},
                                                {-1.0, 4.0,  -1.0},
                                                {0.0,  -1.0, 0.0}};

Image EdgeDetectionFilter::Apply(const Image &image) {
    std::cout << "Edge Detection start" << std::endl;
    Image gs_image = filter.Apply(image);
    int32_t height = image.GetHeight();
    int32_t width = image.GetWidth();
    Image tmp_image(width, height);
    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {
            DoublePixel tmp_double_pixel = ApplyMatrixForPixel(x, y, MATRIX_ARR, gs_image);
            Pixel tmp_pixel;
            if (tmp_double_pixel.blue > threshold_) {
                tmp_pixel.blue = 255;
                tmp_pixel.green = 255;
                tmp_pixel.red = 255;
            } else {
                tmp_pixel.blue = 0;
                tmp_pixel.green = 0;
                tmp_pixel.red = 0;
            }
            tmp_image.RewritePixel(tmp_pixel, x, y);
        }
    }
    std::cout << "Edge Detection end" << std::endl;
    return tmp_image;
}

EdgeDetectionFilter::EdgeDetectionFilter(double threshold) {
    threshold_ = threshold;
}

