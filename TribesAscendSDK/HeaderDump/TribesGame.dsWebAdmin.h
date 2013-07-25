#pragma once
#include "IpDrv.WebApplication.h"
#include "IpDrv.WebRequest.h"
#include "IpDrv.WebResponse.h"
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
