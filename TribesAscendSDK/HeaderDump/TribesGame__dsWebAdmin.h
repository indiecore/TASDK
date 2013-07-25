#pragma once
#include "IpDrv__WebApplication.h"
#include "IpDrv__WebRequest.h"
#include "IpDrv__WebResponse.h"
namespace UnrealScript
{
	class dsWebAdmin : public WebApplication
	{
	public:
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.dsWebAdmin.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Query(class WebRequest* Request, class WebResponse* Response)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.dsWebAdmin.Query");
			byte* params = (byte*)malloc(8);
			*(class WebRequest**)params = Request;
			*(class WebResponse**)(params + 4) = Response;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
