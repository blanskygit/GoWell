

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Jan 20 23:37:10 2014
 */
/* Compiler settings for GoWell.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __GoWell_i_h__
#define __GoWell_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IGoWellBHO_FWD_DEFINED__
#define __IGoWellBHO_FWD_DEFINED__
typedef interface IGoWellBHO IGoWellBHO;
#endif 	/* __IGoWellBHO_FWD_DEFINED__ */


#ifndef __GoWellBHO_FWD_DEFINED__
#define __GoWellBHO_FWD_DEFINED__

#ifdef __cplusplus
typedef class GoWellBHO GoWellBHO;
#else
typedef struct GoWellBHO GoWellBHO;
#endif /* __cplusplus */

#endif 	/* __GoWellBHO_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IGoWellBHO_INTERFACE_DEFINED__
#define __IGoWellBHO_INTERFACE_DEFINED__

/* interface IGoWellBHO */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IGoWellBHO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A9726885-B690-4CDF-89C3-B849D8368052")
    IGoWellBHO : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IGoWellBHOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGoWellBHO * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGoWellBHO * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGoWellBHO * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGoWellBHO * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGoWellBHO * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGoWellBHO * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGoWellBHO * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IGoWellBHOVtbl;

    interface IGoWellBHO
    {
        CONST_VTBL struct IGoWellBHOVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGoWellBHO_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGoWellBHO_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGoWellBHO_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGoWellBHO_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGoWellBHO_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGoWellBHO_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGoWellBHO_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGoWellBHO_INTERFACE_DEFINED__ */



#ifndef __GoWellLib_LIBRARY_DEFINED__
#define __GoWellLib_LIBRARY_DEFINED__

/* library GoWellLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_GoWellLib;

EXTERN_C const CLSID CLSID_GoWellBHO;

#ifdef __cplusplus

class DECLSPEC_UUID("B2ADE44D-7A37-47F4-9A8D-92142F37DCED")
GoWellBHO;
#endif
#endif /* __GoWellLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


