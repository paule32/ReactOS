/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/reactos/idl/winspool.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#ifdef __REACTOS__
#define WIN32_LEAN_AND_MEAN
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __winspool_c_h__
#define __winspool_c_h__

/* Forward declarations */

/* Headers for imported files */


#ifdef __cplusplus
extern "C" {
#endif

#ifndef _DTYP_IDL
#define _DTYP_IDL
#ifndef _WINDEF_H
typedef int BOOL;
typedef int *PBOOL;
typedef int *LPBOOL;
typedef unsigned char BYTE;
typedef unsigned char *PBYTE;
typedef unsigned char *LPBYTE;
typedef ULONG DWORD;
typedef ULONG *PDWORD;
typedef ULONG *LPDWORD;
#endif
#ifndef _BASETSD_H_
typedef unsigned int DWORD32;
typedef UINT64 DWORD64;
#endif
#ifndef _WINDEF_H
typedef int INT;
typedef int *LPINT;
#endif
#ifndef _BASETSD_H_
typedef signed char INT8;
typedef signed short INT16;
typedef signed int INT32;
typedef INT64 INT64;
#endif
#ifndef _BASETSD_H_
typedef signed int LONG32;
typedef INT64 LONG64;
#endif
typedef UINT64 QWORD;
#ifndef _WINNT_
typedef short SHORT;
#endif
typedef INT64 TIME;
#ifndef _WINNT_
typedef char CHAR;
typedef char *PCHAR;
typedef unsigned char UCHAR;
typedef unsigned char *PUCHAR;
#endif
#ifndef _WINDEF_H
typedef unsigned int UINT;
#endif
#ifndef _BASETSD_H_
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef UINT64 UINT64;
#endif
#ifndef _WINNT_
typedef ULONG ULONG;
typedef ULONG *PULONG;
#endif
#ifndef _BASETSD_H_
typedef unsigned int ULONG32;
typedef UINT64 ULONG64;
#endif
#ifndef _WINNT_
typedef UINT64 ULONGLONG;
typedef unsigned short USHORT;
#endif
#ifndef _WINDEF_H
typedef unsigned short WORD;
typedef unsigned short *PWORD;
typedef unsigned short *LPWORD;
#endif
#ifndef _WINNT_
typedef LONG LONG;
typedef LONG *PLONG;
#endif
#ifndef _WINDEF_H
typedef LONG *LPLONG;
#endif
#ifndef _WINNT_
typedef INT64 LONGLONG;
#endif
#ifndef _WINDEF_H
typedef float FLOAT;
#endif
#ifndef __wtypes_h__
typedef double DOUBLE;
#endif
#ifndef _WINNT_
typedef BYTE BOOLEAN;
typedef BYTE *PBOOLEAN;
#endif
#ifndef _BASETSD_H_
typedef LONG LONG_PTR;
typedef ULONG ULONG_PTR;
typedef ULONG_PTR SIZE_T;
typedef ULONG_PTR DWORD_PTR;
#endif
typedef DWORD NET_API_STATUS;
#ifndef _WINNT_
typedef ULONGLONG DWORDLONG;
typedef ULONGLONG *PDWORDLONG;
#endif
typedef DWORD HCALL;
#ifndef _WINNT_
typedef void *HANDLE;
typedef void *PVOID;
#endif
#ifndef __WINE_RPCDCE_H
typedef void *RPC_BINDING_HANDLE;
#endif
typedef void *PCONTEXT_HANDLE;
typedef PCONTEXT_HANDLE *PPCONTEXT_HANDLE;
#ifndef _WINNT_
typedef wchar_t WCHAR;
typedef wchar_t *PWCHAR;
#if 0
typedef wchar_t UNICODE;
#endif
typedef const char *LPCSTR;
typedef const wchar_t *LPCWSTR;
typedef char *PSTR;
typedef char *LPSTR;
typedef wchar_t *LPWSTR;
typedef wchar_t *PWSTR;
#endif
typedef const wchar_t *LMCSTR;
typedef WCHAR *LMSTR;
#ifndef __wtypes_h__
typedef WCHAR *BSTR;
#endif
#if 0
typedef LPCSTR LPCTSTR;
typedef LPSTR LPTSTR;
typedef CHAR TCHAR;
#endif
#if 0
typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME;
typedef struct _FILETIME *PFILETIME;
typedef struct _FILETIME *LPFILETIME;
typedef struct _GUID {
    DWORD Data1;
    WORD Data2;
    WORD Data3;
    BYTE Data4[8];
} GUID;
typedef struct _GUID UUID;
typedef struct _GUID *PGUID;
typedef struct _LARGE_INTEGER {
    LONGLONG QuadPart;
} LARGE_INTEGER;
typedef struct _LARGE_INTEGER *PLARGE_INTEGER;
typedef DWORD LCID;
#endif
typedef struct _RPC_UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    LPWSTR Buffer;
} RPC_UNICODE_STRING;
typedef struct _RPC_UNICODE_STRING *PRPC_UNICODE_STRING;
#if 0
typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME;
typedef struct _SYSTEMTIME *PSYSTEMTIME;
typedef struct _UINT128 {
    UINT64 lower;
    UINT64 upper;
} UINT128;
typedef struct _UINT128 *PUINT128;
typedef struct _ULARGE_INTEGER {
    ULONGLONG QuadPart;
} ULARGE_INTEGER;
typedef struct _ULARGE_INTEGER *PULARGE_INTEGER;
#endif
#if 0
typedef struct _SID_IDENTIFIER_AUTHORITY {
    BYTE Value[6];
} SID_IDENTIFIER_AUTHORITY;
typedef struct _SID {
    BYTE Revision;
    BYTE SubAuthorityCount;
    SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
    DWORD SubAuthority[1];
} SID;
typedef struct _SID *PSID;
typedef struct _ACCESS_MASK {
    DWORD ACCESS_MASK;
} ACCESS_MASK;
typedef struct _ACCESS_MASK *PACCESS_MASK;
typedef struct _ACE_HEADER {
    UCHAR AceType;
    UCHAR AceFlags;
    USHORT AceSize;
} ACE_HEADER;
typedef struct _ACE_HEADER *PACE_HEADER;
typedef struct _ACCESS_ALLOWED_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} ACCESS_ALLOWED_ACE;
typedef struct _ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;
typedef struct _ACCESS_ALLOWED_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} ACCESS_ALLOWED_OBJECT_ACE;
typedef struct _ACCESS_ALLOWED_OBJECT_ACE *PACCESS_ALLOWED_OBJECT_ACE;
typedef struct _ACCESS_DENIED_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} ACCESS_DENIED_ACE;
typedef struct _ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;
typedef struct _ACCESS_ALLOWED_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} ACCESS_ALLOWED_CALLBACK_ACE;
typedef struct _ACCESS_ALLOWED_CALLBACK_ACE *PACCESS_ALLOWED_CALLBACK_ACE;
typedef struct _ACCESS_DENIED_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} ACCESS_DENIED_CALLBACK_ACE;
typedef struct _ACCESS_DENIED_CALLBACK_ACE *PACCESS_DENIED_CALLBACK_ACE;
typedef struct _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} ACCESS_ALLOWED_CALLBACK_OBJECT_ACE;
typedef struct _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE *PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;
typedef struct _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} ACCESS_DENIED_CALLBACK_OBJECT_ACE;
typedef struct _ACCESS_DENIED_CALLBACK_OBJECT_ACE *PACCESS_DENIED_CALLBACK_OBJECT_ACE;
typedef struct _SYSTEM_AUDIT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} SYSTEM_AUDIT_ACE;
typedef struct _SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;
typedef struct _SYSTEM_AUDIT_CALLBACK_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} SYSTEM_AUDIT_CALLBACK_ACE;
typedef struct _SYSTEM_AUDIT_CALLBACK_ACE *PSYSTEM_AUDIT_CALLBACK_ACE;
typedef struct _SYSTEM_MANDATORY_LABEL_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD SidStart;
} SYSTEM_MANDATORY_LABEL_ACE;
typedef struct _SYSTEM_MANDATORY_LABEL_ACE *PSYSTEM_MANDATORY_LABEL_ACE;
typedef struct _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} SYSTEM_AUDIT_CALLBACK_OBJECT_ACE;
typedef struct _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE *PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;
typedef struct _ACL {
    UCHAR AclRevision;
    UCHAR Sbz1;
    USHORT AclSize;
    USHORT AceCount;
    USHORT Sbz2;
} ACL;
typedef struct _ACL *PACL;
typedef struct _SECURITY_DESCRIPTOR {
    UCHAR Revision;
    UCHAR Sbz1;
    USHORT Control;
    ULONG Owner;
    ULONG Group;
    ULONG Sacl;
    ULONG Dacl;
} SECURITY_DESCRIPTOR;
typedef struct _SECURITY_DESCRIPTOR *PSECURITY_DESCRIPTOR;
typedef DWORD SECURITY_INFORMATION;
typedef DWORD *PSECURITY_INFORMATION;
#endif
typedef struct _RPC_SID {
    UCHAR Revision;
    UCHAR SubAuthorityCount;
    SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
    DWORD SubAuthority[1];
} RPC_SID;
typedef struct _RPC_SID *PRPC_SID;
#endif /* _DTYP_IDL */
typedef void *WINSPOOL_GDI_HANDLE;
typedef void *WINSPOOL_PRINTER_HANDLE;
typedef WCHAR *WINSPOOL_HANDLE;
typedef WORD WINSPOOL_LANGID;
typedef enum __WIDL_winspool_generated_name_00000000 {
    WINSPOOL_BIDI_NULL = 0,
    WINSPOOL_BIDI_INT = 1,
    WINSPOOL_BIDI_FLOAT = 2,
    WINSPOOL_BIDI_BOOL = 3,
    WINSPOOL_BIDI_STRING = 4,
    WINSPOOL_BIDI_TEXT = 5,
    WINSPOOL_BIDI_ENUM = 6,
    WINSPOOL_BIDI_BLOB = 7
} WINSPOOL_BIDI_TYPE;
typedef enum __WIDL_winspool_generated_name_00000001 {
    WINSPOOL_TABLE_DWORD = 1,
    WINSPOOL_TABLE_STRING = 2,
    WINSPOOL_TABLE_DEVMODE = 3,
    WINSPOOL_TABLE_TIME = 4,
    WINSPOOL_TABLE_SECURITYDESCRIPTOR = 5
} WINSPOOL_TABLE_TYPE;
typedef struct _WINSPOOL_RECTL {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} WINSPOOL_RECTL;
typedef struct _WINSPOOL_SIZEL {
    LONG cx;
    LONG cy;
} WINSPOOL_SIZEL;
typedef struct _WINSPOOL_DOC_INFO_1 {
    WCHAR *pDocName;
    WCHAR *pOutputFile;
    WCHAR *pDatatype;
} WINSPOOL_DOC_INFO_1;
typedef struct _WINSPOOL_DRIVER_INFO_1 {
    WCHAR *pName;
} WINSPOOL_DRIVER_INFO_1;
typedef struct _WINSPOOL_DRIVER_INFO_2 {
    DWORD cVersion;
    WCHAR *pName;
    WCHAR *pEnvironment;
    WCHAR *pDriverPath;
    WCHAR *pDataFile;
    WCHAR *pConfigFile;
} WINSPOOL_DRIVER_INFO_2;
typedef struct _WINSPOOL_DRIVER_INFO_3 {
    DWORD cVersion;
    WCHAR *pName;
    WCHAR *pEnvironment;
    WCHAR *pDriverPath;
    WCHAR *pDataFile;
    WCHAR *pConfigFile;
    WCHAR *pHelpFile;
    WCHAR *pMonitorName;
    WCHAR *pDefaultDataType;
    DWORD cchDependentFiles;
    WCHAR *pDependentFiles;
} WINSPOOL_DRIVER_INFO_3;
typedef struct _WINSPOOL_DRIVER_INFO_4 {
    DWORD cVersion;
    WCHAR *pName;
    WCHAR *pEnvironment;
    WCHAR *pDriverPath;
    WCHAR *pDataFile;
    WCHAR *pConfigFile;
    WCHAR *pHelpFile;
    WCHAR *pMonitorName;
    WCHAR *pDefaultDataType;
    DWORD cchDependentFiles;
    WCHAR *pDependentFiles;
    DWORD cchPreviousNames;
    WCHAR *pszzPreviousNames;
} WINSPOOL_DRIVER_INFO_4;
typedef struct _WINSPOOL_DRIVER_INFO_6 {
    DWORD cVersion;
    WCHAR *pName;
    WCHAR *pEnvironment;
    WCHAR *pDriverPath;
    WCHAR *pDataFile;
    WCHAR *pConfigFile;
    WCHAR *pHelpFile;
    WCHAR *pMonitorName;
    WCHAR *pDefaultDataType;
    DWORD cchDependentFiles;
    WCHAR *pDependentFiles;
    DWORD cchPreviousNames;
    WCHAR *pszzPreviousNames;
    FILETIME ftDriverDate;
    DWORDLONG dwlDriverVersion;
    WCHAR *pMfgName;
    WCHAR *pOEMUrl;
    WCHAR *pHardwareID;
    WCHAR *pProvider;
} WINSPOOL_DRIVER_INFO_6;
typedef struct _WINSPOOL_DRIVER_INFO_8 {
    DWORD cVersion;
    WCHAR *pName;
    WCHAR *pEnvironment;
    WCHAR *pDriverPath;
    WCHAR *pDataFile;
    WCHAR *pConfigFile;
    WCHAR *pHelpFile;
    WCHAR *pMonitorName;
    WCHAR *pDefaultDataType;
    DWORD cchDependentFiles;
    WCHAR *pDependentFiles;
    DWORD cchPreviousNames;
    WCHAR *pszzPreviousNames;
    FILETIME ftDriverDate;
    DWORDLONG dwlDriverVersion;
    WCHAR *pMfgName;
    WCHAR *pOEMUrl;
    WCHAR *pHardwareID;
    WCHAR *pProvider;
    WCHAR *pPrintProcessor;
    WCHAR *pVendorSetup;
    DWORD cchColorProfiles;
    WCHAR *pszzColorProfiles;
    WCHAR *pInfPath;
    DWORD dwPrinterDriverAttributes;
    DWORD cchCoreDependencies;
    WCHAR *pszzCoreDriverDependencies;
    FILETIME ftMinInboxDriverVerDate;
    DWORDLONG dwlMinInboxDriverVerVersion;
} WINSPOOL_DRIVER_INFO_8;
typedef struct _WINSPOOL_FORM_INFO_1 {
    DWORD Flags;
    WCHAR *pName;
    WINSPOOL_SIZEL Size;
    WINSPOOL_RECTL ImageableArea;
} WINSPOOL_FORM_INFO_1;
typedef struct _WINSPOOL_FORM_INFO_2 {
    DWORD Flags;
    const WCHAR *pName;
    WINSPOOL_SIZEL Size;
    WINSPOOL_RECTL ImageableArea;
    const WCHAR *pKeyword;
    DWORD StringType;
    const WCHAR *pMuiDll;
    DWORD dwResourceId;
    const WCHAR *pDisplayName;
    WINSPOOL_LANGID wLangID;
} WINSPOOL_FORM_INFO_2;
typedef struct _WINSPOOL_JOB_INFO_1 {
    DWORD JobId;
    WCHAR *pPrinterName;
    WCHAR *pMachineName;
    WCHAR *pUserName;
    WCHAR *pDocument;
    WCHAR *pDatatype;
    WCHAR *pStatus;
    DWORD Status;
    DWORD Priority;
    DWORD Position;
    DWORD TotalPages;
    DWORD PagesPrinted;
    SYSTEMTIME Submitted;
} WINSPOOL_JOB_INFO_1;
typedef struct _WINSPOOL_JOB_INFO_2 {
    DWORD JobId;
    WCHAR *pPrinterName;
    WCHAR *pMachineName;
    WCHAR *pUserName;
    WCHAR *pDocument;
    WCHAR *pNotifyName;
    WCHAR *pDatatype;
    WCHAR *pPrintProcessor;
    WCHAR *pParameters;
    WCHAR *pDriverName;
    ULONG_PTR pDevMode;
    WCHAR *pStatus;
    ULONG_PTR pSecurityDescriptor;
    DWORD Status;
    DWORD Priority;
    DWORD Position;
    DWORD StartTime;
    DWORD UntilTime;
    DWORD TotalPages;
    DWORD Size;
    SYSTEMTIME Submitted;
    DWORD Time;
    DWORD PagesPrinted;
} WINSPOOL_JOB_INFO_2;
typedef struct _WINSPOOL_JOB_INFO_3 {
    DWORD JobId;
    DWORD NextJobId;
    DWORD Reserved;
} WINSPOOL_JOB_INFO_3;
typedef struct _WINSPOOL_JOB_INFO_4 {
    DWORD JobId;
    WCHAR *pPrinterName;
    WCHAR *pMachineName;
    WCHAR *pUserName;
    WCHAR *pDocument;
    WCHAR *pNotifyName;
    WCHAR *pDatatype;
    WCHAR *pPrintProcessor;
    WCHAR *pParameters;
    WCHAR *pDriverName;
    ULONG_PTR pDevMode;
    WCHAR *pStatus;
    ULONG_PTR pSecurityDescriptor;
    DWORD Status;
    DWORD Priority;
    DWORD Position;
    DWORD StartTime;
    DWORD UntilTime;
    DWORD TotalPages;
    DWORD Size;
    SYSTEMTIME Submitted;
    DWORD Time;
    DWORD PagesPrinted;
    LONG SizeHigh;
} WINSPOOL_JOB_INFO_4;
typedef struct _WINSPOOL_MONITOR_INFO_1 {
    WCHAR *pName;
} WINSPOOL_MONITOR_INFO_1;
typedef struct _WINSPOOL_MONITOR_INFO_2 {
    WCHAR *pName;
    WCHAR *pEnvironment;
    WCHAR *pDLLName;
} WINSPOOL_MONITOR_INFO_2;
typedef struct _WINSPOOL_PORT_INFO_1 {
    WCHAR *pPortName;
} WINSPOOL_PORT_INFO_1;
typedef struct _WINSPOOL_PORT_INFO_2 {
    WCHAR *pPortName;
    WCHAR *pMonitorName;
    WCHAR *pDescription;
    DWORD fPortType;
    DWORD Reserved;
} WINSPOOL_PORT_INFO_2;
typedef struct _WINSPOOL_PORT_INFO_3 {
    DWORD dwStatus;
    WCHAR *pszStatus;
    DWORD dwSeverity;
} WINSPOOL_PORT_INFO_3;
typedef struct _WINSPOOL_PORT_INFO_FF {
    WCHAR *pPortName;
    DWORD cbMonitorData;
    BYTE *pMonitorData;
} WINSPOOL_PORT_INFO_FF;
typedef struct _WINSPOOL_PRINTER_INFO_STRESS {
    WCHAR *pPrinterName;
    WCHAR *pServerName;
    DWORD cJobs;
    DWORD cTotalJobs;
    DWORD cTotalBytes;
    SYSTEMTIME stUpTime;
    DWORD MaxcRef;
    DWORD cTotalPagesPrinted;
    DWORD dwGetVersion;
    DWORD fFreeBuild;
    DWORD cSpooling;
    DWORD cMaxSpooling;
    DWORD cRef;
    DWORD cErrorOutOfPaper;
    DWORD cErrorNotReady;
    DWORD cJobError;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwHighPartTotalBytes;
    DWORD cChangeID;
    DWORD dwLastError;
    DWORD Status;
    DWORD cEnumerateNetworkPrinters;
    DWORD cAddNetPrinters;
    USHORT wProcessorArchitecture;
    USHORT wProcessorLevel;
    DWORD cRefIC;
    DWORD dwReserved2;
    DWORD dwReserved3;
} WINSPOOL_PRINTER_INFO_STRESS;
typedef struct _WINSPOOL_PRINTER_INFO_1 {
    DWORD Flags;
    WCHAR *pDescription;
    WCHAR *pName;
    WCHAR *pComment;
} WINSPOOL_PRINTER_INFO_1;
typedef struct _WINSPOOL_PRINTER_INFO_2 {
    WCHAR *pServerName;
    WCHAR *pPrinterName;
    WCHAR *pShareName;
    WCHAR *pPortName;
    WCHAR *pDriverName;
    WCHAR *pComment;
    WCHAR *pLocation;
    ULONG_PTR pDevMode;
    WCHAR *pSepFile;
    WCHAR *pPrintProcessor;
    WCHAR *pDatatype;
    WCHAR *pParameters;
    ULONG_PTR pSecurityDescriptor;
    DWORD Attributes;
    DWORD Priority;
    DWORD DefaultPriority;
    DWORD StartTime;
    DWORD UntilTime;
    DWORD Status;
    DWORD cJobs;
    DWORD AveragePPM;
} WINSPOOL_PRINTER_INFO_2;
typedef struct _WINSPOOL_PRINTER_INFO_3 {
    ULONG_PTR pSecurityDescriptor;
} WINSPOOL_PRINTER_INFO_3;
typedef struct _WINSPOOL_PRINTER_INFO_4 {
    WCHAR *pPrinterName;
    WCHAR *pServerName;
    DWORD Attributes;
} WINSPOOL_PRINTER_INFO_4;
typedef struct _WINSPOOL_PRINTER_INFO_5 {
    WCHAR *pPrinterName;
    WCHAR *pPortName;
    DWORD Attributes;
    DWORD DeviceNotSelectedTimeout;
    DWORD TransmissionRetryTimeout;
} WINSPOOL_PRINTER_INFO_5;
typedef struct _WINSPOOL_PRINTER_INFO_6 {
    DWORD dwStatus;
} WINSPOOL_PRINTER_INFO_6;
typedef struct _WINSPOOL_PRINTER_INFO_7 {
    WCHAR *pszObjectGUID;
    DWORD dwAction;
} WINSPOOL_PRINTER_INFO_7;
typedef struct _WINSPOOL_PRINTER_INFO_8 {
    ULONG_PTR pDevMode;
} WINSPOOL_PRINTER_INFO_8;
typedef struct _WINSPOOL_PRINTER_INFO_9 {
    ULONG_PTR pDevMode;
} WINSPOOL_PRINTER_INFO_9;
typedef struct _WINSPOOL_PROVIDOR_INFO_1 {
    WCHAR *pName;
    WCHAR *pEnvironment;
    WCHAR *pDLLName;
} WINSPOOL_PROVIDOR_INFO_1;
typedef struct _WINSPOOL_PROVIDOR_INFO_2 {
    WCHAR *pOrder;
} WINSPOOL_PROVIDOR_INFO_2;
typedef struct _WINSPOOL_SPLCLIENT_INFO_1 {
    DWORD dwSize;
    WCHAR *pMachineName;
    WCHAR *pUserName;
    DWORD dwBuildNum;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    USHORT wProcessorArchitecture;
} WINSPOOL_SPLCLIENT_INFO_1;
typedef struct _WINSPOOL_SPLCLIENT_INFO_2 {
    LONG_PTR notUsed;
} WINSPOOL_SPLCLIENT_INFO_2;
typedef struct _WINSPOOL_SPLCLIENT_INFO_3 {
    UINT cbSize;
    DWORD dwFlags;
    DWORD dwSize;
    WCHAR *pMachineName;
    WCHAR *pUserName;
    DWORD dwBuildNum;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    USHORT wProcessorArchitecture;
    UINT64 hSplPrinter;
} WINSPOOL_SPLCLIENT_INFO_3;
typedef struct _WINSPOOL_BINARY_CONTAINER {
    DWORD cbBuf;
    BYTE *pszString;
} WINSPOOL_BINARY_CONTAINER;
typedef struct _WINSPOOL_BIDI_DATA {
    DWORD dwBidiType;
    union {
        INT bData;
        LONG iData;
        WCHAR *sData;
        FLOAT fData;
        WINSPOOL_BINARY_CONTAINER biData;
    } u;
} WINSPOOL_BIDI_DATA;
typedef struct _WINSPOOL_BIDI_REQUEST_DATA {
    DWORD dwReqNumber;
    WCHAR *pSchema;
    WINSPOOL_BIDI_DATA data;
} WINSPOOL_BIDI_REQUEST_DATA;
typedef struct _WINSPOOL_BIDI_RESPONSE_DATA {
    DWORD dwResult;
    DWORD dwReqNumber;
    WCHAR *pSchema;
    WINSPOOL_BIDI_DATA data;
} WINSPOOL_BIDI_RESPONSE_DATA;
typedef struct _WINSPOOL_BIDI_REQUEST_CONTAINER {
    DWORD Version;
    DWORD Flags;
    DWORD Count;
    WINSPOOL_BIDI_REQUEST_DATA aData[1];
} WINSPOOL_BIDI_REQUEST_CONTAINER;
typedef struct _WINSPOOL_BIDI_RESPONSE_CONTAINER {
    DWORD Version;
    DWORD Flags;
    DWORD Count;
    WINSPOOL_BIDI_RESPONSE_DATA aData[1];
} WINSPOOL_BIDI_RESPONSE_CONTAINER;
typedef struct _WINSPOOL_DOC_INFO_CONTAINER {
    DWORD Level;
    union {
        WINSPOOL_DOC_INFO_1 *pDocInfo1;
    } DocInfo;
} WINSPOOL_DOC_INFO_CONTAINER;
typedef struct _WINSPOOL_DEVMODE_CONTAINER {
    DWORD cbBuf;
    BYTE *pDevMode;
} WINSPOOL_DEVMODE_CONTAINER;
typedef struct _WINSPOOL_DRIVER_CONTAINER {
    DWORD Level;
    union {
        WINSPOOL_DRIVER_INFO_1 *pNotUsed;
        WINSPOOL_DRIVER_INFO_2 *Level2;
        WINSPOOL_DRIVER_INFO_3 *Level3;
        WINSPOOL_DRIVER_INFO_4 *Level4;
        WINSPOOL_DRIVER_INFO_6 *Level6;
        WINSPOOL_DRIVER_INFO_8 *Level8;
    } DriverInfo;
} WINSPOOL_DRIVER_CONTAINER;
typedef struct _WINSPOOL_FORM_CONTAINER {
    DWORD Level;
    union {
        WINSPOOL_FORM_INFO_1 *pFormInfo1;
        WINSPOOL_FORM_INFO_2 *pFormInfo2;
    } FormInfo;
} WINSPOOL_FORM_CONTAINER;
typedef struct _WINSPOOL_JOB_CONTAINER {
    DWORD Level;
    union {
        WINSPOOL_JOB_INFO_1 *Level1;
        WINSPOOL_JOB_INFO_2 *Level2;
        WINSPOOL_JOB_INFO_3 *Level3;
        WINSPOOL_JOB_INFO_4 *Level4;
    } JobInfo;
} WINSPOOL_JOB_CONTAINER;
typedef struct _WINSPOOL_MONITOR_CONTAINER {
    DWORD Level;
    union {
        WINSPOOL_MONITOR_INFO_1 *pMonitorInfo1;
        WINSPOOL_MONITOR_INFO_2 *pMonitorInfo2;
    } MonitorInfo;
} WINSPOOL_MONITOR_CONTAINER;
typedef struct _WINSPOOL_PORT_CONTAINER {
    DWORD Level;
    union {
        WINSPOOL_PORT_INFO_1 *pPortInfo1;
        WINSPOOL_PORT_INFO_2 *pPortInfo2;
        WINSPOOL_PORT_INFO_3 *pPortInfo3;
        WINSPOOL_PORT_INFO_FF *pPortInfoFF;
    } PortInfo;
} WINSPOOL_PORT_CONTAINER;
typedef struct _WINSPOOL_PORT_VAR_CONTAINER {
    DWORD cbMonitorData;
    BYTE *pMonitorData;
} WINSPOOL_PORT_VAR_CONTAINER;
typedef struct _WINSPOOL_PRINTER_CONTAINER {
    DWORD Level;
    union {
        WINSPOOL_PRINTER_INFO_STRESS *pPrinterInfoStress;
        WINSPOOL_PRINTER_INFO_1 *pPrinterInfo1;
        WINSPOOL_PRINTER_INFO_2 *pPrinterInfo2;
        WINSPOOL_PRINTER_INFO_3 *pPrinterInfo3;
        WINSPOOL_PRINTER_INFO_4 *pPrinterInfo4;
        WINSPOOL_PRINTER_INFO_5 *pPrinterInfo5;
        WINSPOOL_PRINTER_INFO_6 *pPrinterInfo6;
        WINSPOOL_PRINTER_INFO_7 *pPrinterInfo7;
        WINSPOOL_PRINTER_INFO_8 *pPrinterInfo8;
        WINSPOOL_PRINTER_INFO_9 *pPrinterInfo9;
    } PrinterInfo;
} WINSPOOL_PRINTER_CONTAINER;
typedef struct _WINSPOOL_PROVIDOR_CONTAINER {
    DWORD Level;
    union {
        WINSPOOL_PROVIDOR_INFO_1 *pProvidorInfo1;
        WINSPOOL_PROVIDOR_INFO_2 *pProvidorInfo2;
    } ProvidorInfo;
} WINSPOOL_PROVIDOR_CONTAINER;
typedef struct _WINSPOOL_SECURITY_CONTAINER {
    DWORD cbBuf;
    BYTE *pSecurity;
} WINSPOOL_SECURITY_CONTAINER;
typedef struct _WINSPOOL_SPLCLIENT_CONTAINER {
    DWORD Level;
    union {
        WINSPOOL_SPLCLIENT_INFO_1 *pClientInfo1;
        WINSPOOL_SPLCLIENT_INFO_2 *pNotUsed1;
        WINSPOOL_SPLCLIENT_INFO_3 *pNotUsed2;
    } ClientInfo;
} WINSPOOL_SPLCLIENT_CONTAINER;
typedef struct _WINSPOOL_STRING_CONTAINER {
    DWORD cbBuf;
    WCHAR *pszString;
} WINSPOOL_STRING_CONTAINER;
typedef struct _WINSPOOL_SYSTEMTIME_CONTAINER {
    DWORD cbBuf;
    SYSTEMTIME *pSystemTime;
} WINSPOOL_SYSTEMTIME_CONTAINER;
typedef struct _WINSPOOL_V2_NOTIFY_OPTIONS_TYPE {
    USHORT Type;
    USHORT Reserved0;
    DWORD Reserved1;
    DWORD Reserved2;
    DWORD Count;
    USHORT *pFields;
} WINSPOOL_V2_NOTIFY_OPTIONS_TYPE;
typedef struct _WINSPOOL_V2_NOTIFY_OPTIONS {
    DWORD Version;
    DWORD Reserved;
    DWORD Count;
    WINSPOOL_V2_NOTIFY_OPTIONS_TYPE *pTypes;
} WINSPOOL_V2_NOTIFY_OPTIONS;
typedef union _WINSPOOL_V2_NOTIFY_INFO_DATA_DATA {
    WINSPOOL_STRING_CONTAINER String;
    DWORD dwData[2];
    WINSPOOL_SYSTEMTIME_CONTAINER SystemTime;
    WINSPOOL_DEVMODE_CONTAINER DevMode;
    WINSPOOL_SECURITY_CONTAINER SecurityDescriptor;
} WINSPOOL_V2_NOTIFY_INFO_DATA_DATA;
typedef struct _WINSPOOL_V2_NOTIFY_INFO_DATA {
    USHORT Type;
    USHORT Field;
    DWORD Reserved;
    DWORD Id;
    WINSPOOL_V2_NOTIFY_INFO_DATA_DATA Data;
} WINSPOOL_V2_NOTIFY_INFO_DATA;
typedef struct _WINSPOOL_V2_NOTIFY_INFO {
    DWORD Version;
    DWORD Flags;
    DWORD Count;
    WINSPOOL_V2_NOTIFY_INFO_DATA aData[1];
} WINSPOOL_V2_NOTIFY_INFO;
typedef union _WINSPOOL_V2_UREPLY_PRINTER {
    WINSPOOL_V2_NOTIFY_INFO *pInfo;
} WINSPOOL_V2_UREPLY_PRINTER;
/*****************************************************************************
 * winspool interface (v1.0)
 */
