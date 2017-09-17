/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/reactos/idl/eventlogrpc.idl - Do not edit ***/

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

#ifndef __eventlogrpc_c_h__
#define __eventlogrpc_c_h__

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
#if !defined(__EVENTLOG_H__) && !defined(__ADVAPI32_H)
typedef LONG NTSTATUS;
#endif
typedef ULONG RULONG;
typedef struct _RPC_STRING {
    USHORT Length;
    USHORT MaximumLength;
    LPSTR Buffer;
} RPC_STRING;
typedef struct _RPC_STRING *PRPC_STRING;
typedef PVOID IELF_HANDLE;
typedef IELF_HANDLE *PIELF_HANDLE;
typedef LPWSTR EVENTLOG_HANDLE_W;
typedef LPSTR EVENTLOG_HANDLE_A;
typedef struct _RPC_CLIENT_ID {
    ULONG UniqueProcess;
    ULONG UniqueThread;
} RPC_CLIENT_ID;
typedef struct _RPC_CLIENT_ID *PRPC_CLIENT_ID;
/*****************************************************************************
 * eventlog interface (v0.0)
 */
#ifndef __eventlog_INTERFACE_DEFINED__
#define __eventlog_INTERFACE_DEFINED__

extern RPC_IF_HANDLE eventlog_v0_0_c_ifspec;
extern RPC_IF_HANDLE eventlog_v0_0_s_ifspec;
NTSTATUS __cdecl ElfrClearELFW(
    IELF_HANDLE LogHandle,
    PRPC_UNICODE_STRING BackupFileName);

NTSTATUS __cdecl ElfrBackupELFW(
    IELF_HANDLE LogHandle,
    PRPC_UNICODE_STRING BackupFileName);

NTSTATUS __cdecl ElfrCloseEL(
    PIELF_HANDLE LogHandle);

NTSTATUS __cdecl ElfrDeregisterEventSource(
    PIELF_HANDLE LogHandle);

NTSTATUS __cdecl ElfrNumberOfRecords(
    IELF_HANDLE LogHandle,
    PULONG NumberOfRecords);

NTSTATUS __cdecl ElfrOldestRecord(
    IELF_HANDLE LogHandle,
    PULONG OldestRecordNumber);

NTSTATUS __cdecl ElfrChangeNotify(
    IELF_HANDLE LogHandle,
    RPC_CLIENT_ID ClientId,
    ULONG Event);

NTSTATUS __cdecl ElfrOpenELW(
    EVENTLOG_HANDLE_W UNCServerName,
    PRPC_UNICODE_STRING ModuleName,
    PRPC_UNICODE_STRING RegModuleName,
    ULONG MajorVersion,
    ULONG MinorVersion,
    PIELF_HANDLE LogHandle);

NTSTATUS __cdecl ElfrRegisterEventSourceW(
    EVENTLOG_HANDLE_W UNCServerName,
    PRPC_UNICODE_STRING ModuleName,
    PRPC_UNICODE_STRING RegModuleName,
    ULONG MajorVersion,
    ULONG MinorVersion,
    PIELF_HANDLE LogHandle);

NTSTATUS __cdecl ElfrOpenBELW(
    EVENTLOG_HANDLE_W UNCServerName,
    PRPC_UNICODE_STRING BackupFileName,
    ULONG MajorVersion,
    ULONG MinorVersion,
    PIELF_HANDLE LogHandle);

NTSTATUS __cdecl ElfrReadELW(
    IELF_HANDLE LogHandle,
    ULONG ReadFlags,
    ULONG RecordOffset,
    RULONG NumberOfBytesToRead,
    PBYTE Buffer,
    PULONG NumberOfBytesRead,
    PULONG MinNumberOfBytesNeeded);

NTSTATUS __cdecl ElfrReportEventW(
    IELF_HANDLE LogHandle,
    ULONG Time,
    USHORT EventType,
    USHORT EventCategory,
    ULONG EventID,
    USHORT NumStrings,
    ULONG DataSize,
    PRPC_UNICODE_STRING ComputerName,
    PRPC_SID UserSID,
    PRPC_UNICODE_STRING Strings[],
    PBYTE Data,
    USHORT Flags,
    PULONG RecordNumber,
    PULONG TimeWritten);

