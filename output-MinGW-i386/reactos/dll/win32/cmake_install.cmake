# Install script for directory: /home/jens/winos/reactos/dll/win32

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
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/acledit/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/aclui/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/activeds/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/actxprxy/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/advapi32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/advapi32_vista/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/advpack/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/atl/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/atl100/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/atl80/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/authz/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/avicap32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/avifil32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/batt/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/bcrypt/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/beepmidi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/browseui/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/cabinet/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/cards/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/cfgmgr32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/clusapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/comcat/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/comctl32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/comdlg32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/compstui/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/credui/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/crtdll/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/crypt32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/cryptdlg/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/cryptdll/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/cryptnet/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/cryptui/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/dbghelp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/dciman32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/devmgr/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/dnsapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/esent/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/faultrep/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/fltlib/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/fmifs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/fontsub/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/framedyn/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/fusion/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/gdiplus/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/getuname/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/hhctrl.ocx/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/hid/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/hlink/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/hnetcfg/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/httpapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/iccvid/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/icmp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ieframe/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/iernonce/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/imaadp32.acm/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/imagehlp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/imm32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/inetcomm/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/inetmib1/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/initpki/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/inseng/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/iologmsg/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/iphlpapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/itircl/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/itss/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/jscript/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/jsproxy/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/kernel32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/kernel32_vista/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/loadperf/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/lpk/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/lsasrv/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/lz32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mapi32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mciavi32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mcicda/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mciqtz32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mciseq/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mciwave/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mgmtapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mlang/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mmdrv/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/modemui/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mpr/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mprapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msacm32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msacm32.drv/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msadp32.acm/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msafd/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mscat32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mscms/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mscoree/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msctf/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msftedit/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msg711.acm/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msgina/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msgsm32.acm/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mshtml/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mshtml.tlb/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msimg32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msimtf/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msisip/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msisys.ocx/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mspatcha/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msports/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msrle32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mssign32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mssip32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mstask/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msv1_0/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msvcrt/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msvcrt20/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msvcrt40/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msvfw32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msvidc32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mswsock/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msxml/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msxml2/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msxml3/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msxml4/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/msxml6/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/mycomput/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/nddeapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/netapi32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/netcfgx/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/netevent/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/netid/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/newdev/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/npptools/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ntdll_vista/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ntdsapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ntlanman/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ntmarta/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/objsel/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/odbc32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/odbccp32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ole32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/oleacc/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/oleaut32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/olecli32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/oledlg/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/olepro32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/olesvr32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/olethk32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/pdh/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/pidgen/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/powrprof/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/printui/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/propsys/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/psapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/pstorec/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/qmgr/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/qmgrprxy/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/query/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/rasadhlp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/rasapi32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/rasdlg/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/rasman/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/resutils/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/riched20/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/riched32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/rpcrt4/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/rsabase/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/rsaenh/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/samlib/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/samsrv/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/sccbase/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/schannel/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/scrrun/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/secur32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/security/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/sensapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/serialui/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/setupapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/sfc/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/sfc_os/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/shdoclc/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/shdocvw/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/shell32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/shfolder/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/shimgvw/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/shlwapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/slbcsp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/smdll/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/sndblst/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/snmpapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/softpub/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/srclient/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/stdole2.tlb/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/stdole32.tlb/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/sti/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/streamci/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/sxs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/syssetup/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/t2embed/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/tapi32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/tapiui/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/themeui/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/traffic/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/twain_32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ubtrfs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/uext2/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ufat/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ufatx/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/uffs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/untfs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/updspapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ureiserfs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/url/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/urlmon/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/userenv/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/usp10/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/uxtheme/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/vbscript/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/version/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/vssapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wbemdisp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wbemprox/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wdmaud.drv/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/windowscodecs/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/windowscodecsext/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/winemp3.acm/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/winfax/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wing32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/winhttp/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wininet/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/winmm/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/winscard/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/winsta/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wintrust/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wlanapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wldap32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wmi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wmiutils/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wmvcore/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ws2_32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/ws2help/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wshirda/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wshom.ocx/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wshtcpip/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wsock32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wtsapi32/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/wuapi/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/xinput1_1/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/xinput1_2/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/xinput1_3/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/xinput9_1_0/cmake_install.cmake")
  include("/home/jens/winos/reactos/output-MinGW-i386/reactos/dll/win32/xmllite/cmake_install.cmake")

endif()
