#pragma once
#include "Engine.DamageType.h"
#include "UTGame.UTGib.h"
#include "Engine.CameraAnim.h"
#include "Core.Object.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTPawn.h"
#include "Engine.Pawn.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "Engine.Actor.h"
#include "Engine.Canvas.h"
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
	class UTDamageType : public DamageType
	{
	public:
		ADD_OBJECT(CameraAnim, DamageCameraAnim, 192)
		ADD_BOOL(bLocationalHit, 128, 0x2)
		ADD_OBJECT(ScriptClass, DamageWeaponClass, 152)
		ADD_BOOL(bDirectDamage, 128, 0x10)
		ADD_BOOL(bHeadGibCamera, 128, 0x40000)
		ADD_STRUCT(float, GibPerterbation, 132)
		ADD_BOOL(bUseDamageBasedDeathEffects, 128, 0x2000)
		ADD_STRUCT(ScriptName, DeathAnim, 172)
		ADD_BOOL(bAnimateHipsForDeathAnim, 128, 0x8000)
		ADD_STRUCT(float, DeathAnimRate, 180)
		ADD_BOOL(bSeversHead, 128, 0x20)
		ADD_STRUCT(float, MotorDecayTime, 184)
		ADD_STRUCT(float, StopAnimAfterDamageInterval, 188)
		ADD_STRUCT(float, DamageOverlayTime, 116)
		ADD_STRUCT(float, XRayEffectTime, 124)
		ADD_STRUCT(Object::LinearColor, DamageBodyMatColor, 100)
		ADD_BOOL(bCausesBloodSplatterDecals, 128, 0x80000)
		ADD_BOOL(bCausesBlood, 128, 0x1)
		ADD_STRUCT(float, PhysicsTakeHitMomentumThreshold, 148)
		ADD_BOOL(bSpecialDeathCamera, 128, 0x4000)
		ADD_BOOL(bThrowRagdoll, 128, 0x100)
		ADD_BOOL(bOverrideHitEffectColor, 128, 0x20000)
		ADD_STRUCT(Object::LinearColor, HitEffectColor, 248)
		ADD_STRUCT(ScriptString*, MaleSuicide, 288)
		ADD_STRUCT(ScriptString*, FemaleSuicide, 276)
		ADD_STRUCT(ScriptString*, DeathString, 264)
		ADD_STRUCT(int, CustomTauntIndex, 244)
		ADD_STRUCT(ScriptName, RewardEvent, 236)
		ADD_STRUCT(int, RewardAnnouncementSwitch, 232)
		ADD_OBJECT(ScriptClass, RewardAnnouncementClass, 228)
		ADD_STRUCT(int, RewardCount, 224)
		ADD_STRUCT(ScriptName, SuicideStatsName, 216)
		ADD_STRUCT(ScriptName, DeathStatsName, 208)
		ADD_STRUCT(ScriptName, KillStatsName, 200)
		ADD_STRUCT(float, NodeDamageScaling, 196)
		ADD_OBJECT(ScriptClass, DeathCameraEffectInstigator, 168)
		ADD_OBJECT(ScriptClass, DeathCameraEffectVictim, 164)
		ADD_OBJECT(ParticleSystem, GibTrail, 160)
		ADD_STRUCT(int, DamageWeaponFireMode, 156)
		ADD_STRUCT(int, AlwaysGibDamageThreshold, 144)
		ADD_STRUCT(int, MinAccumulateDamageThreshold, 140)
		ADD_STRUCT(int, GibThreshold, 136)
		ADD_BOOL(bDontHurtInstigator, 128, 0x100000)
		ADD_BOOL(bComplainFriendlyFire, 128, 0x10000)
		ADD_BOOL(bSelfDestructDamage, 128, 0x1000)
		ADD_BOOL(bVehicleHit, 128, 0x800)
		ADD_BOOL(bBulletHit, 128, 0x400)
		ADD_BOOL(bLeaveBodyEffect, 128, 0x200)
		ADD_BOOL(bUseTearOffMomentum, 128, 0x80)
		ADD_BOOL(bCauseConvulsions, 128, 0x40)
		ADD_BOOL(bNeverGibs, 128, 0x8)
		ADD_BOOL(bAlwaysGibs, 128, 0x4)
		ADD_STRUCT(float, DeathOverlayTime, 120)
		ScriptClass* GetDeathCameraEffectInstigator(class UTPawn* UTP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.GetDeathCameraEffectInstigator");
			byte params[8] = { NULL };
			*(class UTPawn**)&params[0] = UTP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		float GetHitEffectDuration(class Pawn* P, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.GetHitEffectDuration");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(float*)&params[4] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool ShouldGib(class UTPawn* DeadPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.ShouldGib");
			byte params[8] = { NULL };
			*(class UTPawn**)&params[0] = DeadPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptClass* GetDeathCameraEffectVictim(class UTPawn* UTP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.GetDeathCameraEffectVictim");
			byte params[8] = { NULL };
			*(class UTPawn**)&params[0] = UTP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		ScriptString* DeathMessage(class PlayerReplicationInfo* Killer, class PlayerReplicationInfo* Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.DeathMessage");
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Killer;
			*(class PlayerReplicationInfo**)&params[4] = Victim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		ScriptString* SuicideMessage(class PlayerReplicationInfo* Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.SuicideMessage");
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Victim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void SpawnHitEffect(class Pawn* P, float Damage, Object::Vector Momentum, ScriptName BoneName, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.SpawnHitEffect");
			byte params[40] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(float*)&params[4] = Damage;
			*(Object::Vector*)&params[8] = Momentum;
			*(ScriptName*)&params[20] = BoneName;
			*(Object::Vector*)&params[28] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int IncrementKills(class UTPlayerReplicationInfo* KillerPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.IncrementKills");
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void IncrementDeaths(class UTPlayerReplicationInfo* KilledPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.IncrementDeaths");
			byte params[4] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = KilledPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementSuicides(class UTPlayerReplicationInfo* KilledPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.IncrementSuicides");
			byte params[4] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = KilledPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetStatsName(ScriptName StatType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.GetStatsName");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = StatType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		void ScoreKill(class UTPlayerReplicationInfo* KillerPRI, class UTPlayerReplicationInfo* KilledPRI, class Pawn* KilledPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.ScoreKill");
			byte params[12] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = KillerPRI;
			*(class UTPlayerReplicationInfo**)&params[4] = KilledPRI;
			*(class Pawn**)&params[8] = KilledPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnTornOff(class UTPawn* DeadPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.PawnTornOff");
			byte params[4] = { NULL };
			*(class UTPawn**)&params[0] = DeadPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnGibEffects(class UTGib* Gib)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.SpawnGibEffects");
			byte params[4] = { NULL };
			*(class UTGib**)&params[0] = Gib;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoCustomDamageEffects(class UTPawn* ThePawn, ScriptClass* TheDamageType, Actor::TraceHitInfo& HitInfo, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.DoCustomDamageEffects");
			byte params[48] = { NULL };
			*(class UTPawn**)&params[0] = ThePawn;
			*(ScriptClass**)&params[4] = TheDamageType;
			*(Actor::TraceHitInfo*)&params[8] = HitInfo;
			*(Object::Vector*)&params[36] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitInfo = *(Actor::TraceHitInfo*)&params[8];
		}
		void CreateDeathSkeleton(class UTPawn* ThePawn, ScriptClass* TheDamageType, Actor::TraceHitInfo& HitInfo, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.CreateDeathSkeleton");
			byte params[48] = { NULL };
			*(class UTPawn**)&params[0] = ThePawn;
			*(ScriptClass**)&params[4] = TheDamageType;
			*(Actor::TraceHitInfo*)&params[8] = HitInfo;
			*(Object::Vector*)&params[36] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitInfo = *(Actor::TraceHitInfo*)&params[8];
		}
		void BoneBreaker(class UTPawn* ThePawn, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* TheMesh, Object::Vector Impulse, Object::Vector HitLocation, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.BoneBreaker");
			byte params[40] = { NULL };
			*(class UTPawn**)&params[0] = ThePawn;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = TheMesh;
			*(Object::Vector*)&params[8] = Impulse;
			*(Object::Vector*)&params[20] = HitLocation;
			*(ScriptName*)&params[32] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateDeathGoreChunks(class UTPawn* ThePawn, ScriptClass* TheDamageType, Actor::TraceHitInfo& HitInfo, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.CreateDeathGoreChunks");
			byte params[48] = { NULL };
			*(class UTPawn**)&params[0] = ThePawn;
			*(ScriptClass**)&params[4] = TheDamageType;
			*(Actor::TraceHitInfo*)&params[8] = HitInfo;
			*(Object::Vector*)&params[36] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitInfo = *(Actor::TraceHitInfo*)&params[8];
		}
		void SpawnExtraGibEffects(class UTGib* TheGib)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.SpawnExtraGibEffects");
			byte params[4] = { NULL };
			*(class UTGib**)&params[0] = TheGib;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.DrawKillIcon");
			byte params[20] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(float*)&params[4] = ScreenX;
			*(float*)&params[8] = ScreenY;
			*(float*)&params[12] = HUDScaleX;
			*(float*)&params[16] = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CalcDeathCamera(class UTPawn* P, float DeltaTime, Object::Vector& CameraLocation, Object::Rotator& CameraRotation, float& CameraFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDamageType.CalcDeathCamera");
			byte params[36] = { NULL };
			*(class UTPawn**)&params[0] = P;
			*(float*)&params[4] = DeltaTime;
			*(Object::Vector*)&params[8] = CameraLocation;
			*(Object::Rotator*)&params[20] = CameraRotation;
			*(float*)&params[32] = CameraFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CameraLocation = *(Object::Vector*)&params[8];
			CameraRotation = *(Object::Rotator*)&params[20];
			CameraFOV = *(float*)&params[32];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
