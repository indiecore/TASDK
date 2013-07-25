#pragma once
#include "IpDrv.WebApplication.h"
#include "IpDrv.WebRequest.h"
#include "IpDrv.WebResponse.h"
namespace UnrealScript
{
	class ImageServer : public WebApplication
	{
	public:
		void Query(class WebRequest* Request, class WebResponse* Response)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.ImageServer.Query");
			byte* params = (byte*)malloc(8);
			*(class WebRequest**)params = Request;
			*(class WebResponse**)(params + 4) = Response;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
