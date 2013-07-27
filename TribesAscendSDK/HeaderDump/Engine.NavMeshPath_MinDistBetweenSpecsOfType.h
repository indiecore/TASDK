#pragma once
#include "Core.Object.h"
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.Pylon.h"
#include "Engine.NavigationHandle.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshPath_MinDistBetweenSpecsOfType : public NavMeshPathConstraint
	{
	public:
		ADD_STRUCT(Pylon::ENavMeshEdgeType, EdgeType, 96)
		ADD_STRUCT(Vector, InitLocation, 84)
		ADD_STRUCT(float, MinDistBetweenEdgeTypes, 80)
		bool EnforceMinDist(class NavigationHandle* NavHandle, float InMinDist, Pylon::ENavMeshEdgeType InEdgeType, Vector LastLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21063);
			byte params[25] = { NULL };
			*(class NavigationHandle**)params = NavHandle;
			*(float*)&params[4] = InMinDist;
			*(Pylon::ENavMeshEdgeType*)&params[8] = InEdgeType;
			*(Vector*)&params[12] = LastLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21070);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
