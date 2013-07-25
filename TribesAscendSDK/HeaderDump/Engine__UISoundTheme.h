#pragma once
#include "Core__Object.h"
#include "Engine__PlayerController.h"
namespace UnrealScript
{
	class UISoundTheme : public Object
	{
	public:
		void ProcessSoundEvent(ScriptName SoundEventName, class PlayerController* SoundOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UISoundTheme.ProcessSoundEvent");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SoundEventName;
			*(class PlayerController**)(params + 8) = SoundOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
