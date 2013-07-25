#pragma once
#include "Engine.Keypoint.h"
namespace UnrealScript
{
	class PathTargetPoint : public Keypoint
	{
	public:
		bool ShouldBeHiddenBySHOW_NavigationNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PathTargetPoint.ShouldBeHiddenBySHOW_NavigationNodes");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
