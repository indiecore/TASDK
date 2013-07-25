#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineRecentPlayersList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineRecentPlayersList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineRecentPlayersList : public Object
	{
	public:
		ADD_VAR(::IntProperty, RecentPartiesAddIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RecentPlayersAddIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxRecentParties, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxRecentPlayers, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineRecentPlayersList.RecentParty' for the property named 'LastParty'!
		// Here lies the not-yet-implemented method 'AddPlayerToRecentPlayers'
		// Here lies the not-yet-implemented method 'ClearRecentPlayers'
		// Here lies the not-yet-implemented method 'AddPartyToRecentParties'
		// Here lies the not-yet-implemented method 'ClearRecentParties'
		// Here lies the not-yet-implemented method 'GetPlayersFromRecentParties'
		// Here lies the not-yet-implemented method 'GetPlayersFromCurrentPlayers'
		// Here lies the not-yet-implemented method 'GetSkillForCurrentPlayer'
		// Here lies the not-yet-implemented method 'GetTeamForCurrentPlayer'
		// Here lies the not-yet-implemented method 'SetLastParty'
		// Here lies the not-yet-implemented method 'ShowRecentPlayerList'
		// Here lies the not-yet-implemented method 'ShowRecentPartiesPlayerList'
		// Here lies the not-yet-implemented method 'ShowLastPartyPlayerList'
		// Here lies the not-yet-implemented method 'ShowCurrentPlayersList'
		// Here lies the not-yet-implemented method 'SetCurrentPlayersList'
		// Here lies the not-yet-implemented method 'GetCurrentPlayersListCount'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
