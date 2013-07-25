#pragma once
#include "TribesGame.TrCollisionProxy.h"
#include "TribesGame.TrProjectile.h"
#include "Engine.SoundCue.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Actor.h"
#include "Engine.PhysicsVolume.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_Grenade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_Grenade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_Grenade." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_Grenade : public TrProjectile
	{
	public:
		ADD_VAR(::BoolProperty, m_bStuckOnPlayer, 0x1)
		ADD_VAR(::FloatProperty, m_fProxyDetonationHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fProxyDetonationRadius, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_CollisionProxyClass)
		ADD_OBJECT(TrCollisionProxy, m_CollisionProxy)
		ADD_VAR(::FloatProperty, m_fStuckMomentumMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fStuckDamageMultiplier, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_OverloadHitNormal, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_StuckOnPawnLoopingSound)
		ADD_OBJECT(ParticleSystem, m_StuckOnTargetTemplate)
		ADD_VAR(::FloatProperty, m_fExplosionTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bSpawnProxyOnInit, 0x80)
		ADD_VAR(::BoolProperty, m_bScanProxyOnInit, 0x40)
		ADD_VAR(::BoolProperty, m_bFullyInheritVelocity, 0x20)
		ADD_VAR(::BoolProperty, m_bDoRandSpin, 0x10)
		ADD_VAR(::BoolProperty, m_bBounceRequiredForExplode, 0x8)
		ADD_VAR(::BoolProperty, m_bExplodeOnTouchEvent, 0x4)
		ADD_VAR(::BoolProperty, m_bTimedExplosion, 0x2)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.InitProjectile");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Direction;
			*(ScriptClass**)(params + 12) = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnCollisionProxy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.SpawnCollisionProxy");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyCollisionProxy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.DestroyCollisionProxy");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyInheritance(Vector ProjectileDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.ApplyInheritance");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = ProjectileDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.HitWall");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 16) = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.ProcessTouch");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PhysicsVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.PhysicsVolumeChange");
			byte* params = (byte*)malloc(4);
			*(class PhysicsVolume**)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.Explode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool StickToTarget(class Actor* Target, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.StickToTarget");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Target;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void PlayStuckOnEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.PlayStuckOnEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MyOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.MyOnParticleSystemFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnEnteredDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.PawnEnteredDetonationArea");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnLeftDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.PawnLeftDetonationArea");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NativeExplode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Grenade.NativeExplode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
