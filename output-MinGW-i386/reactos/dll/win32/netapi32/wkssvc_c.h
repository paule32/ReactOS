/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/reactos/idl/wkssvc.idl - Do not edit ***/

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

#ifndef __wkssvc_c_h__
#define __wkssvc_c_h__

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
typedef wchar_t *WKSSVC_IDENTIFY_HANDLE;
typedef wchar_t *WKSSVC_IMPERSONATE_HANDLE;
typedef enum _NETSETUP_JOIN_STATUS {
    NetSetupUnknownStatus = 0,
    NetSetupUnjoined = 1,
    NetSetupWorkgroupName = 2,
    NetSetupDomainName = 3
} NETSETUP_JOIN_STATUS;
typedef enum _NETSETUP_JOIN_STATUS *PNETSETUP_JOIN_STATUS;
typedef enum _NETSETUP_NAME_TYPE {
    NetSetupUnknown = 0,
    NetSetupMachine = 1,
    NetSetupWorkgroup = 2,
    NetSetupDomain = 3,
    NetSetupNonExistentDomain = 4,
    NetSetupDnsMachine = 5
} NETSETUP_NAME_TYPE;
typedef enum _NETSETUP_NAME_TYPE *PNETSETUP_NAME_TYPE;
typedef enum _NET_COMPUTER_NAME_TYPE {
    NetPrimaryComputerName = 0,
    NetAlternateComputerNames = 1,
    NetAllComputerNames = 2,
    NetComputerNameTypeMax = 3
} NET_COMPUTER_NAME_TYPE;
typedef enum _NET_COMPUTER_NAME_TYPE *PNET_COMPUTER_NAME_TYPE;
typedef struct _STAT_WORKSTATION_0 {
    LARGE_INTEGER StatisticsStartTime;
    LARGE_INTEGER BytesReceived;
    LARGE_INTEGER SmbsReceived;
    LARGE_INTEGER PagingReadBytesRequested;
    LARGE_INTEGER NonPagingReadBytesRequested;
    LARGE_INTEGER CacheReadBytesRequested;
    LARGE_INTEGER NetworkReadBytesRequested;
    LARGE_INTEGER BytesTransmitted;
    LARGE_INTEGER SmbsTransmitted;
    LARGE_INTEGER PagingWriteBytesRequested;
    LARGE_INTEGER NonPagingWriteBytesRequested;
    LARGE_INTEGER CacheWriteBytesRequested;
    LARGE_INTEGER NetworkWriteBytesRequested;
    ULONG InitiallyFailedOperations;
    ULONG FailedCompletionOperations;
    ULONG ReadOperations;
    ULONG RandomReadOperations;
    ULONG ReadSmbs;
    ULONG LargeReadSmbs;
    ULONG SmallReadSmbs;
    ULONG WriteOperations;
    ULONG RandomWriteOperations;
    ULONG WriteSmbs;
    ULONG LargeWriteSmbs;
    ULONG SmallWriteSmbs;
    ULONG RawReadsDenied;
    ULONG RawWritesDenied;
    ULONG NetworkErrors;
    ULONG Sessions;
    ULONG FailedSessions;
    ULONG Reconnects;
    ULONG CoreConnects;
    ULONG Lanman20Connects;
    ULONG Lanman21Connects;
    ULONG LanmanNtConnects;
    ULONG ServerDisconnects;
    ULONG HungSessions;
    ULONG UseCount;
    ULONG FailedUseCount;
    ULONG CurrentCommands;
} STAT_WORKSTATION_0;
typedef struct _STAT_WORKSTATION_0 *PSTAT_WORKSTATION_0;
typedef struct _STAT_WORKSTATION_0 *LPSTAT_WORKSTATION_0;
typedef struct _WKSTA_INFO_100 {
    ULONG wki100_platform_id;
    wchar_t *wki100_computername;
    wchar_t *wki100_langroup;
    ULONG wki100_ver_major;
    ULONG wki100_ver_minor;
} WKSTA_INFO_100;
typedef struct _WKSTA_INFO_100 *PWKSTA_INFO_100;
typedef struct _WKSTA_INFO_100 *LPWKSTA_INFO_100;
typedef struct _WKSTA_INFO_101 {
    ULONG wki101_platform_id;
    wchar_t *wki101_computername;
    wchar_t *wki101_langroup;
    ULONG wki101_ver_major;
    ULONG wki101_ver_minor;
    wchar_t *wki101_lanroot;
} WKSTA_INFO_101;
typedef struct _WKSTA_INFO_101 *PWKSTA_INFO_101;
typedef struct _WKSTA_INFO_101 *LPWKSTA_INFO_101;
typedef struct _WKSTA_INFO_102 {
    ULONG wki102_platform_id;
    wchar_t *wki102_computername;
    wchar_t *wki102_langroup;
    ULONG wki102_ver_major;
    ULONG wki102_ver_minor;
    wchar_t *wki102_lanroot;
    ULONG wki102_logged_on_users;
} WKSTA_INFO_102;
typedef struct _WKSTA_INFO_102 *PWKSTA_INFO_102;
typedef struct _WKSTA_INFO_102 *LPWKSTA_INFO_102;
typedef struct _WKSTA_INFO_502 {
    ULONG wki502_char_wait;
    ULONG wki502_collection_time;
    ULONG wki502_maximum_collection_count;
    ULONG wki502_keep_conn;
    ULONG wki502_max_cmds;
    ULONG wki502_sess_timeout;
    ULONG wki502_siz_char_buf;
    ULONG wki502_max_threads;
    ULONG wki502_lock_quota;
    ULONG wki502_lock_increment;
    ULONG wki502_lock_maximum;
    ULONG wki502_pipe_increment;
    ULONG wki502_pipe_maximum;
    ULONG wki502_cache_file_timeout;
    ULONG wki502_dormant_file_limit;
    ULONG wki502_read_ahead_throughput;
    ULONG wki502_num_mailslot_buffers;
    ULONG wki502_num_srv_announce_buffers;
    ULONG wki502_max_illegal_datagram_events;
    ULONG wki502_illegal_datagram_event_reset_frequency;
    int wki502_log_election_packets;
    int wki502_use_opportunistic_locking;
    int wki502_use_unlock_behind;
    int wki502_use_close_behind;
    int wki502_buf_named_pipes;
    int wki502_use_lock_read_unlock;
    int wki502_utilize_nt_caching;
    int wki502_use_raw_read;
    int wki502_use_raw_write;
    int wki502_use_write_raw_data;
    int wki502_use_encryption;
    int wki502_buf_files_deny_write;
    int wki502_buf_read_only_files;
    int wki502_force_core_create_mode;
    int wki502_use_512_byte_max_transfer;
} WKSTA_INFO_502;
typedef struct _WKSTA_INFO_502 *PWKSTA_INFO_502;
typedef struct _WKSTA_INFO_502 *LPWKSTA_INFO_502;
typedef struct _WKSTA_INFO_1013 {
    ULONG wki1013_keep_conn;
} WKSTA_INFO_1013;
typedef struct _WKSTA_INFO_1013 *PWKSTA_INFO_1013;
typedef struct _WKSTA_INFO_1013 *LPWKSTA_INFO_1013;
typedef struct _WKSTA_INFO_1018 {
    ULONG wki1018_sess_timeout;
} WKSTA_INFO_1018;
typedef struct _WKSTA_INFO_1018 *PWKSTA_INFO_1018;
typedef struct _WKSTA_INFO_1018 *LPWKSTA_INFO_1018;
typedef struct _WKSTA_INFO_1046 {
    ULONG wki1046_dormant_file_limit;
} WKSTA_INFO_1046;
typedef struct _WKSTA_INFO_1046 *PWKSTA_INFO_1046;
typedef struct _WKSTA_INFO_1046 *LPWKSTA_INFO_1046;
typedef struct _WKSTA_USER_INFO_0 {
    wchar_t *wkui0_username;
} WKSTA_USER_INFO_0;
typedef struct _WKSTA_USER_INFO_0 *PWKSTA_USER_INFO_0;
typedef struct _WKSTA_USER_INFO_0 *LPWKSTA_USER_INFO_0;
typedef struct _WKSTA_USER_INFO_1 {
    wchar_t *wkui1_username;
    wchar_t *wkui1_logon_domain;
    wchar_t *wkui1_oth_domains;
    wchar_t *wkui1_logon_server;
} WKSTA_USER_INFO_1;
typedef struct _WKSTA_USER_INFO_1 *PWKSTA_USER_INFO_1;
typedef struct _WKSTA_USER_INFO_1 *LPWKSTA_USER_INFO_1;
typedef struct _WKSTA_USER_INFO_1101 {
    wchar_t *wkui1101_oth_domains;
} WKSTA_USER_INFO_1101;
typedef struct _WKSTA_USER_INFO_1101 *PWKSTA_USER_INFO_1101;
typedef struct _WKSTA_USER_INFO_1101 *LPWKSTA_USER_INFO_1101;
typedef union _WKSTA_USER_INFO {
    LPWKSTA_USER_INFO_0 UserInfo0;
    LPWKSTA_USER_INFO_1 UserInfo1;
    LPWKSTA_USER_INFO_1101 UserInfo1101;
} WKSTA_USER_INFO;
typedef union _WKSTA_USER_INFO *PWKSTA_USER_INFO;
typedef union _WKSTA_USER_INFO *LPWKSTA_USER_INFO;
typedef struct _WKSTA_TRANSPORT_INFO_0 {
    ULONG wkti0_quality_of_service;
    ULONG wkti0_number_of_vcs;
    wchar_t *wkti0_transport_name;
    wchar_t *wkti0_transport_address;
    ULONG wkti0_wan_ish;
} WKSTA_TRANSPORT_INFO_0;
typedef struct _WKSTA_TRANSPORT_INFO_0 *PWKSTA_TRANSPORT_INFO_0;
typedef struct _WKSTA_TRANSPORT_INFO_0 *LPWKSTA_TRANSPORT_INFO_0;
typedef union _WKSTA_INFO {
    LPWKSTA_INFO_100 WkstaInfo100;
    LPWKSTA_INFO_101 WkstaInfo101;
    LPWKSTA_INFO_102 WkstaInfo102;
    LPWKSTA_INFO_502 WkstaInfo502;
    LPWKSTA_INFO_1013 WkstaInfo1013;
    LPWKSTA_INFO_1018 WkstaInfo1018;
    LPWKSTA_INFO_1046 WkstaInfo1046;
} WKSTA_INFO;
typedef union _WKSTA_INFO *PWKSTA_INFO;
typedef union _WKSTA_INFO *LPWKSTA_INFO;
typedef struct _USE_INFO_0 {
    wchar_t *ui0_local;
    wchar_t *ui0_remote;
} USE_INFO_0;
typedef struct _USE_INFO_0 *PUSE_INFO_0;
typedef struct _USE_INFO_0 *LPUSE_INFO_0;
typedef struct _USE_INFO_1 {
    wchar_t *ui1_local;
    wchar_t *ui1_remote;
    wchar_t *ui1_password;
    ULONG ui1_status;
    ULONG ui1_asg_type;
    ULONG ui1_refcount;
    ULONG ui1_usecount;
} USE_INFO_1;
typedef struct _USE_INFO_1 *PUSE_INFO_1;
typedef struct _USE_INFO_1 *LPUSE_INFO_1;
typedef struct _USE_INFO_2 {
    USE_INFO_1 ui2_useinfo;
    wchar_t *ui2_username;
    wchar_t *ui2_domainname;
} USE_INFO_2;
typedef struct _USE_INFO_2 *PUSE_INFO_2;
typedef struct _USE_INFO_2 *LPUSE_INFO_2;
typedef struct _USE_INFO_3 {
    USE_INFO_2 ui3_ui2;
    ULONG ui3_flags;
} USE_INFO_3;
typedef struct _USE_INFO_3 *PUSE_INFO_3;
typedef struct _USE_INFO_3 *LPUSE_INFO_3;
typedef union _USE_INFO {
    LPUSE_INFO_0 UseInfo0;
    LPUSE_INFO_1 UseInfo1;
    LPUSE_INFO_2 UseInfo2;
    LPUSE_INFO_3 UseInfo3;
} USE_INFO;
typedef union _USE_INFO *PUSE_INFO;
typedef union _USE_INFO *LPUSE_INFO;
typedef struct _USE_INFO_0_CONTAINER {
    ULONG EntriesRead;
    LPUSE_INFO_0 Buffer;
} USE_INFO_0_CONTAINER;
typedef struct _USE_INFO_0_CONTAINER *PUSE_INFO_0_CONTAINER;
typedef struct _USE_INFO_0_CONTAINER *LPUSE_INFO_0_CONTAINER;
typedef struct _USE_INFO_1_CONTAINER {
    ULONG EntriesRead;
    LPUSE_INFO_1 Buffer;
} USE_INFO_1_CONTAINER;
typedef struct _USE_INFO_1_CONTAINER *PUSE_INFO_1_CONTAINER;
typedef struct _USE_INFO_1_CONTAINER *LPUSE_INFO_1_CONTAINER;
typedef struct _USE_INFO_2_CONTAINER {
    ULONG EntriesRead;
    LPUSE_INFO_2 Buffer;
} USE_INFO_2_CONTAINER;
typedef struct _USE_INFO_2_CONTAINER *PUSE_INFO_2_CONTAINER;
typedef struct _USE_INFO_2_CONTAINER *LPUSE_INFO_2_CONTAINER;
typedef struct _USE_ENUM_STRUCT {
    DWORD Level;
    union _USE_ENUM_UNION {
        LPUSE_INFO_0_CONTAINER Level0;
        LPUSE_INFO_1_CONTAINER Level1;
        LPUSE_INFO_2_CONTAINER Level2;
    } UseInfo;
} USE_ENUM_STRUCT;
typedef struct _USE_ENUM_STRUCT *PUSE_ENUM_STRUCT;
typedef struct _USE_ENUM_STRUCT *LPUSE_ENUM_STRUCT;
typedef struct _WKSTA_USER_INFO_0_CONTAINER {
    ULONG EntriesRead;
    LPWKSTA_USER_INFO_0 Buffer;
} WKSTA_USER_INFO_0_CONTAINER;
typedef struct _WKSTA_USER_INFO_0_CONTAINER *PWKSTA_USER_INFO_0_CONTAINER;
typedef struct _WKSTA_USER_INFO_0_CONTAINER *LPWKSTA_USER_INFO_0_CONTAINER;
typedef struct _WKSTA_USER_INFO_1_CONTAINER {
    ULONG EntriesRead;
    LPWKSTA_USER_INFO_1 Buffer;
} WKSTA_USER_INFO_1_CONTAINER;
typedef struct _WKSTA_USER_INFO_1_CONTAINER *PWKSTA_USER_INFO_1_CONTAINER;
typedef struct _WKSTA_USER_INFO_1_CONTAINER *LPWKSTA_USER_INFO_1_CONTAINER;
typedef struct _WKSTA_USER_ENUM_STRUCT {
    ULONG Level;
    union _WKSTA_USER_ENUM_UNION {
        LPWKSTA_USER_INFO_0_CONTAINER Level0;
        LPWKSTA_USER_INFO_1_CONTAINER Level1;
    } WkstaUserInfo;
} WKSTA_USER_ENUM_STRUCT;
typedef struct _WKSTA_USER_ENUM_STRUCT *PWKSTA_USER_ENUM_STRUCT;
typedef struct _WKSTA_USER_ENUM_STRUCT *LPWKSTA_USER_ENUM_STRUCT;
typedef struct _WKSTA_TRANSPORT_INFO_0_CONTAINER {
    ULONG EntriesRead;
    LPWKSTA_TRANSPORT_INFO_0 Buffer;
} WKSTA_TRANSPORT_INFO_0_CONTAINER;
typedef struct _WKSTA_TRANSPORT_INFO_0_CONTAINER *PWKSTA_TRANSPORT_INFO_0_CONTAINER;
typedef struct _WKSTA_TRANSPORT_INFO_0_CONTAINER *LPWKSTA_TRANSPORT_INFO_0_CONTAINER;
typedef struct _WKSTA_TRANSPORT_ENUM_STRUCT {
    ULONG Level;
    union _WKSTA_TRANSPORT_ENUM_UNION {
        LPWKSTA_TRANSPORT_INFO_0_CONTAINER Level0;
    } WkstaTransportInfo;
} WKSTA_TRANSPORT_ENUM_STRUCT;
typedef struct _WKSTA_TRANSPORT_ENUM_STRUCT *PWKSTA_TRANSPORT_ENUM_STRUCT;
typedef struct _WKSTA_TRANSPORT_ENUM_STRUCT *LPWKSTA_TRANSPORT_ENUM_STRUCT;
typedef struct _JOINPR_USER_PASSWORD {
    unsigned char Obfuscator[8];
    wchar_t Buffer[256];
    ULONG Length;
} JOINPR_USER_PASSWORD;
typedef struct _JOINPR_USER_PASSWORD *PJOINPR_USER_PASSWORD;
typedef struct _JOINPR_ENCRYPTED_USER_PASSWORD {
    unsigned char Buffer[524];
} JOINPR_ENCRYPTED_USER_PASSWORD;
typedef struct _JOINPR_ENCRYPTED_USER_PASSWORD *PJOINPR_ENCRYPTED_USER_PASSWORD;
#if !defined(_NTSECAPI_H)
typedef struct _UNICODE_STRING {
    unsigned short Length;
    unsigned short MaximumLength;
    unsigned short *Buffer;
} UNICODE_STRING;
typedef struct _UNICODE_STRING *PUNICODE_STRING;
#endif
typedef struct _NET_COMPUTER_NAME_ARRAY {
    ULONG EntryCount;
    PUNICODE_STRING ComputerNames;
} NET_COMPUTER_NAME_ARRAY;
typedef struct _NET_COMPUTER_NAME_ARRAY *PNET_COMPUTER_NAME_ARRAY;
/*****************************************************************************
 * wkssvc interface (v1.0)
 */
