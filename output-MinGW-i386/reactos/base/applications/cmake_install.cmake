# Install script for directory: /home/jens/winos/reactos/base/applications

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
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/atactl/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cacls/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/calc/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/charmap/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/clipbrd/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/cmdutils/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/control/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/dxdiag/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/extrac32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/findstr/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/fltmc/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/fontview/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/games/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/hh/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/iexplore/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/kbswitch/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/logoff/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/magnify/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/mmc/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/mplay32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/msconfig/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/msconfig_new/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/mscutils/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/mspaint/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/mstsc/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/notepad/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/osk/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/rapps/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/regedit/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/regedt32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/sc/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/screensavers/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/setup16/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/shutdown/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/sndrec32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/sndvol32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/taskmgr/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/winhlp32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/winver/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/wordpad/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/write/cmake_install.cmake")

endif()

