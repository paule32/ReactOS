/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/reactos/idl/atsvc.idl - Do not edit ***/

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

#ifndef __atsvc_c_h__
#define __atsvc_c_h__

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
typedef const wchar_t *ATSVC_HANDLE;
typedef struct _AT_ENUM {
    DWORD JobId;
    DWORD_PTR JobTime;
    DWORD DaysOfMonth;
    unsigned char DaysOfWeek;
    unsigned char Flags;
    wchar_t *Command;
} AT_ENUM;
typedef struct _AT_ENUM *PAT_ENUM;
typedef struct _AT_ENUM *LPAT_ENUM;
typedef struct _AT_INFO {
    DWORD_PTR JobTime;
    DWORD DaysOfMonth;
    unsigned char DaysOfWeek;
    unsigned char Flags;
    wchar_t *Command;
} AT_INFO;
typedef struct _AT_INFO *PAT_INFO;
typedef struct _AT_INFO *LPAT_INFO;
typedef struct _AT_ENUM_CONTAINER {
    DWORD EntriesRead;
    LPAT_ENUM Buffer;
} AT_ENUM_CONTAINER;
typedef struct _AT_ENUM_CONTAINER *PAT_ENUM_CONTAINER;
typedef struct _AT_ENUM_CONTAINER *LPAT_ENUM_CONTAINER;
/*****************************************************************************
 * atsvc interface (v1.0)
 */
#ifndef __atsvc_INTERFACE_DEFINED__
#define __atsvc_INTERFACE_DEFINED__

extern RPC_IF_HANDLE atsvc_v1_0_c_ifspec;
extern RPC_IF_HANDLE atsvc_v1_0_s_ifspec;
NET_API_STATUS __stdcall NetrJobAdd(
    ATSVC_HANDLE ServerName,
    LPAT_INFO pAtInfo,
    LPDWORD pJobId);

NET_API_STATUS __stdcall NetrJobDel(
    ATSVC_HANDLE ServerName,
    DWORD MinJobId,
    DWORD MaxJobId);

NET_API_STATUS __stdcall NetrJobEnum(
    ATSVC_HANDLE ServerName,
    LPAT_ENUM_CONTAINER pEnumContainer,
    DWORD PreferedMaximumLength,
    LPDWORD pTotalEntries,
    LPDWORD pResumeHandle);

NET_API_STATUS __stdcall NetrJobGetInfo(
    ATSVC_HANDLE ServerName,
    DWORD JobId,
    LPAT_INFO *ppAtInfo);


#endif  /* __atsvc_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */

handle_t __RPC_USER ATSVC_HANDLE_bind(ATSVC_HANDLE);
void __RPC_USER ATSVC_HANDLE_unbind(ATSVC_HANDLE, handle_t);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __atsvc_c_h__ */
