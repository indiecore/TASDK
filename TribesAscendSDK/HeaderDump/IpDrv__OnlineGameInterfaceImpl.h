#pragma once
#include "IpDrv__OnlineSubsystemCommonImpl.h"
#include "Core__Object.h"
#include "Engine__OnlineGameSearch.h"
#include "Engine__OnlineGameSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.OnlineGameInterfaceImpl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.OnlineGameInterfaceImpl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.OnlineGameInterfaceImpl." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineGameInterfaceImpl : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SessionInfo'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'LanBeacon'!
		ADD_VAR(::FloatProperty, LanQueryTimeout, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LanQueryTimeLeft, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LanPacketPlatformMask, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LanGameUniqueId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LanAnnouncePort, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LanNonce, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LanBeaconState, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentGameState, 0xFFFFFFFF)
		ADD_OBJECT(OnlineGameSearch, GameSearch)
		ADD_OBJECT(OnlineGameSettings, GameSettings)
		ADD_OBJECT(OnlineSubsystemCommonImpl, OwningSubsystem)
		// Here lies the not-yet-implemented method 'OnCreateOnlineGameComplete'
		// Here lies the not-yet-implemented method 'OnUpdateOnlineGameComplete'
		// Here lies the not-yet-implemented method 'OnDestroyOnlineGameComplete'
		// Here lies the not-yet-implemented method 'OnJoinOnlineGameComplete'
		// Here lies the not-yet-implemented method 'OnMigrateOnlineGameComplete'
		// Here lies the not-yet-implemented method 'OnJoinMigratedOnlineGameComplete'
		// Here lies the not-yet-implemented method 'OnRecalculateSkillRatingComplete'
		// Here lies the not-yet-implemented method 'OnStartOnlineGameComplete'
		// Here lies the not-yet-implemented method 'OnEndOnlineGameComplete'
		// Here lies the not-yet-implemented method 'OnFindOnlineGamesComplete'
		// Here lies the not-yet-implemented method 'OnCancelFindOnlineGamesComplete'
		// Here lies the not-yet-implemented method 'OnQosStatusChanged'
		// Here lies the not-yet-implemented method 'OnGameInviteAccepted'
		// Here lies the not-yet-implemented method 'OnArbitrationRegistrationComplete'
		// Here lies the not-yet-implemented method 'OnUnregisterPlayerComplete'
		// Here lies the not-yet-implemented method 'OnRegisterPlayerComplete'
		// Here lies the not-yet-implemented method 'GetGameSettings'
		// Here lies the not-yet-implemented method 'GetGameSearch'
		// Here lies the not-yet-implemented method 'CreateOnlineGame'
		// Here lies the not-yet-implemented method 'AddCreateOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearCreateOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'UpdateOnlineGame'
		// Here lies the not-yet-implemented method 'AddUpdateOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearUpdateOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'DestroyOnlineGame'
		// Here lies the not-yet-implemented method 'AddDestroyOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearDestroyOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'FindOnlineGames'
		// Here lies the not-yet-implemented method 'AddFindOnlineGamesCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearFindOnlineGamesCompleteDelegate'
		// Here lies the not-yet-implemented method 'CancelFindOnlineGames'
		// Here lies the not-yet-implemented method 'AddCancelFindOnlineGamesCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearCancelFindOnlineGamesCompleteDelegate'
		// Here lies the not-yet-implemented method 'FreeSearchResults'
		// Here lies the not-yet-implemented method 'JoinOnlineGame'
		// Here lies the not-yet-implemented method 'AddJoinOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearJoinOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'GetResolvedConnectString'
		// Here lies the not-yet-implemented method 'RegisterPlayer'
		// Here lies the not-yet-implemented method 'AddRegisterPlayerCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearRegisterPlayerCompleteDelegate'
		// Here lies the not-yet-implemented method 'UnregisterPlayer'
		// Here lies the not-yet-implemented method 'AddUnregisterPlayerCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearUnregisterPlayerCompleteDelegate'
		// Here lies the not-yet-implemented method 'StartOnlineGame'
		// Here lies the not-yet-implemented method 'AddStartOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearStartOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'EndOnlineGame'
		// Here lies the not-yet-implemented method 'AddEndOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearEndOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'RegisterForArbitration'
		// Here lies the not-yet-implemented method 'AddArbitrationRegistrationCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearArbitrationRegistrationCompleteDelegate'
		// Here lies the not-yet-implemented method 'GetArbitratedPlayers'
		// Here lies the not-yet-implemented method 'AddGameInviteAcceptedDelegate'
		// Here lies the not-yet-implemented method 'ClearGameInviteAcceptedDelegate'
		// Here lies the not-yet-implemented method 'AcceptGameInvite'
		// Here lies the not-yet-implemented method 'RecalculateSkillRating'
		// Here lies the not-yet-implemented method 'AddRecalculateSkillRatingCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearRecalculateSkillRatingCompleteDelegate'
		// Here lies the not-yet-implemented method 'MigrateOnlineGame'
		// Here lies the not-yet-implemented method 'AddMigrateOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearMigrateOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'JoinMigratedOnlineGame'
		// Here lies the not-yet-implemented method 'AddJoinMigratedOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearJoinMigratedOnlineGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'QueryNonAdvertisedData'
		// Here lies the not-yet-implemented method 'ReadPlatformSpecificSessionInfo'
		// Here lies the not-yet-implemented method 'ReadPlatformSpecificSessionInfoBySessionName'
		// Here lies the not-yet-implemented method 'BindPlatformSpecificSessionToSearch'
		// Here lies the not-yet-implemented method 'AddQosStatusChangedDelegate'
		// Here lies the not-yet-implemented method 'ClearQosStatusChangedDelegate'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
