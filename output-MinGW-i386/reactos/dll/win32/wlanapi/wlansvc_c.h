/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/reactos/idl/wlansvc.idl - Do not edit ***/

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

#ifndef __wlansvc_c_h__
#define __wlansvc_c_h__

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
typedef struct _L2_NOTIFICATION_DATA {
    DWORD NotificationSource;
    DWORD NotificationCode;
    GUID InterfaceGuid;
    DWORD dwDataSize;
    PBYTE pData;
} L2_NOTIFICATION_DATA;
typedef struct _L2_NOTIFICATION_DATA *PL2_NOTIFICATION_DATA;
typedef enum _NDIS_WAN_QUALITY {
    NdisWanRaw = 0,
    NdisWanErrorControl = 1,
    NdisWanReliable = 2
} NDIS_WAN_QUALITY;
typedef enum _NDIS_WAN_QUALITY *PNDIS_WAN_QUALITY;
typedef enum _NDIS_DEVICE_POWER_STATE {
    NdisDeviceStateUnspecified = 0,
    NdisDeviceStateD0 = 1,
    NdisDeviceStateD1 = 2,
    NdisDeviceStateD2 = 3,
    NdisDeviceStateD3 = 4,
    NdisDeviceStateMaximum = 5
} NDIS_DEVICE_POWER_STATE;
typedef enum _NDIS_DEVICE_POWER_STATE *PNDIS_DEVICE_POWER_STATE;
typedef enum _NDIS_802_11_WEP_STATUS {
    Ndis802_11WEPEnabled = 0,
    Ndis802_11WEPDisabled = 1,
    Ndis802_11WEPKeyAbsent = 2,
    Ndis802_11WEPNotSupported = 3
} NDIS_802_11_WEP_STATUS;
typedef enum _NDIS_802_11_WEP_STATUS *PNDIS_802_11_WEP_STATUS;
typedef enum _NDIS_802_11_AUTHENTICATION_MODE {
    Ndis802_11AuthModeOpen = 0,
    Ndis802_11AuthModeShared = 1,
    Ndis802_11AuthModeAutoSwitch = 2,
    Ndis802_11AuthModeMax = 3
} NDIS_802_11_AUTHENTICATION_MODE;
typedef enum _NDIS_802_11_AUTHENTICATION_MODE *PNDIS_802_11_AUTHENTICATION_MODE;
typedef enum _NDIS_802_11_NETWORK_INFRASTRUCTURE {
    Ndis802_11IBSS = 0,
    Ndis802_11Infrastructure = 1,
    Ndis802_11AutoUnknown = 2,
    Ndis802_11InfrastructureMax = 3
} NDIS_802_11_NETWORK_INFRASTRUCTURE;
typedef enum _NDIS_802_11_NETWORK_INFRASTRUCTURE *PNDIS_802_11_NETWORK_INFRASTRUCTURE;
typedef enum _NDIS_802_11_NETWORK_TYPE {
    Ndis802_11FH = 0,
    Ndis802_11DS = 1,
    Ndis802_11OFDM5 = 2,
    Ndis802_11OFDM24 = 3,
    Ndis802_11Automode = 4,
    Ndis802_11NetworkTypeMax = 5
} NDIS_802_11_NETWORK_TYPE;
typedef enum _NDIS_802_11_NETWORK_TYPE *PNDIS_802_11_NETWORK_TYPE;
typedef struct _NDIS_OBJECT_HEADER {
    UCHAR Type;
    UCHAR Revision;
    USHORT Size;
} NDIS_OBJECT_HEADER;
typedef struct _NDIS_OBJECT_HEADER *PNDIS_OBJECT_HEADER;
typedef UCHAR NDIS_802_11_MAC_ADDRESS[6];
typedef LONG NDIS_802_11_RSSI;
typedef UCHAR NDIS_802_11_RATES[8];
typedef struct _NDIS_802_11_SSID {
    ULONG SsidLength;
    UCHAR Ssid[32];
} NDIS_802_11_SSID;
typedef struct _NDIS_802_11_SSID *PNDIS_802_11_SSID;
typedef struct _NDIS_802_11_CONFIGURATION_FH {
    ULONG Length;
    ULONG HopPattern;
    ULONG HopSet;
    ULONG DwellTime;
} NDIS_802_11_CONFIGURATION_FH;
typedef struct _NDIS_802_11_CONFIGURATION_FH *PNDIS_802_11_CONFIGURATION_FH;
typedef struct _NDIS_802_11_CONFIGURATION {
    ULONG Length;
    ULONG BeaconPeriod;
    ULONG ATIMWindow;
    ULONG DSConfig;
    NDIS_802_11_CONFIGURATION_FH FHConfig;
} NDIS_802_11_CONFIGURATION;
typedef struct _NDIS_802_11_CONFIGURATION *PNDIS_802_11_CONFIGURATION;
typedef struct _NDIS_WLAN_BSSID {
    ULONG Length;
    NDIS_802_11_MAC_ADDRESS MacAddress[6];
    UCHAR Reserved[2];
    NDIS_802_11_SSID Ssid;
    ULONG Privacy;
    NDIS_802_11_RSSI Rssi;
    NDIS_802_11_NETWORK_TYPE NetworkTypeInUse;
    NDIS_802_11_CONFIGURATION Configuration;
    NDIS_802_11_NETWORK_INFRASTRUCTURE InfrastructureMode;
    NDIS_802_11_RATES SupportedRates[8];
} NDIS_WLAN_BSSID;
typedef struct _NDIS_WLAN_BSSID *PNDIS_WLAN_BSSID;
typedef struct _NDIS_802_11_BSSID_LIST {
    ULONG NumberOfItems;
    NDIS_WLAN_BSSID Bssid[1];
} NDIS_802_11_BSSID_LIST;
typedef struct _NDIS_802_11_BSSID_LIST *PNDIS_802_11_BSSID_LIST;
typedef struct _NDIS_802_11_WEP {
    ULONG Length;
    ULONG KeyIndex;
    ULONG KeyLength;
    UCHAR KeyMaterial[1];
} NDIS_802_11_WEP;
typedef struct _NDIS_802_11_WEP *PNDIS_802_11_WEP;
typedef struct _NDIS_PM_WAKE_UP_CAPABILITIES {
    NDIS_DEVICE_POWER_STATE MinMagicPacketWakeUp;
    NDIS_DEVICE_POWER_STATE MinPatternWakeUp;
    NDIS_DEVICE_POWER_STATE MinLinkChangeWakeUp;
} NDIS_PM_WAKE_UP_CAPABILITIES;
typedef struct _NDIS_PM_WAKE_UP_CAPABILITIES *PNDIS_PM_WAKE_UP_CAPABILITIES;
typedef struct _NDIS_PNP_CAPABILITIES {
    ULONG Flags;
    NDIS_PM_WAKE_UP_CAPABILITIES WakeUpCapabilities;
} NDIS_PNP_CAPABILITIES;
typedef struct _NDIS_PNP_CAPABILITIES *PNDIS_PNP_CAPABILITIES;
typedef enum _NDIS_MEDIUM {
    NdisMedium802_3 = 0,
    NdisMedium802_5 = 1,
    NdisMediumFddi = 2,
    NdisMediumWan = 3,
    NdisMediumLocalTalk = 4,
    NdisMediumDix = 5,
    NdisMediumArcnetRaw = 6,
    NdisMediumArcnet878_2 = 7,
    NdisMediumAtm = 8,
    NdisMediumWirelessWan = 9,
    NdisMediumIrda = 10,
    NdisMediumBpc = 11,
    NdisMediumCoWan = 12,
    NdisMedium1394 = 13,
    NdisMediumMax = 14
} NDIS_MEDIUM;
typedef enum _NDIS_MEDIUM *PNDIS_MEDIUM;
typedef enum _NDIS_PHYSICAL_MEDIUM {
    NdisPhysicalMediumUnspecified = 0,
    NdisPhysicalMediumWirelessLan = 1,
    NdisPhysicalMediumCableModem = 2,
    NdisPhysicalMediumPhoneLine = 3,
    NdisPhysicalMediumPowerLine = 4,
    NdisPhysicalMediumDSL = 5,
    NdisPhysicalMediumFibreChannel = 6,
    NdisPhysicalMedium1394 = 7,
    NdisPhysicalMediumWirelessWan = 8,
    NdisPhysicalMediumNative802_11 = 9,
    NdisPhysicalMediumBluetooth = 10,
    NdisPhysicalMediumInfiniband = 11,
    NdisPhysicalMediumWiMax = 12,
    NdisPhysicalMediumUWB = 13,
    NdisPhysicalMedium802_3 = 14,
    NdisPhysicalMedium802_5 = 15,
    NdisPhysicalMediumIrda = 16,
    NdisPhysicalMediumWiredWAN = 17,
    NdisPhysicalMediumWiredCoWan = 18,
    NdisPhysicalMediumOther = 19,
    NdisPhysicalMediumMax = 20
} NDIS_PHYSICAL_MEDIUM;
typedef enum _NDIS_PHYSICAL_MEDIUM *PNDIS_PHYSICAL_MEDIUM;
typedef ULONG NDIS_OID;
typedef ULONG *PNDIS_OID;
typedef enum _NDIS_HARDWARE_STATUS {
    NdisHardwareStatusReady = 0,
    NdisHardwareStatusInitializing = 1,
    NdisHardwareStatusReset = 2,
    NdisHardwareStatusClosing = 3,
    NdisHardwareStatusNotReady = 4
} NDIS_HARDWARE_STATUS;
typedef enum _NDIS_HARDWARE_STATUS *PNDIS_HARDWARE_STATUS;
typedef struct _GEN_GET_TIME_CAPS {
    ULONG Flags;
    ULONG ClockPrecision;
} GEN_GET_TIME_CAPS;
typedef struct _GEN_GET_TIME_CAPS *PGEN_GET_TIME_CAPS;
typedef struct _GEN_GET_NETCARD_TIME {
    ULONGLONG ReadTime;
} GEN_GET_NETCARD_TIME;
typedef struct _GEN_GET_NETCARD_TIME *PGEN_GET_NETCARD_TIME;
typedef enum _NDIS_MEDIA_STATE {
    NdisMediaStateConnected = 0,
    NdisMediaStateDisconnected = 1
} NDIS_MEDIA_STATE;
typedef enum _NDIS_MEDIA_STATE *PNDIS_MEDIA_STATE;
typedef int NDIS_STATUS;
typedef int *PNDIS_STATUS;
typedef struct _NDIS_GUID {
    GUID Guid;
    union {
        NDIS_OID Oid;
        NDIS_STATUS Status;
    } u;
    ULONG Size;
    ULONG Flags;
} NDIS_GUID;
typedef struct _NDIS_GUID *PNDIS_GUID;
typedef struct _NDIS_PM_PACKET_PATTERN {
    ULONG Priority;
    ULONG Reserved;
    ULONG MaskSize;
    ULONG PatternOffset;
    ULONG PatternSize;
    ULONG PatternFlags;
} NDIS_PM_PACKET_PATTERN;
typedef struct _NDIS_PM_PACKET_PATTERN *PNDIS_PM_PACKET_PATTERN;
typedef struct _NETWORK_ADDRESS {
    USHORT AddressLength;
    USHORT AddressType;
    UCHAR Address[1];
} NETWORK_ADDRESS;
typedef struct _NETWORK_ADDRESS *PNETWORK_ADDRESS;
typedef struct _NETWORK_ADDRESS_LIST {
    LONG AddressCount;
    USHORT AddressType;
    NETWORK_ADDRESS Address[1];
} NETWORK_ADDRESS_LIST;
typedef struct _NETWORK_ADDRESS_LIST *PNETWORK_ADDRESS_LIST;
typedef struct _TRANSPORT_HEADER_OFFSET {
    USHORT ProtocolType;
    USHORT HeaderOffset;
} TRANSPORT_HEADER_OFFSET;
typedef struct _TRANSPORT_HEADER_OFFSET *PTRANSPORT_HEADER_OFFSET;
typedef struct _NDIS_CO_LINK_SPEED {
    ULONG Outbound;
    ULONG Inbound;
} NDIS_CO_LINK_SPEED;
typedef struct _NDIS_CO_LINK_SPEED *PNDIS_CO_LINK_SPEED;
typedef enum _DOT11_BSS_TYPE {
    dot11_BSS_type_infrastructure = 1,
    dot11_BSS_type_independent = 2,
    dot11_BSS_type_any = 3
} DOT11_BSS_TYPE;
typedef enum _DOT11_PHY_TYPE {
    dot11_phy_type_unknown = 0,
    dot11_phy_type_any = 1,
    dot11_phy_type_fhss = 2,
    dot11_phy_type_dsss = 3,
    dot11_phy_type_irbaseband = 4,
    dot11_phy_type_ofdm = 5,
    dot11_phy_type_hrdsss = 6,
    dot11_phy_type_erp = 7,
    dot11_phy_type_ht = 8,
    dot11_phy_type_IHV_start = 9,
    dot11_phy_type_IHV_end = 10
} DOT11_PHY_TYPE;
typedef enum _DOT11_AUTH_ALGORITHM {
    DOT11_AUTH_ALGO_80211_OPEN = 1,
    DOT11_AUTH_ALGO_80211_SHARED_KEY = 2,
    DOT11_AUTH_ALGO_WPA = 3,
    DOT11_AUTH_ALGO_WPA_PSK = 4,
    DOT11_AUTH_ALGO_WPA_NONE = 5,
    DOT11_AUTH_ALGO_RSNA = 6,
    DOT11_AUTH_ALGO_RSNA_PSK = 7,
    DOT11_AUTH_ALGO_IHV_START = 0x80000000,
    DOT11_AUTH_ALGO_IHV_END = 0xffffffff
} DOT11_AUTH_ALGORITHM;
typedef enum _DOT11_CIPHER_ALGORITHM {
    DOT11_CIPHER_ALGO_NONE = 0x0,
    DOT11_CIPHER_ALGO_WEP40 = 0x1,
    DOT11_CIPHER_ALGO_TKIP = 0x2,
    DOT11_CIPHER_ALGO_CCMP = 0x4,
    DOT11_CIPHER_ALGO_WEP104 = 0x5,
    DOT11_CIPHER_ALGO_WPA_USE_GROUP = 0x100,
    DOT11_CIPHER_ALGO_RSN_USE_GROUP = 0x100,
    DOT11_CIPHER_ALGO_WEP = 0x101,
    DOT11_CIPHER_ALGO_IHV_START = 0x80000000,
    DOT11_CIPHER_ALGO_IHV_END = 0xffffffff
} DOT11_CIPHER_ALGORITHM;
typedef struct _DOT11_MAC_ADDRESS {
    UCHAR ucDot11MacAddress[6];
} DOT11_MAC_ADDRESS;
typedef struct _DOT11_MAC_ADDRESS *PDOT11_MAC_ADDRESS;
typedef struct _DOT11_SSID {
    ULONG uSSIDLength;
    UCHAR ucSSID[32];
} DOT11_SSID;
typedef struct _DOT11_SSID *PDOT11_SSID;
typedef struct _DOT11_BSSID_LIST {
    NDIS_OBJECT_HEADER Header;
    ULONG uNumOfEntries;
    ULONG uTotalNumOfEntries;
    DOT11_MAC_ADDRESS BSSIDs[1];
} DOT11_BSSID_LIST;
typedef struct _DOT11_BSSID_LIST *PDOT11_BSSID_LIST;
typedef struct _EAP_TYPE {
    BYTE type;
    DWORD dwVendorId;
    DWORD dwVendorType;
} EAP_TYPE;
typedef struct _EAP_TYPE *PEAP_TYPE;
typedef struct _EAP_METHOD_TYPE {
    EAP_TYPE eapType;
    DWORD dwAuthorId;
} EAP_METHOD_TYPE;
typedef struct _EAP_METHOD_TYPE *PEAP_METHOD_TYPE;
typedef enum _WLAN_OPCODE_VALUE_TYPE {
    wlan_opcode_value_type_query_only = 0,
    wlan_opcode_value_type_set_by_group_policy = 1,
    wlan_opcode_value_type_set_by_user = 2,
    wlan_opcode_value_type_invalid = 3
} WLAN_OPCODE_VALUE_TYPE;
typedef enum _WLAN_SECURABLE_OBJECT {
    wlan_secure_permit_list = 0,
    wlan_secure_deny_list = 1,
    wlan_secure_ac_enabled = 2,
    wlan_secure_bc_scan_enabled = 3,
    wlan_secure_bss_type = 4,
    wlan_secure_show_denied = 5,
    wlan_secure_interface_properties = 6,
    wlan_secure_ihv_control = 7,
    wlan_secure_all_user_profiles_order = 8,
    wlan_secure_add_new_all_user_profiles = 9,
    wlan_secure_add_new_per_user_profiles = 10,
    wlan_secure_media_streaming_mode_enabled = 11,
    wlan_secure_current_operation_mode = 12,
    WLAN_SECURABLE_OBJECT_COUNT = 13
} WLAN_SECURABLE_OBJECT;
typedef enum _WLAN_SECURABLE_OBJECT *PWLAN_SECURABLE_OBJECT;
typedef enum _WLAN_CONNECTION_MODE {
    wlan_connection_mode_profile = 0,
    wlan_connection_mode_temporary_profile = 1,
    wlan_connection_mode_discovery_secure = 2,
    wlan_connection_mode_discovery_unsecure = 3,
    wlan_connection_mode_auto = 4,
    wlan_connection_mode_invalid = 5
} WLAN_CONNECTION_MODE;
typedef enum _WLAN_CONNECTION_MODE *PWLAN_CONNECTION_MODE;
typedef enum _WLAN_IHV_CONTROL_TYPE {
    wlan_ihv_control_type_service = 0,
    wlan_ihv_control_type_driver = 1
} WLAN_IHV_CONTROL_TYPE;
typedef enum _WLAN_INTF_OPCODE {
    wlan_intf_opcode_autoconf_start = 0x0,
    wlan_intf_opcode_autoconf_enabled = 0x1,
    wlan_intf_opcode_background_scan_enabled = 0x2,
    wlan_intf_opcode_media_streaming_mode = 0x3,
    wlan_intf_opcode_radio_state = 0x4,
    wlan_intf_opcode_bss_type = 0x5,
    wlan_intf_opcode_interface_state = 0x6,
    wlan_intf_opcode_current_connection = 0x7,
    wlan_intf_opcode_channel_number = 0x8,
    wlan_intf_opcode_supported_infrastructure_auth_cipher_pairs = 0x9,
    wlan_intf_opcode_supported_adhoc_auth_cipher_pairs = 0xa,
    wlan_intf_opcode_supported_country_or_region_string_list = 0xb,
    wlan_intf_opcode_current_operation_mode = 0xc,
    wlan_intf_opcode_supported_safe_mode = 0xd,
    wlan_intf_opcode_certified_safe_mode = 0xe,
    wlan_intf_opcode_hosted_network_capable = 0xf,
    wlan_intf_opcode_management_frame_protection_capable = 0x10,
    wlan_intf_opcode_autoconf_end = 0xfffffff,
    wlan_intf_opcode_msm_start = 0x10000100,
    wlan_intf_opcode_statistics = 0x10000101,
    wlan_intf_opcode_rssi = 0x10000102,
    wlan_intf_opcode_msm_end = 0x1fffffff,
    wlan_intf_opcode_security_start = 0x20010000,
    wlan_intf_opcode_security_end = 0x2fffffff,
    wlan_intf_opcode_ihv_start = 0x30000000,
    wlan_intf_opcode_ihv_end = 0x3fffffff
} WLAN_INTF_OPCODE;
typedef enum _WLAN_INTERFACE_STATE {
    wlan_interface_state_not_ready = 0,
    wlan_interface_state_connected = 1,
    wlan_interface_state_ad_hoc_network_formed = 2,
    wlan_interface_state_disconnecting = 3,
    wlan_interface_state_disconnected = 4,
    wlan_interface_state_associating = 5,
    wlan_interface_state_discovering = 6,
    wlan_interface_state_authenticating = 7
} WLAN_INTERFACE_STATE;
typedef enum _WLAN_INTERFACE_TYPE {
    wlan_interface_type_emulated_802_11 = 0,
    wlan_interface_type_native_802_11 = 1,
    wlan_interface_type_invalid = 2
} WLAN_INTERFACE_TYPE;
typedef enum _WLAN_INTERFACE_TYPE *PWLAN_INTERFACE_TYPE;
typedef DWORD WLAN_REASON_CODE;
typedef DWORD *PWLAN_REASON_CODE;
typedef ULONG WLAN_SIGNAL_QUALITY;
typedef ULONG *PWLAN_SIGNAL_QUALITY;
typedef struct _DOT11_NETWORK {
    DOT11_SSID dot11Ssid;
    DOT11_BSS_TYPE dot11BssType;
} DOT11_NETWORK;
typedef struct _DOT11_NETWORK *PDOT11_NETWORK;
typedef struct _DOT11_NETWORK_LIST {
    DWORD dwNumberOfItems;
    DWORD dwIndex;
    DOT11_NETWORK Network[1];
} DOT11_NETWORK_LIST;
typedef struct _DOT11_NETWORK_LIST *PDOT11_NETWORK_LIST;
typedef struct _WLAN_INTERFACE_INFO {
    GUID InterfaceGuid;
    WCHAR strInterfaceDescription[256];
    WLAN_INTERFACE_STATE isState;
} WLAN_INTERFACE_INFO;
typedef struct _WLAN_INTERFACE_INFO *PWLAN_INTERFACE_INFO;
typedef struct _WLAN_INTERFACE_INFO_LIST {
    DWORD dwNumberOfItems;
    DWORD dwIndex;
    WLAN_INTERFACE_INFO InterfaceInfo[1];
} WLAN_INTERFACE_INFO_LIST;
typedef struct _WLAN_INTERFACE_INFO_LIST *PWLAN_INTERFACE_INFO_LIST;
typedef struct _WLAN_INTERFACE_CAPABILITY {
    WLAN_INTERFACE_TYPE interfaceType;
    BOOL bDot11DSupported;
    DWORD dwMaxDesiredSsidListSize;
    DWORD dwMaxDesiredBssidListSize;
    DWORD dwNumberOfSupportedPhys;
    LONG dot11PhyTypes[64];
} WLAN_INTERFACE_CAPABILITY;
typedef struct _WLAN_INTERFACE_CAPABILITY *PWLAN_INTERFACE_CAPABILITY;
typedef struct _WLAN_RAW_DATA {
    DWORD dwDataSize;
    BYTE DataBlob[1];
} WLAN_RAW_DATA;
typedef struct _WLAN_RAW_DATA *PWLAN_RAW_DATA;
typedef struct _WLAN_PROFILE_INFO {
    WCHAR strProfileName[256];
    DWORD dwFlags;
} WLAN_PROFILE_INFO;
typedef struct _WLAN_PROFILE_INFO *PWLAN_PROFILE_INFO;
typedef struct _WLAN_PROFILE_INFO_LIST {
    DWORD dwNumberOfItems;
    DWORD dwIndex;
    WLAN_PROFILE_INFO ProfileInfo[1];
} WLAN_PROFILE_INFO_LIST;
typedef struct _WLAN_PROFILE_INFO_LIST *PWLAN_PROFILE_INFO_LIST;
typedef struct _WLAN_AVAILABLE_NETWORK {
    WCHAR strProfileName[256];
    DOT11_SSID dot11Ssid;
    DOT11_BSS_TYPE dot11BssType;
    ULONG uNumberOfBssids;
    BOOL bNetworkConnectable;
    WLAN_REASON_CODE wlanNotConnectableReason;
    ULONG uNumberOfPhyTypes;
    DOT11_PHY_TYPE dot11PhyTypes[8];
    BOOL bMorePhyTypes;
    WLAN_SIGNAL_QUALITY wlanSignalQuality;
    BOOL bSecurityEnabled;
    DOT11_AUTH_ALGORITHM dot11DefaultAuthAlgorithm;
    DOT11_CIPHER_ALGORITHM dot11DefaultCipherAlgorithm;
    DWORD dwFlags;
    DWORD dwReserved;
} WLAN_AVAILABLE_NETWORK;
typedef struct _WLAN_AVAILABLE_NETWORK *PWLAN_AVAILABLE_NETWORK;
typedef struct _WLAN_AVAILABLE_NETWORK_LIST {
    DWORD dwNumberOfItems;
    DWORD dwIndex;
    WLAN_AVAILABLE_NETWORK Network[1];
} WLAN_AVAILABLE_NETWORK_LIST;
typedef struct _WLAN_AVAILABLE_NETWORK_LIST *PWLAN_AVAILABLE_NETWORK_LIST;
typedef struct _WLAN_CONNECTION_PARAMETERS {
    WLAN_CONNECTION_MODE wlanConnectionMode;
    LPCWSTR strProfile;
    PDOT11_SSID pDot11Ssid;
    PDOT11_BSSID_LIST pDesiredBssidList;
    DOT11_BSS_TYPE dot11BssType;
    DWORD dwFlags;
} WLAN_CONNECTION_PARAMETERS;
typedef struct _WLAN_CONNECTION_PARAMETERS *PWLAN_CONNECTION_PARAMETERS;
typedef L2_NOTIFICATION_DATA WLAN_NOTIFICATION_DATA;
typedef L2_NOTIFICATION_DATA *PWLAN_NOTIFICATION_DATA;
typedef void (__stdcall *WLAN_NOTIFICATION_CALLBACK)(PWLAN_NOTIFICATION_DATA a,PVOID b);
typedef PVOID WLANSVC_RPC_HANDLE;
typedef WLANSVC_RPC_HANDLE *LPWLANSVC_RPC_HANDLE;
typedef LPWSTR WLANSVC_HANDLE;
typedef struct struct_C {
    ULONGLONG elem_1;
    ULONGLONG elem_2;
    GUID elem_3;
    GUID elem_4;
    DWORD elem_5;
    GUID elem_6;
    DWORD elem_7;
    DWORD elem_8;
    ULONGLONG elem_9;
    BYTE elem_10[1];
} struct_C;
typedef struct struct_D {
    GUID elem_1;
    GUID elem_2;
    DWORD elem_3;
    ULONGLONG elem_4;
    BYTE elem_5[1];
} struct_D;
typedef struct struct_E {
    short elem_1;
    DWORD elem_2;
    WCHAR elem_3[256];
    WCHAR elem_4[1024];
} struct_E;
/*****************************************************************************
 * wlansvc_interface interface (v1.0)
 */
#ifndef __wlansvc_interface_INTERFACE_DEFINED__
#define __wlansvc_interface_INTERFACE_DEFINED__

extern RPC_IF_HANDLE wlansvc_interface_v1_0_c_ifspec;
extern RPC_IF_HANDLE wlansvc_interface_v1_0_s_ifspec;
DWORD __cdecl _RpcOpenHandle(
    WLANSVC_HANDLE szMachineName,
    DWORD dwClientVersion,
    DWORD *pdwNegotiatedVersion,
    WLANSVC_RPC_HANDLE *phClientHandle);

DWORD __cdecl _RpcCloseHandle(
    WLANSVC_RPC_HANDLE *phClientHandle);

DWORD __cdecl _RpcEnumInterfaces(
    WLANSVC_RPC_HANDLE hClientHandle,
    PWLAN_INTERFACE_INFO_LIST *ppInterfaceList);

DWORD __cdecl _RpcSetAutoConfigParameter(
    WLANSVC_RPC_HANDLE hClientHandle,
    LONG OpCode,
    DWORD dwDataSize,
    LPBYTE pData);

DWORD __cdecl _RpcQueryAutoConfigParameter(
    WLANSVC_RPC_HANDLE hClientHandle,
    DWORD OpCode,
    LPDWORD pdwDataSize,
    char **ppData,
    DWORD *pWlanOpcodeValueType);

DWORD __cdecl _RpcGetInterfaceCapability(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    PWLAN_INTERFACE_CAPABILITY *ppCapability);

DWORD __cdecl _RpcSetInterface(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    DWORD OpCode,
    DWORD dwDataSize,
    LPBYTE pData);

DWORD __cdecl _RpcQueryInterface(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    LONG OpCode,
    LPDWORD pdwDataSize,
    LPBYTE *ppData,
    LPDWORD pWlanOpcodeValueType);

DWORD __cdecl _RpcIhvControl(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    DWORD Type,
    DWORD dwInBufferSize,
    LPBYTE pInBuffer,
    DWORD dwOutBufferSize,
    LPBYTE pOutBuffer,
    LPDWORD pdwBytesReturned);

DWORD __cdecl _RpcScan(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    PDOT11_SSID pDot11Ssid,
    PWLAN_RAW_DATA pIeData);

DWORD __cdecl _RpcGetAvailableNetworkList(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    DWORD dwFlags,
    WLAN_AVAILABLE_NETWORK_LIST **ppAvailableNetworkList);

DWORD __cdecl _RpcGetNetworkBssList(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    PDOT11_SSID pDot11Ssid,
    short dot11BssType,
    DWORD bSecurityEnabled,
    LPDWORD dwBssListSize,
    LPBYTE *ppWlanBssList);

DWORD __cdecl _RpcConnect(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    const PWLAN_CONNECTION_PARAMETERS *pConnectionParameters);

DWORD __cdecl _RpcDisconnect(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGUID);

DWORD __cdecl _RpcRegisterNotification(
    WLANSVC_RPC_HANDLE hClientHandle,
    DWORD arg_2,
    LPDWORD pdwPrevNotifSource);

DWORD __cdecl _RpcAsyncGetNotification(
    WLANSVC_RPC_HANDLE hClientHandle,
    PWLAN_NOTIFICATION_DATA *NotificationData);

DWORD __cdecl _RpcSetProfileEapUserData(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    wchar_t *strProfileName,
    EAP_METHOD_TYPE MethodType,
    DWORD dwFlags,
    DWORD dwEapUserDataSize,
    LPBYTE pbEapUserData);

DWORD __cdecl _RpcSetProfile(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    DWORD dwFlags,
    wchar_t *strProfileXml,
    wchar_t *strAllUserProfileSecurity,
    BOOL bOverwrite,
    LPDWORD pdwReasonCode);

DWORD __cdecl _RpcGetProfile(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    wchar_t *strProfileName,
    wchar_t **pstrProfileXml,
    LPDWORD pdwFlags,
    LPDWORD pdwGrantedAccess);

