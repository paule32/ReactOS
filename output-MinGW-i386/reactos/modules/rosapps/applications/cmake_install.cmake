# Install script for directory: /home/jens/winos/reactos/modules/rosapps/applications

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
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/cmdutils/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/devutils/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/explorer-old/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/fraginator/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/imagesoft/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/net/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/notevil/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/screensavers/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/sysutils/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/rosapps/applications/winfile/cmake_install.cmake")

endif()

