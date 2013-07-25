#pragma once
#include "IpDrv__OnlineGameInterfaceImpl.h"
#include "Engine__OnlineGameSearch.h"
#include "OnlineSubsystemMcts__OnlineVoiceInterfaceMcts.h"
#include "OnlineSubsystemMcts__MctsOnlineSettings.h"
#include "Engine__OnlineGameSettings.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty OnlineSubsystemMcts.OnlineGameInterfaceMcts." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineGameInterfaceMcts : public OnlineGameInterfaceImpl
	{
	public:
		ADD_OBJECT(OnlineGameSearch, InviteGameSearch)
		ADD_OBJECT(OnlineVoiceInterfaceMcts, MctsVoiceInt)
		ADD_OBJECT(MctsOnlineSettings, MctsSettings)
		// Here lies the not-yet-implemented method 'OnGameInviteAccepted'
		// Here lies the not-yet-implemented method 'OnRegisterPlayerComplete'
		// Here lies the not-yet-implemented method 'OnUnregisterPlayerComplete'
		// Here lies the not-yet-implemented method 'SealMatch'
		// Here lies the not-yet-implemented method 'HoldInvites'
		// Here lies the not-yet-implemented method 'EndGame'
		// Here lies the not-yet-implemented method 'MatchQueueJoin'
		// Here lies the not-yet-implemented method 'MatchQueueLeave'
		// Here lies the not-yet-implemented method 'MatchChooseClass'
		// Here lies the not-yet-implemented method 'MatchChooseSkin'
		// Here lies the not-yet-implemented method 'MatchAcceptInvite'
		// Here lies the not-yet-implemented method 'MatchLockIn'
		// Here lies the not-yet-implemented method 'MatchLobbyEquipItems'
		// Here lies the not-yet-implemented method 'UpdateOnlineGame'
		// Here lies the not-yet-implemented method 'GetGameSettings'
		// Here lies the not-yet-implemented method 'AddGameInviteAcceptedDelegate'
		// Here lies the not-yet-implemented method 'ClearGameInviteAcceptedDelegate'
		// Here lies the not-yet-implemented method 'AcceptGameInvite'
		// Here lies the not-yet-implemented method 'RegisterPlayer'
		// Here lies the not-yet-implemented method 'AddRegisterPlayerCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearRegisterPlayerCompleteDelegate'
		// Here lies the not-yet-implemented method 'UnregisterPlayer'
		// Here lies the not-yet-implemented method 'AddUnregisterPlayerCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearUnregisterPlayerCompleteDelegate'
		// Here lies the not-yet-implemented method 'QueryNonAdvertisedData'
	};
}
#undef ADD_OBJECT