#ifndef __winspool_INTERFACE_DEFINED__
#define __winspool_INTERFACE_DEFINED__

extern RPC_IF_HANDLE winspool_v1_0_c_ifspec;
extern RPC_IF_HANDLE winspool_v1_0_s_ifspec;
DWORD __cdecl _RpcEnumPrinters(
    DWORD Flags,
    WINSPOOL_HANDLE Name,
    DWORD Level,
    BYTE *pPrinterEnum,
    DWORD cbBuf,
    DWORD *pcbNeeded,
    DWORD *pcReturned);

DWORD __cdecl _RpcOpenPrinter(
    WINSPOOL_HANDLE pPrinterName,
    WINSPOOL_PRINTER_HANDLE *phPrinter,
    WCHAR *pDatatype,
    WINSPOOL_DEVMODE_CONTAINER *pDevModeContainer,
    DWORD AccessRequired);

DWORD __cdecl _RpcSetJob(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD JobId,
    WINSPOOL_JOB_CONTAINER *pJobContainer,
    DWORD Command);

DWORD __cdecl _RpcGetJob(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD JobId,
    DWORD Level,
    BYTE *pJob,
    DWORD cbBuf,
    DWORD *pcbNeeded);

DWORD __cdecl _RpcEnumJobs(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD FirstJob,
    DWORD NoJobs,
    DWORD Level,
    BYTE *pJob,
    DWORD cbBuf,
    DWORD *pcbNeeded,
    DWORD *pcReturned);

