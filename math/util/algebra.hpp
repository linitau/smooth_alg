#pragma once

#include <cfloat>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <vector>

struct Algebra {
  static double WrapAngle(double angle);


  static double CrossProd(double x0, double y0, double x1, double y1);

  static double InnerProd(double x0, double y0, double x1, double y1);

  template <typename T>
  static T Square(const T value);

  static double distance(double x1, double y1, double x2, double y2);

  static double normalizeAngle(double a);

  static double normalizeAngleToSignField(double angle);

  static double angleDiff(double from, double to);

  static double differentAngle(double a0, double a1);
  static double slerp(double a0, double a1, double t);
};

template <typename T>
T Algebra::Square(const T value) {
  return value * value;
}
