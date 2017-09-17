# Install script for directory: /home/jens/winos/reactos

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
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/include/xdk/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/include/psdk/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/include/dxsdk/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/include/reactos/wine/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/include/reactos/mc/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/include/asm/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/boot/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/base/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/drivers/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/hal/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/lib/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/media/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/modules/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/ntoskrnl/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/subsystems/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/sdk/tools/wpp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/win32ss/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/jens/winos/reactos/output-MinGW-i386/reactos/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
