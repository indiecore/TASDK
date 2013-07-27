#pragma once
#include "Core.Object.h"
#include "Engine.SoundCue.h"
#include "Engine.Pawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTPawnSoundGroup : public Object
	{
	public:
		class FootstepSoundInfo
		{
		public:
			ADD_OBJECT(SoundCue, Sound, 8)
			ADD_STRUCT(ScriptName, MaterialType, 0)
		};
		ADD_STRUCT(ScriptArray<UTPawnSoundGroup::FootstepSoundInfo>, FootstepSounds, 108)
		ADD_STRUCT(ScriptArray<UTPawnSoundGroup::FootstepSoundInfo>, JumpingSounds, 124)
		ADD_STRUCT(ScriptArray<UTPawnSoundGroup::FootstepSoundInfo>, LandingSounds, 136)
		ADD_OBJECT(SoundCue, InstagibSound, 164)
		ADD_OBJECT(SoundCue, BodyExplosionSound, 160)
		ADD_OBJECT(SoundCue, CrushedSound, 156)
		ADD_OBJECT(SoundCue, BulletImpactSound, 152)
		ADD_OBJECT(SoundCue, DefaultLandingSound, 148)
		ADD_OBJECT(SoundCue, DefaultFootstepSound, 120)
		ADD_OBJECT(SoundCue, GaspSound, 104)
		ADD_OBJECT(SoundCue, DrownSound, 100)
		ADD_OBJECT(SoundCue, GibSound, 96)
		ADD_OBJECT(SoundCue, HitSounds, 84)
		ADD_OBJECT(SoundCue, DyingSound, 80)
		ADD_OBJECT(SoundCue, FallingDamageLandSound, 76)
		ADD_OBJECT(SoundCue, LandSound, 72)
		ADD_OBJECT(SoundCue, DefaultJumpingSound, 68)
		ADD_OBJECT(SoundCue, DoubleJumpSound, 64)
		ADD_OBJECT(SoundCue, DodgeSound, 60)
		class SoundCue* GetFootstepSound(int FootDown, ScriptName MaterialType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.GetFootstepSound");
			byte params[16] = { NULL };
			*(int*)&params[0] = FootDown;
			*(ScriptName*)&params[4] = MaterialType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[12];
		}
		class SoundCue* GetLandSound(ScriptName MaterialType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.GetLandSound");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = MaterialType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[8];
		}
		class SoundCue* GetJumpSound(ScriptName MaterialType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.GetJumpSound");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = MaterialType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[8];
		}
		void PlayInstagibSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayInstagibSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayBulletImpact(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayBulletImpact");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayCrushedSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayCrushedSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayBodyExplosion(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayBodyExplosion");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDodgeSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayDodgeSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDoubleJumpSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayDoubleJumpSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayJumpSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayJumpSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayLandSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayLandSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFallingDamageLandSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayFallingDamageLandSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDyingSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayDyingSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayTakeHitSound(class Pawn* P, int Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayTakeHitSound");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(int*)&params[4] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayGibSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayGibSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayGaspSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayGaspSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDrownSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPawnSoundGroup.PlayDrownSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