#ifndef __wkssvc_INTERFACE_DEFINED__
#define __wkssvc_INTERFACE_DEFINED__

extern handle_t hBinding;
extern RPC_IF_HANDLE wkssvc_v1_0_c_ifspec;
extern RPC_IF_HANDLE wkssvc_v1_0_s_ifspec;
ULONG __stdcall NetrWkstaGetInfo(
    WKSSVC_IDENTIFY_HANDLE ServerName,
    ULONG Level,
    LPWKSTA_INFO WkstaInfo);

ULONG __stdcall NetrWkstaSetInfo(
    WKSSVC_IDENTIFY_HANDLE ServerName,
    ULONG Level,
    LPWKSTA_INFO WkstaInfo,
    ULONG *ErrorParameter);

ULONG __stdcall NetrWkstaUserEnum(
    WKSSVC_IDENTIFY_HANDLE ServerName,
    LPWKSTA_USER_ENUM_STRUCT UserInfo,
    ULONG PreferredMaximumLength,
    ULONG *TotalEntries,
    ULONG *ResumeHandle);

ULONG __stdcall NetrWkstaUserGetInfo(
    WKSSVC_IDENTIFY_HANDLE Unused,
    ULONG Level,
    LPWKSTA_USER_INFO UserInfo);

ULONG __stdcall NetrWkstaUserSetInfo(
    WKSSVC_IDENTIFY_HANDLE Unused,
    ULONG Level,
    LPWKSTA_USER_INFO UserInfo,
    ULONG *ErrorParameter);

