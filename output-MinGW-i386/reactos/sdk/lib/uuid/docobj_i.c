/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/docobj.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, IID_IOleDocument, 0xb722bcc5, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
MIDL_DEFINE_GUID(IID, IID_IOleDocumentSite, 0xb722bcc7, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
MIDL_DEFINE_GUID(IID, IID_IOleDocumentView, 0xb722bcc6, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
MIDL_DEFINE_GUID(IID, IID_IEnumOleDocumentViews, 0xb722bcc8, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
MIDL_DEFINE_GUID(IID, IID_IOleCommandTarget, 0xb722bccb, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
MIDL_DEFINE_GUID(IID, IID_IContinueCallback, 0xb722bcca, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
MIDL_DEFINE_GUID(IID, IID_IPrint, 0xb722bcc9, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID
