#pragma once
#include "Engine.DamageType.h"
#include "UTGame.UTGib.h"
#include "Engine.CameraAnim.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTPawn.h"
#include "Engine.Pawn.h"
#include "Engine.Canvas.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDamageType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTDamageType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDamageType." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDamageType : public DamageType
	{
	public:
		ADD_OBJECT(CameraAnim, DamageCameraAnim)
		ADD_VAR(::BoolProperty, bLocationalHit, 0x2)
		ADD_OBJECT(ScriptClass, DamageWeaponClass)
		ADD_VAR(::BoolProperty, bDirectDamage, 0x10)
		ADD_VAR(::BoolProperty, bHeadGibCamera, 0x40000)
		ADD_VAR(::FloatProperty, GibPerterbation, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseDamageBasedDeathEffects, 0x2000)
		ADD_VAR(::NameProperty, DeathAnim, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAnimateHipsForDeathAnim, 0x8000)
		ADD_VAR(::FloatProperty, DeathAnimRate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSeversHead, 0x20)
		ADD_VAR(::FloatProperty, MotorDecayTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StopAnimAfterDamageInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageOverlayTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, XRayEffectTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'DamageBodyMatColor'!
		ADD_VAR(::BoolProperty, bCausesBloodSplatterDecals, 0x80000)
		ADD_VAR(::BoolProperty, bCausesBlood, 0x1)
		ADD_VAR(::FloatProperty, PhysicsTakeHitMomentumThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSpecialDeathCamera, 0x4000)
		ADD_VAR(::BoolProperty, bThrowRagdoll, 0x100)
		ADD_VAR(::BoolProperty, bOverrideHitEffectColor, 0x20000)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'HitEffectColor'!
		ADD_VAR(::StrProperty, MaleSuicide, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FemaleSuicide, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeathString, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CustomTauntIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, RewardEvent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RewardAnnouncementSwitch, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, RewardAnnouncementClass)
		ADD_VAR(::IntProperty, RewardCount, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SuicideStatsName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DeathStatsName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, KillStatsName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NodeDamageScaling, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DeathCameraEffectInstigator)
		ADD_OBJECT(ScriptClass, DeathCameraEffectVictim)
		ADD_OBJECT(ParticleSystem, GibTrail)
		ADD_VAR(::IntProperty, DamageWeaponFireMode, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AlwaysGibDamageThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinAccumulateDamageThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GibThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDontHurtInstigator, 0x100000)
		ADD_VAR(::BoolProperty, bComplainFriendlyFire, 0x10000)
		ADD_VAR(::BoolProperty, bSelfDestructDamage, 0x1000)
		ADD_VAR(::BoolProperty, bVehicleHit, 0x800)
		ADD_VAR(::BoolProperty, bBulletHit, 0x400)
		ADD_VAR(::BoolProperty, bLeaveBodyEffect, 0x200)
		ADD_VAR(::BoolProperty, bUseTearOffMomentum, 0x80)
		ADD_VAR(::BoolProperty, bCauseConvulsions, 0x40)
		ADD_VAR(::BoolProperty, bNeverGibs, 0x8)
		ADD_VAR(::BoolProperty, bAlwaysGibs, 0x4)
		ADD_VAR(::FloatProperty, DeathOverlayTime, 0xFFFFFFFF)
		ScriptClass* GetDeathCameraEffectInstigator(class UTPawn* UTP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.GetDeathCameraEffectInstigator");
			byte* params = (byte*)malloc(8);
			*(class UTPawn**)params = UTP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		float GetHitEffectDuration(class Pawn* P, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.GetHitEffectDuration");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = P;
			*(float*)(params + 4) = Damage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		bool ShouldGib(class UTPawn* DeadPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.ShouldGib");
			byte* params = (byte*)malloc(8);
			*(class UTPawn**)params = DeadPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptClass* GetDeathCameraEffectVictim(class UTPawn* UTP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.GetDeathCameraEffectVictim");
			byte* params = (byte*)malloc(8);
			*(class UTPawn**)params = UTP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> DeathMessage(class PlayerReplicationInfo* Killer, class PlayerReplicationInfo* Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.DeathMessage");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Killer;
			*(class PlayerReplicationInfo**)(params + 4) = Victim;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> SuicideMessage(class PlayerReplicationInfo* Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.SuicideMessage");
			byte* params = (byte*)malloc(16);
			*(class PlayerReplicationInfo**)params = Victim;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void SpawnHitEffect(class Pawn* P, float Damage, Vector Momentum, ScriptName BoneName, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.SpawnHitEffect");
			byte* params = (byte*)malloc(40);
			*(class Pawn**)params = P;
			*(float*)(params + 4) = Damage;
			*(Vector*)(params + 8) = Momentum;
			*(ScriptName*)(params + 20) = BoneName;
			*(Vector*)(params + 28) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int IncrementKills(class UTPlayerReplicationInfo* KillerPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.IncrementKills");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void IncrementDeaths(class UTPlayerReplicationInfo* KilledPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.IncrementDeaths");
			byte* params = (byte*)malloc(4);
			*(class UTPlayerReplicationInfo**)params = KilledPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementSuicides(class UTPlayerReplicationInfo* KilledPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.IncrementSuicides");
			byte* params = (byte*)malloc(4);
			*(class UTPlayerReplicationInfo**)params = KilledPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptName GetStatsName(ScriptName StatType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.GetStatsName");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = StatType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 8);
			free(params);
			return returnVal;
		}
		void ScoreKill(class UTPlayerReplicationInfo* KillerPRI, class UTPlayerReplicationInfo* KilledPRI, class Pawn* KilledPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.ScoreKill");
			byte* params = (byte*)malloc(12);
			*(class UTPlayerReplicationInfo**)params = KillerPRI;
			*(class UTPlayerReplicationInfo**)(params + 4) = KilledPRI;
			*(class Pawn**)(params + 8) = KilledPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnTornOff(class UTPawn* DeadPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.PawnTornOff");
			byte* params = (byte*)malloc(4);
			*(class UTPawn**)params = DeadPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnGibEffects(class UTGib* Gib)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.SpawnGibEffects");
			byte* params = (byte*)malloc(4);
			*(class UTGib**)params = Gib;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoCustomDamageEffects(class UTPawn* ThePawn, ScriptClass* TheDamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void*& HitInfo, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.DoCustomDamageEffects");
			byte* params = (byte*)malloc(48);
			*(class UTPawn**)params = ThePawn;
			*(ScriptClass**)(params + 4) = TheDamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 8) = HitInfo;
			*(Vector*)(params + 36) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			HitInfo = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 8);
			free(params);
		}
		void CreateDeathSkeleton(class UTPawn* ThePawn, ScriptClass* TheDamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void*& HitInfo, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.CreateDeathSkeleton");
			byte* params = (byte*)malloc(48);
			*(class UTPawn**)params = ThePawn;
			*(ScriptClass**)(params + 4) = TheDamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 8) = HitInfo;
			*(Vector*)(params + 36) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			HitInfo = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 8);
			free(params);
		}
		void BoneBreaker(class UTPawn* ThePawn, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* TheMesh, Vector Impulse, Vector HitLocation, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.BoneBreaker");
			byte* params = (byte*)malloc(40);
			*(class UTPawn**)params = ThePawn;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = TheMesh;
			*(Vector*)(params + 8) = Impulse;
			*(Vector*)(params + 20) = HitLocation;
			*(ScriptName*)(params + 32) = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateDeathGoreChunks(class UTPawn* ThePawn, ScriptClass* TheDamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void*& HitInfo, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.CreateDeathGoreChunks");
			byte* params = (byte*)malloc(48);
			*(class UTPawn**)params = ThePawn;
			*(ScriptClass**)(params + 4) = TheDamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 8) = HitInfo;
			*(Vector*)(params + 36) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			HitInfo = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 8);
			free(params);
		}
		void SpawnExtraGibEffects(class UTGib* TheGib)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.SpawnExtraGibEffects");
			byte* params = (byte*)malloc(4);
			*(class UTGib**)params = TheGib;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.DrawKillIcon");
			byte* params = (byte*)malloc(20);
			*(class Canvas**)params = Canvas;
			*(float*)(params + 4) = ScreenX;
			*(float*)(params + 8) = ScreenY;
			*(float*)(params + 12) = HUDScaleX;
			*(float*)(params + 16) = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CalcDeathCamera(class UTPawn* P, float DeltaTime, Vector& CameraLocation, Rotator& CameraRotation, float& CameraFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.CalcDeathCamera");
			byte* params = (byte*)malloc(36);
			*(class UTPawn**)params = P;
			*(float*)(params + 4) = DeltaTime;
			*(Vector*)(params + 8) = CameraLocation;
			*(Rotator*)(params + 20) = CameraRotation;
			*(float*)(params + 32) = CameraFOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CameraLocation = *(Vector*)(params + 8);
			CameraRotation = *(Rotator*)(params + 20);
			CameraFOV = *(float*)(params + 32);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
