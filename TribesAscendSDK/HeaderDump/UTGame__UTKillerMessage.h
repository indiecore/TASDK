#pragma once
#include "UTGame__UTWeaponKillMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTKillerMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTKillerMessage : public UTWeaponKillMessage
	{
	public:
		ADD_VAR(::StrProperty, OtherKilledTrailer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OtherKilled, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OtherKilledPrefix, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouTeamKilledTrailer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouTeamKilled, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouKilledTrailer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouKilled, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
	};
}
#undef ADD_VAR
