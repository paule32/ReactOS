/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/activdbg.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, IID_IActiveScriptDebug32, 0x51973c10, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IActiveScriptDebug64, 0xbc437e23, 0xf5b8, 0x47f4, 0xbb,0x79, 0x7d,0x1c,0xe5,0x48,0x3b,0x86);
MIDL_DEFINE_GUID(IID, IID_IDebugDocumentInfo, 0x51973c1f, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugDocument, 0x51973c21, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugCodeContext, 0x51973c13, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IEnumDebugCodeContexts, 0x51973c1d, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugDocumentContext, 0x51973c28, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IRemoteDebugApplicationThread, 0x51973c37, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IRemoteDebugApplication, 0x51973c30, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0xae,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugApplication32, 0x51973c32, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugApplication64, 0x4dedc754, 0x04c7, 0x4f10, 0x9e,0x60, 0x16,0xa3,0x90,0xfe,0x6e,0x62);
MIDL_DEFINE_GUID(IID, IID_IActiveScriptSiteDebug32, 0x51973c11, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IActiveScriptSiteDebug64, 0xd6b96b0a, 0x7463, 0x402c, 0x92,0xac, 0x89,0x98,0x42,0x26,0x94,0x2f);
MIDL_DEFINE_GUID(IID, IID_IDebugStackFrame, 0x51973c17, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IEnumDebugStackFrames, 0x51973c1e, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IApplicationDebugger, 0x51973c2a, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IEnumRemoteDebugApplicationThreads, 0x51973c3c, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugApplicationNode, 0x51973c34, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IEnumDebugExpressionContexts, 0x51973c40, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugApplicationThread, 0x51973c38, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugSyncOperation, 0x51973c1a, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugAsyncOperation, 0x51973c1b, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugStackFrameSniffer, 0x51973c18, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IDebugThreadCall32, 0x51973c36, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IActiveScriptErrorDebug, 0x51973c12, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);
MIDL_DEFINE_GUID(IID, IID_IProvideExpressionContexts, 0x51973c41, 0xcb0c, 0x11d0, 0xb5,0xc9, 0x00,0xa0,0x24,0x4a,0x0e,0x7a);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID