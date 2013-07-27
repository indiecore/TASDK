#pragma once
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Core.Object.h"
#include "Engine.NavigationHandle.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_OutOfViewFrom : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_BOOL(bShowDebug, 96, 0x1)
		ADD_STRUCT(Vector, OutOfViewLocation, 84)
		ADD_STRUCT(Object::Pointer, GoalPoly, 80)
		void RecycleNative()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32860);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool MustBeHiddenFromThisPoint(class NavigationHandle* NavHandle, Vector InOutOfViewLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32861);
			byte params[20] = { NULL };
			*(class NavigationHandle**)params = NavHandle;
			*(Vector*)&params[4] = InOutOfViewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32866);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
