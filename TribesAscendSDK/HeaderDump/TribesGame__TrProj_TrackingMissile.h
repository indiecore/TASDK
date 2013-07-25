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
		ADD_STRUCT(::RotatorProperty, m_MissileCaratRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fStage1MinGroundDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vLastKnownTargetLocation, 0xFFFFFFFF
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
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'ProcessTouch'
		// Here lies the not-yet-implemented method 'EnableCollisionTimer'
		// Here lies the not-yet-implemented method 'SetSeekTarget'
		// Here lies the not-yet-implemented method 'NativeExplode'
		// Here lies the not-yet-implemented method 'OnExploded'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'GetSeekingMissileManager'
		// Here lies the not-yet-implemented method 'SpawnFlightEffects'
		// Here lies the not-yet-implemented method 'SpawnFlightEffectsTimer'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'PostRenderFor'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
