// tester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "..\fsTools\fsTools_i.h"
#include "..\fsTools\fsTools_i.c"
#include <vector>
#define FALSERETURN(hr) \
if (FAILED(hr)) \
	return -1;

int _tmain(int argc, _TCHAR* argv[])
{
	::CoInitialize(NULL);

	CComPtr<IfsXMLParser> pfsXMLP;

	HRESULT hr = pfsXMLP.CoCreateInstance(CLSID_fsXMLParser);

	FALSERETURN(hr);

	hr = pfsXMLP->LoadFile((BSTR*)(_T("E:\\training.xml")));
	FALSERETURN(hr);

	char arrBuffer[64] = { 0 };
	//hr = pfsXMLP->GetSpecifiedAttribute((BSTR*)(_T("StaticScene/Scene/SceneNode")), (BSTR*)_T("Path"), 64, arrBuffer);
	//FALSERETURN(hr);

	char arrAttribute[64] = { 0 };
	char arrValue[64] = { 0 };
	VARIANT_BOOL bRet = false;
	hr = pfsXMLP->GetNodesInfo("Tips/Tip", 64, arrBuffer, arrValue, &bRet);
	while (true)
	{		
		hr = pfsXMLP->GetNodesInfo(NULL, 64, arrBuffer, arrValue, &bRet);
		if (FAILED(hr))
			break;
	}
	pfsXMLP.Release();

	::CoUninitialize();



	return 0;
}





