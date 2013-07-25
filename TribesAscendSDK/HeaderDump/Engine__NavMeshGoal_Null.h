#pragma once
#include "Engine__NavMeshPathGoalEvaluator.h"
#include "Engine__NavigationHandle.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoal_Null." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_Null : public NavMeshPathGoalEvaluator
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'PartialGoal'!
		bool GoUntilBust(class NavigationHandle* NavHandle, int InMaxPathVisits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_Null.GoUntilBust");
			byte* params = (byte*)malloc(12);
			*(class NavigationHandle**)params = NavHandle;
			*(int*)(params + 4) = InMaxPathVisits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void RecycleNative()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_Null.RecycleNative");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_Null.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
