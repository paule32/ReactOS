/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/dll/win32/actxprxy/actxprxy_objsafe.idl - Do not edit ***/

#define __midl_proxy

#ifdef __REACTOS__
#define WIN32_NO_STATUS
#define WIN32_LEAN_AND_MEAN
#endif

#include "objbase.h"

#ifndef DECLSPEC_HIDDEN
#define DECLSPEC_HIDDEN
#endif

#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif

#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error This code needs a newer version of rpcproxy.h
#endif /* __RPCPROXY_H_VERSION__ */

#include "actxprxy_objsafe_p.h"

#ifndef USE_COMPILER_EXCEPTIONS

#include "wine/exception.h"
#undef RpcTryExcept
#undef RpcExcept
#undef RpcEndExcept
#undef RpcTryFinally
#undef RpcFinally
#undef RpcEndFinally
#undef RpcExceptionCode
#undef RpcAbnormalTermination

struct __exception_frame;
typedef int (*__filter_func)(struct __exception_frame *);
typedef void (*__finally_func)(struct __exception_frame *);

#define __DECL_EXCEPTION_FRAME \
    EXCEPTION_REGISTRATION_RECORD frame; \
    __filter_func                 filter; \
    __finally_func                finally; \
    sigjmp_buf                    jmp; \
    DWORD                         code; \
    unsigned char                 abnormal_termination; \
    unsigned char                 filter_level; \
    unsigned char                 finally_level;

struct __exception_frame
{
    __DECL_EXCEPTION_FRAME
};

static inline void __widl_unwind_target(void)
{
    struct __exception_frame *exc_frame = (struct __exception_frame *)__wine_get_frame();
    if (exc_frame->finally_level > exc_frame->filter_level)
    {
        exc_frame->abnormal_termination = 1;
        exc_frame->finally( exc_frame );
        __wine_pop_frame( &exc_frame->frame );
    }
    exc_frame->filter_level = 0;
    siglongjmp( exc_frame->jmp, 1 );
}

static DWORD __widl_exception_handler( EXCEPTION_RECORD *record,
                                       EXCEPTION_REGISTRATION_RECORD *frame,
                                       CONTEXT *context,
                                       EXCEPTION_REGISTRATION_RECORD **pdispatcher )
{
    struct __exception_frame *exc_frame = (struct __exception_frame *)frame;

    if (record->ExceptionFlags & (EH_UNWINDING | EH_EXIT_UNWIND | EH_NESTED_CALL))
    {
        if (exc_frame->finally_level && (record->ExceptionFlags & (EH_UNWINDING | EH_EXIT_UNWIND)))
        {
            exc_frame->abnormal_termination = 1;
            exc_frame->finally( exc_frame );
        }
        return ExceptionContinueSearch;
    }
    exc_frame->code = record->ExceptionCode;
    if (exc_frame->filter_level && exc_frame->filter( exc_frame ) == EXCEPTION_EXECUTE_HANDLER)
        __wine_rtl_unwind( frame, record, __widl_unwind_target );
    return ExceptionContinueSearch;
}

#define RpcTryExcept \
    if (!sigsetjmp( __frame->jmp, 0 )) \
    { \
        if (!__frame->finally_level) \
            __wine_push_frame( &__frame->frame ); \
        __frame->filter_level = __frame->finally_level + 1;

#define RpcExcept(expr) \
        if (!__frame->finally_level) \
            __wine_pop_frame( &__frame->frame ); \
        __frame->filter_level = 0; \
    } \
    else \

#define RpcEndExcept

#define RpcExceptionCode() (__frame->code)

#define RpcTryFinally \
    if (!__frame->filter_level) \
        __wine_push_frame( &__frame->frame ); \
    __frame->finally_level = __frame->filter_level + 1;

#define RpcFinally \
    if (!__frame->filter_level) \
        __wine_pop_frame( &__frame->frame ); \
    __frame->finally_level = 0;

#define RpcEndFinally

#define RpcAbnormalTermination() (__frame->abnormal_termination)

