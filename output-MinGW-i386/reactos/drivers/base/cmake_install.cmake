# Install script for directory: /home/jens/winos/reactos/drivers/base

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
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/base/beep/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/base/bootvid/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/base/condrv/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/base/kdrosdbg/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/base/nmidebug/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/base/null/cmake_install.cmake")

endif()

