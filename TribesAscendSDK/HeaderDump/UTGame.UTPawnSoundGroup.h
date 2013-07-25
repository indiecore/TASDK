#pragma once
#include "Core.Object.h"
#include "Engine.SoundCue.h"
#include "Engine.Pawn.h"
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
		class SoundCue* GetFootstepSound(int FootDown, ScriptName MaterialType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.GetFootstepSound");
			byte* params = (byte*)malloc(16);
			*(int*)params = FootDown;
			*(ScriptName*)(params + 4) = MaterialType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundCue**)(params + 12);
			free(params);
			return returnVal;
		}
		class SoundCue* GetLandSound(ScriptName MaterialType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.GetLandSound");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = MaterialType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundCue**)(params + 8);
			free(params);
			return returnVal;
		}
		class SoundCue* GetJumpSound(ScriptName MaterialType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.GetJumpSound");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = MaterialType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundCue**)(params + 8);
			free(params);
			return returnVal;
		}
		void PlayInstagibSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayInstagibSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayBulletImpact(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayBulletImpact");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayCrushedSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayCrushedSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayBodyExplosion(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayBodyExplosion");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDodgeSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayDodgeSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDoubleJumpSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayDoubleJumpSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayJumpSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayJumpSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayLandSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayLandSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayFallingDamageLandSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayFallingDamageLandSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDyingSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayDyingSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayTakeHitSound(class Pawn* P, int Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayTakeHitSound");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			*(int*)(params + 4) = Damage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayGibSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayGibSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayGaspSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayGaspSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDrownSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayDrownSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
