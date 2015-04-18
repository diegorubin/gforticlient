cmake_minimum_required(VERSION 2.6)
project (gforticlient)
enable_testing(true)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/vala)

find_package(Vala "0.18.0" REQUIRED)
include(${VALA_USE_FILE})

add_subdirectory (src)

