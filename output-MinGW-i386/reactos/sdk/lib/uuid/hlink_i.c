/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/hlink.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, IID_IHlink, 0x79eac9c3, 0xbaf9, 0x11ce, 0x8c,0x82, 0x00,0xaa,0x00,0x4b,0xa9,0x0b);
MIDL_DEFINE_GUID(IID, IID_IHlinkSite, 0x79eac9c2, 0xbaf9, 0x11ce, 0x8c,0x82, 0x00,0xaa,0x00,0x4b,0xa9,0x0b);
MIDL_DEFINE_GUID(IID, IID_IEnumHLITEM, 0x79eac9c6, 0xbaf9, 0x11ce, 0x8c,0x82, 0x00,0xaa,0x00,0x4b,0xa9,0x0b);
MIDL_DEFINE_GUID(IID, IID_IHlinkBrowseContext, 0x79eac9c7, 0xbaf9, 0x11ce, 0x8c,0x82, 0x00,0xaa,0x00,0x4b,0xa9,0x0b);
MIDL_DEFINE_GUID(IID, IID_IHlinkTarget, 0x79eac9c4, 0xbaf9, 0x11ce, 0x8c,0x82, 0x00,0xaa,0x00,0x4b,0xa9,0x0b);
MIDL_DEFINE_GUID(IID, IID_IHlinkFrame, 0x79eac9c5, 0xbaf9, 0x11ce, 0x8c,0x82, 0x00,0xaa,0x00,0x4b,0xa9,0x0b);
MIDL_DEFINE_GUID(IID, IID_IExtensionServices, 0x79eac9cb, 0xbaf9, 0x11ce, 0x8c,0x82, 0x00,0xaa,0x00,0x4b,0xa9,0x0b);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID
