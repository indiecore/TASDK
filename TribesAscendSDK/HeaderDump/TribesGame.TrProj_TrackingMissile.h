#pragma once
#include "Engine.Canvas.h"
#include "TribesGame.TrProjectile.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "TribesGame.TrSeekingMissileManager.h"
#include "Engine.PlayerController.h"
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
namespace UnrealScript
{
	class TrProj_TrackingMissile : public TrProjectile
	{
	public:
		enum ETrackingMissileStage : byte
		{
			ETrackingMissileStage_JustFired = 0,
			ETrackingMissileStage_AdjustingForGoodLOS = 1,
			ETrackingMissileStage_HomingInOnTarget = 2,
			ETrackingMissileStage_MAX = 3,
		};
		ADD_STRUCT(float, m_fLoseTightTrackingDistance, 884)
		ADD_STRUCT(Object::Rotator, m_MissileCaratRotation, 872)
		ADD_STRUCT(float, m_fStage1MinGroundDist, 868)
		ADD_STRUCT(Object::Vector, m_vLastKnownTargetLocation, 856)
		ADD_STRUCT(float, m_fInitialLocationZ, 852)
		ADD_STRUCT(float, m_fMinHeightGainForGoodLOS, 844)
		ADD_STRUCT(float, m_fIdealHeightAboveTargetForGoodLOS, 840)
		ADD_STRUCT(float, m_fAdjustingForGoodLOSAccelRate, 836)
		ADD_STRUCT(float, m_fTrackingTime, 832)
		ADD_STRUCT(float, m_fTrackingDelay, 828)
		ADD_STRUCT(float, m_fLOSDelay, 824)
		ADD_BOOL(m_bLostTightHoming, 820, 0x2)
		ADD_BOOL(m_bHasBentToTarget, 820, 0x1)
		ADD_STRUCT(TrProj_TrackingMissile::ETrackingMissileStage, m_MissileStage, 816)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init(Object::Vector Direction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.Init");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTouch(class Actor* Other, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.ProcessTouch");
			byte params[28] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableCollisionTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.EnableCollisionTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSeekTarget(class Actor* NewSeekTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.SetSeekTarget");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewSeekTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NativeExplode(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.NativeExplode");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnExploded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.OnExploded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Explode(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.Explode");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class TrSeekingMissileManager* GetSeekingMissileManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.GetSeekingMissileManager");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrSeekingMissileManager**)&params[0];
		}
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.SpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnFlightEffectsTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.SpawnFlightEffectsTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.PostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
