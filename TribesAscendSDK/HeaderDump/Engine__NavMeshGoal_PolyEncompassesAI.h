#pragma once
#include "Engine__NavMeshPathGoalEvaluator.h"
#include "Engine__NavigationHandle.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoal_PolyEncompassesAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_PolyEncompassesAI : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_STRUCT(::VectorProperty, OverrideExtentToCheck, 0xFFFFFFFF
		bool MakeSureAIFits(class NavigationHandle* NavHandle, Vector InOverrideExtentToCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_PolyEncompassesAI.MakeSureAIFits");
			byte* params = (byte*)malloc(20);
			*(class NavigationHandle**)params = NavHandle;
			*(Vector*)(params + 4) = InOverrideExtentToCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_PolyEncompassesAI.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
