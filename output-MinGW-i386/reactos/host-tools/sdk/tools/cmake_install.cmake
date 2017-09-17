# Install script for directory: /home/jens/winos/reactos/sdk/tools

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/cabman/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/hhpcomp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/hpp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/isohybrid/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/kbdtool/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/mkhive/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/mkisofs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/unicode/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/widl/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/wpp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/xml2sdb/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/log2lines/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/rsym/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/host-tools/sdk/tools/fatten/cmake_install.cmake")

endif()

