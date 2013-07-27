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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_EnforceTwoWayEdges.EnforceTwoWayEdges");
			byte params[8] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
