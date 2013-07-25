#pragma once
#include "Core__Object.h"
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
	};
}
#undef ADD_OBJECT
