#pragma once
#include "UTGame__UTPlayerController.h"
#include "Engine__LocalPlayer.h"
#include "Engine__PostProcessChain.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTEntryPlayerController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTEntryPlayerController : public UTPlayerController
	{
	public:
		ADD_OBJECT(LocalPlayer, OldPlayer)
		ADD_OBJECT(PostProcessChain, EntryPostProcessChain)
		// Here lies the not-yet-implemented method 'InitInputSystem'
		// Here lies the not-yet-implemented method 'RestorePostProcessing'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'OnControllerChanged'
		// Here lies the not-yet-implemented method 'OnGameInviteReceived'
		// Here lies the not-yet-implemented method 'OnFriendInviteReceived'
		// Here lies the not-yet-implemented method 'OnFriendMessageReceived'
		// Here lies the not-yet-implemented method 'OnConnectionStatusChange'
		// Here lies the not-yet-implemented method 'OnLinkStatusChanged'
		// Here lies the not-yet-implemented method 'QuitToMainMenu'
		// Here lies the not-yet-implemented method 'SetPawnConstructionScene'
		// Here lies the not-yet-implemented method 'ShowMidGameMenu'
		// Here lies the not-yet-implemented method 'ShowScoreboard'
	};
}
#undef ADD_OBJECT
