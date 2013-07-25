#pragma once
#include "UDKBase__UDKPickupFactory.h"
#include "UTGame__UTHUD.h"
#include "Engine__ForceFeedbackWaveform.h"
#include "Engine__SoundCue.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#include "Engine__Projectile.h"
#include "UTGame__UTBot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTPickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTPickupFactory : public UDKPickupFactory
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, PickUpWaveForm)
		ADD_VAR(::FloatProperty, LastSeekNotificationTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasLocationSpeech, 0x1)
		ADD_VAR(::NameProperty, PickupStatName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, RespawnSound)
		ADD_OBJECT(Controller, TeamOwner)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SetResOut'
		// Here lies the not-yet-implemented method 'DisablePickup'
		// Here lies the not-yet-implemented method 'ShutDown'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'ShouldCamp'
		// Here lies the not-yet-implemented method 'UpdateHUD'
		// Here lies the not-yet-implemented method 'RespawnEffect'
		// Here lies the not-yet-implemented method 'StopsProjectile'
		// Here lies the not-yet-implemented method 'StartPulse'
		// Here lies the not-yet-implemented method 'SetPickupMesh'
		// Here lies the not-yet-implemented method 'GetPickupStatName'
		// Here lies the not-yet-implemented method 'InitPickupMeshEffects'
		// Here lies the not-yet-implemented method 'SetPickupVisible'
		// Here lies the not-yet-implemented method 'SetPickupHidden'
		// Here lies the not-yet-implemented method 'SetInitialState'
		// Here lies the not-yet-implemented method 'PickedUpBy'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
