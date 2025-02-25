cmake_minimum_required(VERSION 3.15)

project(graphicsGeant4 LANGUAGES CXX)

# set C++ standard
set(CMAKE_CXX_STANDARD 17)

# gather sources
file(GLOB SRCS "src/*.cpp")

# Make a library and add that to C++ executable
add_library(functions SHARED ${SRCS})

add_executable(pointTest pointTest.cpp)
target_link_libraries(pointTest functions)
target_include_directories(pointTest PRIVATE "./src/")

add_executable(lineTest lineTest.cpp)
target_link_libraries(lineTest functions)
target_include_directories(lineTest PRIVATE "./src/")

add_executable(planeTest planeTest.cpp)
target_link_libraries(planeTest functions)
target_include_directories(planeTest PRIVATE "./src/")

