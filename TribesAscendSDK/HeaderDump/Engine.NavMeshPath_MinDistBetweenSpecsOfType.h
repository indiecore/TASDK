#pragma once
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.NavigationHandle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshPath_MinDistBetweenSpecsOfType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshPath_MinDistBetweenSpecsOfType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshPath_MinDistBetweenSpecsOfType : public NavMeshPathConstraint
	{
	public:
		ADD_VAR(::ByteProperty, EdgeType, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, InitLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinDistBetweenEdgeTypes, 0xFFFFFFFF)
		bool EnforceMinDist(class NavigationHandle* NavHandle, float InMinDist, byte InEdgeType, Vector LastLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_MinDistBetweenSpecsOfType.EnforceMinDist");
			byte* params = (byte*)malloc(25);
			*(class NavigationHandle**)params = NavHandle;
			*(float*)(params + 4) = InMinDist;
			*(params + 8) = InEdgeType;
			*(Vector*)(params + 12) = LastLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_MinDistBetweenSpecsOfType.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
