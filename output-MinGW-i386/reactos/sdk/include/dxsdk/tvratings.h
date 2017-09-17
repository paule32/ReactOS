/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/sdk/include/dxsdk/tvratings.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#ifdef __REACTOS__
#define WIN32_LEAN_AND_MEAN
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __tvratings_h__
#define __tvratings_h__

/* Forward declarations */

#ifndef __IXDSToRat_FWD_DEFINED__
#define __IXDSToRat_FWD_DEFINED__
typedef interface IXDSToRat IXDSToRat;
#ifdef __cplusplus
interface IXDSToRat;
#endif /* __cplusplus */
#endif

#ifndef __IEvalRat_FWD_DEFINED__
#define __IEvalRat_FWD_DEFINED__
typedef interface IEvalRat IEvalRat;
#ifdef __cplusplus
interface IEvalRat;
#endif /* __cplusplus */
#endif

#ifndef __XDSToRat_FWD_DEFINED__
#define __XDSToRat_FWD_DEFINED__
#ifdef __cplusplus
typedef class XDSToRat XDSToRat;
#else
typedef struct XDSToRat XDSToRat;
#endif /* defined __cplusplus */
#endif /* defined __XDSToRat_FWD_DEFINED__ */

#ifndef __EvalRat_FWD_DEFINED__
#define __EvalRat_FWD_DEFINED__
#ifdef __cplusplus
typedef class EvalRat EvalRat;
#else
typedef struct EvalRat EvalRat;
#endif /* defined __cplusplus */
#endif /* defined __EvalRat_FWD_DEFINED__ */

/* Headers for imported files */

#include <oaidl.h>
#include <ocidl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum __WIDL_tvratings_generated_name_0000000F {
    MPAA = 0,
    US_TV = 1,
    Canadian_English = 2,
    Canadian_French = 3,
    Reserved4 = 4,
    System5 = 5,
    System6 = 6,
    Reserved7 = 7,
    TvRat_kSystems = 8,
    TvRat_SystemDontKnow = 255
} EnTvRat_System;
typedef enum __WIDL_tvratings_generated_name_00000010 {
    TvRat_0 = 0,
    TvRat_1 = 1,
    TvRat_2 = 2,
    TvRat_3 = 3,
    TvRat_4 = 4,
    TvRat_5 = 5,
    TvRat_6 = 6,
    TvRat_7 = 7,
    TvRat_kLevels = 8,
    TvRat_LevelDontKnow = 255
} EnTvRat_GenericLevel;
typedef enum __WIDL_tvratings_generated_name_00000011 {
    MPAA_NotApplicable = TvRat_0,
    MPAA_G = TvRat_1,
    MPAA_PG = TvRat_2,
    MPAA_PG13 = TvRat_3,
    MPAA_R = TvRat_4,
    MPAA_NC17 = TvRat_5,
    MPAA_X = TvRat_6,
    MPAA_NotRated = TvRat_7
} EnTvRat_MPAA;
typedef enum __WIDL_tvratings_generated_name_00000012 {
    US_TV_None = TvRat_0,
    US_TV_Y = TvRat_1,
    US_TV_Y7 = TvRat_2,
    US_TV_G = TvRat_3,
    US_TV_PG = TvRat_4,
    US_TV_14 = TvRat_5,
    US_TV_MA = TvRat_6,
    US_TV_None7 = TvRat_7
} EnTvRat_US_TV;
typedef enum __WIDL_tvratings_generated_name_00000013 {
    CAE_TV_Exempt = TvRat_0,
    CAE_TV_C = TvRat_1,
    CAE_TV_C8 = TvRat_2,
    CAE_TV_G = TvRat_3,
    CAE_TV_PG = TvRat_4,
    CAE_TV_14 = TvRat_5,
    CAE_TV_18 = TvRat_6,
    CAE_TV_Reserved = TvRat_7
} EnTvRat_CAE_TV;
typedef enum __WIDL_tvratings_generated_name_00000014 {
    CAF_TV_Exempt = TvRat_0,
    CAF_TV_G = TvRat_1,
    CAF_TV_8 = TvRat_2,
    CAF_TV_13 = TvRat_3,
    CAF_TV_16 = TvRat_4,
    CAF_TV_18 = TvRat_5,
    CAF_TV_Reserved6 = TvRat_6,
    CAF_TV_Reserved = TvRat_7
} EnTvRat_CAF_TV;
typedef enum __WIDL_tvratings_generated_name_00000015 {
    BfAttrNone = 0,
    BfIsBlocked = 1,
    BfIsAttr_1 = 2,
    BfIsAttr_2 = 4,
    BfIsAttr_3 = 8,
    BfIsAttr_4 = 16,
    BfIsAttr_5 = 32,
    BfIsAttr_6 = 64,
    BfIsAttr_7 = 128,
    BfValidAttrSubmask = 255
} BfEnTvRat_GenericAttributes;
typedef enum __WIDL_tvratings_generated_name_00000016 {
    US_TV_IsBlocked = BfIsBlocked,
    US_TV_IsViolent = BfIsAttr_1,
    US_TV_IsSexualSituation = BfIsAttr_2,
    US_TV_IsAdultLanguage = BfIsAttr_3,
    US_TV_IsSexuallySuggestiveDialog = BfIsAttr_4,
    US_TV_ValidAttrSubmask = 31
} BfEnTvRat_Attributes_US_TV;
typedef enum __WIDL_tvratings_generated_name_00000017 {
    MPAA_IsBlocked = BfIsBlocked,
    MPAA_ValidAttrSubmask = 1
} BfEnTvRat_Attributes_MPAA;
typedef enum __WIDL_tvratings_generated_name_00000018 {
    CAE_IsBlocked = BfIsBlocked,
    CAE_ValidAttrSubmask = 1
} BfEnTvRat_Attributes_CAE_TV;
typedef enum __WIDL_tvratings_generated_name_00000019 {
    CAF_IsBlocked = BfIsBlocked,
    CAF_ValidAttrSubmask = 1
} BfEnTvRat_Attributes_CAF_TV;
/*****************************************************************************
 * IXDSToRat interface
 */
#ifndef __IXDSToRat_INTERFACE_DEFINED__
#define __IXDSToRat_INTERFACE_DEFINED__

DEFINE_GUID(IID_IXDSToRat, 0xc5c5c5b0, 0x3abc, 0x11d6, 0xb2,0x5b, 0x00,0xc0,0x4f,0xa0,0xc0,0x26);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("c5c5c5b0-3abc-11d6-b25b-00c04fa0c026")
IXDSToRat : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE Init(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ParseXDSBytePair(
        BYTE byte1,
        BYTE byte2,
        EnTvRat_System *pEnSystem,
        EnTvRat_GenericLevel *pEnLevel,
        LONG *plBfEnAttributes) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IXDSToRat, 0xc5c5c5b0, 0x3abc, 0x11d6, 0xb2,0x5b, 0x00,0xc0,0x4f,0xa0,0xc0,0x26)
#endif
#else
typedef struct IXDSToRatVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IXDSToRat *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IXDSToRat *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IXDSToRat *This);

    /*** IDispatch methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTypeInfoCount)(
        IXDSToRat *This,
        UINT *pctinfo);

    HRESULT (STDMETHODCALLTYPE *GetTypeInfo)(
        IXDSToRat *This,
        UINT iTInfo,
        LCID lcid,
        ITypeInfo **ppTInfo);

    HRESULT (STDMETHODCALLTYPE *GetIDsOfNames)(
        IXDSToRat *This,
        REFIID riid,
        LPOLESTR *rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID *rgDispId);

    HRESULT (STDMETHODCALLTYPE *Invoke)(
        IXDSToRat *This,
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pDispParams,
        VARIANT *pVarResult,
        EXCEPINFO *pExcepInfo,
        UINT *puArgErr);

    /*** IXDSToRat methods ***/
    HRESULT (STDMETHODCALLTYPE *Init)(
        IXDSToRat *This);

    HRESULT (STDMETHODCALLTYPE *ParseXDSBytePair)(
        IXDSToRat *This,
        BYTE byte1,
        BYTE byte2,
        EnTvRat_System *pEnSystem,
        EnTvRat_GenericLevel *pEnLevel,
        LONG *plBfEnAttributes);

    END_INTERFACE
} IXDSToRatVtbl;

interface IXDSToRat {
    CONST_VTBL IXDSToRatVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IXDSToRat_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IXDSToRat_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IXDSToRat_Release(This) (This)->lpVtbl->Release(This)
/*** IDispatch methods ***/
#define IXDSToRat_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IXDSToRat_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IXDSToRat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IXDSToRat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
/*** IXDSToRat methods ***/
#define IXDSToRat_Init(This) (This)->lpVtbl->Init(This)
#define IXDSToRat_ParseXDSBytePair(This,byte1,byte2,pEnSystem,pEnLevel,plBfEnAttributes) (This)->lpVtbl->ParseXDSBytePair(This,byte1,byte2,pEnSystem,pEnLevel,plBfEnAttributes)
#else
/*** IUnknown methods ***/
FORCEINLINE HRESULT IXDSToRat_QueryInterface(IXDSToRat* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
FORCEINLINE ULONG IXDSToRat_AddRef(IXDSToRat* This) {
    return This->lpVtbl->AddRef(This);
}
FORCEINLINE ULONG IXDSToRat_Release(IXDSToRat* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispatch methods ***/
FORCEINLINE HRESULT IXDSToRat_GetTypeInfoCount(IXDSToRat* This,UINT *pctinfo) {
    return This->lpVtbl->GetTypeInfoCount(This,pctinfo);
}
FORCEINLINE HRESULT IXDSToRat_GetTypeInfo(IXDSToRat* This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) {
    return This->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo);
}
FORCEINLINE HRESULT IXDSToRat_GetIDsOfNames(IXDSToRat* This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) {
    return This->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId);
}
FORCEINLINE HRESULT IXDSToRat_Invoke(IXDSToRat* This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) {
    return This->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}
/*** IXDSToRat methods ***/
FORCEINLINE HRESULT IXDSToRat_Init(IXDSToRat* This) {
    return This->lpVtbl->Init(This);
}
FORCEINLINE HRESULT IXDSToRat_ParseXDSBytePair(IXDSToRat* This,BYTE byte1,BYTE byte2,EnTvRat_System *pEnSystem,EnTvRat_GenericLevel *pEnLevel,LONG *plBfEnAttributes) {
    return This->lpVtbl->ParseXDSBytePair(This,byte1,byte2,pEnSystem,pEnLevel,plBfEnAttributes);
}
#endif
#endif

#endif

HRESULT STDMETHODCALLTYPE IXDSToRat_Init_Proxy(
    IXDSToRat* This);
void __RPC_STUB IXDSToRat_Init_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IXDSToRat_ParseXDSBytePair_Proxy(
    IXDSToRat* This,
    BYTE byte1,
    BYTE byte2,
    EnTvRat_System *pEnSystem,
    EnTvRat_GenericLevel *pEnLevel,
    LONG *plBfEnAttributes);
void __RPC_STUB IXDSToRat_ParseXDSBytePair_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IXDSToRat_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IEvalRat interface
 */
#ifndef __IEvalRat_INTERFACE_DEFINED__
#define __IEvalRat_INTERFACE_DEFINED__

DEFINE_GUID(IID_IEvalRat, 0xc5c5c5b1, 0x3abc, 0x11d6, 0xb2,0x5b, 0x00,0xc0,0x4f,0xa0,0xc0,0x26);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("c5c5c5b1-3abc-11d6-b25b-00c04fa0c026")
IEvalRat : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE get_BlockedRatingAttributes(
        EnTvRat_System enSystem,
        EnTvRat_GenericLevel enLevel,
        LONG *plbfAttrs) = 0;

    virtual HRESULT STDMETHODCALLTYPE put_BlockedRatingAttributes(
        EnTvRat_System enSystem,
        EnTvRat_GenericLevel enLevel,
        LONG lbfAttrs) = 0;

    virtual HRESULT STDMETHODCALLTYPE get_BlockUnRated(
        BOOL *pfBlockUnRatedShows) = 0;

    virtual HRESULT STDMETHODCALLTYPE put_BlockUnRated(
        BOOL fBlockUnRatedShows) = 0;

    virtual HRESULT STDMETHODCALLTYPE MostRestrictiveRating(
        EnTvRat_System enSystem1,
        EnTvRat_GenericLevel enEnLevel1,
        LONG lbfEnAttr1,
        EnTvRat_System enSystem2,
        EnTvRat_GenericLevel enEnLevel2,
        LONG lbfEnAttr2,
        EnTvRat_System *penSystem,
        EnTvRat_GenericLevel *penEnLevel,
        LONG *plbfEnAttr) = 0;

    virtual HRESULT STDMETHODCALLTYPE TestRating(
        EnTvRat_System enShowSystem,
        EnTvRat_GenericLevel enShowLevel,
        LONG lbfEnShowAttributes) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IEvalRat, 0xc5c5c5b1, 0x3abc, 0x11d6, 0xb2,0x5b, 0x00,0xc0,0x4f,0xa0,0xc0,0x26)
#endif
#else
typedef struct IEvalRatVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IEvalRat *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IEvalRat *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IEvalRat *This);

    /*** IDispatch methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTypeInfoCount)(
        IEvalRat *This,
        UINT *pctinfo);

    HRESULT (STDMETHODCALLTYPE *GetTypeInfo)(
        IEvalRat *This,
        UINT iTInfo,
        LCID lcid,
        ITypeInfo **ppTInfo);

    HRESULT (STDMETHODCALLTYPE *GetIDsOfNames)(
        IEvalRat *This,
        REFIID riid,
        LPOLESTR *rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID *rgDispId);

    HRESULT (STDMETHODCALLTYPE *Invoke)(
        IEvalRat *This,
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pDispParams,
        VARIANT *pVarResult,
        EXCEPINFO *pExcepInfo,
        UINT *puArgErr);

    /*** IEvalRat methods ***/
    HRESULT (STDMETHODCALLTYPE *get_BlockedRatingAttributes)(
        IEvalRat *This,
        EnTvRat_System enSystem,
        EnTvRat_GenericLevel enLevel,
        LONG *plbfAttrs);

    HRESULT (STDMETHODCALLTYPE *put_BlockedRatingAttributes)(
        IEvalRat *This,
        EnTvRat_System enSystem,
        EnTvRat_GenericLevel enLevel,
        LONG lbfAttrs);

    HRESULT (STDMETHODCALLTYPE *get_BlockUnRated)(
        IEvalRat *This,
        BOOL *pfBlockUnRatedShows);

    HRESULT (STDMETHODCALLTYPE *put_BlockUnRated)(
        IEvalRat *This,
        BOOL fBlockUnRatedShows);

    HRESULT (STDMETHODCALLTYPE *MostRestrictiveRating)(
        IEvalRat *This,
        EnTvRat_System enSystem1,
        EnTvRat_GenericLevel enEnLevel1,
        LONG lbfEnAttr1,
        EnTvRat_System enSystem2,
        EnTvRat_GenericLevel enEnLevel2,
        LONG lbfEnAttr2,
        EnTvRat_System *penSystem,
        EnTvRat_GenericLevel *penEnLevel,
        LONG *plbfEnAttr);

    HRESULT (STDMETHODCALLTYPE *TestRating)(
        IEvalRat *This,
        EnTvRat_System enShowSystem,
        EnTvRat_GenericLevel enShowLevel,
        LONG lbfEnShowAttributes);

    END_INTERFACE
} IEvalRatVtbl;

