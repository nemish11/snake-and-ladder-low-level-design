cmake_minimum_required(VERSION 3.17)
project(snake_and_ladder)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE snake_and_ladder_SRC "models/*.h" "models/*.cpp" "services/*.cpp" "services/*.h" "driver.cpp")
add_executable(snake_and_ladder ${snake_and_ladder_SRC})