ULONG __stdcall NetrWkstaTransportEnum(
    WKSSVC_IDENTIFY_HANDLE ServerName,
    LPWKSTA_TRANSPORT_ENUM_STRUCT TransportInfo,
    ULONG PreferredMaximumLength,
    ULONG *TotalEntries,
    ULONG *ResumeHandle);

ULONG __stdcall NetrWkstaTransportAdd(
    WKSSVC_IDENTIFY_HANDLE ServerName,
    ULONG Level,
    LPWKSTA_TRANSPORT_INFO_0 TransportInfo,
    ULONG *ErrorParameter);

ULONG __stdcall NetrWkstaTransportDel(
    WKSSVC_IDENTIFY_HANDLE ServerName,
    wchar_t *TransportName,
    ULONG ForceLevel);

ULONG __stdcall NetrUseAdd(
    WKSSVC_IMPERSONATE_HANDLE ServerName,
    ULONG Level,
    LPUSE_INFO InfoStruct,
    ULONG *ErrorParameter);

ULONG __stdcall NetrUseGetInfo(
    WKSSVC_IMPERSONATE_HANDLE ServerName,
    wchar_t *UseName,
    ULONG Level,
    LPUSE_INFO InfoStruct);

ULONG __stdcall NetrUseDel(
    WKSSVC_IMPERSONATE_HANDLE ServerName,
    wchar_t *UseName,
    ULONG ForceLevel);

