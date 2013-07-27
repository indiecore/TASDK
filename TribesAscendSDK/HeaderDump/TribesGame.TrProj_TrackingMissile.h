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
		ADD_STRUCT(Rotator, m_MissileCaratRotation, 872)
		ADD_STRUCT(float, m_fStage1MinGroundDist, 868)
		ADD_STRUCT(Vector, m_vLastKnownTargetLocation, 856)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109357);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init(Vector Direction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109359);
			byte params[12] = { NULL };
			*(Vector*)params = Direction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109361);
			byte params[28] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableCollisionTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109365);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSeekTarget(class Actor* NewSeekTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109366);
			byte params[4] = { NULL };
			*(class Actor**)params = NewSeekTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NativeExplode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109369);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnExploded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109372);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109374);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109377);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class TrSeekingMissileManager* GetSeekingMissileManager()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109378);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrSeekingMissileManager**)params;
		}
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109381);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnFlightEffectsTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109382);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109388);
			byte params[68] = { NULL };
			*(int*)params = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109400);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109402);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
