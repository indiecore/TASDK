#pragma once
#include "Engine__NavMeshPathGoalEvaluator.h"
#include "Engine__NavigationHandle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.NavMeshGoal_OutOfViewFrom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.NavMeshGoal_OutOfViewFrom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_OutOfViewFrom : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_VAR(::BoolProperty, bShowDebug, 0x1)
		ADD_STRUCT(::VectorProperty, OutOfViewLocation, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'GoalPoly'!
		void RecycleNative()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.NavMeshGoal_OutOfViewFrom.RecycleNative");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool MustBeHiddenFromThisPoint(class NavigationHandle* NavHandle, Vector InOutOfViewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.NavMeshGoal_OutOfViewFrom.MustBeHiddenFromThisPoint");
			byte* params = (byte*)malloc(20);
			*(class NavigationHandle**)params = NavHandle;
			*(Vector*)(params + 4) = InOutOfViewLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.NavMeshGoal_OutOfViewFrom.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
