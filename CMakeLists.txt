cmake_minimum_required(VERSION 3.20)
include_directories(./)
project(smooth_alg)

set(CMAKE_CXX_STANDARD 14)
find_package(OSQP REQUIRED)
find_package(glog REQUIRED)
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
add_executable(smooth_alg main.cpp
        fem_smooth/fem_pos_deviation_osqp_interface.cpp
        fem_smooth/fem_pos_deviation_smoother.cpp
        fem_smooth/smooth.cpp
        third_party/matplotlibcpp.h
        math/util/algebra.cpp
        math/util/math_utils.cpp
        math/util/common.cpp)
target_link_libraries(smooth_alg glog::glog
        ${PYTHON_LIBRARIES}
        osqp::osqp)
