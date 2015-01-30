

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
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

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IfsXMLParser,0x4EB388AF,0x2DF3,0x4208,0xA1,0x51,0x1D,0x41,0xFF,0x03,0x60,0x23);


MIDL_DEFINE_GUID(IID, LIBID_fsToolsLib,0x04AEA90B,0x0622,0x4997,0xB4,0xC8,0x59,0xD7,0xF7,0x8F,0x9D,0x7E);


MIDL_DEFINE_GUID(IID, DIID__IfsXMLParserEvents,0x7EC5C565,0xCE7D,0x46A7,0x96,0xA4,0xAE,0xF6,0x17,0xDB,0x26,0xCB);


MIDL_DEFINE_GUID(CLSID, CLSID_fsXMLParser,0xED5F13F4,0xDE0B,0x4475,0xA0,0x14,0x05,0xA0,0xE5,0xEA,0xD4,0x90);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



