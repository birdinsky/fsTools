

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jan 30 18:40:23 2015
 */
/* Compiler settings for fsTools.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
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

#ifndef __fsTools_i_h__
#define __fsTools_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IfsXMLParser_FWD_DEFINED__
#define __IfsXMLParser_FWD_DEFINED__
typedef interface IfsXMLParser IfsXMLParser;

#endif 	/* __IfsXMLParser_FWD_DEFINED__ */


#ifndef ___IfsXMLParserEvents_FWD_DEFINED__
#define ___IfsXMLParserEvents_FWD_DEFINED__
typedef interface _IfsXMLParserEvents _IfsXMLParserEvents;

#endif 	/* ___IfsXMLParserEvents_FWD_DEFINED__ */


#ifndef __fsXMLParser_FWD_DEFINED__
#define __fsXMLParser_FWD_DEFINED__

#ifdef __cplusplus
typedef class fsXMLParser fsXMLParser;
#else
typedef struct fsXMLParser fsXMLParser;
#endif /* __cplusplus */

#endif 	/* __fsXMLParser_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IfsXMLParser_INTERFACE_DEFINED__
#define __IfsXMLParser_INTERFACE_DEFINED__

/* interface IfsXMLParser */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IfsXMLParser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4EB388AF-2DF3-4208-A151-1D41FF036023")
    IfsXMLParser : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE LoadFile( 
            BSTR *FileName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSpecifiedAttribute( 
            /* [in] */ BSTR *NodePath,
            /* [in] */ BSTR *AttributeName,
            /* [in] */ ULONG bufferSize,
            /* [retval][out] */ CHAR *pAttribute) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNodesInfo( 
            /* [in] */ CHAR *NodePath,
            /* [in] */ ULONG bufferSize,
            /* [out][in] */ CHAR *AttributeName,
            /* [out][in] */ CHAR *AttributeValue,
            /* [retval][out] */ VARIANT_BOOL *IsNextNode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IfsXMLParserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IfsXMLParser * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IfsXMLParser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IfsXMLParser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IfsXMLParser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IfsXMLParser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IfsXMLParser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IfsXMLParser * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *LoadFile )( 
            IfsXMLParser * This,
            BSTR *FileName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSpecifiedAttribute )( 
            IfsXMLParser * This,
            /* [in] */ BSTR *NodePath,
            /* [in] */ BSTR *AttributeName,
            /* [in] */ ULONG bufferSize,
            /* [retval][out] */ CHAR *pAttribute);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNodesInfo )( 
            IfsXMLParser * This,
            /* [in] */ CHAR *NodePath,
            /* [in] */ ULONG bufferSize,
            /* [out][in] */ CHAR *AttributeName,
            /* [out][in] */ CHAR *AttributeValue,
            /* [retval][out] */ VARIANT_BOOL *IsNextNode);
        
        END_INTERFACE
    } IfsXMLParserVtbl;

    interface IfsXMLParser
    {
        CONST_VTBL struct IfsXMLParserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IfsXMLParser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IfsXMLParser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IfsXMLParser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IfsXMLParser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IfsXMLParser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IfsXMLParser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IfsXMLParser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IfsXMLParser_LoadFile(This,FileName)	\
    ( (This)->lpVtbl -> LoadFile(This,FileName) ) 

#define IfsXMLParser_GetSpecifiedAttribute(This,NodePath,AttributeName,bufferSize,pAttribute)	\
    ( (This)->lpVtbl -> GetSpecifiedAttribute(This,NodePath,AttributeName,bufferSize,pAttribute) ) 

#define IfsXMLParser_GetNodesInfo(This,NodePath,bufferSize,AttributeName,AttributeValue,IsNextNode)	\
    ( (This)->lpVtbl -> GetNodesInfo(This,NodePath,bufferSize,AttributeName,AttributeValue,IsNextNode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IfsXMLParser_INTERFACE_DEFINED__ */



#ifndef __fsToolsLib_LIBRARY_DEFINED__
#define __fsToolsLib_LIBRARY_DEFINED__

/* library fsToolsLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_fsToolsLib;

#ifndef ___IfsXMLParserEvents_DISPINTERFACE_DEFINED__
#define ___IfsXMLParserEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IfsXMLParserEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IfsXMLParserEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7EC5C565-CE7D-46A7-96A4-AEF617DB26CB")
    _IfsXMLParserEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IfsXMLParserEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IfsXMLParserEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IfsXMLParserEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IfsXMLParserEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IfsXMLParserEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IfsXMLParserEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IfsXMLParserEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IfsXMLParserEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IfsXMLParserEventsVtbl;

    interface _IfsXMLParserEvents
    {
        CONST_VTBL struct _IfsXMLParserEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IfsXMLParserEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IfsXMLParserEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IfsXMLParserEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IfsXMLParserEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IfsXMLParserEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IfsXMLParserEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IfsXMLParserEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IfsXMLParserEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_fsXMLParser;

#ifdef __cplusplus

class DECLSPEC_UUID("ED5F13F4-DE0B-4475-A014-05A0E5EAD490")
fsXMLParser;
#endif
#endif /* __fsToolsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


