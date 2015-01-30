#ifdef _DEBUG 
#define MSGBOXREERR(msg) \
{\
	::MessageBox(NULL, _T(msg), _T("ERR"), MB_OK | MB_ICONERROR); \
	return E_FAIL; \
}
#else
#define MSGBOXREERR(msg) \
{\
	return E_FAIL; \
}
#endif

#ifdef __cplusplus

#define _fsData_NS_BEGIN namespace fsData {
#define _fsData_NS_END }

#endif

/*
define private member variable with default SETER and GETER
*/
#define DEFINEPRIVATE(T, V)\
	private:\
	T V; \
	public:\
	void Set##V(T val)\
	{\
	V = val; \
	}\
	T Get##V()\
	{\
	return V; \
	}