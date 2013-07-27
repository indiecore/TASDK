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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18354);
			byte params[4] = { NULL };
			*(class SoundCue**)params = Cue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
