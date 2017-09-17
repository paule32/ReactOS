/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/exdisp.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, LIBID_SHDocVw, 0xeab22ac0, 0x30c1, 0x11cf, 0xa7,0xeb, 0x00,0x00,0xc0,0x5b,0xae,0x0b);
MIDL_DEFINE_GUID(IID, IID_IWebBrowser, 0xeab22ac1, 0x30c1, 0x11cf, 0xa7,0xeb, 0x00,0x00,0xc0,0x5b,0xae,0x0b);
MIDL_DEFINE_GUID(IID, DIID_DWebBrowserEvents, 0xeab22ac2, 0x30c1, 0x11cf, 0xa7,0xeb, 0x00,0x00,0xc0,0x5b,0xae,0x0b);
MIDL_DEFINE_GUID(IID, IID_IWebBrowserApp, 0x0002df05, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(IID, IID_IWebBrowser2, 0xd30c1661, 0xcdaf, 0x11d0, 0x8a,0x3e, 0x00,0xc0,0x4f,0xc9,0xe2,0x6e);
MIDL_DEFINE_GUID(IID, DIID_DWebBrowserEvents2, 0x34a715a0, 0x6587, 0x11d0, 0x92,0x4a, 0x00,0x20,0xaf,0xc7,0xac,0x4d);
MIDL_DEFINE_GUID(CLSID, CLSID_WebBrowser_V1, 0xeab22ac3, 0x30c1, 0x11cf, 0xa7,0xeb, 0x00,0x00,0xc0,0x5b,0xae,0x0b);
MIDL_DEFINE_GUID(CLSID, CLSID_WebBrowser, 0x8856f961, 0x340a, 0x11d0, 0xa9,0x6b, 0x00,0xc0,0x4f,0xd7,0x05,0xa2);
MIDL_DEFINE_GUID(CLSID, CLSID_InternetExplorer, 0x0002df01, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
MIDL_DEFINE_GUID(CLSID, CLSID_ShellBrowserWindow, 0xc08afd90, 0xf2a1, 0x11d1, 0x84,0x55, 0x00,0xa0,0xc9,0x1f,0x38,0x80);
MIDL_DEFINE_GUID(IID, DIID_DShellWindowsEvents, 0xfe4106e0, 0x399a, 0x11d0, 0xa4,0x8c, 0x00,0xa0,0xc9,0x0a,0x8f,0x39);
MIDL_DEFINE_GUID(IID, IID_IShellWindows, 0x85cb6900, 0x4d95, 0x11cf, 0x96,0x0c, 0x00,0x80,0xc7,0xf4,0xee,0x85);
MIDL_DEFINE_GUID(CLSID, CLSID_ShellWindows, 0x9ba05972, 0xf6a8, 0x11cf, 0xa4,0x42, 0x00,0xa0,0xc9,0x0a,0x8f,0x39);
MIDL_DEFINE_GUID(IID, IID_IShellUIHelper, 0x729fe2f8, 0x1ea8, 0x11d1, 0x8f,0x85, 0x00,0xc0,0x4f,0xc2,0xfb,0xe1);
MIDL_DEFINE_GUID(IID, IID_IShellUIHelper2, 0xa7fe6eda, 0x1932, 0x4281, 0xb8,0x81, 0x87,0xb3,0x1b,0x8b,0xc5,0x2c);
MIDL_DEFINE_GUID(CLSID, CLSID_ShellUIHelper, 0x64ab4bb7, 0x111e, 0x11d1, 0x8f,0x79, 0x00,0xc0,0x4f,0xc2,0xfb,0xe1);
MIDL_DEFINE_GUID(IID, DIID_DShellNameSpaceEvents, 0x55136806, 0xb2de, 0x11d1, 0xb9,0xf2, 0x00,0xa0,0xc9,0x8b,0xc5,0x47);
MIDL_DEFINE_GUID(IID, IID_IShellFavoritesNameSpace, 0x55136804, 0xb2de, 0x11d1, 0xb9,0xf2, 0x00,0xa0,0xc9,0x8b,0xc5,0x47);
MIDL_DEFINE_GUID(IID, IID_IShellNameSpace, 0xe572d3c9, 0x37be, 0x4ae2, 0x82,0x5d, 0xd5,0x21,0x76,0x3e,0x31,0x08);
MIDL_DEFINE_GUID(CLSID, CLSID_ShellShellNameSpace, 0x2f2f1f96, 0x2bc1, 0x4b1c, 0xbe,0x28, 0xea,0x37,0x74,0xf4,0x67,0x6a);
MIDL_DEFINE_GUID(CLSID, CLSID_ShellNameSpace, 0x55136805, 0xb2de, 0x11d1, 0xb9,0xf2, 0x00,0xa0,0xc9,0x8b,0xc5,0x47);
MIDL_DEFINE_GUID(IID, IID_IScriptErrorList, 0xf3470f24, 0x15fd, 0x11d2, 0xbb,0x2e, 0x00,0x80,0x5f,0xf7,0xef,0xca);
MIDL_DEFINE_GUID(CLSID, CLSID_CScriptErrorList, 0xefd01300, 0x160f, 0x11d2, 0xbb,0x2e, 0x00,0x80,0x5f,0xf7,0xef,0xca);
MIDL_DEFINE_GUID(IID, IID_ISearch, 0xba9239a4, 0x3dd5, 0x11d2, 0xbf,0x8b, 0x00,0xc0,0x4f,0xb9,0x36,0x61);
MIDL_DEFINE_GUID(IID, IID_ISearches, 0x47c922a2, 0x3dd5, 0x11d2, 0xbf,0x8b, 0x00,0xc0,0x4f,0xb9,0x36,0x61);
MIDL_DEFINE_GUID(IID, IID_ISearchAssistantOC, 0x72423e8f, 0x8011, 0x11d2, 0xbe,0x79, 0x00,0xa0,0xc9,0xa8,0x3d,0xa1);
MIDL_DEFINE_GUID(IID, IID_ISearchAssistantOC2, 0x72423e8f, 0x8011, 0x11d2, 0xbe,0x79, 0x00,0xa0,0xc9,0xa8,0x3d,0xa2);
MIDL_DEFINE_GUID(IID, IID_ISearchAssistantOC3, 0x72423e8f, 0x8011, 0x11d2, 0xbe,0x79, 0x00,0xa0,0xc9,0xa8,0x3d,0xa3);
MIDL_DEFINE_GUID(IID, DIID__SearchAssistantEvents, 0x1611fdda, 0x445b, 0x11d2, 0x85,0xde, 0x00,0xc0,0x4f,0xa3,0x5c,0x89);
MIDL_DEFINE_GUID(CLSID, CLSID_ShellSearchAssistantOC, 0x2e71fd0f, 0xaab1, 0x42c0, 0x91,0x46, 0x6d,0x2c,0x4e,0xdc,0xf0,0x7d);
MIDL_DEFINE_GUID(CLSID, CLSID_SearchAssistantOC, 0xb45ff030, 0x4447, 0x11d2, 0x85,0xde, 0x00,0xc0,0x4f,0xa3,0x5c,0x89);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID