/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/msdadc.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, IID_IDataConvert, 0x0c733a8d, 0x2a1c, 0x11ce, 0xad,0xe5, 0x00,0xaa,0x00,0x44,0x77,0x3d);
MIDL_DEFINE_GUID(IID, IID_IDCInfo, 0x0c733a9c, 0x2a1c, 0x11ce, 0xad,0xe5, 0x00,0xaa,0x00,0x44,0x77,0x3d);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID