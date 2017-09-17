/*
 * Implementation of a generic ConnectionPoint object.
 *
 * Copyright 2000 Huw D M Davies for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 * NOTES:
 * See one exported function here is CreateConnectionPoint, see
 * comments just above that function for information.
 */

#include "precomp.h"

#include <assert.h>

WINE_DEFAULT_DEBUG_CHANNEL(ole);

#define MAXSINKS 10

/************************************************************************
 * Implementation of IConnectionPoint
 */
typedef struct ConnectionPointImpl {

  IConnectionPoint IConnectionPoint_iface;

  /* IUnknown of our main object*/
  IUnknown *Obj;

  /* Reference count */
  LONG ref;

  /* IID of sink interface */
  IID iid;

  /* Array of sink IUnknowns */
  IUnknown **sinks;
  DWORD maxSinks;

  DWORD nSinks;
} ConnectionPointImpl;

/************************************************************************
 * Implementation of IEnumConnections
 */
typedef struct EnumConnectionsImpl {

  IEnumConnections IEnumConnections_iface;

  LONG ref;

  /* IUnknown of ConnectionPoint, used for ref counting */
  IUnknown *pUnk;

  /* Connection Data */
  CONNECTDATA *pCD;
  DWORD nConns;

  /* Next connection to enumerate from */
  DWORD nCur;

} EnumConnectionsImpl;

static EnumConnectionsImpl *EnumConnectionsImpl_Construct(IUnknown *pUnk,
							  DWORD nSinks,
							  CONNECTDATA *pCD);

static inline ConnectionPointImpl *impl_from_IConnectionPoint(IConnectionPoint *iface)
{
  return CONTAINING_RECORD(iface, ConnectionPointImpl, IConnectionPoint_iface);
}

static inline EnumConnectionsImpl *impl_from_IEnumConnections(IEnumConnections *iface)
{
  return CONTAINING_RECORD(iface, EnumConnectionsImpl, IEnumConnections_iface);
}

/************************************************************************
 * ConnectionPointImpl_Destroy
 */
static void ConnectionPointImpl_Destroy(ConnectionPointImpl *Obj)
{
  DWORD i;
  for(i = 0; i < Obj->maxSinks; i++) {
    if(Obj->sinks[i]) {
      IUnknown_Release(Obj->sinks[i]);
      Obj->sinks[i] = NULL;
    }
  }
  HeapFree(GetProcessHeap(), 0, Obj->sinks);
  HeapFree(GetProcessHeap(), 0, Obj);
  return;
}

/************************************************************************
 * ConnectionPointImpl_QueryInterface (IUnknown)
 *
 * See Windows documentation for more details on IUnknown methods.
 */
static HRESULT WINAPI ConnectionPointImpl_QueryInterface(
  IConnectionPoint*  iface,
  REFIID  riid,
  void**  ppvObject)
{
  ConnectionPointImpl *This = impl_from_IConnectionPoint(iface);
  TRACE("(%p)->(%s, %p)\n", This, debugstr_guid(riid), ppvObject);

  /*
   * Perform a sanity check on the parameters.
   */
  if (!ppvObject)
    return E_INVALIDARG;

  /*
   * Initialize the return parameter.
   */
  *ppvObject = 0;


  if (IsEqualIID(&IID_IConnectionPoint, riid) || IsEqualIID(&IID_IUnknown, riid))
    *ppvObject = iface;

  /*
   * Check that we obtained an interface.
   */
  if ((*ppvObject)==0)
  {
    FIXME("() : asking for unsupported interface %s\n", debugstr_guid(riid));
    return E_NOINTERFACE;
  }

  IUnknown_AddRef((IUnknown*)*ppvObject);

  return S_OK;
}


/************************************************************************
 * ConnectionPointImpl_AddRef (IUnknown)
 *
 * See Windows documentation for more details on IUnknown methods.
 */
static ULONG WINAPI ConnectionPointImpl_AddRef(IConnectionPoint* iface)
{
  ConnectionPointImpl *This = impl_from_IConnectionPoint(iface);
  ULONG refCount = InterlockedIncrement(&This->ref);

  TRACE("(%p)->(ref before=%d)\n", This, refCount - 1);

  return refCount;
}

/************************************************************************
 * ConnectionPointImpl_Release (IUnknown)
 *
 * See Windows documentation for more details on IUnknown methods.
 */
static ULONG WINAPI ConnectionPointImpl_Release(
      IConnectionPoint* iface)
{
  ConnectionPointImpl *This = impl_from_IConnectionPoint(iface);
  ULONG refCount = InterlockedDecrement(&This->ref);

  TRACE("(%p)->(ref before=%d)\n", This, refCount + 1);

  /*
   * If the reference count goes down to 0, perform suicide.
   */
  if (!refCount) ConnectionPointImpl_Destroy(This);

  return refCount;
}

/************************************************************************
 * ConnectionPointImpl_GetConnectionInterface (IConnectionPoint)
 *
 */
static HRESULT WINAPI ConnectionPointImpl_GetConnectionInterface(
					       IConnectionPoint *iface,
					       IID              *piid)
{
  ConnectionPointImpl *This = impl_from_IConnectionPoint(iface);
  TRACE("(%p)->(%p) returning %s\n", This, piid, debugstr_guid(&(This->iid)));
  *piid = This->iid;
  return S_OK;
}

/************************************************************************
 * ConnectionPointImpl_GetConnectionPointContainer (IConnectionPoint)
 *
 */
static HRESULT WINAPI ConnectionPointImpl_GetConnectionPointContainer(
				      IConnectionPoint           *iface,
				      IConnectionPointContainer  **ppCPC)
{
  ConnectionPointImpl *This = impl_from_IConnectionPoint(iface);
  TRACE("(%p)->(%p)\n", This, ppCPC);

  return IUnknown_QueryInterface(This->Obj, &IID_IConnectionPointContainer, (void**)ppCPC);
}

/************************************************************************
 * ConnectionPointImpl_Advise (IConnectionPoint)
 *
 */
static HRESULT WINAPI ConnectionPointImpl_Advise(IConnectionPoint *iface,
						 IUnknown *lpUnk,
						 DWORD *pdwCookie)
{
  DWORD i;
  ConnectionPointImpl *This = impl_from_IConnectionPoint(iface);
  IUnknown *lpSink;
  TRACE("(%p)->(%p, %p)\n", This, lpUnk, pdwCookie);

  *pdwCookie = 0;
  if(FAILED(IUnknown_QueryInterface(lpUnk, &This->iid, (void**)&lpSink)))
    return CONNECT_E_CANNOTCONNECT;

  for(i = 0; i < This->maxSinks; i++) {
    if(This->sinks[i] == NULL)
      break;
  }
  if(i == This->maxSinks) {
    This->maxSinks += MAXSINKS;
    This->sinks = HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, This->sinks,
			      This->maxSinks * sizeof(IUnknown *));
  }
  This->sinks[i] = lpSink;
  This->nSinks++;
  *pdwCookie = i + 1;
  return S_OK;
}


/************************************************************************
 * ConnectionPointImpl_Unadvise (IConnectionPoint)
 *
 */
static HRESULT WINAPI ConnectionPointImpl_Unadvise(IConnectionPoint *iface,
						   DWORD dwCookie)
{
  ConnectionPointImpl *This = impl_from_IConnectionPoint(iface);
  TRACE("(%p)->(%d)\n", This, dwCookie);

  if(dwCookie == 0 || dwCookie > This->maxSinks) return E_INVALIDARG;

  if(This->sinks[dwCookie-1] == NULL) return CONNECT_E_NOCONNECTION;

  IUnknown_Release(This->sinks[dwCookie-1]);
  This->sinks[dwCookie-1] = NULL;
  This->nSinks--;
  return S_OK;
}

/************************************************************************
 * ConnectionPointImpl_EnumConnections (IConnectionPoint)
 *
 */
static HRESULT WINAPI ConnectionPointImpl_EnumConnections(
						    IConnectionPoint *iface,
						    LPENUMCONNECTIONS *ppEnum)
{
  ConnectionPointImpl *This = impl_from_IConnectionPoint(iface);
  CONNECTDATA *pCD;
  DWORD i, nextslot;
  EnumConnectionsImpl *EnumObj;
  HRESULT hr;

  TRACE("(%p)->(%p)\n", This, ppEnum);

  *ppEnum = NULL;

  if(This->nSinks == 0) return OLE_E_NOCONNECTION;

  pCD = HeapAlloc(GetProcessHeap(), 0, sizeof(CONNECTDATA) * This->nSinks);

  for(i = 0, nextslot = 0; i < This->maxSinks; i++) {
    if(This->sinks[i] != NULL) {
      pCD[nextslot].pUnk = This->sinks[i];
      pCD[nextslot].dwCookie = i + 1;
      nextslot++;
    }
  }
  assert(nextslot == This->nSinks);

  /* Bump the ref count of this object up by one.  It gets Released in
     IEnumConnections_Release */
  IConnectionPoint_AddRef(iface);

  EnumObj = EnumConnectionsImpl_Construct((IUnknown*)iface, This->nSinks, pCD);
  hr = IEnumConnections_QueryInterface(&EnumObj->IEnumConnections_iface,
                                       &IID_IEnumConnections, (void**)ppEnum);
  IEnumConnections_Release(&EnumObj->IEnumConnections_iface);

  HeapFree(GetProcessHeap(), 0, pCD);
  return hr;
}

static const IConnectionPointVtbl ConnectionPointImpl_VTable =
{
  ConnectionPointImpl_QueryInterface,
  ConnectionPointImpl_AddRef,
  ConnectionPointImpl_Release,
  ConnectionPointImpl_GetConnectionInterface,
  ConnectionPointImpl_GetConnectionPointContainer,
  ConnectionPointImpl_Advise,
  ConnectionPointImpl_Unadvise,
  ConnectionPointImpl_EnumConnections
};


static const IEnumConnectionsVtbl EnumConnectionsImpl_VTable;

/************************************************************************
 * EnumConnectionsImpl_Construct
 */
static EnumConnectionsImpl *EnumConnectionsImpl_Construct(IUnknown *pUnk,
							  DWORD nSinks,
							  CONNECTDATA *pCD)
{
  EnumConnectionsImpl *Obj = HeapAlloc(GetProcessHeap(), 0, sizeof(*Obj));
  DWORD i;

  Obj->IEnumConnections_iface.lpVtbl = &EnumConnectionsImpl_VTable;
  Obj->ref = 1;
  Obj->pUnk = pUnk;
  Obj->pCD = HeapAlloc(GetProcessHeap(), 0, nSinks * sizeof(CONNECTDATA));
  Obj->nConns = nSinks;
  Obj->nCur = 0;

  for(i = 0; i < nSinks; i++) {
    Obj->pCD[i] = pCD[i];
    IUnknown_AddRef(Obj->pCD[i].pUnk);
  }
  return Obj;
}

/************************************************************************
 * EnumConnectionsImpl_Destroy
 */
static void EnumConnectionsImpl_Destroy(EnumConnectionsImpl *Obj)
{
  DWORD i;

  for(i = 0; i < Obj->nConns; i++)
    IUnknown_Release(Obj->pCD[i].pUnk);

  HeapFree(GetProcessHeap(), 0, Obj->pCD);
  HeapFree(GetProcessHeap(), 0, Obj);
  return;
}

/************************************************************************
 * EnumConnectionsImpl_QueryInterface (IUnknown)
 *
 * See Windows documentation for more details on IUnknown methods.
 */
static HRESULT WINAPI EnumConnectionsImpl_QueryInterface(
  IEnumConnections*  iface,
  REFIID  riid,
  void**  ppvObject)
{
  ConnectionPointImpl *This = (ConnectionPointImpl *)iface;
  TRACE("(%p)->(%s, %p)\n", This, debugstr_guid(riid), ppvObject);

  /*
   * Perform a sanity check on the parameters.
   */
  if (!ppvObject)
    return E_INVALIDARG;

  /*
   * Initialize the return parameter.
   */
  *ppvObject = 0;

  if (IsEqualIID(&IID_IEnumConnections, riid) || IsEqualIID(&IID_IUnknown, riid))
    *ppvObject = iface;

  /*
   * Check that we obtained an interface.
   */
  if ((*ppvObject)==0)
  {
    FIXME("() : asking for unsupported interface %s\n", debugstr_guid(riid));
    return E_NOINTERFACE;
  }

  IUnknown_AddRef((IUnknown*)*ppvObject);

  return S_OK;
}


/************************************************************************
 * EnumConnectionsImpl_AddRef (IUnknown)
 *
 * See Windows documentation for more details on IUnknown methods.
 */
static ULONG WINAPI EnumConnectionsImpl_AddRef(IEnumConnections* iface)
{
  EnumConnectionsImpl *This = impl_from_IEnumConnections(iface);
  ULONG refCount = InterlockedIncrement(&This->ref);

  TRACE("(%p)->(ref before=%d)\n", This, refCount - 1);

  IUnknown_AddRef(This->pUnk);
  return refCount;
}

/************************************************************************
 * EnumConnectionsImpl_Release (IUnknown)
 *
 * See Windows documentation for more details on IUnknown methods.
 */
static ULONG WINAPI EnumConnectionsImpl_Release(IEnumConnections* iface)
{
  EnumConnectionsImpl *This = impl_from_IEnumConnections(iface);
  ULONG refCount = InterlockedDecrement(&This->ref);

  TRACE("(%p)->(ref before=%d)\n", This, refCount + 1);

  IUnknown_Release(This->pUnk);

  /*
   * If the reference count goes down to 0, perform suicide.
   */
  if (!refCount) EnumConnectionsImpl_Destroy(This);

  return refCount;
}

