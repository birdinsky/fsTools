// fsXMLParser.h : Declaration of the CfsXMLParser

#pragma once
#include "resource.h"       // main symbols



#include "fsTools_i.h"
#include "_IfsXMLParserEvents_CP.h"
#include "tinyxml\tinystr.h"
#include "tinyxml\tinyxml.h"

#define MAXNODENAME 64

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CfsXMLParser

class ATL_NO_VTABLE CfsXMLParser :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CfsXMLParser, &CLSID_fsXMLParser>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CfsXMLParser>,
	public CProxy_IfsXMLParserEvents<CfsXMLParser>,
	public IDispatchImpl<IfsXMLParser, &IID_IfsXMLParser, &LIBID_fsToolsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CfsXMLParser() : _mXMLRoot(NULL), _mcurNode(NULL), _mcurAttribute(NULL)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FSXMLPARSER1)


BEGIN_COM_MAP(CfsXMLParser)
	COM_INTERFACE_ENTRY(IfsXMLParser)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CfsXMLParser)
	CONNECTION_POINT_ENTRY(__uuidof(_IfsXMLParserEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(LoadFile)(BSTR* FileName);

private:

	TiXmlDocument _mXMLDoc;
	TiXmlElement* _mXMLRoot;
	TiXmlElement* _mcurNode;
	TiXmlAttribute* _mcurAttribute;

	TiXmlElement* _findSpecifiedNode(const char* nodeName, TiXmlElement* parentNode, bool bUnique = TRUE);
	bool _getCurNodeName(const char* nodeName, char* curName, const unsigned int nSize = MAXNODENAME);
	TiXmlAttribute* _getSpecifiedNode(TiXmlElement* curNode, const char* attributeName);
public:
	STDMETHOD(GetSpecifiedAttribute)(BSTR* NodePath, BSTR* AttributeName, ULONG bufferSize, CHAR* pAttribute);
	STDMETHOD(GetNodesInfo)(CHAR* NodePath, ULONG bufferSize, CHAR* AttributeName, CHAR* AttributeValue, VARIANT_BOOL* IsNextNode);
};

OBJECT_ENTRY_AUTO(__uuidof(fsXMLParser), CfsXMLParser)
