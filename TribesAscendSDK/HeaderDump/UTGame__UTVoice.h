#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Engine__SoundNodeWave.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#include "UTGame__UTPlayerController.h"
#include "UTGame__UTGame.h"
#include "UTGame__UTQueuedAnnouncement.h"
#include "UTGame__UTAnnouncer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVoice." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVoice." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVoice : public UTLocalMessage
	{
	public:
		ADD_VAR(::IntProperty, LocationSpeechOffset, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, GotOurFlagSound)
		ADD_OBJECT(SoundNodeWave, MidfieldSound)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierLowSound)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierHighSound)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierHereSound)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierSound)
		ADD_OBJECT(SoundNodeWave, IncomingSound)
		// Here lies the not-yet-implemented method 'GetAckMessageIndex'
		// Here lies the not-yet-implemented method 'GetFriendlyFireMessageIndex'
		// Here lies the not-yet-implemented method 'GetGotYourBackMessageIndex'
		// Here lies the not-yet-implemented method 'GetNeedOurFlagMessageIndex'
		// Here lies the not-yet-implemented method 'ClientReceive'
		// Here lies the not-yet-implemented method 'AnnouncementSound'
		// Here lies the not-yet-implemented method 'EnemySound'
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'AllowVoiceMessage'
		// Here lies the not-yet-implemented method 'SendVoiceMessage'
		// Here lies the not-yet-implemented method 'GetMessageIndex'
		// Here lies the not-yet-implemented method 'InitStatusUpdate'
		// Here lies the not-yet-implemented method 'InitCombatUpdate'
		// Here lies the not-yet-implemented method 'SetHoldingFlagUpdate'
		// Here lies the not-yet-implemented method 'SendLocalizedMessage'
		// Here lies the not-yet-implemented method 'SendEnemyFlagCarrierHereUpdate'
		// Here lies the not-yet-implemented method 'InitSniperUpdate'
		// Here lies the not-yet-implemented method 'SendEnemyStatusUpdate'
		// Here lies the not-yet-implemented method 'SendKilledVehicleMessage'
		// Here lies the not-yet-implemented method 'KilledVehicleSound'
		// Here lies the not-yet-implemented method 'SendLocationUpdate'
		// Here lies the not-yet-implemented method 'SendInPositionMessage'
		// Here lies the not-yet-implemented method 'ShouldBeRemoved'
		// Here lies the not-yet-implemented method 'AddAnnouncement'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
