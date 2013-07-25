#pragma once
#include "Engine__NavMeshPathConstraint.h"
#include "Engine__NavigationHandle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations : public NavMeshPathConstraint
	{
	public:
		ADD_VAR(::FloatProperty, DistanceToCheck, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Rotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF)
		bool BiasAgainstPolysWithinDistanceOfLocations(class NavigationHandle* NavHandle, Vector InLocation, Rotator InRotation, float InDistanceToCheck, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* InLocationsToCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.BiasAgainstPolysWithinDistanceOfLocations");
			byte* params = (byte*)malloc(48);
			*(class NavigationHandle**)params = NavHandle;
			*(Vector*)(params + 4) = InLocation;
			*(Rotator*)(params + 16) = InRotation;
			*(float*)(params + 28) = InDistanceToCheck;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 32) = InLocationsToCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 44);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
