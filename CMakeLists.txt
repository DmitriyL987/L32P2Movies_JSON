cmake_minimum_required(VERSION 3.20)
project(L32P2Movies_JSON)

set(CMAKE_CXX_STANDARD 20)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)
add_executable(L32P2Movies_JSON main.cpp Movie.hpp)
target_link_libraries(L32P2Movies_JSON PRIVATE nlohmann_json::nlohmann_json)