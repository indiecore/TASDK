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
			byte* params = (byte*)malloc(8);
			*(class NavigationHandle**)params = NavHandle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
