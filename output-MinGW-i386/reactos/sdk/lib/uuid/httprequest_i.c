/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/httprequest.idl - Do not edit ***/

#ifdef __REACTOS__
#define WIN32_NO_STATUS
#define WIN32_LEAN_AND_MEAN
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
    DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
    const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif

#ifdef __cplusplus
extern "C" {
#endif

MIDL_DEFINE_GUID(IID, LIBID_WinHttp, 0x662901fc, 0x6951, 0x4854, 0x9e,0xb2, 0xd9,0xa2,0x57,0x0f,0x2b,0x2e);
MIDL_DEFINE_GUID(IID, IID_IWinHttpRequest, 0x016fe2ec, 0xb2c8, 0x45f8, 0xb2,0x3b, 0x39,0xe5,0x3a,0x75,0x39,0x6b);
MIDL_DEFINE_GUID(CLSID, CLSID_WinHttpRequest, 0x2087c2f4, 0x2cef, 0x4953, 0xa8,0xab, 0x66,0x77,0x9b,0x67,0x04,0x95);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID
