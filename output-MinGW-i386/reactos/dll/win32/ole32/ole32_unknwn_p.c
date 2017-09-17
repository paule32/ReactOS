/*** Autogenerated by WIDL <undefined version> from /home/jens/winos/reactos/dll/win32/ole32/ole32_unknwn.idl - Do not edit ***/

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

#include "ole32_unknwn_p.h"

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

#define TYPE_FORMAT_STRING_SIZE 35
#define PROC_FORMAT_STRING_SIZE 15

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
 * IClassFactory interface
 */
static void __finally_IClassFactory_RemoteCreateInstance_Proxy( struct __proxy_frame *__frame )
{
    NdrProxyFreeBuffer( __frame->This, &__frame->_StubMsg );
}

HRESULT STDMETHODCALLTYPE IClassFactory_RemoteCreateInstance_Proxy(
    IClassFactory* This,
    REFIID riid,
    IUnknown **ppvObject)
{
    struct __proxy_frame __f, * const __frame = &__f;
    HRESULT _RetVal;
    RPC_MESSAGE _RpcMessage;

    RpcExceptionInit( __proxy_filter, __finally_IClassFactory_RemoteCreateInstance_Proxy );
    __frame->This = This;
    if (ppvObject) MIDL_memset( ppvObject, 0, sizeof( *ppvObject ));
    RpcTryExcept
    {
        NdrProxyInitialize(This, &_RpcMessage, &__frame->_StubMsg, &Object_StubDesc, 3);
        if (!riid) RpcRaiseException(RPC_X_NULL_REF_POINTER);
        if (!ppvObject) RpcRaiseException(RPC_X_NULL_REF_POINTER);
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

            NdrPointerUnmarshall(
                &__frame->_StubMsg,
                (unsigned char **)&ppvObject,
                (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[30],
                0);

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
            __finally_IClassFactory_RemoteCreateInstance_Proxy( __frame );
        }
        RpcEndFinally
    }
    RpcExcept(__frame->_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
    {
        __frame->_StubMsg.MaxCount = (ULONG_PTR) riid;

        NdrClearOutParameters( &__frame->_StubMsg, &__MIDL_TypeFormatString.Format[30], (void *)ppvObject );

        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
    }
    RpcEndExcept
    return _RetVal;
}

struct __frame_IClassFactory_RemoteCreateInstance_Stub
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
    IClassFactory * _This;
    HRESULT _RetVal;
    REFIID riid;
    IUnknown *_W0;
    IUnknown ** ppvObject;
};

