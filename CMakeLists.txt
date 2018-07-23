cmake_minimum_required(VERSION 3.5)
project(testlib)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

add_library(libserial STATIC
    src/SerialStream.cpp
    src/SerialStreamBuf.cpp
)

target_include_directories(libserial
    PUBLIC include
    PRIVATE src
)

add_executable(testlib test/testlib.cpp)

target_link_libraries(testlib libserial)
