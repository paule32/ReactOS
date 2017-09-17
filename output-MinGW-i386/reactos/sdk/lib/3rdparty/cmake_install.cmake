# Install script for directory: /home/jens/winos/reactos/sdk/lib/3rdparty

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
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/adns/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/bzip2/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/cardlib/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/freetype/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/fullfat/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/libmpg123/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/libsamplerate/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/libwine/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/libwin-iconv/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/libxml2/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/strmbase/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/3rdparty/zlib/cmake_install.cmake")

endif()

