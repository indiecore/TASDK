#pragma once
#include "Engine.Info.h"
namespace UnrealScript
{
	class PotentialClimbWatcher : public Info
	{
	public:
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24758);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
