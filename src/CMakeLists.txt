# - Main CMake buildscript for mpags-cipher
# Comments in a CMake script are lines beginning with '#' 

# Set CMake requirements then declare project
# These command check we're running a suitable version of CMake and perform
# minimal setup for our project.
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
# Do this to begin with so it's easy to see what compiler command/flags
# are used. This can also be done by removign the 'set' command and
# running make as 'make VERBOSE=1'
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Set the C++ standard directly
set(CMAKE_CXX_STANDARD 14)

# - Declaring the build of mpags-cipher main program 
add_executable(mpags-cipher mpags-cipher.cpp)

# - Use our standard set of flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

# - Declare the compile features we need for mpags-cipher
target_compile_features(mpags-cipher
  PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
  )