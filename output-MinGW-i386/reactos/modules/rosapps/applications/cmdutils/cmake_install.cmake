# Install script for directory: /home/jens/winos/reactos/modules/rosapps/applications/cmdutils

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
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/appwiz/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/arping/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/cat/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/gflags/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/ntfsinfo/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/tee/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/touch/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/uptime/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/winspool_print/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/y/cmake_install.cmake")

endif()

