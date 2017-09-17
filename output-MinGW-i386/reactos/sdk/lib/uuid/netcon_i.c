/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/netcon.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, IID_INetConnection, 0xc08956a1, 0x1cd3, 0x11d1, 0xb1,0xc5, 0x00,0x80,0x5f,0xc1,0x27,0x0e);
MIDL_DEFINE_GUID(IID, IID_INetSharingPortMappingProps, 0x24b7e9b5, 0xe38f, 0x4685, 0x85,0x1b, 0x00,0x89,0x2c,0xf5,0xf9,0x40);
MIDL_DEFINE_GUID(IID, IID_INetSharingPortMapping, 0xc08956b1, 0x1cd3, 0x11d1, 0xb1,0xc5, 0x00,0x80,0x5f,0xc1,0x27,0x0e);
MIDL_DEFINE_GUID(IID, IID_INetSharingPortMappingCollection, 0x02e4a2de, 0xda20, 0x4e34, 0x89,0xc8, 0xac,0x22,0x27,0x5a,0x01,0x0b);
MIDL_DEFINE_GUID(IID, IID_INetSharingConfiguration, 0xc08956b6, 0x1cd3, 0x11d1, 0xb1,0xc5, 0x00,0x80,0x5f,0xc1,0x27,0x0e);
MIDL_DEFINE_GUID(IID, IID_IEnumNetSharingPublicConnection, 0xc08956b4, 0x1cd3, 0x11d1, 0xb1,0xc5, 0x00,0x80,0x5f,0xc1,0x27,0x0e);
MIDL_DEFINE_GUID(IID, IID_IEnumNetSharingPrivateConnection, 0xc08956b5, 0x1cd3, 0x11d1, 0xb1,0xc5, 0x00,0x80,0x5f,0xc1,0x27,0x0e);
MIDL_DEFINE_GUID(IID, IID_INetConnectionProps, 0xf4277c95, 0xce5b, 0x463d, 0x81,0x67, 0x56,0x62,0xd9,0xbc,0xaa,0x72);
MIDL_DEFINE_GUID(IID, IID_INetSharingPublicConnectionCollection, 0x7d7a6355, 0xf372, 0x4971, 0xa1,0x49, 0xbf,0xc9,0x27,0xbe,0x76,0x2a);
MIDL_DEFINE_GUID(IID, IID_INetSharingEveryConnectionCollection, 0x33c4643c, 0x7811, 0x46fa, 0xa8,0x9a, 0x76,0x85,0x97,0xbd,0x72,0x23);
MIDL_DEFINE_GUID(IID, IID_INetSharingPrivateConnectionCollection, 0x38ae69e0, 0x4409, 0x402a, 0xa2,0xcb, 0xe9,0x65,0xc7,0x27,0xf8,0x40);
MIDL_DEFINE_GUID(IID, IID_INetSharingManager, 0xc08956b7, 0x1cd3, 0x11d1, 0xb1,0xc5, 0x00,0x80,0x5f,0xc1,0x27,0x0e);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID