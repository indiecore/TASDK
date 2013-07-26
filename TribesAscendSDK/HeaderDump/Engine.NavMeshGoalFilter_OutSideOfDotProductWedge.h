#pragma once
#include "Engine.NavMeshGoal_GenericFilterContainer.h"
#include "Engine.NavMeshGoal_Filter.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshGoalFilter_OutSideOfDotProductWedge." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoalFilter_OutSideOfDotProductWedge." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_OutSideOfDotProductWedge : public NavMeshGoal_Filter
	{
	public:
		ADD_VAR(::FloatProperty, Epsilon, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Rotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF)
		bool OutsideOfDotProductWedge(class NavMeshGoal_GenericFilterContainer* FilterContainer, Vector InLocation, Rotator InRotation, float InEpsilon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoalFilter_OutSideOfDotProductWedge.OutsideOfDotProductWedge");
			byte* params = (byte*)malloc(36);
			*(class NavMeshGoal_GenericFilterContainer**)params = FilterContainer;
			*(Vector*)(params + 4) = InLocation;
			*(Rotator*)(params + 16) = InRotation;
			*(float*)(params + 28) = InEpsilon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
