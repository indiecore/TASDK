#pragma once
#include "Engine.Keypoint.h"
namespace UnrealScript
{
	class PathTargetPoint : public Keypoint
	{
	public:
		bool ShouldBeHiddenBySHOW_NavigationNodes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24034);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
