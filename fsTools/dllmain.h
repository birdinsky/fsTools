// dllmain.h : Declaration of module class.

class CfsToolsModule : public ATL::CAtlDllModuleT< CfsToolsModule >
{
public :
	DECLARE_LIBID(LIBID_fsToolsLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FSTOOLS, "{345A15C2-C36F-4CB8-AF91-1FB675726887}")
};

extern class CfsToolsModule _AtlModule;
