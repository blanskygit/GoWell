// dllmain.h : Declaration of module class.

class CGoWellModule : public ATL::CAtlDllModuleT< CGoWellModule >
{
public :
	DECLARE_LIBID(LIBID_GoWellLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_GOWELL, "{9045160B-2D77-4178-93F4-26D9D7C3BF0A}")
};

extern class CGoWellModule _AtlModule;
