cmake_minimum_required(VERSION 3.16)

project(hellnah_db LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========================
# Include directories
# ========================
include_directories(include)

# ========================
# Source files
# ========================
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# ========================
# Library
# ========================
add_library(hellnah_db STATIC ${SOURCES})

target_include_directories(hellnah_db PUBLIC include)

# ========================
# Example executable
# ========================
add_executable(example_app examples/main.cpp)

target_link_libraries(example_app PRIVATE hellnah_db)
