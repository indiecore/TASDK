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
		ADD_STRUCT(ScriptArray<Vector>, LocationsToCheck, 108)
		ADD_STRUCT(float, DistanceToCheck, 104)
		ADD_STRUCT(Vector, Rotation, 92)
		ADD_STRUCT(Vector, Location, 80)
		bool BiasAgainstPolysWithinDistanceOfLocations(class NavigationHandle* NavHandle, Vector InLocation, Rotator InRotation, float InDistanceToCheck, ScriptArray<Vector> InLocationsToCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32872);
			byte params[48] = { NULL };
			*(class NavigationHandle**)params = NavHandle;
			*(Vector*)&params[4] = InLocation;
			*(Rotator*)&params[16] = InRotation;
			*(float*)&params[28] = InDistanceToCheck;
			*(ScriptArray<Vector>*)&params[32] = InLocationsToCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[44];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32881);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