interface IEvalRat {
    CONST_VTBL IEvalRatVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IEvalRat_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEvalRat_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEvalRat_Release(This) (This)->lpVtbl->Release(This)
/*** IDispatch methods ***/
#define IEvalRat_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IEvalRat_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IEvalRat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IEvalRat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
/*** IEvalRat methods ***/
#define IEvalRat_get_BlockedRatingAttributes(This,enSystem,enLevel,plbfAttrs) (This)->lpVtbl->get_BlockedRatingAttributes(This,enSystem,enLevel,plbfAttrs)
#define IEvalRat_put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs) (This)->lpVtbl->put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs)
#define IEvalRat_get_BlockUnRated(This,pfBlockUnRatedShows) (This)->lpVtbl->get_BlockUnRated(This,pfBlockUnRatedShows)
#define IEvalRat_put_BlockUnRated(This,fBlockUnRatedShows) (This)->lpVtbl->put_BlockUnRated(This,fBlockUnRatedShows)
#define IEvalRat_MostRestrictiveRating(This,enSystem1,enEnLevel1,lbfEnAttr1,enSystem2,enEnLevel2,lbfEnAttr2,penSystem,penEnLevel,plbfEnAttr) (This)->lpVtbl->MostRestrictiveRating(This,enSystem1,enEnLevel1,lbfEnAttr1,enSystem2,enEnLevel2,lbfEnAttr2,penSystem,penEnLevel,plbfEnAttr)
#define IEvalRat_TestRating(This,enShowSystem,enShowLevel,lbfEnShowAttributes) (This)->lpVtbl->TestRating(This,enShowSystem,enShowLevel,lbfEnShowAttributes)
#else
/*** IUnknown methods ***/
FORCEINLINE HRESULT IEvalRat_QueryInterface(IEvalRat* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
FORCEINLINE ULONG IEvalRat_AddRef(IEvalRat* This) {
    return This->lpVtbl->AddRef(This);
}
FORCEINLINE ULONG IEvalRat_Release(IEvalRat* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispatch methods ***/
FORCEINLINE HRESULT IEvalRat_GetTypeInfoCount(IEvalRat* This,UINT *pctinfo) {
    return This->lpVtbl->GetTypeInfoCount(This,pctinfo);
}
FORCEINLINE HRESULT IEvalRat_GetTypeInfo(IEvalRat* This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) {
    return This->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo);
}
FORCEINLINE HRESULT IEvalRat_GetIDsOfNames(IEvalRat* This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) {
    return This->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId);
}
FORCEINLINE HRESULT IEvalRat_Invoke(IEvalRat* This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) {
    return This->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}
/*** IEvalRat methods ***/
FORCEINLINE HRESULT IEvalRat_get_BlockedRatingAttributes(IEvalRat* This,EnTvRat_System enSystem,EnTvRat_GenericLevel enLevel,LONG *plbfAttrs) {
    return This->lpVtbl->get_BlockedRatingAttributes(This,enSystem,enLevel,plbfAttrs);
}
FORCEINLINE HRESULT IEvalRat_put_BlockedRatingAttributes(IEvalRat* This,EnTvRat_System enSystem,EnTvRat_GenericLevel enLevel,LONG lbfAttrs) {
    return This->lpVtbl->put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs);
}
FORCEINLINE HRESULT IEvalRat_get_BlockUnRated(IEvalRat* This,BOOL *pfBlockUnRatedShows) {
    return This->lpVtbl->get_BlockUnRated(This,pfBlockUnRatedShows);
}
FORCEINLINE HRESULT IEvalRat_put_BlockUnRated(IEvalRat* This,BOOL fBlockUnRatedShows) {
    return This->lpVtbl->put_BlockUnRated(This,fBlockUnRatedShows);
}
FORCEINLINE HRESULT IEvalRat_MostRestrictiveRating(IEvalRat* This,EnTvRat_System enSystem1,EnTvRat_GenericLevel enEnLevel1,LONG lbfEnAttr1,EnTvRat_System enSystem2,EnTvRat_GenericLevel enEnLevel2,LONG lbfEnAttr2,EnTvRat_System *penSystem,EnTvRat_GenericLevel *penEnLevel,LONG *plbfEnAttr) {
    return This->lpVtbl->MostRestrictiveRating(This,enSystem1,enEnLevel1,lbfEnAttr1,enSystem2,enEnLevel2,lbfEnAttr2,penSystem,penEnLevel,plbfEnAttr);
}
FORCEINLINE HRESULT IEvalRat_TestRating(IEvalRat* This,EnTvRat_System enShowSystem,EnTvRat_GenericLevel enShowLevel,LONG lbfEnShowAttributes) {
    return This->lpVtbl->TestRating(This,enShowSystem,enShowLevel,lbfEnShowAttributes);
}
#endif
#endif

