#include "fem_pos_deviation_smoother.hpp"
#include "fem_pos_deviation_osqp_interface.hpp"

FemPosDeviationSmoother::FemPosDeviationSmoother(){}

bool FemPosDeviationSmoother::Solve(
        const std::vector<std::pair<double, double>>& raw_point2d,
        const std::vector<double>& bounds, std::vector<double>* opt_x,
        std::vector<double>* opt_y) {
    return SolveWithOsqp(raw_point2d, bounds, opt_x, opt_y);
}

bool FemPosDeviationSmoother::SolveWithOsqp(
        const std::vector<std::pair<double, double>>& raw_point2d,
        const std::vector<double>& bounds, std::vector<double>* opt_x,
        std::vector<double>* opt_y) {
    CHECK_NOTNULL(opt_x);
    CHECK_NOTNULL(opt_y);

    FemPosDeviationOsqpInterface solver;

    solver.set_weight_fem_pos_deviation(1.0e10);
    solver.set_weight_path_length(100.0);
    solver.set_weight_ref_deviation(1000.0);
    solver.set_max_iter(500.0);
    solver.set_time_limit(0.0);
    solver.set_verbose(true);
    solver.set_scaled_termination(true);
    solver.set_warm_start(true);

    solver.set_ref_points(raw_point2d);
    solver.set_bounds_around_refs(bounds);

    if (!solver.Solve()) {
        return false;
    }

    *opt_x = solver.opt_x();
    *opt_y = solver.opt_y();
    return true;
}