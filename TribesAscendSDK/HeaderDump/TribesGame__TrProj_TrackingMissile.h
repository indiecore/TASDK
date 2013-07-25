#pragma once
#include "TribesGame__TrProjectile.h"
#include "Engine__Actor.h"
#include "TribesGame__TrSeekingMissileManager.h"
#include "Engine__Controller.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_TrackingMissile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_TrackingMissile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_TrackingMissile : public TrProjectile
	{
	public:
		ADD_VAR(::FloatProperty, m_fLoseTightTrackingDistance, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_MissileCaratRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fStage1MinGroundDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vLastKnownTargetLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInitialLocationZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinHeightGainForGoodLOS, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fIdealHeightAboveTargetForGoodLOS, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAdjustingForGoodLOSAccelRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTrackingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTrackingDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLOSDelay, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bLostTightHoming, 0x2)
		ADD_VAR(::BoolProperty, m_bHasBentToTarget, 0x1)
		ADD_VAR(::ByteProperty, m_MissileStage, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init(Vector Direction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.Init");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Direction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.ProcessTouch");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableCollisionTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.EnableCollisionTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSeekTarget(class Actor* NewSeekTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.SetSeekTarget");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewSeekTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NativeExplode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.NativeExplode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnExploded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.OnExploded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.Explode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class TrSeekingMissileManager* GetSeekingMissileManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.GetSeekingMissileManager");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrSeekingMissileManager**)params;
			free(params);
			return returnVal;
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
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = DamageAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_TrackingMissile.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