#define RpcExceptionInit(filter_func,finally_func) \
    do { \
        __frame->frame.Handler = __widl_exception_handler; \
        __frame->filter = (__filter_func)(filter_func); \
        __frame->finally = (__finally_func)(finally_func); \
        __frame->abnormal_termination = 0; \
        __frame->filter_level = 0; \
        __frame->finally_level = 0; \
    } while (0)

#else /* USE_COMPILER_EXCEPTIONS */

#define RpcExceptionInit(filter_func,finally_func) \
    do { (void)(filter_func); } while(0)

#define __DECL_EXCEPTION_FRAME \
    DWORD code;

#endif /* USE_COMPILER_EXCEPTIONS */

struct __proxy_frame
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
    void             *This;
};

static int __proxy_filter( struct __proxy_frame *__frame )
{
    return (__frame->_StubMsg.dwStubPhase != PROXY_SENDRECEIVE);
}

#define TYPE_FORMAT_STRING_SIZE 37
#define PROC_FORMAT_STRING_SIZE 25

typedef struct _MIDL_TYPE_FORMAT_STRING
{
    short Pad;
    unsigned char Format[TYPE_FORMAT_STRING_SIZE];
} MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
{
    short Pad;
    unsigned char Format[PROC_FORMAT_STRING_SIZE];
} MIDL_PROC_FORMAT_STRING;


static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;

static const MIDL_STUB_DESC Object_StubDesc;

/*****************************************************************************
 * IObjectSafety interface
 */
static void __finally_IObjectSafety_GetInterfaceSafetyOptions_Proxy( struct __proxy_frame *__frame )
{
    NdrProxyFreeBuffer( __frame->This, &__frame->_StubMsg );
}

