#include "smooth.hpp"
#include "fem_pos_deviation_smoother.hpp"
#include "third_party/matplotlibcpp.h"
#include "math/util/common.hpp"
namespace plt = matplotlibcpp;

void Smooth::Setup_smooth() {
    FemPosDeviationSmoother smoother;
    smoother.Solve(raw_point2d_, bounds_, &opt_x_, &opt_y_);
    std::vector<double> x, y, raw_kappa, opt_kappa;
    for (auto &pt : raw_point2d_) {
        x.push_back(pt.first);
        y.push_back(pt.second);
    }
    std::vector<int> index;
    for (int i = 1; i < x.size() - 1; i++) {
        double a_x, a_y, b_x, b_y, c_x, c_y;
        a_x = x[i-1];
        a_y = y[i-1];
        b_x = x[i];
        b_y = y[i];
        c_x = x[i+1];
        c_y = y[i+1];
        raw_kappa.push_back(CalculateCurvature(a_x, a_y, b_x, b_y, c_x, c_y));
        index.push_back(i);
    }
    for (int i = 1; i < x.size() - 1; i++) {
        double a_x, a_y, b_x, b_y, c_x, c_y;
        a_x = opt_x_[i-1];
        a_y = opt_y_[i-1];
        b_x = opt_x_[i];
        b_y = opt_y_[i];
        c_x = opt_x_[i+1];
        c_y = opt_y_[i+1];
        opt_kappa.push_back(CalculateCurvature(a_x, a_y, b_x, b_y, c_x, c_y));
    }
    plt::figure_size(800, 800);
    plt::plot(x, y, {{"label", "raw curve"}});
    plt::plot(opt_x_, opt_y_, {{"label", "opt curve"}});
//    plt::plot(index, raw_kappa);
//    plt::plot(index, opt_kappa);
    plt::legend();
    plt::show();
}
















