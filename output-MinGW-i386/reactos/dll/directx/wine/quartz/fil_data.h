/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/dll/directx/wine/quartz/fil_data.idl - Do not edit ***/

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

#ifndef __fil_data_h__
#define __fil_data_h__

/* Forward declarations */

#ifndef __IAMFilterData_FWD_DEFINED__
#define __IAMFilterData_FWD_DEFINED__
typedef interface IAMFilterData IAMFilterData;
#ifdef __cplusplus
interface IAMFilterData;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <objidl.h>
#include <strmif.h>
#include <unknwn.h>

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * IAMFilterData interface
 */
#ifndef __IAMFilterData_INTERFACE_DEFINED__
#define __IAMFilterData_INTERFACE_DEFINED__

typedef IAMFilterData *LPIAMFILTERDATA;
DEFINE_GUID(IID_IAMFilterData, 0x97f7c4d4, 0x547b, 0x4a5f, 0x83,0x32, 0x53,0x64,0x30,0xad,0x2e,0x4d);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("97f7c4d4-547b-4a5f-8332-536430ad2e4d")
IAMFilterData : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE ParseFilterData(
        BYTE *rgbFilterData,
        ULONG cb,
        BYTE **prgbRegFilter2) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateFilterData(
        REGFILTER2 *prf2,
        BYTE **prgbFilterData,
        ULONG *pcb) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IAMFilterData, 0x97f7c4d4, 0x547b, 0x4a5f, 0x83,0x32, 0x53,0x64,0x30,0xad,0x2e,0x4d)
#endif
#else
typedef struct IAMFilterDataVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IAMFilterData *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IAMFilterData *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IAMFilterData *This);

    /*** IAMFilterData methods ***/
    HRESULT (STDMETHODCALLTYPE *ParseFilterData)(
        IAMFilterData *This,
        BYTE *rgbFilterData,
        ULONG cb,
        BYTE **prgbRegFilter2);

    HRESULT (STDMETHODCALLTYPE *CreateFilterData)(
        IAMFilterData *This,
        REGFILTER2 *prf2,
        BYTE **prgbFilterData,
        ULONG *pcb);

    END_INTERFACE
} IAMFilterDataVtbl;

interface IAMFilterData {
    CONST_VTBL IAMFilterDataVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IAMFilterData_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IAMFilterData_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IAMFilterData_Release(This) (This)->lpVtbl->Release(This)
/*** IAMFilterData methods ***/
#define IAMFilterData_ParseFilterData(This,rgbFilterData,cb,prgbRegFilter2) (This)->lpVtbl->ParseFilterData(This,rgbFilterData,cb,prgbRegFilter2)
#define IAMFilterData_CreateFilterData(This,prf2,prgbFilterData,pcb) (This)->lpVtbl->CreateFilterData(This,prf2,prgbFilterData,pcb)
#else
/*** IUnknown methods ***/
FORCEINLINE HRESULT IAMFilterData_QueryInterface(IAMFilterData* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
FORCEINLINE ULONG IAMFilterData_AddRef(IAMFilterData* This) {
    return This->lpVtbl->AddRef(This);
}
FORCEINLINE ULONG IAMFilterData_Release(IAMFilterData* This) {
    return This->lpVtbl->Release(This);
}
/*** IAMFilterData methods ***/
FORCEINLINE HRESULT IAMFilterData_ParseFilterData(IAMFilterData* This,BYTE *rgbFilterData,ULONG cb,BYTE **prgbRegFilter2) {
    return This->lpVtbl->ParseFilterData(This,rgbFilterData,cb,prgbRegFilter2);
}
FORCEINLINE HRESULT IAMFilterData_CreateFilterData(IAMFilterData* This,REGFILTER2 *prf2,BYTE **prgbFilterData,ULONG *pcb) {
    return This->lpVtbl->CreateFilterData(This,prf2,prgbFilterData,pcb);
}
#endif
#endif

#endif

HRESULT STDMETHODCALLTYPE IAMFilterData_ParseFilterData_Proxy(
    IAMFilterData* This,
    BYTE *rgbFilterData,
    ULONG cb,
    BYTE **prgbRegFilter2);
void __RPC_STUB IAMFilterData_ParseFilterData_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IAMFilterData_CreateFilterData_Proxy(
    IAMFilterData* This,
    REGFILTER2 *prf2,
    BYTE **prgbFilterData,
    ULONG *pcb);
void __RPC_STUB IAMFilterData_CreateFilterData_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IAMFilterData_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __fil_data_h__ */