DWORD __cdecl _RpcAddPrinter(
    WINSPOOL_HANDLE pName,
    WINSPOOL_PRINTER_CONTAINER *pPrinterContainer,
    WINSPOOL_DEVMODE_CONTAINER *pDevModeContainer,
    WINSPOOL_SECURITY_CONTAINER *pSecurityContainer,
    WINSPOOL_PRINTER_HANDLE *pHandle);

DWORD __cdecl _RpcDeletePrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter);

DWORD __cdecl _RpcSetPrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WINSPOOL_PRINTER_CONTAINER *pPrinterContainer,
    WINSPOOL_DEVMODE_CONTAINER *pDevModeContainer,
    WINSPOOL_SECURITY_CONTAINER *pSecurityContainer,
    DWORD Command);

DWORD __cdecl _RpcGetPrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD Level,
    BYTE *pPrinter,
    DWORD cbBuf,
    DWORD *pcbNeeded);

DWORD __cdecl _RpcAddPrinterDriver(
    WINSPOOL_HANDLE pName,
    WINSPOOL_DRIVER_CONTAINER *pDriverContainer);

DWORD __cdecl _RpcEnumPrinterDrivers(
    WINSPOOL_HANDLE pName,
    WCHAR *pEnvironment,
    DWORD Level,
    BYTE *pDrivers,
    DWORD cbBuf,
    DWORD *pcbNeeded,
    DWORD *pcReturned);

