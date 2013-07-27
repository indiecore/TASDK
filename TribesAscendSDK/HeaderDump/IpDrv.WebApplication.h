#pragma once
#include "Core.Object.h"
#include "IpDrv.WebServer.h"
#include "IpDrv.WebResponse.h"
#include "Engine.WorldInfo.h"
#include "IpDrv.WebRequest.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class WebApplication : public Object
	{
	public:
		ADD_STRUCT(ScriptString*, Path, 68)
		ADD_OBJECT(WebServer, WebServer, 64)
		ADD_OBJECT(WorldInfo, WorldInfo, 60)
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
			byte params[12] = { NULL };
			*(class WebRequest**)&params[0] = Request;
			*(class WebResponse**)&params[4] = Response;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void Query(class WebRequest* Request, class WebResponse* Response)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebApplication.Query");
			byte params[8] = { NULL };
			*(class WebRequest**)&params[0] = Request;
			*(class WebResponse**)&params[4] = Response;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostQuery(class WebRequest* Request, class WebResponse* Response)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebApplication.PostQuery");
			byte params[8] = { NULL };
			*(class WebRequest**)&params[0] = Request;
			*(class WebResponse**)&params[4] = Response;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
