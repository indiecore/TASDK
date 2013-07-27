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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
