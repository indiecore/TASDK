#pragma once
#include "Core.Object.h"
#include "IpDrv.WebServer.h"
#include "IpDrv.WebResponse.h"
#include "Engine.WorldInfo.h"
#include "IpDrv.WebRequest.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.WebApplication." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.WebApplication." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WebApplication : public Object
	{
	public:
		ADD_VAR(::StrProperty, Path, 0xFFFFFFFF)
		ADD_OBJECT(WebServer, WebServer)
		ADD_OBJECT(WorldInfo, WorldInfo)
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebApplication.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Cleanup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebApplication.Cleanup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanupApp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebApplication.CleanupApp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool PreQuery(class WebRequest* Request, class WebResponse* Response)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebApplication.PreQuery");
			byte* params = (byte*)malloc(12);
			*(class WebRequest**)params = Request;
			*(class WebResponse**)(params + 4) = Response;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void Query(class WebRequest* Request, class WebResponse* Response)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebApplication.Query");
			byte* params = (byte*)malloc(8);
			*(class WebRequest**)params = Request;
			*(class WebResponse**)(params + 4) = Response;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostQuery(class WebRequest* Request, class WebResponse* Response)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebApplication.PostQuery");
			byte* params = (byte*)malloc(8);
			*(class WebRequest**)params = Request;
			*(class WebResponse**)(params + 4) = Response;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