DWORD __cdecl _RpcGetPrinterDriver(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WCHAR *pEnvironment,
    DWORD Level,
    BYTE *pDriver,
    DWORD cbBuf,
    DWORD *pcbNeeded);

DWORD __cdecl _RpcGetPrinterDriverDirectory(
    WINSPOOL_HANDLE pName,
    WCHAR *pEnvironment,
    DWORD Level,
    BYTE *pDriverDirectory,
    DWORD cbBuf,
    DWORD *pcbNeeded);

DWORD __cdecl _RpcDeletePrinterDriver(
    WINSPOOL_HANDLE pName,
    WCHAR *pEnvironment,
    WCHAR *pDriverName);

DWORD __cdecl _RpcAddPrintProcessor(
    WINSPOOL_HANDLE pName,
    WCHAR *pEnvironment,
    WCHAR *pPathName,
    WCHAR *pPrintProcessorName);

DWORD __cdecl _RpcEnumPrintProcessors(
    WINSPOOL_HANDLE pName,
    WCHAR *pEnvironment,
    DWORD Level,
    BYTE *pPrintProcessorInfo,
    DWORD cbBuf,
    DWORD *pcbNeeded,
    DWORD *pcReturned);

DWORD __cdecl _RpcGetPrintProcessorDirectory(
    WINSPOOL_HANDLE pName,
    WCHAR *pEnvironment,
    DWORD Level,
    BYTE *pPrintProcessorDirectory,
    DWORD cbBuf,
    DWORD *pcbNeeded);

