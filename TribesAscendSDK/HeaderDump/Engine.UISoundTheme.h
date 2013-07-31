#pragma once
#include "Core.Object.h"
#include "Engine.PlayerController.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UISoundTheme : public Object
	{
	public:
		struct SoundEventMapping
		{
		public:
			ADD_OBJECT(SoundCue, SoundToPlay, 8)
			ADD_STRUCT(ScriptName, SoundEventName, 0)
		};
		ADD_STRUCT(ScriptArray<UISoundTheme::SoundEventMapping>, SoundEventBindings, 60)
		void ProcessSoundEvent(ScriptName SoundEventName, class PlayerController* SoundOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29228);
			byte params[12] = { NULL };
			*(ScriptName*)params = SoundEventName;
			*(class PlayerController**)&params[8] = SoundOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
