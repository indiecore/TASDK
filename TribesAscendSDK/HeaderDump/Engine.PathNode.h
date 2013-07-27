#pragma once
#include "Engine.NavigationPoint.h"
namespace UnrealScript
{
	class PathNode : public NavigationPoint
	{
	public:
		ScriptString* GetDebugAbbrev()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24026);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
