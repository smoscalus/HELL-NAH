cmake_minimum_required(VERSION 3.16)

project(hellnah_db LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

target_include_directories(hellnah_db
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# ========================
# Example executable
# ========================
add_executable(hellnah examples/main.cpp)

target_link_libraries(hellnah PRIVATE hellnah_db)

# ========================
# Tests
# ========================
enable_testing()

add_executable(tests
    tests/test.cpp
)

target_link_libraries(tests PRIVATE hellnah_db)

add_test(NAME hellnah_tests COMMAND tests)

# ========================
# Install
# ========================
install(TARGETS hellnah_db
    EXPORT hellnahTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT hellnahTargets
    FILE hellnahTargets.cmake
    NAMESPACE hellnah::
    DESTINATION lib/cmake/hellnah
)