ULONG __stdcall NetrUseEnum(
    WKSSVC_IDENTIFY_HANDLE ServerName,
    LPUSE_ENUM_STRUCT InfoStruct,
    ULONG PreferredMaximumLength,
    ULONG *TotalEntries,
    ULONG *ResumeHandle);

void __stdcall Opnum12NotUsedOnWire(
    void);

ULONG __stdcall NetrWorkstationStatisticsGet(
    WKSSVC_IDENTIFY_HANDLE ServerName,
    wchar_t *ServiceName,
    ULONG Level,
    ULONG Options,
    LPSTAT_WORKSTATION_0 *Buffer);

void __stdcall Opnum14NotUsedOnWire(
    void);

void __stdcall Opnum15NotUsedOnWire(
    void);

void __stdcall Opnum16NotUsedOnWire(
    void);

void __stdcall Opnum17NotUsedOnWire(
    void);

void __stdcall Opnum18NotUsedOnWire(
    void);

void __stdcall Opnum19NotUsedOnWire(
    void);

ULONG __stdcall NetrGetJoinInformation(
    WKSSVC_IMPERSONATE_HANDLE ServerName,
    wchar_t **NameBuffer,
    PNETSETUP_JOIN_STATUS BufferType);

void __stdcall Opnum21NotUsedOnWire(
    void);

