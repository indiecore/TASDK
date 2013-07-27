#pragma once
#include "IpDrv.WebApplication.h"
#include "IpDrv.WebRequest.h"
#include "IpDrv.WebResponse.h"
namespace UnrealScript
{
	class HelloWeb : public WebApplication
	{
	public:
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.HelloWeb.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Query(class WebRequest* Request, class WebResponse* Response)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.HelloWeb.Query");
			byte params[8] = { NULL };
			*(class WebRequest**)&params[0] = Request;
			*(class WebResponse**)&params[4] = Response;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