DWORD __cdecl _RpcStartDocPrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WINSPOOL_DOC_INFO_CONTAINER *pDocInfoContainer,
    DWORD *pJobId);

DWORD __cdecl _RpcStartPagePrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter);

DWORD __cdecl _RpcWritePrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    BYTE *pBuf,
    DWORD cbBuf,
    DWORD *pcWritten);

DWORD __cdecl _RpcEndPagePrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter);

DWORD __cdecl _RpcAbortPrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter);

DWORD __cdecl _RpcReadPrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    BYTE *pBuf,
    DWORD cbBuf,
    DWORD *pcNoBytesRead);

DWORD __cdecl _RpcEndDocPrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter);

DWORD __cdecl _RpcAddJob(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD Level,
    BYTE *pAddJob,
    DWORD cbBuf,
    DWORD *pcbNeeded);

DWORD __cdecl _RpcScheduleJob(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD JobId);

DWORD __cdecl _RpcGetPrinterData(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WCHAR *pValueName,
    DWORD *pType,
    BYTE *pData,
    DWORD nSize,
    DWORD *pcbNeeded);

DWORD __cdecl _RpcSetPrinterData(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WCHAR *pValueName,
    DWORD Type,
    BYTE *pData,
    DWORD cbData);

DWORD __cdecl _RpcWaitForPrinterChange(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD Flags,
    DWORD *pFlags);

