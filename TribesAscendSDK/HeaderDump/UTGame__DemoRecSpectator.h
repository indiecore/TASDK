#pragma once
#include "Engine__Actor.h"
#include "UTGame__UTPlayerController.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.DemoRecSpectator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.DemoRecSpectator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DemoRecSpectator : public UTPlayerController
	{
	public:
		ADD_VAR(::FloatProperty, AutoSwitchPlayerInterval, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, MyRealViewTarget)
		ADD_VAR(::BoolProperty, bAutoSwitchPlayers, 0x4)
		ADD_VAR(::BoolProperty, bLockRotationToViewTarget, 0x2)
		ADD_VAR(::BoolProperty, bFindPlayer, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ReceivedPlayer'
		// Here lies the not-yet-implemented method 'InitPlayerReplicationInfo'
		// Here lies the not-yet-implemented method 'Slomo'
		// Here lies the not-yet-implemented method 'ViewClass'
		// Here lies the not-yet-implemented method 'DemoViewNextPlayer'
		// Here lies the not-yet-implemented method 'SetViewTarget'
		// Here lies the not-yet-implemented method 'ServerViewSelf'
		// Here lies the not-yet-implemented method 'ClientSetRealViewTarget'
		// Here lies the not-yet-implemented method 'SetPause'
		// Here lies the not-yet-implemented method 'Pause'
		// Here lies the not-yet-implemented method 'GetPlayerViewPoint'
		// Here lies the not-yet-implemented method 'UpdateRotation'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
