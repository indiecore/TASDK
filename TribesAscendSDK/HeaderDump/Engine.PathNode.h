#pragma once
#include "Engine.NavigationPoint.h"
namespace UnrealScript
{
	class PathNode : public NavigationPoint
	{
	public:
		ScriptString* GetDebugAbbrev()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PathNode.GetDebugAbbrev");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
