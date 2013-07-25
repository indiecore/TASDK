#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class OnlineStats : public Object
	{
	public:
		bool GetViewId(ScriptName ViewName, int& ViewId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStats.GetViewId");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ViewName;
			*(int*)(params + 8) = ViewId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ViewId = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptName GetViewName(int ViewId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStats.GetViewName");
			byte* params = (byte*)malloc(12);
			*(int*)params = ViewId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
