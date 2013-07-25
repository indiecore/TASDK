#pragma once
#include "Engine__NavMeshPathGoalEvaluator.h"
#include "Engine__NavigationHandle.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshGoal_At." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoal_At." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_At : public NavMeshPathGoalEvaluator
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'PartialGoal'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'GoalPoly'!
		ADD_VAR(::BoolProperty, bKeepPartial, 0x1)
		ADD_VAR(::FloatProperty, GoalDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Goal, 0xFFFFFFFF)
		void RecycleNative()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_At.RecycleNative");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AtActor(class NavigationHandle* NavHandle, class Actor* GoalActor, float Dist, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_At.AtActor");
			byte* params = (byte*)malloc(20);
			*(class NavigationHandle**)params = NavHandle;
			*(class Actor**)(params + 4) = GoalActor;
			*(float*)(params + 8) = Dist;
			*(bool*)(params + 12) = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool AtLocation(class NavigationHandle* NavHandle, Vector GoalLocation, float Dist, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_At.AtLocation");
			byte* params = (byte*)malloc(28);
			*(class NavigationHandle**)params = NavHandle;
			*(Vector*)(params + 4) = GoalLocation;
			*(float*)(params + 16) = Dist;
			*(bool*)(params + 20) = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_At.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
