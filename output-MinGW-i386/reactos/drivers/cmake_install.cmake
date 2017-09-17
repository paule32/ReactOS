# Install script for directory: /home/jens/winos/reactos/drivers

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
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/base/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/battery/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/bluetooth/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/bus/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/crypto/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filters/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/hid/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/input/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/ksfilter/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/multimedia/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/network/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/parallel/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/processor/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/sac/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/serial/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/setup/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/storage/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/usb/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/wdm/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/wmi/cmake_install.cmake")

endif()

