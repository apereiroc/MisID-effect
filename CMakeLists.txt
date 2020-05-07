cmake_minimum_required(VERSION 3.16)
project(simulation)

set(CMAKE_CXX_STANDARD 17)

find_package(ROOT 6.20 CONFIG REQUIRED)
# Sets up global settings
include("${ROOT_USE_FILE}")

# This is required on if there is more than one flag (like on macOS)
separate_arguments(ROOT_EXE_LINKER_FLAGS)

add_executable(simulation src/main.cpp src/funs.cpp include/funs.h src/funs.cpp)
target_link_libraries(simulation PUBLIC ${ROOT_LIBRARIES} ${ROOT_EXE_LINKER_FLAGS})