cmake_minimum_required(VERSION 3.16)
project(oct26 LANGUAGES CXX)

# Enforce out-of-source builds to prevent polluting the repository tree
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR 
    "In-source builds are forbidden.\n"
    "Please create an out-of-source build directory, for example:\n"
    "  cmake -B build\n"
    "  cmake --build build\n"
    "On Windows (MSYS2 UCRT64):\n"
    "  cmake -B build-ucrt64\n"
    "  cmake --build build-ucrt64"
  )
endif()

# C++ Standard Configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable compiler warnings across platforms
if(MSVC)
  add_compile_options(/W4 /EHsc)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Define Executable Target
add_executable(oct26 main.cpp)
