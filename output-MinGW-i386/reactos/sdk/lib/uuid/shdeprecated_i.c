/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/shdeprecated.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, IID_ITravelEntry, 0xf46edb3b, 0xbc2f, 0x11d0, 0x94,0x12, 0x00,0xaa,0x00,0xa3,0xeb,0xd3);
MIDL_DEFINE_GUID(IID, IID_ITravelLog, 0x66a9cb08, 0x4802, 0x11d2, 0xa5,0x61, 0x00,0xa0,0xc9,0x2d,0xbf,0xe8);
MIDL_DEFINE_GUID(IID, IID_IExpDispSupport, 0x0d7d1d00, 0x6fc0, 0x11d0, 0xa9,0x74, 0x00,0xc0,0x4f,0xd7,0x05,0xa2);
MIDL_DEFINE_GUID(IID, IID_IBrowserService, 0x02ba3b52, 0x0547, 0x11d1, 0xb8,0x33, 0x00,0xc0,0x4f,0xc9,0xb3,0x1f);
MIDL_DEFINE_GUID(IID, IID_IShellService, 0x5836fb00, 0x8187, 0x11cf, 0xa1,0x2b, 0x00,0xaa,0x00,0x4a,0xe8,0x37);
MIDL_DEFINE_GUID(IID, IID_IBrowserService2, 0x68bd21cc, 0x438b, 0x11d2, 0xa5,0x60, 0x00,0xa0,0xc9,0x2d,0xbf,0xe8);
MIDL_DEFINE_GUID(IID, IID_IBrowserService3, 0x27d7ce21, 0x762d, 0x48f3, 0x86,0xf3, 0x40,0xe2,0xfd,0x37,0x49,0xc4);
MIDL_DEFINE_GUID(IID, IID_IBrowserService4, 0x639f1bff, 0xe135, 0x4096, 0xab,0xd8, 0xe0,0xf5,0x04,0xd6,0x49,0xa4);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID