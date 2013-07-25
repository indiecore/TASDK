#pragma once
#include "Engine.NavigationPoint.h"
namespace UnrealScript
{
	class PathNode : public NavigationPoint
	{
	public:
		ScriptArray<wchar_t> GetDebugAbbrev()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PathNode.GetDebugAbbrev");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
