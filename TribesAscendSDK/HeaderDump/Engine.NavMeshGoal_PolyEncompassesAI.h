#pragma once
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Core.Object.h"
#include "Engine.NavigationHandle.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_PolyEncompassesAI : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_STRUCT(Object::Vector, OverrideExtentToCheck, 80)
		bool MakeSureAIFits(class NavigationHandle* NavHandle, Object::Vector InOverrideExtentToCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_PolyEncompassesAI.MakeSureAIFits");
			byte params[20] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			*(Object::Vector*)&params[4] = InOverrideExtentToCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_PolyEncompassesAI.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
