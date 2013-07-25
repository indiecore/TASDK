#pragma once
#include "Engine__PathNode.h"
namespace UnrealScript
{
	class PathNode_Dynamic : public PathNode
	{
	public:
		ScriptArray<wchar_t> GetDebugAbbrev()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PathNode_Dynamic.GetDebugAbbrev");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