/************************************************************************
 * EnumConnectionsImpl_Next (IEnumConnections)
 *
 */
static HRESULT WINAPI EnumConnectionsImpl_Next(IEnumConnections* iface,
					       ULONG cConn, LPCONNECTDATA pCD,
					       ULONG *pEnum)
{
  EnumConnectionsImpl *This = impl_from_IEnumConnections(iface);
  DWORD nRet = 0;
  TRACE("(%p)->(%d, %p, %p)\n", This, cConn, pCD, pEnum);

  if(pEnum == NULL) {
    if(cConn != 1)
      return E_POINTER;
  } else
    *pEnum = 0;

  if(This->nCur >= This->nConns)
    return S_FALSE;

  while(This->nCur < This->nConns && cConn) {
    *pCD++ = This->pCD[This->nCur];
    IUnknown_AddRef(This->pCD[This->nCur].pUnk);
    This->nCur++;
    cConn--;
    nRet++;
  }

  if(pEnum)
    *pEnum = nRet;

  return S_OK;
}


/************************************************************************
 * EnumConnectionsImpl_Skip (IEnumConnections)
 *
 */
static HRESULT WINAPI EnumConnectionsImpl_Skip(IEnumConnections* iface,
					       ULONG cSkip)
{
  EnumConnectionsImpl *This = impl_from_IEnumConnections(iface);
  TRACE("(%p)->(%d)\n", This, cSkip);

  if(This->nCur + cSkip >= This->nConns)
    return S_FALSE;

  This->nCur += cSkip;

  return S_OK;
}


/************************************************************************
 * EnumConnectionsImpl_Reset (IEnumConnections)
 *
 */
static HRESULT WINAPI EnumConnectionsImpl_Reset(IEnumConnections* iface)
{
  EnumConnectionsImpl *This = impl_from_IEnumConnections(iface);
  TRACE("(%p)\n", This);

  This->nCur = 0;

  return S_OK;
}


/************************************************************************
 * EnumConnectionsImpl_Clone (IEnumConnections)
 *
 */
static HRESULT WINAPI EnumConnectionsImpl_Clone(IEnumConnections* iface,
						LPENUMCONNECTIONS *ppEnum)
{
  EnumConnectionsImpl *This = impl_from_IEnumConnections(iface);
  EnumConnectionsImpl *newObj;
  TRACE("(%p)->(%p)\n", This, ppEnum);

  newObj = EnumConnectionsImpl_Construct(This->pUnk, This->nConns, This->pCD);
  newObj->nCur = This->nCur;
  *ppEnum = &newObj->IEnumConnections_iface;
  IUnknown_AddRef(This->pUnk);
  return S_OK;
}

static const IEnumConnectionsVtbl EnumConnectionsImpl_VTable =
{
  EnumConnectionsImpl_QueryInterface,
  EnumConnectionsImpl_AddRef,
  EnumConnectionsImpl_Release,
  EnumConnectionsImpl_Next,
  EnumConnectionsImpl_Skip,
  EnumConnectionsImpl_Reset,
  EnumConnectionsImpl_Clone
};

/************************************************************************
 *
 *  The exported function to create the connection point.
 *  NB not a windows API
 *
 * PARAMS
 * pUnk [in] IUnknown of object to which the ConnectionPoint is associated.
 *           Needed to access IConnectionPointContainer.
 *
 * riid [in] IID of sink interface that this ConnectionPoint manages
 *
 * pCP [out] returns IConnectionPoint
 *
 */
HRESULT CreateConnectionPoint(IUnknown *pUnk, REFIID riid,
			      IConnectionPoint **pCP)
{
  ConnectionPointImpl *Obj;

  TRACE("(%p %s %p)\n", pUnk, debugstr_guid(riid), pCP);

  *pCP = NULL;
  Obj = HeapAlloc(GetProcessHeap(), 0, sizeof(*Obj));
  if (!Obj)
    return E_OUTOFMEMORY;

  Obj->IConnectionPoint_iface.lpVtbl = &ConnectionPointImpl_VTable;
  Obj->Obj = pUnk;
  Obj->ref = 1;
  Obj->iid = *riid;
  Obj->maxSinks = MAXSINKS;
  Obj->sinks = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(IUnknown*) * MAXSINKS);
  Obj->nSinks = 0;

  *pCP = &Obj->IConnectionPoint_iface;
  return S_OK;
}
