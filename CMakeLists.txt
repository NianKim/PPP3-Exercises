cmake_minimum_required(VERSION 3.16)
project(PPP3_Exercises LANGUAGES CXX)

# Use C++20 (Required for PPP3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 (Points to the path we set up in your .zshrc)
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)

# If you added the submodule as discussed, this pulls in the graph library
# If you haven't added it yet, comment out the next line with a '#'
# add_subdirectory(external/graph-lib)

# Example: How to add your Chapter 9/10 drills
 add_executable(ch09_drill chapter09/drill.cpp)
