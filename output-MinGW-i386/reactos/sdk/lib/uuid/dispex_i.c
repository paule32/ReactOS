/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/dispex.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, IID_IDispatchEx, 0xa6ef9860, 0xc720, 0x11d0, 0x93,0x37, 0x00,0xa0,0xc9,0x0d,0xca,0xa9);
MIDL_DEFINE_GUID(IID, IID_IDispError, 0xa6ef9861, 0xc720, 0x11d0, 0x93,0x37, 0x00,0xa0,0xc9,0x0d,0xca,0xa9);
MIDL_DEFINE_GUID(IID, IID_IVariantChangeType, 0xa6ef9862, 0xc720, 0x11d0, 0x93,0x37, 0x00,0xa0,0xc9,0x0d,0xca,0xa9);
MIDL_DEFINE_GUID(IID, IID_IObjectIdentity, 0xca04b7e6, 0x0d21, 0x11d1, 0x8c,0xc5, 0x00,0xc0,0x4f,0xc2,0xb0,0x85);
MIDL_DEFINE_GUID(IID, IID_ICanHandleException, 0xc5598e60, 0xb307, 0x11d1, 0xb2,0x7d, 0x00,0x60,0x08,0xc3,0xfb,0xfb);
MIDL_DEFINE_GUID(IID, IID_IProvideRuntimeContext, 0x10e2414a, 0xec59, 0x49d2, 0xbc,0x51, 0x5a,0xdd,0x2c,0x36,0xfe,0xbc);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID