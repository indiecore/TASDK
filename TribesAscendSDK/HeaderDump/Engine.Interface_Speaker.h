#pragma once
#include "Core.Interface.h"
#include "Engine.SoundCue.h"
namespace UnrealScript
{
	class Interface_Speaker : public Interface
	{
	public:
		void Speak(class SoundCue* Cue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interface_Speaker.Speak");
			byte* params = (byte*)malloc(4);
			*(class SoundCue**)params = Cue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
