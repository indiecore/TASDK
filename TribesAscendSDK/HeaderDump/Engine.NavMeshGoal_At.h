#pragma once
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Engine.Actor.h"
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
	class NavMeshGoal_At : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_STRUCT(Object::Pointer, PartialGoal, 104)
		ADD_STRUCT(Object::Pointer, GoalPoly, 100)
		ADD_BOOL(bKeepPartial, 96, 0x1)
		ADD_STRUCT(float, GoalDist, 92)
		ADD_STRUCT(Object::Vector, Goal, 80)
		void RecycleNative()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_At.RecycleNative");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AtActor(class NavigationHandle* NavHandle, class Actor* GoalActor, float Dist, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_At.AtActor");
			byte params[20] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			*(class Actor**)&params[4] = GoalActor;
			*(float*)&params[8] = Dist;
			*(bool*)&params[12] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool AtLocation(class NavigationHandle* NavHandle, Object::Vector GoalLocation, float Dist, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_At.AtLocation");
			byte params[28] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			*(Object::Vector*)&params[4] = GoalLocation;
			*(float*)&params[16] = Dist;
			*(bool*)&params[20] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_At.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