DWORD __cdecl _RpcDeleteProfile(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    const wchar_t *strProfileName);

DWORD __cdecl _RpcRenameProfile(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    const wchar_t *strOldProfileName,
    const wchar_t *strNewProfileName);

DWORD __cdecl _RpcSetProfileList(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    DWORD dwItems,
    BYTE **strProfileNames);

DWORD __cdecl _RpcGetProfileList(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    PWLAN_PROFILE_INFO_LIST *ppProfileList);

DWORD __cdecl _RpcSetProfilePosition(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    wchar_t *strProfileName,
    DWORD dwPosition);

DWORD __cdecl _RpcSetProfileCustomUserData(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    wchar_t *strProfileName,
    DWORD dwDataSize,
    LPBYTE pData);

DWORD __cdecl _RpcGetProfileCustomUserData(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    wchar_t *strProfileName,
    LPDWORD dwDataSize,
    LPBYTE *pData);

DWORD __cdecl _RpcSetFilterList(
    WLANSVC_RPC_HANDLE hClientHandle,
    short wlanFilterListType,
    PDOT11_NETWORK_LIST pNetworkList);

DWORD __cdecl _RpcGetFilterList(
    WLANSVC_RPC_HANDLE hClientHandle,
    short wlanFilterListType,
    PDOT11_NETWORK_LIST *pNetworkList);

