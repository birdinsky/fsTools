// fsXMLParser.cpp : Implementation of CfsXMLParser

#include "stdafx.h"
#include "fsXMLParser.h"
#include "fsMacro.h"
#include <string>
// CfsXMLParser

STDMETHODIMP CfsXMLParser::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] =
	{
		&IID_IfsXMLParser
	};

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i], riid))
			return S_OK;
	}
	return S_FALSE;
}




STDMETHODIMP CfsXMLParser::LoadFile(CHAR* FileName)
{
	// TODO: Add your implementation code here
	//::MessageBox(NULL, (TCHAR*)FileName, _T("HELLO"), MB_OK);
	if (!_mXMLDoc.LoadFile(FileName))
		MSGBOXREERR("can't load xml file")

		_mXMLRoot = _mXMLDoc.RootElement();
	if (_mXMLRoot == NULL)
		MSGBOXREERR("can't get root node")
		return S_OK;
}


STDMETHODIMP CfsXMLParser::GetSpecifiedAttribute(BSTR* NodePath, BSTR* AttributeName, ULONG bufferSize, CHAR* pAttribute)
{
	// TODO: Add your implementation code here
	USES_CONVERSION;
	TiXmlElement* pCurNode = _findSpecifiedNode(W2A((TCHAR*)NodePath), _mXMLRoot);
	if (pCurNode == NULL)
		MSGBOXREERR("can't find specified node in xml file or  specified node not unique")
	TiXmlAttribute* pCurAttribute = _getSpecifiedNode(pCurNode, W2A((TCHAR*)AttributeName));
	if (pCurAttribute == NULL)
		MSGBOXREERR("can't find specified attribute in xml file")

		size_t len = strlen(pCurAttribute->Value());
	if (len > bufferSize)
		MSGBOXREERR("buffer overflow")
	memcpy(pAttribute, pCurAttribute->Value(), len);
	return S_OK;
}

TiXmlElement* CfsXMLParser::_findSpecifiedNode(const char* nodeName, TiXmlElement* parentNode, bool bUnique)
{
	TiXmlElement* curNode;
	char arrBuffer[MAXNODENAME] = { 0 };
	bool bRet = _getCurNodeName(nodeName, arrBuffer);
	curNode = parentNode->FirstChildElement();
	while (true)
	{
		std::string str_(curNode->Value());
		if (arrBuffer == NULL)
			return NULL;
		if (!str_.compare(arrBuffer))
			break;
		curNode = curNode->NextSiblingElement();
		if (curNode == NULL)
			return NULL;
	}
	if (bRet)
		_findSpecifiedNode(nodeName + strlen(arrBuffer) + 1, curNode, bUnique);//recursive here
	else
	{
		if (bUnique)
		{
			std::string str_(curNode->NextSiblingElement()->Value());
			if (!str_.compare(nodeName))
				return NULL;
		}
		else
			return curNode;
	}
}
bool CfsXMLParser::_getCurNodeName(const char* nodeName, char * curName, const unsigned int nSize)
{
	std::string strNode(nodeName);

	size_t pos = strNode.find('/');
	if (pos != strNode.npos)
	{
		std::string _str(strNode.c_str(), pos);

		if (_str.size() > nSize)
			return false;
		::memcpy(curName, _str.c_str(), _str.size());
		return true;
	}
	size_t len = strlen(nodeName);
	if (len > nSize)
		curName = NULL;
	else
		memcpy(curName, nodeName, len);
	return false;
}

TiXmlAttribute* CfsXMLParser::_getSpecifiedNode(TiXmlElement* curNode, const char* attributeName)
{
	std::string strAttribute(attributeName);
	if (curNode == NULL)
		return NULL;
	TiXmlAttribute* _attribute = curNode->FirstAttribute();
	if (_attribute == NULL)
		return NULL;
	while (true)
	{
		if (!strAttribute.compare(_attribute->Name()))
			return _attribute;
		_attribute = _attribute->Next();
		if (_attribute == NULL)
			return NULL;
	}
}



STDMETHODIMP CfsXMLParser::GetNodesInfo(CHAR* NodePath, ULONG bufferSize, CHAR* AttributeName, CHAR* AttributeValue, VARIANT_BOOL* IsNextNode)
{
	// TODO: Add your implementation code here
	std::string _strNodePath(NodePath);
	if (_strNodePath.compare(_preNodePath))
	{
		::ZeroMemory(_preNodePath, MAX_PATH);
		::memcpy(_preNodePath, _strNodePath.c_str(), _strNodePath.size());
		_mcurNode = _findSpecifiedNode(NodePath, _mXMLRoot, false);

	}
	if (_mcurNode == NULL)
		MSGBOXREERR("CurNode is NULL")
	if (_mcurAttribute == NULL)
	{
		_mcurAttribute = _mcurNode->FirstAttribute();
		if (_mcurAttribute == NULL)
			MSGBOXREERR("no attribute in node")
	}
	else
	{
		_mcurAttribute = _mcurAttribute->Next();
		*IsNextNode = false;
		if (_mcurAttribute == NULL)
		{
			_mcurNode = _mcurNode->NextSiblingElement();
			if (_mcurNode == NULL)
				return E_FAIL;
			_mcurAttribute = _mcurNode->FirstAttribute();
			if (_mcurAttribute == NULL)
				MSGBOXREERR("no attribute in node")
			*IsNextNode = true;
		}
	}
	std::string _str(_mcurAttribute->Name());
	size_t len = _str.size() + 1;
	if (len > bufferSize)
		MSGBOXREERR("buffer overflow")
	if (AttributeName == NULL || AttributeValue == NULL)
		MSGBOXREERR("invalid buffer pointer")
		::memcpy(AttributeName, _str.c_str(), len);
	_str.assign(_mcurAttribute->Value());
	len = _str.size() + 1;
	if (len > bufferSize)
		MSGBOXREERR("buffer overflow")
		::memcpy(AttributeValue, _str.c_str(), len);
	return S_OK;
}
