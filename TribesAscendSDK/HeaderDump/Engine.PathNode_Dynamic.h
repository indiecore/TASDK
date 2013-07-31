#pragma once
#include "Engine.PathNode.h"
namespace UnrealScript
{
	class PathNode_Dynamic : public PathNode
	{
	public:
		ScriptString* GetDebugAbbrev()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24030);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
