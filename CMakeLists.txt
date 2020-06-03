cmake_minimum_required(VERSION 2.0.0)
project(intMatrix VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(intMatrix intMatrix.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