DWORD __cdecl _RpcSetPsdIEDataList(
    WLANSVC_RPC_HANDLE hClientHandle,
    wchar_t *strFormat,
    DWORD dwDataListSize,
    LPBYTE pPsdIEDataList);

DWORD __cdecl _RpcSaveTemporaryProfile(
    WLANSVC_RPC_HANDLE hClientHandle,
    const GUID *pInterfaceGuid,
    wchar_t *strProfileName,
    wchar_t *strAllUserProfileSecurity,
    DWORD dwFlags,
    BOOL bOverWrite);

DWORD __cdecl _RpcIsUIRequestPending(
    WLANSVC_HANDLE arg_1,
    const GUID *pInterfaceGuid,
    struct_C *arg_3,
    LPDWORD arg_4);

DWORD __cdecl _RpcSetUIForwardingNetworkList(
    WLANSVC_HANDLE arg_1,
    GUID *arg_2,
    DWORD dwSize,
    GUID *arg_4);

DWORD __cdecl _RpcIsNetworkSuppressed(
    WLANSVC_HANDLE arg_1,
    DWORD arg_2,
    const GUID *pInterfaceGuid,
    LPDWORD arg_4);

DWORD __cdecl _RpcRemoveUIForwardingNetworkList(
    WLANSVC_HANDLE arg_1,
    const GUID *pInterfaceGuid);

