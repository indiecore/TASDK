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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39477);
			byte params[8] = { NULL };
			*(class UTPawn**)params = UTP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		float GetHitEffectDuration(class Pawn* P, float Damage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39820);
			byte params[12] = { NULL };
			*(class Pawn**)params = P;
			*(float*)&params[4] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool ShouldGib(class UTPawn* DeadPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41750);
			byte params[8] = { NULL };
			*(class UTPawn**)params = DeadPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptClass* GetDeathCameraEffectVictim(class UTPawn* UTP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41770);
			byte params[8] = { NULL };
			*(class UTPawn**)params = UTP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		ScriptString* DeathMessage(class PlayerReplicationInfo* Killer, class PlayerReplicationInfo* Victim)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46779);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Killer;
			*(class PlayerReplicationInfo**)&params[4] = Victim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		ScriptString* SuicideMessage(class PlayerReplicationInfo* Victim)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46783);
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)params = Victim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void SpawnHitEffect(class Pawn* P, float Damage, Vector Momentum, ScriptName BoneName, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46786);
			byte params[40] = { NULL };
			*(class Pawn**)params = P;
			*(float*)&params[4] = Damage;
			*(Vector*)&params[8] = Momentum;
			*(ScriptName*)&params[20] = BoneName;
			*(Vector*)&params[28] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int IncrementKills(class UTPlayerReplicationInfo* KillerPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46794);
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)params = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void IncrementDeaths(class UTPlayerReplicationInfo* KilledPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46798);
			byte params[4] = { NULL };
			*(class UTPlayerReplicationInfo**)params = KilledPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementSuicides(class UTPlayerReplicationInfo* KilledPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46800);
			byte params[4] = { NULL };
			*(class UTPlayerReplicationInfo**)params = KilledPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetStatsName(ScriptName StatType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46802);
			byte params[16] = { NULL };
			*(ScriptName*)params = StatType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		void ScoreKill(class UTPlayerReplicationInfo* KillerPRI, class UTPlayerReplicationInfo* KilledPRI, class Pawn* KilledPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46805);
			byte params[12] = { NULL };
			*(class UTPlayerReplicationInfo**)params = KillerPRI;
			*(class UTPlayerReplicationInfo**)&params[4] = KilledPRI;
			*(class Pawn**)&params[8] = KilledPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnTornOff(class UTPawn* DeadPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46809);
			byte params[4] = { NULL };
			*(class UTPawn**)params = DeadPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnGibEffects(class UTGib* Gib)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46811);
			byte params[4] = { NULL };
			*(class UTGib**)params = Gib;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoCustomDamageEffects(class UTPawn* ThePawn, ScriptClass* TheDamageType, Actor::TraceHitInfo& HitInfo, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46815);
			byte params[48] = { NULL };
			*(class UTPawn**)params = ThePawn;
			*(ScriptClass**)&params[4] = TheDamageType;
			*(Actor::TraceHitInfo*)&params[8] = HitInfo;
			*(Vector*)&params[36] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitInfo = *(Actor::TraceHitInfo*)&params[8];
		}
		void CreateDeathSkeleton(class UTPawn* ThePawn, ScriptClass* TheDamageType, Actor::TraceHitInfo& HitInfo, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46820);
			byte params[48] = { NULL };
			*(class UTPawn**)params = ThePawn;
			*(ScriptClass**)&params[4] = TheDamageType;
			*(Actor::TraceHitInfo*)&params[8] = HitInfo;
			*(Vector*)&params[36] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitInfo = *(Actor::TraceHitInfo*)&params[8];
		}
		void BoneBreaker(class UTPawn* ThePawn, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* TheMesh, Vector Impulse, Vector HitLocation, ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46837);
			byte params[40] = { NULL };
			*(class UTPawn**)params = ThePawn;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = TheMesh;
			*(Vector*)&params[8] = Impulse;
			*(Vector*)&params[20] = HitLocation;
			*(ScriptName*)&params[32] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateDeathGoreChunks(class UTPawn* ThePawn, ScriptClass* TheDamageType, Actor::TraceHitInfo& HitInfo, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46846);
			byte params[48] = { NULL };
			*(class UTPawn**)params = ThePawn;
			*(ScriptClass**)&params[4] = TheDamageType;
			*(Actor::TraceHitInfo*)&params[8] = HitInfo;
			*(Vector*)&params[36] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitInfo = *(Actor::TraceHitInfo*)&params[8];
		}
		void SpawnExtraGibEffects(class UTGib* TheGib)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46855);
			byte params[4] = { NULL };
			*(class UTGib**)params = TheGib;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46857);
			byte params[20] = { NULL };
			*(class Canvas**)params = Canvas;
			*(float*)&params[4] = ScreenX;
			*(float*)&params[8] = ScreenY;
			*(float*)&params[12] = HUDScaleX;
			*(float*)&params[16] = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CalcDeathCamera(class UTPawn* P, float DeltaTime, Vector& CameraLocation, Rotator& CameraRotation, float& CameraFOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46863);
			byte params[36] = { NULL };
			*(class UTPawn**)params = P;
			*(float*)&params[4] = DeltaTime;
			*(Vector*)&params[8] = CameraLocation;
			*(Rotator*)&params[20] = CameraRotation;
			*(float*)&params[32] = CameraFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CameraLocation = *(Vector*)&params[8];
			CameraRotation = *(Rotator*)&params[20];
			CameraFOV = *(float*)&params[32];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
