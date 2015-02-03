#pragma once
#include "..\\fsTools\\fsMacro.h"
#include <vector>

_fsData_NS_BEGIN

//typedef TiXmlElement dtXMLNode;
//typedef TiXmlAttribute dtXMLAttribute;

typedef struct  _IN_STREAM_PARAM
{
	_IN_STREAM_PARAM(const unsigned int nCount, const char* nodePath);
	DEFINEPRIVATE(unsigned int, __nSpecifiedCount);
	DEFINEPRIVATE(const char*, __node);
}inStreamParam;


enum class fsDataType
{
	fsDefault = 0,
	fsINT = 1,
	fsFLOAT, fsCHAR, fsSTRING
};

enum class fsSerializeMethod
{
	fsDefault = 0,
	fsXML = 1,
	fsINI
};

#define MAX_LIST_COUNT 64

#define DECLARE_REGISTERDATA(CLASSTYPE) \
	public:\
	CLASSTYPE();\
	private: \
	void __InitializeList();
#define BEGIN_REGISTERDATA(CLASSTYPE) \
	CLASSTYPE::CLASSTYPE(){ __InitializeList(); }\
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
	//friend class fsDataObjs;
	fsDataObject();
	~fsDataObject();
protected:
	/*
	data member type list
	*/
	fsDataType __tList[MAX_LIST_COUNT];
	/*
	pointers of data member
	*/
	void* __pM[MAX_LIST_COUNT];
	unsigned int __Index;

	static void* __pMethod;
	static fsSerializeMethod __sm;
private:
	virtual void __InitializeList() = 0;

public:
	static bool ObjSerializeInitialize(fsSerializeMethod method, const char* pOpt);

	//void InitializeExclueMethod();
	void operator << (const char* pNodePath);
	 void operator >> (FILE* pFile) ;

};
//
//class fsDataObjs
//{
//public:
//	bool ObjsSerializeInitialize(fsSerializeMethod method, const char* pOpt);
//	void operator << (inStreamParam* pData);
//
//private:
//	std::vector<fsDataObject> __data;
//	unsigned int __count;
//};

_fsData_NS_END