#pragma once
#include "Engine__SoundCue.h"
#include "Core__Object.h"
#include "Engine__Pawn.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTPawnSoundGroup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTPawnSoundGroup : public Object
	{
	public:
		ADD_OBJECT(SoundCue, InstagibSound)
		ADD_OBJECT(SoundCue, BodyExplosionSound)
		ADD_OBJECT(SoundCue, CrushedSound)
		ADD_OBJECT(SoundCue, BulletImpactSound)
		ADD_OBJECT(SoundCue, DefaultLandingSound)
		ADD_OBJECT(SoundCue, DefaultFootstepSound)
		ADD_OBJECT(SoundCue, GaspSound)
		ADD_OBJECT(SoundCue, DrownSound)
		ADD_OBJECT(SoundCue, GibSound)
		ADD_OBJECT(SoundCue, HitSounds)
		ADD_OBJECT(SoundCue, DyingSound)
		ADD_OBJECT(SoundCue, FallingDamageLandSound)
		ADD_OBJECT(SoundCue, LandSound)
		ADD_OBJECT(SoundCue, DefaultJumpingSound)
		ADD_OBJECT(SoundCue, DoubleJumpSound)
		ADD_OBJECT(SoundCue, DodgeSound)
		// Here lies the not-yet-implemented method 'GetFootstepSound'
		// Here lies the not-yet-implemented method 'GetLandSound'
		// Here lies the not-yet-implemented method 'GetJumpSound'
		// Here lies the not-yet-implemented method 'PlayInstagibSound'
		// Here lies the not-yet-implemented method 'PlayBulletImpact'
		// Here lies the not-yet-implemented method 'PlayCrushedSound'
		// Here lies the not-yet-implemented method 'PlayBodyExplosion'
		// Here lies the not-yet-implemented method 'PlayDodgeSound'
		// Here lies the not-yet-implemented method 'PlayDoubleJumpSound'
		// Here lies the not-yet-implemented method 'PlayJumpSound'
		// Here lies the not-yet-implemented method 'PlayLandSound'
		// Here lies the not-yet-implemented method 'PlayFallingDamageLandSound'
		// Here lies the not-yet-implemented method 'PlayDyingSound'
		// Here lies the not-yet-implemented method 'PlayTakeHitSound'
		// Here lies the not-yet-implemented method 'PlayGibSound'
		// Here lies the not-yet-implemented method 'PlayGaspSound'
		// Here lies the not-yet-implemented method 'PlayDrownSound'
	};
}
#undef ADD_OBJECT
