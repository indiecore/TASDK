#pragma once
#include "UTGame__UTDeathmatch.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTeamGame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTeamGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTeamGame : public UTDeathmatch
	{
	public:
		ADD_VAR(::NameProperty, FlagKillMessageName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SwapRequestTime, 0xFFFFFFFF)
		ADD_OBJECT(PlayerController, PendingTeamSwap)
		ADD_VAR(::StrProperty, TeamFactions, 0xFFFFFFFF)
		ADD_OBJECT(UTTeamInfo, Teams)
		ADD_VAR(::FloatProperty, TeammateBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FriendlyFireScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceAllRed, 0x20)
		ADD_VAR(::BoolProperty, bScoreVictimsTarget, 0x10)
		ADD_VAR(::BoolProperty, bSpawnInTeamArea, 0x8)
		ADD_VAR(::BoolProperty, bScoreTeamKills, 0x4)
		ADD_VAR(::BoolProperty, bAllowNonTeamChat, 0x2)
		ADD_VAR(::BoolProperty, bPlayersBalanceTeams, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
