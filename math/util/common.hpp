#pragma once
#include <iostream>
#include <cmath>
#include "math_utils.hpp"
double CalculateCurvature(double a_x,
                          double a_y,
                          double b_x,
                          double b_y,
                          double c_x,
                          double c_y);

double CalculateHeading(double a_x,
                        double a_y,
                        double b_x,
                        double b_y);