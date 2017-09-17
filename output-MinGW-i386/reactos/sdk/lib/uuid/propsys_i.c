/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/propsys.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, IID_IInitializeWithFile, 0xb7d14566, 0x0509, 0x4cce, 0xa7,0x1f, 0x0a,0x55,0x42,0x33,0xbd,0x9b);
MIDL_DEFINE_GUID(IID, IID_IInitializeWithStream, 0xb824b49d, 0x22ac, 0x4161, 0xac,0x8a, 0x99,0x16,0xe8,0xfa,0x3f,0x7f);
MIDL_DEFINE_GUID(IID, IID_IPropertyStore, 0x886d8eeb, 0x8cf2, 0x4446, 0x8d,0x02, 0xcd,0xba,0x1d,0xbd,0xcf,0x99);
MIDL_DEFINE_GUID(IID, IID_INamedPropertyStore, 0x71604b0f, 0x97b0, 0x4764, 0x85,0x77, 0x2f,0x13,0xe9,0x8a,0x14,0x22);
MIDL_DEFINE_GUID(IID, IID_IObjectWithPropertyKey, 0xfc0ca0a7, 0xc316, 0x4fd2, 0x90,0x31, 0x3e,0x62,0x8e,0x6d,0x4f,0x23);
MIDL_DEFINE_GUID(IID, IID_IPropertyChange, 0xf917bc8a, 0x1bba, 0x4478, 0xa2,0x45, 0x1b,0xde,0x03,0xeb,0x94,0x31);
MIDL_DEFINE_GUID(IID, IID_IPropertyChangeArray, 0x380f5cad, 0x1b5e, 0x42f2, 0x80,0x5d, 0x63,0x7f,0xd3,0x92,0xd3,0x1e);
MIDL_DEFINE_GUID(IID, IID_IPropertyStoreCapabilities, 0xc8e2d566, 0x186e, 0x4d49, 0xbf,0x41, 0x69,0x09,0xea,0xd5,0x6a,0xcc);
MIDL_DEFINE_GUID(IID, IID_IPropertyStoreCache, 0x3017056d, 0x9a91, 0x4e90, 0x93,0x7d, 0x74,0x6c,0x72,0xab,0xbf,0x4f);
MIDL_DEFINE_GUID(IID, IID_IPropertyEnumType, 0x11e1fbf9, 0x2d56, 0x4a6b, 0x8d,0xb3, 0x7c,0xd1,0x93,0xa4,0x71,0xf2);
MIDL_DEFINE_GUID(IID, IID_IPropertyEnumType2, 0x9b6e051c, 0x5ddd, 0x4321, 0x90,0x70, 0xfe,0x2a,0xcb,0x55,0xe9,0x74);
MIDL_DEFINE_GUID(IID, IID_IPropertyEnumTypeList, 0xa99400f4, 0x3d84, 0x4557, 0x94,0xba, 0x12,0x42,0xfb,0x2c,0xc9,0xa6);
MIDL_DEFINE_GUID(IID, IID_IPropertyDescription, 0x6f79d558, 0x3e96, 0x4549, 0xa1,0xd1, 0x7d,0x75,0xd2,0x28,0x88,0x14);
MIDL_DEFINE_GUID(IID, IID_IPropertyDescription2, 0x57d2eded, 0x5062, 0x400e, 0xb1,0x07, 0x5d,0xae,0x79,0xfe,0x57,0xa6);
MIDL_DEFINE_GUID(IID, IID_IPropertyDescriptionAliasInfo, 0xf67104fc, 0x2af9, 0x46fd, 0xb3,0x2d, 0x24,0x3c,0x14,0x04,0xf3,0xd1);
MIDL_DEFINE_GUID(IID, IID_IPropertyDescriptionSearchInfo, 0x078f91bd, 0x29a2, 0x440f, 0x92,0x4e, 0x46,0xa2,0x91,0x52,0x45,0x20);
MIDL_DEFINE_GUID(IID, IID_IPropertyDescriptionRelatedPropertyInfo, 0x507393f4, 0x2a3d, 0x4a60, 0xb5,0x9e, 0xd9,0xc7,0x57,0x16,0xc2,0xdd);
MIDL_DEFINE_GUID(IID, IID_IPropertySystem, 0xca724e8a, 0xc3e6, 0x442b, 0x88,0xa4, 0x6f,0xb0,0xdb,0x80,0x35,0xa3);
MIDL_DEFINE_GUID(IID, IID_IPropertyDescriptionList, 0x1f9fc1d0, 0xc39b, 0x4b26, 0x81,0x7f, 0x01,0x19,0x67,0xd3,0x44,0x0e);
MIDL_DEFINE_GUID(IID, IID_IPropertyStoreFactory, 0xbc110b6d, 0x57e8, 0x4148, 0xa9,0xc6, 0x91,0x01,0x5a,0xb2,0xf3,0xa5);
MIDL_DEFINE_GUID(IID, IID_IDelayedPropertyStoreFactory, 0x40d4577f, 0xe237, 0x4bdb, 0xbd,0x69, 0x58,0xf0,0x89,0x43,0x1b,0x6a);
MIDL_DEFINE_GUID(IID, IID_IPersistSerializedPropStorage, 0xe318ad57, 0x0aa0, 0x450f, 0xac,0xa5, 0x6f,0xab,0x71,0x03,0xd9,0x17);
MIDL_DEFINE_GUID(IID, IID_IPersistSerializedPropStorage2, 0x77effa68, 0x4f98, 0x4366, 0xba,0x72, 0x57,0x3b,0x3d,0x88,0x05,0x71);
MIDL_DEFINE_GUID(IID, IID_IPropertySystemChangeNotify, 0xfa955fd9, 0x38be, 0x4879, 0xa6,0xce, 0x82,0x4c,0xf5,0x2d,0x60,0x9f);
MIDL_DEFINE_GUID(IID, IID_ICreateObject, 0x75121952, 0xe0d0, 0x43e5, 0x93,0x80, 0x1d,0x80,0x48,0x3a,0xcf,0x72);
MIDL_DEFINE_GUID(IID, LIBID_PropSysObjects, 0x2cda3294, 0x6c4f, 0x4020, 0xb1,0x61, 0x27,0xc5,0x30,0xc8,0x1f,0xa6);
MIDL_DEFINE_GUID(CLSID, CLSID_InMemoryPropertyStore, 0x9a02e012, 0x6303, 0x4e1e, 0xb9,0xa1, 0x63,0x0f,0x80,0x25,0x92,0xc5);
MIDL_DEFINE_GUID(CLSID, CLSID_PropertySystem, 0xb8967f86, 0x58ae, 0x4f96, 0x9f,0xb2, 0x5d,0x79,0x04,0x79,0x8f,0x4b);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID