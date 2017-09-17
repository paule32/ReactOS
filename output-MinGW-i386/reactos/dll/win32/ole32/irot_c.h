/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/dll/win32/ole32/irot.idl - Do not edit ***/

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

#ifndef __irot_c_h__
#define __irot_c_h__

/* Forward declarations */

/* Headers for imported files */

#include <wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#define IROT_PROTSEQ {'n','c','a','l','r','p','c',0}
#define IROT_ENDPOINT {'i','r','o','t',0}
typedef struct tagMonikerComparisonData {
    ULONG ulCntData;
    BYTE abData[1];
} MonikerComparisonData;
/*****************************************************************************
 * Irot interface (v0.2)
 */
#ifndef __Irot_INTERFACE_DEFINED__
#define __Irot_INTERFACE_DEFINED__

extern RPC_IF_HANDLE Irot_v0_2_c_ifspec;
extern RPC_IF_HANDLE Irot_v0_2_s_ifspec;
typedef struct tagInterfaceData {
    ULONG ulCntData;
    BYTE abData[1];
} InterfaceData;
typedef InterfaceData *PInterfaceData;
typedef struct tagInterfaceList {
    ULONG size;
    PInterfaceData interfaces[1];
} InterfaceList;
typedef InterfaceList *PInterfaceList;
typedef DWORD IrotCookie;
typedef handle_t IrotHandle;
typedef void *IrotContextHandle;
HRESULT __cdecl IrotRegister(
    IrotHandle h,
    const MonikerComparisonData *moniker_data,
    const InterfaceData *object,
    const InterfaceData *moniker,
    const FILETIME *time,
    DWORD grfFlags,
    IrotCookie *cookie,
    IrotContextHandle *ctxt_handle);

HRESULT __cdecl IrotRevoke(
    IrotHandle h,
    IrotCookie cookie,
    IrotContextHandle *ctxt_handle,
    PInterfaceData *object,
    PInterfaceData *moniker);

HRESULT __cdecl IrotIsRunning(
    IrotHandle h,
    const MonikerComparisonData *moniker_data);

HRESULT __cdecl IrotGetObject(
    IrotHandle h,
    const MonikerComparisonData *moniker_data,
    PInterfaceData *obj,
    IrotCookie *cookie);

HRESULT __cdecl IrotNoteChangeTime(
    IrotHandle h,
    IrotCookie cookie,
    const FILETIME *time);

HRESULT __cdecl IrotGetTimeOfLastChange(
    IrotHandle h,
    const MonikerComparisonData *moniker_data,
    FILETIME *time);

HRESULT __cdecl IrotEnumRunning(
    IrotHandle h,
    PInterfaceList *list);


#endif  /* __Irot_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */

void __RPC_USER IrotContextHandle_rundown(IrotContextHandle);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __irot_c_h__ */