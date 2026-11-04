cmake_minimum_required(VERSION 4.1)

project(Calculator C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

add_executable(Calculator main.c)

target_link_libraries(Calculator PRIVATE PkgConfig::GTK4)