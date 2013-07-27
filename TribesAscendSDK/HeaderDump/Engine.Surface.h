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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetSurfaceHeight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Surface.GetSurfaceHeight");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
	};
}
