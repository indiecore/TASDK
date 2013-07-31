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
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108555);
			byte params[16] = { NULL };
			*(Vector*)params = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108558);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InternalSpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108559);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetDamage(class Actor* Other, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108560);
			byte params[20] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float GetMomentumTransfer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108564);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108566);
			byte params[28] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108572);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SpawnImpactEffect(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108575);
			byte params[28] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108579);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartToShrink()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108585);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MyOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108586);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
