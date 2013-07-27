#pragma once
#include "Core.Object.h"
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.NavigationHandle.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations : public NavMeshPathConstraint
	{
	public:
		ADD_STRUCT(ScriptArray<Object::Vector>, LocationsToCheck, 108)
		ADD_STRUCT(float, DistanceToCheck, 104)
		ADD_STRUCT(Object::Vector, Rotation, 92)
		ADD_STRUCT(Object::Vector, Location, 80)
		bool BiasAgainstPolysWithinDistanceOfLocations(class NavigationHandle* NavHandle, Object::Vector InLocation, Object::Rotator InRotation, float InDistanceToCheck, ScriptArray<Object::Vector> InLocationsToCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.BiasAgainstPolysWithinDistanceOfLocations");
			byte params[48] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			*(Object::Vector*)&params[4] = InLocation;
			*(Object::Rotator*)&params[16] = InRotation;
			*(float*)&params[28] = InDistanceToCheck;
			*(ScriptArray<Object::Vector>*)&params[32] = InLocationsToCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[44];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
