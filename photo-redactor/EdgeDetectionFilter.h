#pragma once

#include "Filter.h"
#include "MatrixFilter.h"

class EdgeDetectionFilter : public MatrixFilter {
public:
    EdgeDetectionFilter(double threshold);

    Image Apply(const Image& image) override;

private:
    double threshold_ = 0;
};