#pragma once
#include "TribesGame__GFxTrMenuMoviePlayer.h"
#include "Core__Object.h"
#include "OnlineSubsystemMcts__OnlineGameInterfaceMcts.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrQueueManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrQueueManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrQueueManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bQueued, 0x1)
		ADD_VAR(::BoolProperty, bJoiningCustom, 0x4)
		ADD_VAR(::StrProperty, QueueFriend, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFilterOwner, 0x8)
		ADD_VAR(::IntProperty, GameTypeId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ServerIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MapSlots, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNeedPassword, 0x2)
		ADD_OBJECT(GFxTrMenuMoviePlayer, TrOuter)
		ADD_OBJECT(OnlineGameInterfaceMcts, OnlineGameMcts)
		ADD_VAR(::BoolProperty, bFavoriteSort, 0x1000)
		ADD_VAR(::BoolProperty, bPasswordSort, 0x800)
		ADD_VAR(::BoolProperty, bSlotsSort, 0x400)
		ADD_VAR(::BoolProperty, bRangeSort, 0x200)
		ADD_VAR(::BoolProperty, bRulesSort, 0x100)
		ADD_VAR(::BoolProperty, bTypeSort, 0x80)
		ADD_VAR(::BoolProperty, bPingSort, 0x40)
		ADD_VAR(::BoolProperty, bNameSort, 0x20)
		ADD_VAR(::BoolProperty, bMapSort, 0x10)
		ADD_VAR(::IntProperty, PasswordQueue, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PasswordIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ProfileIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, queueId, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetStatus'
		// Here lies the not-yet-implemented method 'SetPropNumber'
		// Here lies the not-yet-implemented method 'GetNextMapId'
		// Here lies the not-yet-implemented method 'GetMapName'
		// Here lies the not-yet-implemented method 'GetProfileName'
		// Here lies the not-yet-implemented method 'GetProfileDesc'
		// Here lies the not-yet-implemented method 'GetServerGameTypeName'
		// Here lies the not-yet-implemented method 'GetProfileGameType'
		// Here lies the not-yet-implemented method 'GetServerRotationName'
		// Here lies the not-yet-implemented method 'IsGameTypeFiltered'
		// Here lies the not-yet-implemented method 'AmServerOwner'
		// Here lies the not-yet-implemented method 'GetPropNumber'
		// Here lies the not-yet-implemented method 'GetServerTimeFormat'
		// Here lies the not-yet-implemented method 'GetQueueCaseId'
		// Here lies the not-yet-implemented method 'GetServerOnline'
		// Here lies the not-yet-implemented method 'GetServerName'
		// Here lies the not-yet-implemented method 'AddCustomServer'
		// Here lies the not-yet-implemented method 'GetProfileRotation'
		// Here lies the not-yet-implemented method 'GetServerExpired'
		// Here lies the not-yet-implemented method 'GetServerTime'
		// Here lies the not-yet-implemented method 'CustomStart'
		// Here lies the not-yet-implemented method 'CustomStop'
		// Here lies the not-yet-implemented method 'CustomShutdown'
		// Here lies the not-yet-implemented method 'CustomNextMap'
		// Here lies the not-yet-implemented method 'CustomKick'
		// Here lies the not-yet-implemented method 'CustomBan'
		// Here lies the not-yet-implemented method 'AddCustomServerTime'
		// Here lies the not-yet-implemented method 'GetPropMin'
		// Here lies the not-yet-implemented method 'GetPropMax'
		// Here lies the not-yet-implemented method 'GetAdminPassword'
		// Here lies the not-yet-implemented method 'GetPublicPassword'
		// Here lies the not-yet-implemented method 'CustomSetName'
		// Here lies the not-yet-implemented method 'SetPropString'
		// Here lies the not-yet-implemented method 'GetProfileRegion'
		// Here lies the not-yet-implemented method 'CustomLogin'
		// Here lies the not-yet-implemented method 'FavoriteSortB'
		// Here lies the not-yet-implemented method 'PasswordSortB'
		// Here lies the not-yet-implemented method 'SlotsSortB'
		// Here lies the not-yet-implemented method 'RangeSortB'
		// Here lies the not-yet-implemented method 'RulesSortB'
		// Here lies the not-yet-implemented method 'TypeSortB'
		// Here lies the not-yet-implemented method 'PingSortB'
		// Here lies the not-yet-implemented method 'NameSortB'
		// Here lies the not-yet-implemented method 'MapSortB'
		// Here lies the not-yet-implemented method 'FavoriteSortA'
		// Here lies the not-yet-implemented method 'PasswordSortA'
		// Here lies the not-yet-implemented method 'SlotsSortA'
		// Here lies the not-yet-implemented method 'RangeSortA'
		// Here lies the not-yet-implemented method 'RulesSortA'
		// Here lies the not-yet-implemented method 'TypeSortA'
		// Here lies the not-yet-implemented method 'PingSortA'
		// Here lies the not-yet-implemented method 'NameSortA'
		// Here lies the not-yet-implemented method 'MapSortA'
		// Here lies the not-yet-implemented method 'ForceGoHome'
		// Here lies the not-yet-implemented method 'OpenLocal'
		// Here lies the not-yet-implemented method 'GetCustomServers'
		// Here lies the not-yet-implemented method 'RequestCustomServers'
		// Here lies the not-yet-implemented method 'RefreshRentedServers'
		// Here lies the not-yet-implemented method 'GetPropString'
		// Here lies the not-yet-implemented method 'SetLocalName'
		// Here lies the not-yet-implemented method 'MatchQueueJoin'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'LeaveMatchmaking'
		// Here lies the not-yet-implemented method 'JoinQueue'
		// Here lies the not-yet-implemented method 'SetPlayerQueued'
		// Here lies the not-yet-implemented method 'JoinFriend'
		// Here lies the not-yet-implemented method 'ExitGameInProgress'
		// Here lies the not-yet-implemented method 'ServerInfoLoaded'
		// Here lies the not-yet-implemented method 'JoinCustomServer'
		// Here lies the not-yet-implemented method 'JoinProtectedServer'
		// Here lies the not-yet-implemented method 'FavoriteServer'
		// Here lies the not-yet-implemented method 'PasswordServer'
		// Here lies the not-yet-implemented method 'SetActiveServer'
		// Here lies the not-yet-implemented method 'ServerPage'
		// Here lies the not-yet-implemented method 'ServerSort'
		// Here lies the not-yet-implemented method 'SortOn'
		// Here lies the not-yet-implemented method 'GetSlots'
		// Here lies the not-yet-implemented method 'GetGameCaseId'
		// Here lies the not-yet-implemented method 'AddServerConfig'
		// Here lies the not-yet-implemented method 'AddProfileConfig'
		// Here lies the not-yet-implemented method 'ResetRotation'
		// Here lies the not-yet-implemented method 'GetDefaultMapId'
		// Here lies the not-yet-implemented method 'MarkFavorite'
		// Here lies the not-yet-implemented method 'FilterGameType'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
