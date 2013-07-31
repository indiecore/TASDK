#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class Surface : public Object
	{
	public:
		float GetSurfaceWidth()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5028);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetSurfaceHeight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5030);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
	};
}
