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
		// Here lies the not-yet-implemented method 'MakeSureAIFits'
		// Here lies the not-yet-implemented method 'Recycle'
	};
}
#undef ADD_STRUCT
