#pragma once
#include "UTGame__UTLocalMessage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTKillsRemainingMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTKillsRemainingMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTKillsRemainingMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, KillsRemainStrings, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, KillsRemainSounds)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