DWORD __cdecl _RpcClosePrinter(
    WINSPOOL_PRINTER_HANDLE *phPrinter);

DWORD __cdecl _RpcAddForm(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WINSPOOL_FORM_CONTAINER *pFormInfoContainer);

DWORD __cdecl _RpcDeleteForm(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WCHAR *pFormName);

DWORD __cdecl _RpcGetForm(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WCHAR *pFormName,
    DWORD Level,
    BYTE *pForm,
    DWORD cbBuf,
    DWORD *pcbNeeded);

DWORD __cdecl _RpcSetForm(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WCHAR *pFormName,
    WINSPOOL_FORM_CONTAINER *pFormInfoContainer);

DWORD __cdecl _RpcEnumForms(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD Level,
    BYTE *pForm,
    DWORD cbBuf,
    DWORD *pcbNeeded,
    DWORD *pcReturned);

DWORD __cdecl _RpcEnumPorts(
    WINSPOOL_HANDLE pName,
    DWORD Level,
    BYTE *pPort,
    DWORD cbBuf,
    DWORD *pcbNeeded,
    DWORD *pcReturned);

DWORD __cdecl _RpcEnumMonitors(
    WINSPOOL_HANDLE pName,
    DWORD Level,
    BYTE *pMonitor,
    DWORD cbBuf,
    DWORD *pcbNeeded,
    DWORD *pcReturned);

