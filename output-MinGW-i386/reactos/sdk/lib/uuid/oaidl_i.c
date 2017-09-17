/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/oaidl.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, IID_IDispatch, 0x00020400, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_IEnumVARIANT, 0x00020404, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ITypeComp, 0x00020403, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ITypeInfo, 0x00020401, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ITypeInfo2, 0x00020412, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ITypeLib, 0x00020402, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ITypeLib2, 0x00020411, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ITypeChangeEvents, 0x00020410, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_IErrorInfo, 0x1cf2b120, 0x547d, 0x101b, 0x8e,0x65, 0x08,0x00,0x2b,0x2b,0xd1,0x19);
MIDL_DEFINE_GUID(IID, IID_ICreateErrorInfo, 0x22f03340, 0x547d, 0x101b, 0x8e,0x65, 0x08,0x00,0x2b,0x2b,0xd1,0x19);
MIDL_DEFINE_GUID(IID, IID_ISupportErrorInfo, 0xdf0b3d60, 0x548f, 0x101b, 0x8e,0x65, 0x08,0x00,0x2b,0x2b,0xd1,0x19);
MIDL_DEFINE_GUID(IID, IID_ITypeFactory, 0x0000002e, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ITypeMarshal, 0x0000002d, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_IRecordInfo, 0x0000002f, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ICreateTypeInfo, 0x00020405, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ICreateTypeInfo2, 0x0002040e, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ICreateTypeLib, 0x00020406, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_ICreateTypeLib2, 0x0002040f, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_IErrorLog, 0x3127ca40, 0x446e, 0x11ce, 0x81,0x35, 0x00,0xaa,0x00,0x4b,0xb8,0x51);
MIDL_DEFINE_GUID(IID, IID_IPropertyBag, 0x55272a00, 0x42cb, 0x11ce, 0x81,0x35, 0x00,0xaa,0x00,0x4b,0xb8,0x51);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID