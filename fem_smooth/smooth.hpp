#pragma once
#include <vector>

class Smooth {
public:
    Smooth()= default;
    void Setup_smooth();

    std::vector<double> opt_x_;
    std::vector<double> opt_y_;
    std::vector<std::pair<double, double>> raw_point2d_;
    std::vector<double> bounds_;
};