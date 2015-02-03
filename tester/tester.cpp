// tester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include "..\fsTools\fsTools_i.h"
//#include "..\fsTools\fsTools_i.c"

#include "..\\fsBaseObj\fsDataObject.h"
#include <vector>

#pragma comment(lib, "..\\Debug\\fsBaseObj.lib")
#define FALSERETURN(hr) \
if (FAILED(hr)) \
	return -1;

using namespace fsData;

class TestObj : public fsDataObject
{
	DECLARE_REGISTERDATA(TestObj)

	int id;
	float r;
	float h;
	float v;
	float x;
	float y;
	float z;
};

BEGIN_REGISTERDATA(TestObj)
REGISTERDATA(fsDataType::fsINT, id)
REGISTERDATA(fsDataType::fsFLOAT, r)
REGISTERDATA(fsDataType::fsFLOAT, h)
REGISTERDATA(fsDataType::fsFLOAT, v)
REGISTERDATA(fsDataType::fsFLOAT, x)
REGISTERDATA(fsDataType::fsFLOAT, y)
REGISTERDATA(fsDataType::fsFLOAT, z)
END_REGISTERDATA

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<TestObj> objs;
	TestObj::ObjSerializeInitialize(fsSerializeMethod::fsXML, "E:\\AbdomenTraining.xml");
	for (int i = 0; i < 2; i++)
	{
		TestObj obj;
		obj << "Camera/Target/Steps/Step";
		objs.push_back(obj);
	}

	return 0;
}