#endif

HRESULT STDMETHODCALLTYPE IEvalRat_get_BlockedRatingAttributes_Proxy(
    IEvalRat* This,
    EnTvRat_System enSystem,
    EnTvRat_GenericLevel enLevel,
    LONG *plbfAttrs);
void __RPC_STUB IEvalRat_get_BlockedRatingAttributes_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IEvalRat_put_BlockedRatingAttributes_Proxy(
    IEvalRat* This,
    EnTvRat_System enSystem,
    EnTvRat_GenericLevel enLevel,
    LONG lbfAttrs);
void __RPC_STUB IEvalRat_put_BlockedRatingAttributes_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IEvalRat_get_BlockUnRated_Proxy(
    IEvalRat* This,
    BOOL *pfBlockUnRatedShows);
void __RPC_STUB IEvalRat_get_BlockUnRated_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IEvalRat_put_BlockUnRated_Proxy(
    IEvalRat* This,
    BOOL fBlockUnRatedShows);
void __RPC_STUB IEvalRat_put_BlockUnRated_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IEvalRat_MostRestrictiveRating_Proxy(
    IEvalRat* This,
    EnTvRat_System enSystem1,
    EnTvRat_GenericLevel enEnLevel1,
    LONG lbfEnAttr1,
    EnTvRat_System enSystem2,
    EnTvRat_GenericLevel enEnLevel2,
    LONG lbfEnAttr2,
    EnTvRat_System *penSystem,
    EnTvRat_GenericLevel *penEnLevel,
    LONG *plbfEnAttr);
void __RPC_STUB IEvalRat_MostRestrictiveRating_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IEvalRat_TestRating_Proxy(
    IEvalRat* This,
    EnTvRat_System enShowSystem,
    EnTvRat_GenericLevel enShowLevel,
    LONG lbfEnShowAttributes);
void __RPC_STUB IEvalRat_TestRating_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IEvalRat_INTERFACE_DEFINED__ */


DEFINE_GUID(LIBID_TVRATINGSLib, 0xc5c5c500, 0x3abc, 0x11d6, 0xb2,0x5b, 0x00,0xc0,0x4f,0xa0,0xc0,0x26);

/*****************************************************************************
 * XDSToRat coclass
 */

DEFINE_GUID(CLSID_XDSToRat, 0xc5c5c5f0, 0x3abc, 0x11d6, 0xb2,0x5b, 0x00,0xc0,0x4f,0xa0,0xc0,0x26);

#ifdef __cplusplus
class DECLSPEC_UUID("c5c5c5f0-3abc-11d6-b25b-00c04fa0c026") XDSToRat;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(XDSToRat, 0xc5c5c5f0, 0x3abc, 0x11d6, 0xb2,0x5b, 0x00,0xc0,0x4f,0xa0,0xc0,0x26)
#endif
#endif

/*****************************************************************************
 * EvalRat coclass
 */

DEFINE_GUID(CLSID_EvalRat, 0xc5c5c5f1, 0x3abc, 0x11d6, 0xb2,0x5b, 0x00,0xc0,0x4f,0xa0,0xc0,0x26);

#ifdef __cplusplus
class DECLSPEC_UUID("c5c5c5f1-3abc-11d6-b25b-00c04fa0c026") EvalRat;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(EvalRat, 0xc5c5c5f1, 0x3abc, 0x11d6, 0xb2,0x5b, 0x00,0xc0,0x4f,0xa0,0xc0,0x26)
#endif
#endif

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __tvratings_h__ */
