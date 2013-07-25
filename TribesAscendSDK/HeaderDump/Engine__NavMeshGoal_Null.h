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
		// Here lies the not-yet-implemented method 'GoUntilBust'
		// Here lies the not-yet-implemented method 'RecycleNative'
		// Here lies the not-yet-implemented method 'Recycle'
	};
}
#undef ADD_STRUCT
