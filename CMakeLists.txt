cmake_minimum_required(VERSION 3.5)
project(libserial VERSION 1.0.0 LANGUAGES CXX)

find_package(PythonLibs REQUIRED)
find_package(Threads REQUIRED)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Option to build testlib
option(LIBSERIAL_EXAMPLE "Build libserial example" ON)

add_library(libserial
    src/SerialStream.cpp
    src/SerialStreamBuf.cpp
)

# For use inside build tree
add_library(LibSerial::libserial ALIAS libserial)

target_include_directories(libserial
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(libserial PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)

# Libserial test example
if(LIBSERIAL_EXAMPLE)
    add_executable(egserial example/testlib.cpp)
    target_link_libraries(egserial PRIVATE libserial)
endif()

# Provides install directory variables
include(GNUInstallDirs)
message("Libraries will be installed in " ${CMAKE_INSTALL_FULL_LIBDIR})
message("Headers will be installed in " ${CMAKE_INSTALL_FULL_INCLUDEDIR})

set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/LibSerial)

install(TARGETS libserial
    EXPORT libserial-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

set_target_properties(libserial PROPERTIES EXPORT_NAME LibSerial)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT libserial-targets
  FILE
    LibSerialTargets.cmake
  NAMESPACE
    LibSerial::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

# Create LibSerialConfig.cmake file
include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/LibSerialConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/LibSerialConfig.cmake
  INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

# Install the Config.cmake file
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/LibSerialConfig.cmake
  DESTINATION ${INSTALL_CONFIGDIR}
)

# Exporting from the build tree
export(EXPORT libserial-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/LibSerialTargets.cmake
    NAMESPACE LibSerial::
)

#Register package in user's package registry
export(PACKAGE LibSerial)
