#pragma once
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrPlayerVoice.VGSCommandToVoiceMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrPlayerVoice.VGSCommandToVoiceMap." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VGSCommandToVoiceMap
	{
	public:
		ADD_OBJECT(SoundCue, Sound)
		ADD_VAR(::ByteProperty, Command, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