DWORD __cdecl _RpcAddPort(
    WINSPOOL_HANDLE pName,
    ULONG_PTR hWnd,
    WCHAR *pMonitorName);

DWORD __cdecl _RpcConfigurePort(
    WINSPOOL_HANDLE pName,
    ULONG_PTR hWnd,
    WCHAR *pPortName);

DWORD __cdecl _RpcDeletePort(
    WINSPOOL_HANDLE pName,
    ULONG_PTR hWnd,
    WCHAR *pPortName);

DWORD __cdecl _RpcCreatePrinterIC(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WINSPOOL_GDI_HANDLE *pHandle,
    WINSPOOL_DEVMODE_CONTAINER *pDevModeContainer);

DWORD __cdecl _RpcPlayGdiScriptOnPrinterIC(
    WINSPOOL_GDI_HANDLE hPrinterIC,
    BYTE *pIn,
    DWORD cIn,
    BYTE *pOut,
    DWORD cOut,
    DWORD ul);

DWORD __cdecl _RpcDeletePrinterIC(
    WINSPOOL_GDI_HANDLE *phPrinterIC);

DWORD __cdecl _RpcAddPrinterConnection(
    WINSPOOL_HANDLE pName);

DWORD __cdecl _RpcDeletePrinterConnection(
    WINSPOOL_HANDLE pName);

DWORD __cdecl _RpcPrinterMessageBox(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD Error,
    ULONG_PTR hWnd,
    WCHAR *pText,
    WCHAR *pCaption,
    DWORD dwType);

DWORD __cdecl _RpcAddMonitor(
    WINSPOOL_HANDLE pName,
    WINSPOOL_MONITOR_CONTAINER *pMonitorContainer);

DWORD __cdecl _RpcDeleteMonitor(
    WINSPOOL_HANDLE pName,
    WCHAR *pEnvironment,
    WCHAR *pMonitorName);

DWORD __cdecl _RpcDeletePrintProcessor(
    WINSPOOL_HANDLE pName,
    WCHAR *pEnvironment,
    WCHAR *pPrintProcessorName);

DWORD __cdecl _RpcAddPrintProvidor(
    WINSPOOL_HANDLE pName,
    WINSPOOL_PROVIDOR_CONTAINER *pProvidorContainer);

DWORD __cdecl _RpcDeletePrintProvidor(
    WINSPOOL_HANDLE pName,
    WCHAR *pEnvironment,
    WCHAR *pPrintProviderName);

DWORD __cdecl _RpcEnumPrintProcessorDatatypes(
    WINSPOOL_HANDLE pName,
    WCHAR *pPrintProcessorName,
    DWORD Level,
    BYTE *pDatatypes,
    DWORD cbBuf,
    DWORD *pcbNeeded,
    DWORD *pcReturned);

DWORD __cdecl _RpcResetPrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WCHAR *pDatatype,
    WINSPOOL_DEVMODE_CONTAINER *pDevModeContainer);

DWORD __cdecl _RpcGetPrinterDriver2(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WCHAR *pEnvironment,
    DWORD Level,
    BYTE *pDriver,
    DWORD cbBuf,
    DWORD *pcbNeeded,
    DWORD dwClientMajorVersion,
    DWORD dwClientMinorVersion,
    DWORD *pdwServerMaxVersion,
    DWORD *pdwServerMinVersion);

DWORD __cdecl _RpcClientFindFirstPrinterChangeNotification(
    void);

DWORD __cdecl _RpcFindNextPrinterChangeNotification(
    void);

DWORD __cdecl _RpcFindClosePrinterChangeNotification(
    void);

DWORD __cdecl _RpcRouterFindFirstPrinterChangeNotificationOld(
    void);

DWORD __cdecl _RpcReplyOpenPrinter(
    WINSPOOL_HANDLE pMachine,
    WINSPOOL_PRINTER_HANDLE *phPrinterNotify,
    DWORD dwPrinterRemote,
    DWORD dwType,
    DWORD cbBuffer,
    BYTE *pBuffer);

DWORD __cdecl _RpcRouterReplyPrinter(
    WINSPOOL_PRINTER_HANDLE hNotify,
    DWORD fdwFlags,
    DWORD cbBuffer,
    BYTE *pBuffer);

DWORD __cdecl _RpcReplyClosePrinter(
    WINSPOOL_PRINTER_HANDLE *phNotify);

DWORD __cdecl _RpcAddPortEx(
    WINSPOOL_HANDLE pName,
    WINSPOOL_PORT_CONTAINER *pPortContainer,
    WINSPOOL_PORT_VAR_CONTAINER *pPortVarContainer,
    WCHAR *pMonitorName);

DWORD __cdecl _RpcRemoteFindFirstPrinterChangeNotification(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD fdwFlags,
    DWORD fdwOptions,
    WCHAR *pszLocalMachine,
    DWORD dwPrinterLocal,
    DWORD cbBuffer,
    BYTE *pBuffer);

DWORD __cdecl _RpcSpoolerInit(
    void);

DWORD __cdecl _RpcResetPrinterEx(
    void);

DWORD __cdecl _RpcRemoteFindFirstPrinterChangeNotificationEx(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD fdwFlags,
    DWORD fdwOptions,
    WCHAR *pszLocalMachine,
    DWORD dwPrinterLocal,
    WINSPOOL_V2_NOTIFY_OPTIONS *pOptions);

