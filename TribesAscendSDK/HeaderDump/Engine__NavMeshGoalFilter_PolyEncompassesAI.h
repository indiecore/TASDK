#pragma once
#include "Engine__NavMeshGoal_Filter.h"
#include "Engine__NavMeshGoal_GenericFilterContainer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoalFilter_PolyEncompassesAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_PolyEncompassesAI : public NavMeshGoal_Filter
	{
	public:
		ADD_STRUCT(::VectorProperty, OverrideExtentToCheck, 0xFFFFFFFF
		// Here lies the not-yet-implemented method 'MakeSureAIFits'
	};
}
#undef ADD_STRUCT
