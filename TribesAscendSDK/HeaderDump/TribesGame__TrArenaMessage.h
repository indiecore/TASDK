#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrArenaMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrArenaMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, WeLostTheRound, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WeWonTheRound, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CannotSwitchTeam, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NoRespawnsRemain, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Fight, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouAreLastManStanding, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TeamRespawnsDepleted, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FiveTeamRespawnsRemain, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TenTeamRespawnsRemain, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'ClientReceive'
	};
}
#undef ADD_VAR
