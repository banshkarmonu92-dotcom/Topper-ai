cmake_minimum_required(VERSION 3.10)
project(ProAITutor)
set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)
find_package(CURL REQUIRED)

add_executable(ProAITutor main.cpp)
target_link_libraries(ProAITutor raylib CURL)
