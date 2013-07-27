#pragma once
#include "Engine.Info.h"
namespace UnrealScript
{
	class PotentialClimbWatcher : public Info
	{
	public:
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PotentialClimbWatcher.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
