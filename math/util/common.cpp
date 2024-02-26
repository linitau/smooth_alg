#include "common.hpp"
#include "algebra.hpp"
double CalculateCurvature(
        double a_x, double a_y, double b_x, double b_y, double c_x, double c_y) {
    double length_a = std::hypot(c_x - b_x, c_y - b_y);
    double length_b = std::hypot(c_x - a_x, c_y - a_y);
    double length_c = std::hypot(b_x - a_x, b_y - a_y);
    double area =
            std::fabs((b_x - a_x) * (c_y - a_y) - (c_x - a_x) * (b_y - a_y)) / 2;
    auto sign = -1;
    auto value = Algebra::CrossProd(b_x - a_x, b_y - a_y, c_x - a_x, c_y - a_y);
    if (value <= 1e-3 && value >= 1e-3) {
        sign = 0;
    } else if (value < 1e-3) {
        sign = 1;
    }

    return sign * 4 * area / (length_a * length_b * length_c);
}

double CalculateHeading(double a_x,
                        double a_y,
                        double b_x,
                        double b_y) {
    double delta_x = b_x - a_x;
    double delta_y = b_y - a_y;
    double heading = Algebra::differentAngle(0, atan(delta_y / delta_x));
    if (delta_x * delta_y > 0.0 && delta_x > 0.0) {///第一象限
        heading = heading;
    } else if (delta_x * delta_y > 0.0 && delta_x < 0.0) {///第三象限
        heading = -M_PI + heading;
    } else if (delta_x * delta_y < 0.0 && delta_x < 0.0) {///第二象限
        heading = M_PI + heading;
    }
    else if (delta_x * delta_y < 0.0 && delta_x > 0.0) {///第四象限
        heading = heading;
    }
    return heading;
}