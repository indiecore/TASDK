#pragma once
#include "UTGame__UTWeaponKillMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVictimMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTVictimMessage : public UTWeaponKillMessage
	{
	public:
		ADD_VAR(::StrProperty, TelefragString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ViperKamikazeString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ScorpionKamikazeString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SpiderMineString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RunOverString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OrbSuicideString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KilledByTrailer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouWereKilledBy, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
	};
}
#undef ADD_VAR