static void __finally_IClassFactory_RemoteCreateInstance_Stub( struct __frame_IClassFactory_RemoteCreateInstance_Stub *__frame )
{

    __frame->_StubMsg.MaxCount = (ULONG_PTR) __frame->riid;

    NdrPointerFree(
        &__frame->_StubMsg,
        (unsigned char *)__frame->ppvObject,
        (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[30]);

}

void __RPC_STUB IClassFactory_RemoteCreateInstance_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD* _pdwStubPhase)
{
    struct __frame_IClassFactory_RemoteCreateInstance_Stub __f, * const __frame = &__f;

    __frame->_This = (IClassFactory*)((CStdStubBuffer*)This)->pvServerObject;

    NdrStubInitialize(_pRpcMessage, &__frame->_StubMsg, &Object_StubDesc, _pRpcChannelBuffer);

    RpcExceptionInit( 0, __finally_IClassFactory_RemoteCreateInstance_Stub );
    __frame->riid = 0;
    __frame->ppvObject = 0;

    RpcTryFinally
    {
        if ((_pRpcMessage->DataRepresentation & 0xffff) != NDR_LOCAL_DATA_REPRESENTATION)
            NdrConvert( &__frame->_StubMsg, &__MIDL_ProcFormatString.Format[0]);

        NdrSimpleStructUnmarshall(
            &__frame->_StubMsg,
            (unsigned char **)&__frame->riid,
            (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[8],
            0);


        __frame->ppvObject = &__frame->_W0;
        __frame->_W0 = 0;

        *_pdwStubPhase = STUB_CALL_SERVER;

        __frame->_RetVal = IClassFactory_CreateInstance_Stub(__frame->_This, __frame->riid, __frame->ppvObject);

        *_pdwStubPhase = STUB_MARSHAL;

        __frame->_StubMsg.BufferLength = 8;
        __frame->_StubMsg.MaxCount = (ULONG_PTR) __frame->riid;

        NdrPointerBufferSize(
            &__frame->_StubMsg,
            (unsigned char *)__frame->ppvObject,
            (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[30]);

        NdrStubGetBuffer(This, _pRpcChannelBuffer, &__frame->_StubMsg);
        __frame->_StubMsg.MaxCount = (ULONG_PTR) __frame->riid;

        NdrPointerMarshall(
            &__frame->_StubMsg,
            (unsigned char *)__frame->ppvObject,
            (PFORMAT_STRING)&__MIDL_TypeFormatString.Format[30]);


        MIDL_memset(__frame->_StubMsg.Buffer, 0, (0x4 - (ULONG_PTR)__frame->_StubMsg.Buffer) & 0x3);
        __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
        *(HRESULT *)__frame->_StubMsg.Buffer = __frame->_RetVal;
        __frame->_StubMsg.Buffer += sizeof(HRESULT);

    }
    RpcFinally
    {
        __finally_IClassFactory_RemoteCreateInstance_Stub( __frame );
    }
    RpcEndFinally
    _pRpcMessage->BufferLength = __frame->_StubMsg.Buffer - (unsigned char *)_pRpcMessage->Buffer;
}

static void __finally_IClassFactory_RemoteLockServer_Proxy( struct __proxy_frame *__frame )
{
    NdrProxyFreeBuffer( __frame->This, &__frame->_StubMsg );
}

HRESULT STDMETHODCALLTYPE IClassFactory_RemoteLockServer_Proxy(
    IClassFactory* This,
    BOOL fLock)
{
    struct __proxy_frame __f, * const __frame = &__f;
    HRESULT _RetVal;
    RPC_MESSAGE _RpcMessage;

    RpcExceptionInit( __proxy_filter, __finally_IClassFactory_RemoteLockServer_Proxy );
    __frame->This = This;
    RpcTryExcept
    {
        NdrProxyInitialize(This, &_RpcMessage, &__frame->_StubMsg, &Object_StubDesc, 4);
        RpcTryFinally
        {
            __frame->_StubMsg.BufferLength = 8;
            NdrProxyGetBuffer(This, &__frame->_StubMsg);
            MIDL_memset(__frame->_StubMsg.Buffer, 0, (0x4 - (ULONG_PTR)__frame->_StubMsg.Buffer) & 0x3);
            __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
            *(BOOL *)__frame->_StubMsg.Buffer = fLock;
            __frame->_StubMsg.Buffer += sizeof(BOOL);

            NdrProxySendReceive(This, &__frame->_StubMsg);

            __frame->_StubMsg.BufferStart = _RpcMessage.Buffer;
            __frame->_StubMsg.BufferEnd   = __frame->_StubMsg.BufferStart + _RpcMessage.BufferLength;

            if ((_RpcMessage.DataRepresentation & 0xffff) != NDR_LOCAL_DATA_REPRESENTATION)
                NdrConvert( &__frame->_StubMsg, &__MIDL_ProcFormatString.Format[10]);

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
            __finally_IClassFactory_RemoteLockServer_Proxy( __frame );
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

struct __frame_IClassFactory_RemoteLockServer_Stub
{
    __DECL_EXCEPTION_FRAME
    MIDL_STUB_MESSAGE _StubMsg;
    IClassFactory * _This;
    HRESULT _RetVal;
    BOOL fLock;
};

static void __finally_IClassFactory_RemoteLockServer_Stub( struct __frame_IClassFactory_RemoteLockServer_Stub *__frame )
{

}

void __RPC_STUB IClassFactory_RemoteLockServer_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD* _pdwStubPhase)
{
    struct __frame_IClassFactory_RemoteLockServer_Stub __f, * const __frame = &__f;

    __frame->_This = (IClassFactory*)((CStdStubBuffer*)This)->pvServerObject;

    NdrStubInitialize(_pRpcMessage, &__frame->_StubMsg, &Object_StubDesc, _pRpcChannelBuffer);

    RpcExceptionInit( 0, __finally_IClassFactory_RemoteLockServer_Stub );

    RpcTryFinally
    {
        if ((_pRpcMessage->DataRepresentation & 0xffff) != NDR_LOCAL_DATA_REPRESENTATION)
            NdrConvert( &__frame->_StubMsg, &__MIDL_ProcFormatString.Format[10]);

        __frame->_StubMsg.Buffer = (unsigned char *)(((ULONG_PTR)__frame->_StubMsg.Buffer + 3) & ~0x3);
        if (__frame->_StubMsg.Buffer + sizeof(BOOL) > __frame->_StubMsg.BufferEnd)
        {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
        }
        __frame->fLock = *(BOOL *)__frame->_StubMsg.Buffer;
        __frame->_StubMsg.Buffer += sizeof(BOOL);


        *_pdwStubPhase = STUB_CALL_SERVER;

        __frame->_RetVal = IClassFactory_LockServer_Stub(__frame->_This, __frame->fLock);

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
        __finally_IClassFactory_RemoteLockServer_Stub( __frame );
    }
    RpcEndFinally
    _pRpcMessage->BufferLength = __frame->_StubMsg.Buffer - (unsigned char *)_pRpcMessage->Buffer;
}

static const unsigned short IClassFactory_FormatStringOffsetTable[] =
{
    0,  /* IClassFactory::RemoteCreateInstance */
    10,  /* IClassFactory::RemoteLockServer */
};

static const CINTERFACE_PROXY_VTABLE(5) _IClassFactoryProxyVtbl =
{
    {
        &IID_IClassFactory,
    },
    {
        IUnknown_QueryInterface_Proxy,
        IUnknown_AddRef_Proxy,
        IUnknown_Release_Proxy,
        IClassFactory_CreateInstance_Proxy,
        IClassFactory_LockServer_Proxy,
    }
};

static const MIDL_SERVER_INFO IClassFactory_ServerInfo =
{
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IClassFactory_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
};

static const PRPC_STUB_FUNCTION IClassFactory_table[] =
{
    IClassFactory_RemoteCreateInstance_Stub,
    IClassFactory_RemoteLockServer_Stub
};

static const CInterfaceStubVtbl _IClassFactoryStubVtbl =
{
    {
        &IID_IClassFactory,
        &IClassFactory_ServerInfo,
        5,
        &IClassFactory_table[-3]
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
/* 4 (parameter ppvObject) */
        0x51,    /* FC_OUT_PARAM */
        0x01,
        NdrFcShort(0x1e),	/* type offset = 30 */
/* 8 (return value) */
        0x53,    /* FC_RETURN_PARAM_BASETYPE */
        0x08,    /* FC_LONG */
/* 10 (parameter fLock) */
        0x4e,    /* FC_IN_PARAM_BASETYPE */
        0x08,    /* FC_LONG */
/* 12 (return value) */
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
/* 24 (IUnknown *) */
        0x2f,  /* FC_IP */
        0x5c,  /* FC_PAD */
        0x28,	/* Corr desc: parameter riid, FC_LONG */
        0x0,	/* no operators */
        NdrFcShort(0x4),	/* offset = 4 */
/* 30 (IUnknown **) */
        0x11, 0x14,		/* FC_RP [allocated_on_stack] [pointer_deref] */
        NdrFcShort(0xfff8),	/* Offset= -8 (24) */
        0x0
    }
};

static const CInterfaceProxyVtbl* const _ole32_unknwn_ProxyVtblList[] =
{
    (const CInterfaceProxyVtbl*)&_IClassFactoryProxyVtbl,
    0
};

static const CInterfaceStubVtbl* const _ole32_unknwn_StubVtblList[] =
{
    &_IClassFactoryStubVtbl,
    0
};

static PCInterfaceName const _ole32_unknwn_InterfaceNamesList[] =
{
    "IClassFactory",
    0
};

static int __stdcall _ole32_unknwn_IID_Lookup(const IID* pIID, int* pIndex)
{
    int low = 0, high = 0;

    while (low <= high)
    {
        int pos = (low + high) / 2;
        int res = IID_GENERIC_CHECK_IID(_ole32_unknwn, pIID, pos);
        if (!res) { *pIndex = pos; return 1; }
        if (res > 0) low = pos + 1;
        else high = pos - 1;
    }
    return 0;
}

const ExtendedProxyFileInfo ole32_unknwn_ProxyFileInfo DECLSPEC_HIDDEN =
{
    (const PCInterfaceProxyVtblList*)_ole32_unknwn_ProxyVtblList,
    (const PCInterfaceStubVtblList*)_ole32_unknwn_StubVtblList,
    _ole32_unknwn_InterfaceNamesList,
    0,
    _ole32_unknwn_IID_Lookup,
    1,
    1,
    0,
    0,
    0,
    0
};
