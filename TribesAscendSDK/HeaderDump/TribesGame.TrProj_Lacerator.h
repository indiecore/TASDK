#pragma once
#include "TribesGame.TrProjectile.h"
#include "Engine.CameraAnim.h"
#include "Engine.SoundCue.h"
#include "UDKBase.UDKPawn.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class TrProj_Lacerator : public TrProjectile
	{
	public:
		ADD_OBJECT(CameraAnim, ShortRangeKillAnim, 860)
		ADD_BOOL(bShrinking, 856, 0x2)
		ADD_BOOL(bCheckShortRangeKill, 856, 0x1)
		ADD_OBJECT(SoundCue, HitPawnSound, 852)
		ADD_STRUCT(UDKPawn::MaterialSoundEffect, DefaultHitSound, 840)
		ADD_OBJECT(ParticleSystem, RockSmokeTemplate, 832)
		ADD_OBJECT(ParticleSystem, BounceTemplate, 828)
		ADD_STRUCT(float, ShrinkTimer, 824)
		ADD_STRUCT(float, DamageAttenuation, 820)
		ADD_STRUCT(int, Bounces, 816)
		void InitProjectile(Object::Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.InitProjectile");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.SpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InternalSpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.InternalSpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetDamage(class Actor* Other, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.GetDamage");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float GetMomentumTransfer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.GetMomentumTransfer");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void ProcessTouch(class Actor* Other, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.ProcessTouch");
			byte params[28] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Landed(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.Landed");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SpawnImpactEffect(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.SpawnImpactEffect");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void HitWall(Object::Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.HitWall");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartToShrink()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.StartToShrink");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MyOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.MyOnParticleSystemFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