ULONG __stdcall NetrJoinDomain2(
    handle_t RpcBindingHandle,
    wchar_t *ServerName,
    wchar_t *DomainNameParam,
    wchar_t *MachineAccountOU,
    wchar_t *AccountName,
    PJOINPR_ENCRYPTED_USER_PASSWORD Password,
    ULONG Options);

ULONG __stdcall NetrUnjoinDomain2(
    handle_t RpcBindingHandle,
    wchar_t *ServerName,
    wchar_t *AccountName,
    PJOINPR_ENCRYPTED_USER_PASSWORD Password,
    ULONG Options);

ULONG __stdcall NetrRenameMachineInDomain2(
    handle_t RpcBindingHandle,
    wchar_t *ServerName,
    wchar_t *MachineName,
    wchar_t *AccountName,
    PJOINPR_ENCRYPTED_USER_PASSWORD Password,
    ULONG Options);

ULONG __stdcall NetrValidateName2(
    handle_t RpcBindingHandle,
    wchar_t *ServerName,
    wchar_t *NameToValidate,
    wchar_t *AccountName,
    PJOINPR_ENCRYPTED_USER_PASSWORD Password,
    NETSETUP_NAME_TYPE NameType);

ULONG __stdcall NetrGetJoinableOUs2(
    handle_t RpcBindingHandle,
    wchar_t *ServerName,
    wchar_t *DomainNameParam,
    wchar_t *AccountName,
    PJOINPR_ENCRYPTED_USER_PASSWORD Password,
    ULONG *OUCount,
    wchar_t ***OUs);

