#include "stdafx.h"
#include "fsDataObject.h"
#include <atlbase.h>
using namespace fsData;

fsDataObject::fsDataObject()
{
}


fsDataObject::~fsDataObject()
{
}

bool fsDataObject::ObjSerializeInitialize(fsSerializeMethod method)
{
	__InitializeList();
	for (int i = 0; i < __Index; i++)
	{
		switch (__tList[i])
		{
		case fsINT:
			*(int*)__pM[i] = 1;
			break;
		case fsFLOAT:
			*(float*)__pM[i] = 1.1;
			break;
		default:
			break;
		}
	}

	::CoInitialize(NULL);//to do  uninitialize

	switch (method)
	{
	case fsData::fsXML:
	{
		ATL::CComPtr<IfsXMLParser> parser;
		parser.CoCreateInstance(CLSID_fsXMLParser);
		break;
	}
	case fsData::fsINI:
		break;
	default:
		break;
	}
}

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