HRESULT STDMETHODCALLTYPE IObjectSafety_GetInterfaceSafetyOptions_Proxy(
    IObjectSafety* This,
    REFIID riid,
    DWORD *pdwSupportedOptions,
    DWORD *pdwEnabledOptions)
{
    struct __proxy_frame __f, * const __frame = &__f;
    HRESULT _RetVal;
    RPC_MESSAGE _RpcMessage;

    RpcExceptionInit( __proxy_filter, __finally_IObjectSafety_GetInterfaceSafetyOptions_Proxy );
    __frame->This = This;
    RpcTryExcept
    {
        NdrProxyInitialize(This, &_RpcMessage, &__frame->_StubMsg, &Object_StubDesc, 3);
        if (!riid) RpcRaiseException(RPC_X_NULL_REF_POINTER);
        if (!pdwSupportedOptions) RpcRaiseException(RPC_X_NULL_REF_POINTER);
        if (!pdwEnabledOptions) RpcRaiseException(RPC_X_NULL_REF_POINTER);
        RpcTryFinally
        {
            __frame->_StubMsg.BufferLength = 20;
            NdrProxyGetBuffer(This, &__frame->_StubMsg);
            NdrSimpleStructMarshall(
                &__frame->_StubMsg,
                (unsigned char *)riid,
                (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[8]);

            NdrProxySendReceive(This, &__frame->_StubMsg);

            __frame->_StubMsg.BufferStart = _RpcMessage.Buffer;
            __frame->_StubMsg.BufferEnd   = __frame->_StubMsg.BufferStart + _RpcMessage.BufferLength;

            if ((_RpcMessage.DataRepresentation & 0xffff) != NDR_LOCAL_DATA_REPRESENTATION)
                NdrConvert( &__frame->_StubMsg, &__MIDL_ProcFormatString.Format[0]);

            __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
            if (__frame->_StubMsg.Buffer + sizeof(DWORD) > __frame->_StubMsg.BufferEnd)
            {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
            *pdwSupportedOptions = *(DWORD *)__frame->_StubMsg.Buffer;
            __frame->_StubMsg.Buffer += sizeof(DWORD);

            __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
            if (__frame->_StubMsg.Buffer + sizeof(DWORD) > __frame->_StubMsg.BufferEnd)
            {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
            *pdwEnabledOptions = *(DWORD *)__frame->_StubMsg.Buffer;
            __frame->_StubMsg.Buffer += sizeof(DWORD);

            __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
            if (__frame->_StubMsg.Buffer + sizeof(HRESULT) > __frame->_StubMsg.BufferEnd)
            {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
            _RetVal = *(HRESULT *)__frame->_StubMsg.Buffer;
            __frame->_StubMsg.Buffer += sizeof(HRESULT);

        }
        RpcFinally
        {
            __finally_IObjectSafety_GetInterfaceSafetyOptions_Proxy( __frame );
        }
        RpcEndFinally
    }
    RpcExcept(__frame->_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
    {
        NdrClearOutParameters( &__frame->_StubMsg, &__MIDL_TypeFormatString.Format[24], (void *)pdwSupportedOptions );

        NdrClearOutParameters( &__frame->_StubMsg, &__MIDL_TypeFormatString.Format[28], (void *)pdwEnabledOptions );

        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
    }
    RpcEndExcept
    return _RetVal;
}

struct __frame_IObjectSafety_GetInterfaceSafetyOptions_Stub
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
    IObjectSafety * _This;
    HRESULT _RetVal;
    REFIID riid;
    DWORD _W0;
    DWORD * pdwSupportedOptions;
    DWORD _W1;
    DWORD * pdwEnabledOptions;
};

static void __finally_IObjectSafety_GetInterfaceSafetyOptions_Stub( struct __frame_IObjectSafety_GetInterfaceSafetyOptions_Stub *__frame )
{



}

void __RPC_STUB IObjectSafety_GetInterfaceSafetyOptions_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD* _pdwStubPhase)
{
    struct __frame_IObjectSafety_GetInterfaceSafetyOptions_Stub __f, * const __frame = &__f;

    __frame->_This = (IObjectSafety*)((CStdStubBuffer*)This)->pvServerObject;

    NdrStubInitialize(_pRpcMessage, &__frame->_StubMsg, &Object_StubDesc, _pRpcChannelBuffer);

    RpcExceptionInit( 0, __finally_IObjectSafety_GetInterfaceSafetyOptions_Stub );
    __frame->riid = 0;
    __frame->pdwSupportedOptions = 0;
    __frame->pdwEnabledOptions = 0;

    RpcTryFinally
    {
        if ((_pRpcMessage->DataRepresentation & 0xffff) != NDR_LOCAL_DATA_REPRESENTATION)
            NdrConvert( &__frame->_StubMsg, &__MIDL_ProcFormatString.Format[0]);

        NdrSimpleStructUnmarshall(
            &__frame->_StubMsg,
            (unsigned char **)&__frame->riid,
            (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[8],
            0);


        __frame->pdwSupportedOptions = &__frame->_W0;
        __frame->_W0 = 0;
        __frame->pdwEnabledOptions = &__frame->_W1;
        __frame->_W1 = 0;

        *_pdwStubPhase = STUB_CALL_SERVER;

        __frame->_RetVal = __frame->_This->lpVtbl->GetInterfaceSafetyOptions(__frame->_This, __frame->riid, __frame->pdwSupportedOptions, __frame->pdwEnabledOptions);

        *_pdwStubPhase = STUB_MARSHAL;

        __frame->_StubMsg.BufferLength = 24;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &__frame->_StubMsg);
        MIDL_memset(__frame->_StubMsg.Buffer, 0, (0x4 - (ULONG_PTR)__frame->_StubMsg.Buffer) & 0x3);
        __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
        *(DWORD *)__frame->_StubMsg.Buffer = *__frame->pdwSupportedOptions;
        __frame->_StubMsg.Buffer += sizeof(DWORD);

        MIDL_memset(__frame->_StubMsg.Buffer, 0, (0x4 - (ULONG_PTR)__frame->_StubMsg.Buffer) & 0x3);
        __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
        *(DWORD *)__frame->_StubMsg.Buffer = *__frame->pdwEnabledOptions;
        __frame->_StubMsg.Buffer += sizeof(DWORD);


        MIDL_memset(__frame->_StubMsg.Buffer, 0, (0x4 - (ULONG_PTR)__frame->_StubMsg.Buffer) & 0x3);
        __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
        *(HRESULT *)__frame->_StubMsg.Buffer = __frame->_RetVal;
        __frame->_StubMsg.Buffer += sizeof(HRESULT);

    }
    RpcFinally
    {
        __finally_IObjectSafety_GetInterfaceSafetyOptions_Stub( __frame );
    }
    RpcEndFinally
    _pRpcMessage->BufferLength = __frame->_StubMsg.Buffer - (unsigned char *)_pRpcMessage->Buffer;
}

static void __finally_IObjectSafety_SetInterfaceSafetyOptions_Proxy( struct __proxy_frame *__frame )
{
    NdrProxyFreeBuffer( __frame->This, &__frame->_StubMsg );
}

HRESULT STDMETHODCALLTYPE IObjectSafety_SetInterfaceSafetyOptions_Proxy(
    IObjectSafety* This,
    REFIID riid,
    DWORD dwOptionSetMask,
    DWORD dwEnabledOptions)
{
    struct __proxy_frame __f, * const __frame = &__f;
    HRESULT _RetVal;
    RPC_MESSAGE _RpcMessage;

    RpcExceptionInit( __proxy_filter, __finally_IObjectSafety_SetInterfaceSafetyOptions_Proxy );
    __frame->This = This;
    RpcTryExcept
    {
        NdrProxyInitialize(This, &_RpcMessage, &__frame->_StubMsg, &Object_StubDesc, 4);
        if (!riid) RpcRaiseException(RPC_X_NULL_REF_POINTER);
        RpcTryFinally
        {
            __frame->_StubMsg.BufferLength = 36;
            NdrProxyGetBuffer(This, &__frame->_StubMsg);
            NdrSimpleStructMarshall(
                &__frame->_StubMsg,
                (unsigned char *)riid,
                (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[8]);

            MIDL_memset(__frame->_StubMsg.Buffer, 0, (0x4 - (ULONG_PTR)__frame->_StubMsg.Buffer) & 0x3);
            __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
            *(DWORD *)__frame->_StubMsg.Buffer = dwOptionSetMask;
            __frame->_StubMsg.Buffer += sizeof(DWORD);

            MIDL_memset(__frame->_StubMsg.Buffer, 0, (0x4 - (ULONG_PTR)__frame->_StubMsg.Buffer) & 0x3);
            __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
            *(DWORD *)__frame->_StubMsg.Buffer = dwEnabledOptions;
            __frame->_StubMsg.Buffer += sizeof(DWORD);

            NdrProxySendReceive(This, &__frame->_StubMsg);

            __frame->_StubMsg.BufferStart = _RpcMessage.Buffer;
            __frame->_StubMsg.BufferEnd   = __frame->_StubMsg.BufferStart + _RpcMessage.BufferLength;

            if ((_RpcMessage.DataRepresentation & 0xffff) != NDR_LOCAL_DATA_REPRESENTATION)
                NdrConvert( &__frame->_StubMsg, &__MIDL_ProcFormatString.Format[14]);

            __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
            if (__frame->_StubMsg.Buffer + sizeof(HRESULT) > __frame->_StubMsg.BufferEnd)
            {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
            _RetVal = *(HRESULT *)__frame->_StubMsg.Buffer;
            __frame->_StubMsg.Buffer += sizeof(HRESULT);

        }
        RpcFinally
        {
            __finally_IObjectSafety_SetInterfaceSafetyOptions_Proxy( __frame );
        }
        RpcEndFinally
    }
    RpcExcept(__frame->_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
    {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
    }
    RpcEndExcept
    return _RetVal;
}

struct __frame_IObjectSafety_SetInterfaceSafetyOptions_Stub
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
    IObjectSafety * _This;
    HRESULT _RetVal;
    REFIID riid;
    DWORD dwOptionSetMask;
    DWORD dwEnabledOptions;
};

static void __finally_IObjectSafety_SetInterfaceSafetyOptions_Stub( struct __frame_IObjectSafety_SetInterfaceSafetyOptions_Stub *__frame )
{



}

void __RPC_STUB IObjectSafety_SetInterfaceSafetyOptions_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD* _pdwStubPhase)
{
    struct __frame_IObjectSafety_SetInterfaceSafetyOptions_Stub __f, * const __frame = &__f;

    __frame->_This = (IObjectSafety*)((CStdStubBuffer*)This)->pvServerObject;

    NdrStubInitialize(_pRpcMessage, &__frame->_StubMsg, &Object_StubDesc, _pRpcChannelBuffer);

    RpcExceptionInit( 0, __finally_IObjectSafety_SetInterfaceSafetyOptions_Stub );
    __frame->riid = 0;

    RpcTryFinally
    {
        if ((_pRpcMessage->DataRepresentation & 0xffff) != NDR_LOCAL_DATA_REPRESENTATION)
            NdrConvert( &__frame->_StubMsg, &__MIDL_ProcFormatString.Format[14]);

        NdrSimpleStructUnmarshall(
            &__frame->_StubMsg,
            (unsigned char **)&__frame->riid,
            (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[8],
            0);

        __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
        if (__frame->_StubMsg.Buffer + sizeof(DWORD) > __frame->_StubMsg.BufferEnd)
        {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
        }
        __frame->dwOptionSetMask = *(DWORD *)__frame->_StubMsg.Buffer;
        __frame->_StubMsg.Buffer += sizeof(DWORD);

        __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
        if (__frame->_StubMsg.Buffer + sizeof(DWORD) > __frame->_StubMsg.BufferEnd)
        {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
        }
        __frame->dwEnabledOptions = *(DWORD *)__frame->_StubMsg.Buffer;
        __frame->_StubMsg.Buffer += sizeof(DWORD);


        *_pdwStubPhase = STUB_CALL_SERVER;

        __frame->_RetVal = __frame->_This->lpVtbl->SetInterfaceSafetyOptions(__frame->_This, __frame->riid, __frame->dwOptionSetMask, __frame->dwEnabledOptions);

        *_pdwStubPhase = STUB_MARSHAL;

        __frame->_StubMsg.BufferLength = 8;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &__frame->_StubMsg);

        MIDL_memset(__frame->_StubMsg.Buffer, 0, (0x4 - (ULONG_PTR)__frame->_StubMsg.Buffer) & 0x3);
        __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
        *(HRESULT *)__frame->_StubMsg.Buffer = __frame->_RetVal;
        __frame->_StubMsg.Buffer += sizeof(HRESULT);

    }
    RpcFinally
    {
        __finally_IObjectSafety_SetInterfaceSafetyOptions_Stub( __frame );
    }
    RpcEndFinally
    _pRpcMessage->BufferLength = __frame->_StubMsg.Buffer - (unsigned char *)_pRpcMessage->Buffer;
}

static const unsigned short IObjectSafety_FormatStringOffsetTable[] =
{
    0,  /* IObjectSafety::GetInterfaceSafetyOptions */
    14,  /* IObjectSafety::SetInterfaceSafetyOptions */
};

static const CINTERFACE_PROXY_VTABLE(5) _IObjectSafetyProxyVtbl =
{
    {
        &IID_IObjectSafety,
    },
    {
        IUnknown_QueryInterface_Proxy,
        IUnknown_AddRef_Proxy,
        IUnknown_Release_Proxy,
        IObjectSafety_GetInterfaceSafetyOptions_Proxy,
        IObjectSafety_SetInterfaceSafetyOptions_Proxy,
    }
};

static const MIDL_SERVER_INFO IObjectSafety_ServerInfo =
{
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IObjectSafety_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
};

static const PRPC_STUB_FUNCTION IObjectSafety_table[] =
{
    IObjectSafety_GetInterfaceSafetyOptions_Stub,
    IObjectSafety_SetInterfaceSafetyOptions_Stub
};

static const CInterfaceStubVtbl _IObjectSafetyStubVtbl =
{
    {
        &IID_IObjectSafety,
        &IObjectSafety_ServerInfo,
        5,
        &IObjectSafety_table[-3]
    },
    {
        CStdStubBuffer_METHODS
    }
};

static const MIDL_STUB_DESC Object_StubDesc =
{
    0,
    NdrOleAllocate,
    NdrOleFree,
    {0}, 0, 0, 0, 0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x10001, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
};

#if !defined(__RPC_WIN32__)
#error Currently only Wine and WIN32 are supported.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
{
    0,
    {
/* 0 (parameter riid) */
        0x4d,    /* FC_IN_PARAM */
        0x01,
        NdrFcShort(0x14),	/* type offset = 20 */
/* 4 (parameter pdwSupportedOptions) */
        0x51,    /* FC_OUT_PARAM */
        0x01,
        NdrFcShort(0x18),	/* type offset = 24 */
/* 8 (parameter pdwEnabledOptions) */
        0x51,    /* FC_OUT_PARAM */
        0x01,
        NdrFcShort(0x1c),	/* type offset = 28 */
/* 12 (return value) */
        0x53,    /* FC_RETURN_PARAM_BASETYPE */
        0x08,    /* FC_LONG */
/* 14 (parameter riid) */
        0x4d,    /* FC_IN_PARAM */
        0x01,
        NdrFcShort(0x20),	/* type offset = 32 */
/* 18 (parameter dwOptionSetMask) */
        0x4e,    /* FC_IN_PARAM_BASETYPE */
        0x08,    /* FC_LONG */
/* 20 (parameter dwEnabledOptions) */
        0x4e,    /* FC_IN_PARAM_BASETYPE */
        0x08,    /* FC_LONG */
/* 22 (return value) */
        0x53,    /* FC_RETURN_PARAM_BASETYPE */
        0x08,    /* FC_LONG */
        0x0
    }
};

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
{
    0,
    {
        NdrFcShort(0x0),
/* 2 (unsigned char[8]) */
        0x1d,	/* FC_SMFARRAY */
        0x0,	/* 0 */
        NdrFcShort(0x8),	/* 8 */
        0x02,	/* FC_CHAR */
        0x5b,	/* FC_END */
/* 8 (IID) */
        0x15,	/* FC_STRUCT */
        0x3,	/* 3 */
        NdrFcShort(0x10),	/* 16 */
        0x08,	/* FC_LONG */
        0x06,	/* FC_SHORT */
        0x06,	/* FC_SHORT */
        0x4c,	/* FC_EMBEDDED_COMPLEX */
        0x0,
        NdrFcShort(0xfff1),	/* Offset= -15 (2) */
        0x5b,	/* FC_END */
/* 20 (REFIID) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xfff2),	/* Offset= -14 (8) */
/* 24 (DWORD *) */
        0x11, 0xc,	/* FC_RP [allocated_on_stack] [simple_pointer] */
        0x09,	/* FC_ULONG */
        0x5c,	/* FC_PAD */
/* 28 (DWORD *) */
        0x11, 0xc,	/* FC_RP [allocated_on_stack] [simple_pointer] */
        0x09,	/* FC_ULONG */
        0x5c,	/* FC_PAD */
/* 32 (REFIID) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xffe6),	/* Offset= -26 (8) */
        0x0
    }
};

static const CInterfaceProxyVtbl* const _actxprxy_objsafe_ProxyVtblList[] =
{
    (const CInterfaceProxyVtbl*)&_IObjectSafetyProxyVtbl,
    0
};

static const CInterfaceStubVtbl* const _actxprxy_objsafe_StubVtblList[] =
{
    &_IObjectSafetyStubVtbl,
    0
};

static PCInterfaceName const _actxprxy_objsafe_InterfaceNamesList[] =
{
    "IObjectSafety",
    0
};

static int __stdcall _actxprxy_objsafe_IID_Lookup(const IID* pIID, int* pIndex)
{
    int low = 0, high = 0;

    while (low <= high)
    {
        int pos = (low + high) / 2;
        int res = IID_GENERIC_CHECK_IID(_actxprxy_objsafe, pIID, pos);
        if (!res) { *pIndex = pos; return 1; }
        if (res > 0) low = pos + 1;
        else high = pos - 1;
    }
    return 0;
}

const ExtendedProxyFileInfo actxprxy_objsafe_ProxyFileInfo DECLSPEC_HIDDEN =
{
    (const PCInterfaceProxyVtblList*)_actxprxy_objsafe_ProxyVtblList,
    (const PCInterfaceStubVtblList*)_actxprxy_objsafe_StubVtblList,
    _actxprxy_objsafe_InterfaceNamesList,
    0,
    _actxprxy_objsafe_IID_Lookup,
    1,
    1,
    0,
    0,
    0,
    0
};
