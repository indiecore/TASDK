#pragma once
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.NavigationHandle.h"
namespace UnrealScript
{
	class NavMeshPath_EnforceTwoWayEdges : public NavMeshPathConstraint
	{
	public:
		bool EnforceTwoWayEdges(class NavigationHandle* NavHandle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21056);
			byte params[8] = { NULL };
			*(class NavigationHandle**)params = NavHandle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