NTSTATUS __cdecl ElfrClearELFA(
    IELF_HANDLE LogHandle,
    PRPC_STRING BackupFileName);

NTSTATUS __cdecl ElfrBackupELFA(
    IELF_HANDLE LogHandle,
    PRPC_STRING BackupFileName);

NTSTATUS __cdecl ElfrOpenELA(
    EVENTLOG_HANDLE_A UNCServerName,
    PRPC_STRING ModuleName,
    PRPC_STRING RegModuleName,
    ULONG MajorVersion,
    ULONG MinorVersion,
    PIELF_HANDLE LogHandle);

NTSTATUS __cdecl ElfrRegisterEventSourceA(
    EVENTLOG_HANDLE_A UNCServerName,
    PRPC_STRING ModuleName,
    PRPC_STRING RegModuleName,
    ULONG MajorVersion,
    ULONG MinorVersion,
    PIELF_HANDLE LogHandle);

NTSTATUS __cdecl ElfrOpenBELA(
    EVENTLOG_HANDLE_A UNCServerName,
    PRPC_STRING BackupFileName,
    ULONG MajorVersion,
    ULONG MinorVersion,
    PIELF_HANDLE LogHandle);

NTSTATUS __cdecl ElfrReadELA(
    IELF_HANDLE LogHandle,
    ULONG ReadFlags,
    ULONG RecordOffset,
    RULONG NumberOfBytesToRead,
    PBYTE Buffer,
    PULONG NumberOfBytesRead,
    PULONG MinNumberOfBytesNeeded);

NTSTATUS __cdecl ElfrReportEventA(
    IELF_HANDLE LogHandle,
    ULONG Time,
    USHORT EventType,
    USHORT EventCategory,
    ULONG EventID,
    USHORT NumStrings,
    ULONG DataSize,
    PRPC_STRING ComputerName,
    PRPC_SID UserSID,
    PRPC_STRING Strings[],
    PBYTE Data,
    USHORT Flags,
    PULONG RecordNumber,
    PULONG TimeWritten);

NTSTATUS __cdecl ElfrRegisterClusterSvc(
    handle_t BindingHandle);

NTSTATUS __cdecl ElfrDeregisterClusterSvc(
    handle_t BindingHandle);

NTSTATUS __cdecl ElfrWriteClusterEvents(
    handle_t BindingHandle);

NTSTATUS __cdecl ElfrGetLogInformation(
    IELF_HANDLE LogHandle,
    ULONG InfoLevel,
    PBYTE Buffer,
    ULONG cbBufSize,
    PULONG pcbBytesNeeded);

NTSTATUS __cdecl ElfrFlushEL(
    IELF_HANDLE LogHandle);

NTSTATUS __cdecl ElfrReportEventAndSourceW(
    IELF_HANDLE LogHandle,
    ULONG Time,
    USHORT EventType,
    USHORT EventCategory,
    ULONG EventID,
    PRPC_UNICODE_STRING SourceName,
    USHORT NumStrings,
    ULONG DataSize,
    PRPC_UNICODE_STRING ComputerName,
    PRPC_SID UserSID,
    PRPC_UNICODE_STRING Strings[],
    PBYTE Data,
    USHORT Flags,
    PULONG RecordNumber,
    PULONG TimeWritten);


#endif  /* __eventlog_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */

handle_t __RPC_USER EVENTLOG_HANDLE_W_bind(EVENTLOG_HANDLE_W);
void __RPC_USER EVENTLOG_HANDLE_W_unbind(EVENTLOG_HANDLE_W, handle_t);
handle_t __RPC_USER EVENTLOG_HANDLE_A_bind(EVENTLOG_HANDLE_A);
void __RPC_USER EVENTLOG_HANDLE_A_unbind(EVENTLOG_HANDLE_A, handle_t);
void __RPC_USER IELF_HANDLE_rundown(IELF_HANDLE);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __eventlogrpc_c_h__ */