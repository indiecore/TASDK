#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class Surface : public Object
	{
	public:
		float GetSurfaceWidth()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Surface.GetSurfaceWidth");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetSurfaceHeight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Surface.GetSurfaceHeight");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
	};
}
