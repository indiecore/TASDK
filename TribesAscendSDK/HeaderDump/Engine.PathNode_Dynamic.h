#pragma once
#include "Engine.PathNode.h"
namespace UnrealScript
{
	class PathNode_Dynamic : public PathNode
	{
	public:
		ScriptString* GetDebugAbbrev()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PathNode_Dynamic.GetDebugAbbrev");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
