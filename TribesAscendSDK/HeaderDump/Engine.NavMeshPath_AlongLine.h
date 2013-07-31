#pragma once
#include "Core.Object.h"
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.NavigationHandle.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshPath_AlongLine : public NavMeshPathConstraint
	{
	public:
		ADD_STRUCT(Vector, Direction, 80)
		bool AlongLine(class NavigationHandle* NavHandle, Vector Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21050);
			byte params[20] = { NULL };
			*(class NavigationHandle**)params = NavHandle;
			*(Vector*)&params[4] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21055);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
