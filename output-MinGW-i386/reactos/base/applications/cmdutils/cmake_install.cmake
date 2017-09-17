# Install script for directory: /home/jens/winos/reactos/base/applications/cmdutils

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
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/at/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/clip/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/comp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/cscript/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/dbgprint/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/doskey/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/eventcreate/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/find/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/help/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/hostname/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/lodctr/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/mode/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/mofcomp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/more/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/reg/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/schtasks/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/sort/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/taskkill/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/tree/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/whoami/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/wmic/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/wscript/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/xcopy/cmake_install.cmake")

endif()

