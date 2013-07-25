#pragma once
#include "Engine__NavMeshPathGoalEvaluator.h"
#include "Engine__NavigationHandle.h"
#include "Engine__NavMeshGoal_Filter.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoal_GenericFilterContainer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NavMeshGoal_GenericFilterContainer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshGoal_GenericFilterContainer : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_OBJECT(NavigationHandle, MyNavigationHandle)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SuccessfulGoal'!
		// Here lies the not-yet-implemented method 'CreateAndAddFilterToNavHandle'
		// Here lies the not-yet-implemented method 'GetFilterOfType'
		// Here lies the not-yet-implemented method 'GetGoalPoint'
		// Here lies the not-yet-implemented method 'Recycle'
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