DWORD __cdecl _RpcRouterReplyPrinterEx(
    WINSPOOL_PRINTER_HANDLE hNotify,
    DWORD dwColor,
    DWORD fdwFlags,
    DWORD *pdwResult,
    DWORD dwReplyType,
    WINSPOOL_V2_UREPLY_PRINTER Reply);

DWORD __cdecl _RpcRouterRefreshPrinterChangeNotification(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD dwColor,
    WINSPOOL_V2_NOTIFY_OPTIONS *pOptions,
    WINSPOOL_V2_NOTIFY_INFO **ppInfo);

DWORD __cdecl _RpcSetAllocFailCount(
    void);

DWORD __cdecl _RpcOpenPrinterEx(
    WINSPOOL_HANDLE pPrinterName,
    WINSPOOL_PRINTER_HANDLE *pHandle,
    WCHAR *pDatatype,
    WINSPOOL_DEVMODE_CONTAINER *pDevModeContainer,
    DWORD AccessRequired,
    WINSPOOL_SPLCLIENT_CONTAINER *pClientInfo);

DWORD __cdecl _RpcAddPrinterEx(
    WINSPOOL_HANDLE pName,
    WINSPOOL_PRINTER_CONTAINER *pPrinterContainer,
    WINSPOOL_DEVMODE_CONTAINER *pDevModeContainer,
    WINSPOOL_SECURITY_CONTAINER *pSecurityContainer,
    WINSPOOL_SPLCLIENT_CONTAINER *pClientInfo,
    WINSPOOL_PRINTER_HANDLE *pHandle);

DWORD __cdecl _RpcSetPort(
    WINSPOOL_HANDLE pName,
    WCHAR *pPortName,
    WINSPOOL_PORT_CONTAINER *pPortContainer);

DWORD __cdecl _RpcEnumPrinterData(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    DWORD dwIndex,
    WCHAR *pValueName,
    DWORD cbValueName,
    DWORD *pcbValueName,
    DWORD *pType,
    BYTE *pData,
    DWORD cbData,
    DWORD *pcbData);

DWORD __cdecl _RpcDeletePrinterData(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    WCHAR *pValueName);

DWORD __cdecl _RpcClusterSplOpen(
    void);

DWORD __cdecl _RpcClusterSplClose(
    void);

DWORD __cdecl _RpcClusterSplIsAlive(
    void);

DWORD __cdecl _RpcSetPrinterDataEx(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    const WCHAR *pKeyName,
    const WCHAR *pValueName,
    DWORD Type,
    BYTE *pData,
    DWORD cbData);

DWORD __cdecl _RpcGetPrinterDataEx(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    const WCHAR *pKeyName,
    const WCHAR *pValueName,
    DWORD *pType,
    BYTE *pData,
    DWORD nSize,
    DWORD *pcbNeeded);

DWORD __cdecl _RpcEnumPrinterDataEx(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    const WCHAR *pKeyName,
    BYTE *pEnumValues,
    DWORD cbEnumValues,
    DWORD *pcbEnumValues,
    DWORD *pnEnumValues);

DWORD __cdecl _RpcEnumPrinterKey(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    const WCHAR *pKeyName,
    WCHAR *pSubkey,
    DWORD cbSubkey,
    DWORD *pcbSubkey);

DWORD __cdecl _RpcDeletePrinterDataEx(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    const WCHAR *pKeyName,
    const WCHAR *pValueName);

DWORD __cdecl _RpcDeletePrinterKey(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    const WCHAR *pKeyName);

DWORD __cdecl _RpcSeekPrinter(
    void);

DWORD __cdecl _RpcDeletePrinterDriverEx(
    WINSPOOL_HANDLE pName,
    WCHAR *pEnvironment,
    WCHAR *pDriverName,
    DWORD dwDeleteFlag,
    DWORD dwVersionNum);

DWORD __cdecl _RpcAddPerMachineConnection(
    WINSPOOL_HANDLE pServer,
    const WCHAR *pPrinterName,
    const WCHAR *pPrintServer,
    const WCHAR *pProvider);

DWORD __cdecl _RpcDeletePerMachineConnection(
    WINSPOOL_HANDLE pServer,
    const WCHAR *pPrinterName);

DWORD __cdecl _RpcEnumPerMachineConnections(
    WINSPOOL_HANDLE pServer,
    BYTE *pPrinterEnum,
    DWORD cbBuf,
    DWORD *pcbNeeded,
    DWORD *pcReturned);

DWORD __cdecl _RpcXcvData(
    WINSPOOL_PRINTER_HANDLE hXcv,
    const WCHAR *pszDataName,
    BYTE *pInputData,
    DWORD cbInputData,
    BYTE *pOutputData,
    DWORD cbOutputData,
    DWORD *pcbOutputNeeded,
    DWORD *pdwStatus);

DWORD __cdecl _RpcAddPrinterDriverEx(
    WINSPOOL_HANDLE pName,
    WINSPOOL_DRIVER_CONTAINER *pDriverContainer,
    DWORD dwFileCopyFlags);

DWORD __cdecl _RpcSplOpenPrinter(
    void);

DWORD __cdecl _RpcGetSpoolFileInfo(
    void);

DWORD __cdecl _RpcCommitSpoolData(
    void);

DWORD __cdecl _RpcCloseSpoolFileHandle(
    void);

DWORD __cdecl _RpcFlushPrinter(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    BYTE *pBuf,
    DWORD cbBuf,
    DWORD *pcWritten,
    DWORD cSleep);

DWORD __cdecl _RpcSendRecvBidiData(
    WINSPOOL_PRINTER_HANDLE hPrinter,
    const WCHAR *pAction,
    WINSPOOL_BIDI_REQUEST_CONTAINER *pReqData,
    WINSPOOL_BIDI_RESPONSE_CONTAINER **ppRespData);

DWORD __cdecl _RpcAddDriverCatalog(
    void);


#endif  /* __winspool_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */

handle_t __RPC_USER WINSPOOL_HANDLE_bind(WINSPOOL_HANDLE);
void __RPC_USER WINSPOOL_HANDLE_unbind(WINSPOOL_HANDLE, handle_t);
void __RPC_USER WINSPOOL_PRINTER_HANDLE_rundown(WINSPOOL_PRINTER_HANDLE);
void __RPC_USER WINSPOOL_GDI_HANDLE_rundown(WINSPOOL_GDI_HANDLE);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __winspool_c_h__ */
