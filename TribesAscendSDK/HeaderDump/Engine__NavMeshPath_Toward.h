#pragma once
#include "Engine__Actor.h"
#include "Engine__NavMeshPathConstraint.h"
#include "Engine__NavigationHandle.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshPath_Toward." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NavMeshPath_Toward." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshPath_Toward : public NavMeshPathConstraint
	{
	public:
		ADD_STRUCT(::VectorProperty, GoalPoint, 0xFFFFFFFF
		ADD_OBJECT(Actor, GoalActor)
		bool TowardGoal(class NavigationHandle* NavHandle, class Actor* Goal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_Toward.TowardGoal");
			byte* params = (byte*)malloc(12);
			*(class NavigationHandle**)params = NavHandle;
			*(class Actor**)(params + 4) = Goal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool TowardPoint(class NavigationHandle* NavHandle, Vector Point)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_Toward.TowardPoint");
			byte* params = (byte*)malloc(20);
			*(class NavigationHandle**)params = NavHandle;
			*(Vector*)(params + 4) = Point;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
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
