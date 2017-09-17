# Install script for directory: /home/jens/winos/reactos/base/applications/network

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
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/arp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/dwnl/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/finger/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/ftp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/ipconfig/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/net/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/netsh/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/netstat/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/nslookup/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/ping/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/route/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/telnet/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/tracert/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/whois/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/applications/network/wlanconf/cmake_install.cmake")

endif()

