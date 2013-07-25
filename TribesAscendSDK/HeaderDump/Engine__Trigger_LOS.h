#pragma once
#include "Engine__Trigger.h"
namespace UnrealScript
{
	class Trigger_LOS : public Trigger
	{
	public:
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger_LOS.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
