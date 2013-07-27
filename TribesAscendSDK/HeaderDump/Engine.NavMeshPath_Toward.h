#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.NavigationHandle.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshPath_Toward : public NavMeshPathConstraint
	{
	public:
		ADD_STRUCT(Object::Vector, GoalPoint, 84)
		ADD_OBJECT(Actor, GoalActor, 80)
		bool TowardGoal(class NavigationHandle* NavHandle, class Actor* Goal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_Toward.TowardGoal");
			byte params[12] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			*(class Actor**)&params[4] = Goal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool TowardPoint(class NavigationHandle* NavHandle, Object::Vector Point)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_Toward.TowardPoint");
			byte params[20] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			*(Object::Vector*)&params[4] = Point;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_Toward.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
