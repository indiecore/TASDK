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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33113);
			byte params[8] = { NULL };
			*(class WebRequest**)params = Request;
			*(class WebResponse**)&params[4] = Response;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
