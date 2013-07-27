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
			byte params[4] = { NULL };
			*(class SoundCue**)&params[0] = Cue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
