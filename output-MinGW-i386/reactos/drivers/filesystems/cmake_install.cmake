# Install script for directory: /home/jens/winos/reactos/drivers/filesystems

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
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/btrfs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/cdfs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/ext2/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/fastfat/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/ffs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/fs_rec/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/msfs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/mup/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/nfs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/npfs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/ntfs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/reiserfs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/filesystems/udfs/cmake_install.cmake")

endif()