ULONG __stdcall NetrAddAlternateComputerName(
    handle_t RpcBindingHandle,
    wchar_t *ServerName,
    wchar_t *AlternateName,
    wchar_t *DomainAccount,
    PJOINPR_ENCRYPTED_USER_PASSWORD EncryptedPassword,
    ULONG Reserved);

ULONG __stdcall NetrRemoveAlternateComputerName(
    handle_t RpcBindingHandle,
    wchar_t *ServerName,
    wchar_t *AlternateName,
    wchar_t *DomainAccount,
    PJOINPR_ENCRYPTED_USER_PASSWORD EncryptedPassword,
    ULONG Reserved);

ULONG __stdcall NetrSetPrimaryComputerName(
    handle_t RpcBindingHandle,
    wchar_t *ServerName,
    wchar_t *PrimaryName,
    wchar_t *DomainAccount,
    PJOINPR_ENCRYPTED_USER_PASSWORD EncryptedPassword,
    ULONG Reserved);

ULONG __stdcall NetrEnumerateComputerNames(
    WKSSVC_IMPERSONATE_HANDLE ServerName,
    NET_COMPUTER_NAME_TYPE NameType,
    ULONG Reserved,
    PNET_COMPUTER_NAME_ARRAY *ComputerNames);


#endif  /* __wkssvc_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */

handle_t __RPC_USER WKSSVC_IDENTIFY_HANDLE_bind(WKSSVC_IDENTIFY_HANDLE);
void __RPC_USER WKSSVC_IDENTIFY_HANDLE_unbind(WKSSVC_IDENTIFY_HANDLE, handle_t);
handle_t __RPC_USER WKSSVC_IMPERSONATE_HANDLE_bind(WKSSVC_IMPERSONATE_HANDLE);
void __RPC_USER WKSSVC_IMPERSONATE_HANDLE_unbind(WKSSVC_IMPERSONATE_HANDLE, handle_t);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __wkssvc_c_h__ */
