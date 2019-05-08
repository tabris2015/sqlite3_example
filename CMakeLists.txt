cmake_minimum_required(VERSION 2.8)

project(sqlite3_example)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# find_package(sqlite3 REQUIRED)

add_executable(usuario src/usuario.cpp)

target_link_libraries(usuario sqlite3)