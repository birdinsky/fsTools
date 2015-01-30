#pragma once
#include "fsMacro.h"
#include <vector>
#include "tinyxml\tinyxml.h"
#include "fsTools_i.h"


typedef TiXmlElement dtXMLNode;
typedef TiXmlAttribute dtXMLAttribute;

typedef struct  _IN_STREAM_PARAM
{
	_IN_STREAM_PARAM(const unsigned int nCount, dtXMLNode* node)
	{
		__nSpecifiedCount = nCount;
		__node = node;
	}
	DEFINEPRIVATE(unsigned int, __nSpecifiedCount);
	DEFINEPRIVATE(dtXMLNode*, __node);
private:
	dtXMLNode* __node;
}inStreamParam;

_fsData_NS_BEGIN



enum fsDataType
{
	fsINT = 1,
	fsFLOAT, fsCHAR
};

enum fsSerializeMethod
{
	fsXML = 1, 
	fsINI
};

#define MAX_LIST_COUNT 64

#define DECLARE_REGISTERDATA \
	private: \
	void __InitializeList();
#define BEGIN_REGISTERDATA(CLASSTYPE) \
	void CLASSTYPE::__InitializeList(){\
	__Index = 0;
/*
	@T: fsDataType
	@V:data member variable
	NOTE:be aware of  MAX_LIST_COUNT
	*/
#define REGISTERDATA(T, V)\
if (__Index >= MAX_LIST_COUNT)\
	return;\
__tList[__Index] = T; \
	__pM[__Index++] = &V;

#define END_REGISTERDATA }

class RawData;

class fsDataObject
{
public:
	fsDataObject();
	~fsDataObject();
protected:
	/*
	data member type list
	*/
	char __tList[MAX_LIST_COUNT];
	/*
	pointers of data member
	*/
	void* __pM[MAX_LIST_COUNT];
	unsigned int __Index;
private:
	virtual void __InitializeList() = 0;
public:
	bool ObjSerializeInitialize(fsSerializeMethod method);

	void operator << (dtXMLNode* pData)
	{
		for (int i = 0; i < __Index; i++)
		{

		}
	};
	 void operator >> (FILE* pFile) ;
};

template <typename T>
class fsContainer
{
	void operator << (inStreamParam* pData)
	{
		for (int i = 0; i < pData->Get__nSpecifiedCount(); i++)
		{
			T meta;
			meta << pData->Get__node();
			__data.push_back(meta);
		}
	}

private:
	std::vector<T> __data;
	unsigned int __count;


};

_fsData_NS_END