DWORD __cdecl _RpcQueryExtUIRequest(
    WLANSVC_HANDLE arg_1,
    GUID *arg_2,
    GUID *arg_3,
    short arg_4,
    GUID *pInterfaceGuid,
    struct_C **arg_6);

DWORD __cdecl _RpcUIResponse(
    WLANSVC_HANDLE arg_1,
    struct_C *arg_2,
    struct_D *arg_3);

DWORD __cdecl _RpcGetProfileKeyInfo(
    WLANSVC_HANDLE arg_1,
    DWORD arg_2,
    const GUID *pInterfaceGuid,
    wchar_t *arg_4,
    DWORD arg_5,
    LPDWORD arg_6,
    char *arg_7,
    LPDWORD arg_8);

DWORD __cdecl _RpcAsyncDoPlap(
    WLANSVC_HANDLE arg_1,
    const GUID *pInterfaceGuid,
    wchar_t *arg_3,
    DWORD dwSize,
    struct_E arg_5[]);

DWORD __cdecl _RpcQueryPlapCredentials(
    WLANSVC_HANDLE arg_1,
    LPDWORD dwSize,
    struct_E **arg_3,
    wchar_t **arg_4,
    GUID *pInterfaceGuid,
    LPDWORD arg_6,
    LPDWORD arg_7,
    LPDWORD arg_8,
    LPDWORD arg_9);

DWORD __cdecl _RpcCancelPlap(
    WLANSVC_HANDLE arg_1,
    const GUID *pInterfaceGuid);

DWORD __cdecl _RpcSetSecuritySettings(
    WLANSVC_RPC_HANDLE hClientHandle,
    WLAN_SECURABLE_OBJECT SecurableObject,
    const wchar_t *strModifiedSDDL);

DWORD __cdecl _RpcGetSecuritySettings(
    WLANSVC_RPC_HANDLE hClientHandle,
    WLAN_SECURABLE_OBJECT SecurableObject,
    WLAN_OPCODE_VALUE_TYPE *pValueType,
    wchar_t **pstrCurrentSDDL,
    LPDWORD pdwGrantedAccess);


#endif  /* __wlansvc_interface_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */

handle_t __RPC_USER WLANSVC_HANDLE_bind(WLANSVC_HANDLE);
void __RPC_USER WLANSVC_HANDLE_unbind(WLANSVC_HANDLE, handle_t);
void __RPC_USER WLANSVC_RPC_HANDLE_rundown(WLANSVC_RPC_HANDLE);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __wlansvc_c_h__ */