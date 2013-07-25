#pragma once
#include "TribesGame__TrGameObjective.h"
#include "Engine__Pawn.h"
#include "Engine__AnimNodeScalePlayRate.h"
#include "Engine__Controller.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "Engine__Actor.h"
#include "Engine__PlayerController.h"
#include "TribesGame__TrPowerGenerator.h"
#include "TribesGame__TrSubDevice.h"
#include "TribesGame__TrTurretPawn.h"
#include "TribesGame__TrDeployableCollisionProxy.h"
#include "TribesGame__TrPawn.h"
#include "TribesGame__TrVehicle.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__Weapon.h"
#include "Engine__Projectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDeployable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployable : public TrGameObjective
	{
	public:
		ADD_OBJECT(Controller, m_Controller)
		ADD_VAR(::IntProperty, m_nIconStackId, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vDeathCamStartOffset, 0xFFFFFFFF
		ADD_OBJECT(PlayerReplicationInfo, r_OwnerPRI)
		ADD_VAR(::FloatProperty, m_fAnimInterpSpeed, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeScalePlayRate, m_AnimNodeScale)
		ADD_OBJECT(Actor, m_LastViewer)
		ADD_OBJECT(PlayerController, m_LastRealViewer)
		ADD_VAR(::FloatProperty, m_fNetRelevancyTime, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_DeploySound)
		ADD_OBJECT(TrPowerGenerator, m_MyMainGenerator)
		ADD_OBJECT(Pawn, r_TargetPawn)
		ADD_VAR(::ByteProperty, r_FlashCount, 0xFFFFFFFF)
		ADD_OBJECT(TrSubDevice, m_Weapon)
		ADD_OBJECT(TrTurretPawn, m_WeaponHolder)
		ADD_OBJECT(ScriptClass, m_DeviceClass)
		ADD_VAR(::FloatProperty, m_fAlwaysRelevantDistanceSquared, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fNewDetectionRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDamageRadius, 0xFFFFFFFF)
		ADD_OBJECT(TrDeployableCollisionProxy, m_CollisionProxy)
		ADD_VAR(::FloatProperty, m_fOverriddenTargetComponentHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_TargetCollisionTraceDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFiringArcCheckValue, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_PlacementOrientationVector, 0xFFFFFFFF
		ADD_VAR(::IntProperty, m_nFiringArcDegrees, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bBlocksFriendlies, 0x80)
		ADD_VAR(::BoolProperty, m_bCanBeSpottedByVGS, 0x40)
		ADD_VAR(::BoolProperty, m_bIsXRay, 0x20)
		ADD_VAR(::BoolProperty, m_bCachedRelevant, 0x10)
		ADD_VAR(::BoolProperty, m_bOverrideTargetComponentHeight, 0x8)
		ADD_VAR(::BoolProperty, m_bUsesArmoredMultiplier, 0x4)
		ADD_VAR(::BoolProperty, m_bRequireLOS, 0x2)
		ADD_VAR(::BoolProperty, m_bIsDeployed, 0x1)
		ADD_VAR(::FloatProperty, m_fTimeToDeploySecs, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemoteActivationTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBuildupTime, 0xFFFFFFFF)
		ADD_OBJECT(TrPawn, m_TouchedPlayer)
		ADD_VAR(::FloatProperty, m_TimeCreated, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nMaxDeployablesOut, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AdjustMeshToGround'
		// Here lies the not-yet-implemented method 'CalcMeshOffset'
		// Here lies the not-yet-implemented method 'IsInLOS'
		// Here lies the not-yet-implemented method 'ApplyServerSettings'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'OnPRIReplicated'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'OnPawnDetectedByCollisionProxy'
		// Here lies the not-yet-implemented method 'OnPawnExitedCollisionProxy'
		// Here lies the not-yet-implemented method 'OnVehicleDetectedByCollisionProxy'
		// Here lies the not-yet-implemented method 'OnVehicleExitedCollisionProxy'
		// Here lies the not-yet-implemented method 'OnPowerStatusChanged'
		// Here lies the not-yet-implemented method 'SetInstigatorController'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'GetDamageRadius'
		// Here lies the not-yet-implemented method 'FinalizeDeployment'
		// Here lies the not-yet-implemented method 'DeployComplete'
		// Here lies the not-yet-implemented method 'IsFiring'
		// Here lies the not-yet-implemented method 'UpdateHealthMaterial'
		// Here lies the not-yet-implemented method 'OnHealthChanged'
		// Here lies the not-yet-implemented method 'GetWeaponStartTraceLocation'
		// Here lies the not-yet-implemented method 'StopsProjectile'
		// Here lies the not-yet-implemented method 'IncrementFlashCount'
		// Here lies the not-yet-implemented method 'PlayFireEffects'
		// Here lies the not-yet-implemented method 'PulseBackupGenerators'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'ReceivesPowerFromGenerator'
		// Here lies the not-yet-implemented method 'GetPossessiveInstigatorName'
		// Here lies the not-yet-implemented method 'CalcOtherWatchingCam'
		// Here lies the not-yet-implemented method 'OnUpgradePerformed'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
