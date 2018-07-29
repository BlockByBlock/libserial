cmake_minimum_required(VERSION 3.5)
project(testpackage)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

message("CMAKE MODULE PATH: " ${CMAKE_MODULE_PATH})
find_package(LibSerial REQUIRED)

add_executable(main testlib.cpp)

target_link_libraries(main LibSerial::LibSerial)
