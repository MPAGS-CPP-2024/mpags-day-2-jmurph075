# - Main CMake buildscript for mpags-cipher
# Comments in a CMake script are lines beginning with '#'

# - Set CMake requirements then declare project
# for the cipher.

cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
# Do this to begin with so it's easy to see what compiler command/flags
# are used. This can also be done by removing the 'set' command and 
# running make as 'make VERBOSE=1'.
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Set the C++ standard directly
set(CMAKE_CXX_STANDARD 14)

# - Declare the build of mpags-cipher main program
# Have now included the separate function for TransformChar
add_executable(mpags-cipher 
    mpags-cipher.cpp
    MPAGSCipher/TransformChar.cpp
    )

target_include_directories(mpags-cipher
PRIVATE MPAGSCipher
)

# - To prevent vendor extensions to C++11
set(CMAKE_CXX_EXTENSIONS OFF)

# - We want our standard compiler flags to run when using CMake
# These will be extra pedantic for now.
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher
  PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
  )