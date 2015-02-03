#include "stdafx.h"
#include "fsDataObject.h"
#include <atlbase.h>
#include <string>
#include "..\\fsTools\\fsTools_i.h"
#include "..\\fsTools\fsTools_i.c"
using namespace fsData;

void* fsDataObject::__pMethod = NULL;
fsSerializeMethod fsDataObject::__sm = fsSerializeMethod::fsDefault;

_IN_STREAM_PARAM::_IN_STREAM_PARAM(const unsigned int nCount, const char* node)
{
	__nSpecifiedCount = nCount;
	__node = node;
}

fsDataObject::fsDataObject() :__tList(), __pM()
{
	
}


fsDataObject::~fsDataObject()
{

}

bool fsDataObject::ObjSerializeInitialize(fsSerializeMethod method, const char* pOpt)
{
	__sm = method;

	if (__pMethod)
	{
		switch (__sm)
		{
		case fsSerializeMethod::fsXML:
		{
			IfsXMLParser* p = (IfsXMLParser*)__pMethod;
			p->Release();
			break;
		}
		case fsSerializeMethod::fsINI:
			break;
		default:
			break;
		}
		::CoUninitialize();
	}

	::CoInitialize(NULL);//to do  uninitialize

	HRESULT hr = 0;
	switch (method)
	{
	case fsSerializeMethod::fsXML:
	{
		IfsXMLParser* parser;
		hr = ::CoCreateInstance(CLSID_fsXMLParser, NULL, CLSCTX_INPROC_SERVER, IID_IfsXMLParser, (void**)&parser);
		parser->LoadFile(const_cast<CHAR*>(pOpt));
		__pMethod = parser;
		break;
	}
	case fsSerializeMethod::fsINI:
		break;
	default:
		break;
	}
	return hr;
}
//void fsDataObject::InitializeExclueMethod()
//{
//	__InitializeList();
//}
void fsDataObject::operator << (const char* pNodePath)
{
	for (int i = 0; i < __Index; i++)
	{
		char arrName[MAX_VALUE_BUFFER_SIZE] = { 0 };
		char arrValue[MAX_VALUE_BUFFER_SIZE] = { 0 };
		VARIANT_BOOL bRet = false;
		HRESULT hr = ((IfsXMLParser*)__pMethod)->GetNodesInfo(const_cast<char*>(pNodePath) , MAX_VALUE_BUFFER_SIZE, arrName, arrValue, &bRet);
		if (FAILED(hr))
			throw - 1;
		switch (__tList[i])
		{
		case fsDataType::fsINT:
			*(int*)__pM[i] = std::stoi(arrValue);
			break;
		case fsDataType::fsFLOAT:
			*(float*)__pM[i] = std::stof(arrValue);
			break;
		case fsDataType::fsCHAR:
			break;
		Default:
			break;
		}
	}
}

//void fsDataObjs::operator << (inStreamParam* pData)
//{
//	bool bFirst = true;
//	for (int i = 0; i < pData->Get__nSpecifiedCount(); i++)
//	{
//		T meta;
//		meta.__InitializeExclueMethod();
//		meta << bFirst ? pData->Get__node() : NULL;
//		bFirst = false;
//		__data.push_back(meta);
//	}
//}
//
//bool fsDataObjs::ObjsSerializeInitialize(fsSerializeMethod method, const char* pOpt)
//{
//	::CoInitialize(NULL);//to do  uninitialize
//
//	HRESULT hr = 0;
//	switch (method)
//	{
//	case fsSerializeMethod::fsXML:
//	{
//			IfsXMLParser* parser;
//			hr = ::CoCreateInstance(CLSID_fsXMLParser, NULL, CLSCTX_INPROC_SERVER, IID_IfsXMLParser, (void**)&parser);
//			parser->LoadFile(const_cast<CHAR*>(pOpt));
//			fsDataObject::__pMethod = parser;
//			break;
//	}
//	case fsSerializeMethod::fsINI:
//		break;
//	default:
//		break;
//	}
//	return hr;
//}

/*
class AData :public fsDataObject
{
DECLARE_REGISTERDATA;
int a;
float b;
};
BEGIN_REGISTERDATA(AData)
REGISTERDATA(fsINT, a)
REGISTERDATA(fsFLOAT, b)
END_REGISTERDATA
*/