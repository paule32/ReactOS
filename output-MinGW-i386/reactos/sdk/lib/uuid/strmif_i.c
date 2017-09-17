/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/psdk/strmif.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, IID_ICreateDevEnum, 0x29840822, 0x5b84, 0x11d0, 0xbd,0x3b, 0x00,0xa0,0xc9,0x11,0xce,0x86);
MIDL_DEFINE_GUID(IID, IID_IPin, 0x56a86891, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IEnumPins, 0x56a86892, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IEnumMediaTypes, 0x89c31040, 0x846b, 0x11ce, 0x97,0xd3, 0x00,0xaa,0x00,0x55,0x59,0x5a);
MIDL_DEFINE_GUID(IID, IID_IFilterGraph, 0x56a8689f, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IEnumFilters, 0x56a86893, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IMediaFilter, 0x56a86899, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IBaseFilter, 0x56a86895, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IReferenceClock, 0x56a86897, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IReferenceClockTimerControl, 0xebec459c, 0x2eca, 0x4d42, 0xa8,0xaf, 0x30,0xdf,0x55,0x76,0x14,0xb8);
MIDL_DEFINE_GUID(IID, IID_IMediaSample, 0x56a8689a, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IMediaSample2, 0x36b73884, 0xc2c8, 0x11cf, 0x8b,0x46, 0x00,0x80,0x5f,0x6c,0xef,0x60);
MIDL_DEFINE_GUID(IID, IID_IMemAllocator, 0x56a8689c, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IMemAllocatorCallbackTemp, 0x379a0cf0, 0xc1de, 0x11d2, 0xab,0xf5, 0x00,0xa0,0xc9,0x05,0xf3,0x75);
MIDL_DEFINE_GUID(IID, IID_IMemAllocatorNotifyCallbackTemp, 0x92980b30, 0xc1de, 0x11d2, 0xab,0xf5, 0x00,0xa0,0xc9,0x05,0xf3,0x75);
MIDL_DEFINE_GUID(IID, IID_IMemInputPin, 0x56a8689d, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IAMovieSetup, 0xa3d8cec0, 0x7e5a, 0x11cf, 0xbb,0xc5, 0x00,0x80,0x5f,0x6c,0xef,0x20);
MIDL_DEFINE_GUID(IID, IID_IMediaSeeking, 0x36b73880, 0xc2c8, 0x11cf, 0x8b,0x46, 0x00,0x80,0x5f,0x6c,0xef,0x60);
MIDL_DEFINE_GUID(IID, IID_IAMStreamSelect, 0xc1960960, 0x17f5, 0x11d1, 0xab,0xe1, 0x00,0xa0,0xc9,0x05,0xf3,0x75);
MIDL_DEFINE_GUID(IID, IID_IEnumRegFilters, 0x56a868a4, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IFilterMapper, 0x56a868a3, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IFilterMapper2, 0xb79bb0b0, 0x33c1, 0x11d1, 0xab,0xe1, 0x00,0xa0,0xc9,0x05,0xf3,0x75);
MIDL_DEFINE_GUID(IID, IID_IFilterMapper3, 0xb79bb0b1, 0x33c1, 0x11d1, 0xab,0xe1, 0x00,0xa0,0xc9,0x05,0xf3,0x75);
MIDL_DEFINE_GUID(IID, IID_IQualityControl, 0x56a868a5, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IOverlayNotify, 0x56a868a0, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IOverlayNotify2, 0x680efa10, 0xd535, 0x11d1, 0x87,0xc8, 0x00,0xa0,0xc9,0x22,0x31,0x96);
MIDL_DEFINE_GUID(IID, IID_IOverlay, 0x56a868a1, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IMediaEventSink, 0x56a868a2, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IFileSourceFilter, 0x56a868a6, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IFileSinkFilter, 0xa2104830, 0x7c70, 0x11cf, 0x8b,0xce, 0x00,0xaa,0x00,0xa3,0xf1,0xa6);
MIDL_DEFINE_GUID(IID, IID_IFileSinkFilter2, 0x00855b90, 0xce1b, 0x11d0, 0xbd,0x4f, 0x00,0xa0,0xc9,0x11,0xce,0x86);
MIDL_DEFINE_GUID(IID, IID_IAMDeviceRemoval, 0xf90a6130, 0xb658, 0x11d2, 0xae,0x49, 0x00,0x00,0xf8,0x75,0x4b,0x99);
MIDL_DEFINE_GUID(IID, IID_IGraphBuilder, 0x56a868a9, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_ICaptureGraphBuilder, 0xbf87b6e0, 0x8c27, 0x11d0, 0xb3,0xf0, 0x00,0xaa,0x00,0x37,0x61,0xc5);
MIDL_DEFINE_GUID(IID, IID_IAMCopyCaptureFileProgress, 0x670d1d20, 0xa068, 0x11d0, 0xb3,0xf0, 0x00,0xaa,0x00,0x37,0x61,0xc5);
MIDL_DEFINE_GUID(IID, IID_ICaptureGraphBuilder2, 0x93e5a4e0, 0x2d50, 0x11d2, 0xab,0xfa, 0x00,0xa0,0xc9,0xc6,0xe3,0x8d);
MIDL_DEFINE_GUID(IID, IID_IConfigAviMux, 0x5acd6aa0, 0xf482, 0x11ce, 0x8b,0x67, 0x00,0xaa,0x00,0xa3,0xf1,0xa6);
MIDL_DEFINE_GUID(IID, IID_IConfigInterleaving, 0xbee3d220, 0x157b, 0x11d0, 0xbd,0x23, 0x00,0xa0,0xc9,0x11,0xce,0x86);
MIDL_DEFINE_GUID(IID, IID_IAMClockSlave, 0x9fd52741, 0x176d, 0x4b36, 0x8f,0x51, 0xca,0x8f,0x93,0x32,0x23,0xbe);
MIDL_DEFINE_GUID(IID, IID_IAMCertifiedOutputProtection, 0x6feded3e, 0x0ff1, 0x4901, 0xa2,0xf1, 0x43,0xf7,0x01,0x2c,0x85,0x15);
MIDL_DEFINE_GUID(IID, IID_IFilterGraph2, 0x36b73882, 0xc2c8, 0x11cf, 0x8b,0x46, 0x00,0x80,0x5f,0x6c,0xef,0x60);
MIDL_DEFINE_GUID(IID, IID_IStreamBuilder, 0x56a868bf, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IDistributorNotify, 0x56a868af, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IAMStreamConfig, 0xc6e13340, 0x30ac, 0x11d0, 0xa1,0x8c, 0x00,0xa0,0xc9,0x11,0x89,0x56);
MIDL_DEFINE_GUID(IID, IID_IAMVideoProcAmp, 0xc6e13360, 0x30ac, 0x11d0, 0xa1,0x8c, 0x00,0xa0,0xc9,0x11,0x89,0x56);
MIDL_DEFINE_GUID(IID, IID_IAsyncReader, 0x56a868aa, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IGraphVersion, 0x56a868ab, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IResourceConsumer, 0x56a868ad, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IResourceManager, 0x56a868ac, 0x0ad4, 0x11ce, 0xb0,0x3a, 0x00,0x20,0xaf,0x0b,0xa7,0x70);
MIDL_DEFINE_GUID(IID, IID_IKsPropertySet, 0x31efac30, 0x515c, 0x11d0, 0xa9,0xaa, 0x00,0xaa,0x00,0x61,0xbe,0x93);
MIDL_DEFINE_GUID(IID, IID_ISeekingPassThru, 0x36b73883, 0xc2c8, 0x11cf, 0x8b,0x46, 0x00,0x80,0x5f,0x6c,0xef,0x60);
MIDL_DEFINE_GUID(IID, IID_IAMClockAdjust, 0x4d5466b0, 0xa49c, 0x11d1, 0xab,0xe8, 0x00,0xa0,0xc9,0x05,0xf3,0x75);
MIDL_DEFINE_GUID(IID, IID_IAMFilterMiscFlags, 0x2dd74950, 0xa890, 0x11d1, 0xab,0xe8, 0x00,0xa0,0xc9,0x05,0xf3,0x75);
MIDL_DEFINE_GUID(IID, IID_IAMGraphBuilderCallback, 0x4995f511, 0x9ddb, 0x4f12, 0xbd,0x3b, 0xf0,0x46,0x11,0x80,0x7b,0x79);
MIDL_DEFINE_GUID(IID, IID_IAMBufferNegotiation, 0x56ed71a0, 0xaf5f, 0x11d0, 0xb3,0xf0, 0x00,0xaa,0x00,0x37,0x61,0xc5);
MIDL_DEFINE_GUID(IID, IID_IAMStreamControl, 0x36b73881, 0xc2c8, 0x11cf, 0x8b,0x46, 0x00,0x80,0x5f,0x6c,0xef,0x60);
MIDL_DEFINE_GUID(IID, IID_IPinConnection, 0x4a9a62d3, 0x27d4, 0x403d, 0x91,0xe9, 0x89,0xf5,0x40,0xe5,0x55,0x34);
MIDL_DEFINE_GUID(IID, IID_IPinFlowControl, 0xc56e9858, 0xdbf3, 0x4f6b, 0x81,0x19, 0x38,0x4a,0xf2,0x06,0x0d,0xeb);
MIDL_DEFINE_GUID(IID, IID_IGraphConfig, 0x03a1eb8e, 0x32bf, 0x4245, 0x85,0x02, 0x11,0x4d,0x08,0xa9,0xcb,0x88);
MIDL_DEFINE_GUID(IID, IID_IGraphConfigCallback, 0xade0fd60, 0xd19d, 0x11d2, 0xab,0xf6, 0x00,0xa0,0xc9,0x05,0xf3,0x75);
MIDL_DEFINE_GUID(IID, IID_IFilterChain, 0xdcfbdcf6, 0x0dc2, 0x45f5, 0x9a,0xb2, 0x7c,0x33,0x0e,0xa0,0x9c,0x29);
MIDL_DEFINE_GUID(IID, IID_IVMRImagePresenter, 0xce704fe7, 0xe71e, 0x41fb, 0xba,0xa2, 0xc4,0x40,0x3e,0x11,0x82,0xf5);
MIDL_DEFINE_GUID(IID, IID_IVMRSurfaceAllocator, 0x31ce832e, 0x4484, 0x458b, 0x8c,0xca, 0xf4,0xd7,0xe3,0xdb,0x0b,0x52);
MIDL_DEFINE_GUID(IID, IID_IVMRSurfaceAllocatorNotify, 0xaada05a8, 0x5a4e, 0x4729, 0xaf,0x0b, 0xce,0xa2,0x7a,0xed,0x51,0xe2);
MIDL_DEFINE_GUID(IID, IID_IVMRWindowlessControl, 0x0eb1088c, 0x4dcd, 0x46f0, 0x87,0x8f, 0x39,0xda,0xe8,0x6a,0x51,0xb7);
MIDL_DEFINE_GUID(IID, IID_IVMRMixerControl, 0x1c1a17b0, 0xbed0, 0x415d, 0x97,0x4b, 0xdc,0x66,0x96,0x13,0x15,0x99);
MIDL_DEFINE_GUID(IID, IID_IVMRMonitorConfig, 0x9cf0b1b6, 0xfbaa, 0x4b7f, 0x88,0xcf, 0xcf,0x1f,0x13,0x0a,0x0d,0xce);
MIDL_DEFINE_GUID(IID, IID_IVMRFilterConfig, 0x9e5530c5, 0x7034, 0x48b4, 0xbb,0x46, 0x0b,0x8a,0x6e,0xfc,0x8e,0x36);
MIDL_DEFINE_GUID(IID, IID_IVMRAspectRatioControl, 0xede80b5c, 0xbad6, 0x4623, 0xb5,0x37, 0x65,0x58,0x6c,0x9f,0x8d,0xfd);
MIDL_DEFINE_GUID(IID, IID_IVMRDeinterlaceControl, 0xbb057577, 0x0db8, 0x4e6a, 0x87,0xa7, 0x1a,0x8c,0x9a,0x50,0x5a,0x0f);
MIDL_DEFINE_GUID(IID, IID_IVMRMixerBitmap, 0x1e673275, 0x0257, 0x40aa, 0xaf,0x20, 0x7c,0x60,0x8d,0x4a,0x04,0x28);
MIDL_DEFINE_GUID(IID, IID_IVMRImageCompositor, 0x7a4fb5af, 0x479f, 0x4074, 0xbb,0x40, 0xce,0x67,0x22,0xe4,0x3c,0x82);
MIDL_DEFINE_GUID(IID, IID_IVMRVideoStreamControl, 0x058d1f11, 0x2a54, 0x4bef, 0xbd,0x54, 0xdf,0x70,0x66,0x26,0xb7,0x27);
MIDL_DEFINE_GUID(IID, IID_IVMRImagePresenterConfig, 0x9f3a1c85, 0x8555, 0x49ba, 0x93,0x5f, 0xbe,0x5b,0x5b,0x29,0xd1,0x78);
MIDL_DEFINE_GUID(IID, IID_IVMRImagePresenterExclModeConfig, 0xe6f7ce40, 0x4673, 0x44f1, 0x8f,0x77, 0x54,0x99,0xd6,0x8c,0xb4,0xea);
MIDL_DEFINE_GUID(IID, IID_IVPManager, 0xaac18c18, 0xe186, 0x46d2, 0x82,0x5d, 0xa1,0xf8,0xdc,0x8e,0x39,0x5a);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID