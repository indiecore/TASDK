#pragma once
#include "TribesGame.TrCollisionProxy.h"
#include "TribesGame.TrProjectile.h"
#include "Engine.Pawn.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.SoundCue.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PhysicsVolume.h"
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
	class TrProj_Grenade : public TrProjectile
	{
	public:
		ADD_BOOL(m_bStuckOnPlayer, 816, 0x1)
		ADD_STRUCT(ScriptArray<class Pawn*>, m_PotentialTargets, 872)
		ADD_STRUCT(float, m_fProxyDetonationHeight, 868)
		ADD_STRUCT(float, m_fProxyDetonationRadius, 864)
		ADD_OBJECT(ScriptClass, m_CollisionProxyClass, 860)
		ADD_OBJECT(TrCollisionProxy, m_CollisionProxy, 856)
		ADD_STRUCT(float, m_fStuckMomentumMultiplier, 852)
		ADD_STRUCT(float, m_fStuckDamageMultiplier, 848)
		ADD_STRUCT(Vector, m_OverloadHitNormal, 836)
		ADD_OBJECT(SoundCue, m_StuckOnPawnLoopingSound, 832)
		ADD_OBJECT(ParticleSystem, m_StuckOnTargetTemplate, 828)
		ADD_STRUCT(float, m_fExplosionTime, 820)
		ADD_BOOL(m_bSpawnProxyOnInit, 816, 0x80)
		ADD_BOOL(m_bScanProxyOnInit, 816, 0x40)
		ADD_BOOL(m_bFullyInheritVelocity, 816, 0x20)
		ADD_BOOL(m_bDoRandSpin, 816, 0x10)
		ADD_BOOL(m_bBounceRequiredForExplode, 816, 0x8)
		ADD_BOOL(m_bExplodeOnTouchEvent, 816, 0x4)
		ADD_BOOL(m_bTimedExplosion, 816, 0x2)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107823);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107824);
			byte params[16] = { NULL };
			*(Vector*)params = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnCollisionProxy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107828);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyCollisionProxy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107829);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107830);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyInheritance(Vector ProjectileDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107831);
			byte params[12] = { NULL };
			*(Vector*)params = ProjectileDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107834);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107835);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107839);
			byte params[28] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PhysicsVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107843);
			byte params[4] = { NULL };
			*(class PhysicsVolume**)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107845);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StickToTarget(class Actor* Target, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107848);
			byte params[32] = { NULL };
			*(class Actor**)params = Target;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void PlayStuckOnEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107854);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MyOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107856);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnEnteredDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107858);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeftDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107860);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NativeExplode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107862);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
