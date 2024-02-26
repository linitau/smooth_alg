#include "algebra.hpp"

double Algebra::WrapAngle(double angle) {
  double new_angle = std::fmod(angle, M_PI * 2.0);
  return new_angle < 0 ? new_angle + M_PI * 2.0 : new_angle;
}

double Algebra::CrossProd(double x0, double y0, double x1, double y1) {
  return x0 * y1 - x1 * y0;
}

double Algebra::InnerProd(double x0, double y0, double x1, double y1) {
  return x0 * x1 + y0 * y1;
}

double Algebra::distance(double x1, double y1, double x2, double y2) {
  return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}


double Algebra::normalizeAngle(double a) {///[0,2pi]
  double a_n = std::fmod(a, 2.0 * M_PI);
  if (a_n < 0.0) {
    a_n += (2.0 * M_PI);
  }
  return a_n;
}

double Algebra::normalizeAngleToSignField(double angle) {
  double a = std::fmod(angle + M_PI, 2.0 * M_PI);
  if (a < 0.0) {
    a += (2.0 * M_PI);
  }
  return a - M_PI;
}

double Algebra::angleDiff(double from, double to) {
  return normalizeAngleToSignField(to - from);
}

double Algebra::differentAngle(double a0, double a1) {///以a0的角度为原点，将a1转换到相对a0的角度值
  double d;
  auto a0_n = normalizeAngle(a0);
  auto a1_n = normalizeAngle(a1);
  if (a1_n > a0_n && a1_n - a0_n <= M_PI) {
    d = a1_n - a0_n;
  } else if (a1_n > a0_n && a1_n - a0_n > M_PI) {
    d = (a1_n - a0_n) - 2 * M_PI;
  } else if (a0_n > a1_n && a0_n - a1_n <= M_PI) {
    d = a1_n - a0_n;
  } else if (a0_n > a1_n && a0_n - a1_n > M_PI) {
    d = 2 * M_PI - (a0_n - a1_n);
  } else {
    d = std::abs(a0_n - a1_n);
  }
  return d;
}

double Algebra::slerp(double a0, double a1, double t) {
    double a0_n = normalizeAngle(a0);
    double a1_n = normalizeAngle(a1);
    double d = differentAngle(a0_n, a1_n);

    double a = a0_n + d * t;
    return normalizeAngle(a);
}
