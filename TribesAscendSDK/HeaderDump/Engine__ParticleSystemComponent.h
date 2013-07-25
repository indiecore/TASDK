#pragma once
#include "Engine__Actor.h"
#include "Engine__ParticleSystem.h"
#include "Engine__PrimitiveComponent.h"
#include "Engine__MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleSystemComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleSystemComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ParticleSystemComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ParticleSystemComponent : public PrimitiveComponent
	{
	public:
		ADD_OBJECT(ParticleSystem, Template)
		ADD_OBJECT(ScriptClass, LightEnvironmentClass)
		ADD_VAR(::BoolProperty, bAutoActivate, 0x1)
		ADD_VAR(::BoolProperty, bWasCompleted, 0x2)
		ADD_VAR(::BoolProperty, bSuppressSpawning, 0x4)
		ADD_VAR(::BoolProperty, bWasDeactivated, 0x8)
		ADD_VAR(::BoolProperty, bResetOnDetach, 0x10)
		ADD_VAR(::BoolProperty, bUpdateOnDedicatedServer, 0x20)
		ADD_VAR(::BoolProperty, bJustAttached, 0x40)
		ADD_VAR(::BoolProperty, bIsActive, 0x80)
		ADD_VAR(::BoolProperty, bWarmingUp, 0x100)
		ADD_VAR(::BoolProperty, bIsCachedInPool, 0x200)
		ADD_VAR(::BoolProperty, bOverrideLODMethod, 0x400)
		ADD_VAR(::BoolProperty, bSkipUpdateDynamicDataDuringTick, 0x800)
		ADD_VAR(::BoolProperty, bUpdateComponentInTick, 0x1000)
		ADD_VAR(::BoolProperty, bDeferredBeamUpdate, 0x2000)
		ADD_VAR(::BoolProperty, bForcedInActive, 0x4000)
		ADD_VAR(::BoolProperty, bIsWarmingUp, 0x8000)
		ADD_VAR(::BoolProperty, bIsViewRelevanceDirty, 0x10000)
		ADD_VAR(::BoolProperty, bRecacheViewRelevance, 0x20000)
		ADD_VAR(::BoolProperty, bLODUpdatePending, 0x40000)
		ADD_VAR(::BoolProperty, bSkipSpawnCountCheck, 0x80000)
		ADD_STRUCT(::VectorProperty, OldPosition, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, PartSysVelocity, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, WarmupTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LODLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SecondsBeforeInactive, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeSinceLastForceUpdateTransform, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxTimeBeforeForceUpdateTransform, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EditorLODLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AccumTickTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LODMethod, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ReplayState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ReplayClipIDNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ReplayFrameIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AccumLODDistanceCheckTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ReleaseResourcesFence'!
		ADD_VAR(::FloatProperty, CustomTimeDilation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmitterDelay, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SetTemplate'
		// Here lies the not-yet-implemented method 'ActivateSystem'
		// Here lies the not-yet-implemented method 'SetActive'
		// Here lies the not-yet-implemented method 'OnSystemFinished'
		// Here lies the not-yet-implemented method 'DeactivateSystem'
		// Here lies the not-yet-implemented method 'KillParticlesForced'
		// Here lies the not-yet-implemented method 'KillParticlesInEmitter'
		// Here lies the not-yet-implemented method 'SetSkipUpdateDynamicDataDuringTick'
		// Here lies the not-yet-implemented method 'GetSkipUpdateDynamicDataDuringTick'
		// Here lies the not-yet-implemented method 'SetKillOnDeactivate'
		// Here lies the not-yet-implemented method 'SetKillOnCompleted'
		// Here lies the not-yet-implemented method 'RewindEmitterInstance'
		// Here lies the not-yet-implemented method 'RewindEmitterInstances'
		// Here lies the not-yet-implemented method 'SetBeamType'
		// Here lies the not-yet-implemented method 'SetBeamTessellationFactor'
		// Here lies the not-yet-implemented method 'SetBeamEndPoint'
		// Here lies the not-yet-implemented method 'SetBeamDistance'
		// Here lies the not-yet-implemented method 'SetBeamSourcePoint'
		// Here lies the not-yet-implemented method 'SetBeamSourceTangent'
		// Here lies the not-yet-implemented method 'SetBeamSourceStrength'
		// Here lies the not-yet-implemented method 'SetBeamTargetPoint'
		// Here lies the not-yet-implemented method 'SetBeamTargetTangent'
		// Here lies the not-yet-implemented method 'SetBeamTargetStrength'
		// Here lies the not-yet-implemented method 'DetermineLODLevelForLocation'
		// Here lies the not-yet-implemented method 'SetLODLevel'
		// Here lies the not-yet-implemented method 'SetEditorLODLevel'
		// Here lies the not-yet-implemented method 'GetLODLevel'
		// Here lies the not-yet-implemented method 'GetEditorLODLevel'
		// Here lies the not-yet-implemented method 'SetFloatParameter'
		// Here lies the not-yet-implemented method 'SetFloatRandParameter'
		// Here lies the not-yet-implemented method 'SetVectorParameter'
		// Here lies the not-yet-implemented method 'SetVectorRandParameter'
		// Here lies the not-yet-implemented method 'SetColorParameter'
		// Here lies the not-yet-implemented method 'SetActorParameter'
		// Here lies the not-yet-implemented method 'SetMaterialParameter'
		// Here lies the not-yet-implemented method 'GetFloatParameter'
		// Here lies the not-yet-implemented method 'GetVectorParameter'
		// Here lies the not-yet-implemented method 'GetColorParameter'
		// Here lies the not-yet-implemented method 'GetActorParameter'
		// Here lies the not-yet-implemented method 'GetMaterialParameter'
		// Here lies the not-yet-implemented method 'ClearParameter'
		// Here lies the not-yet-implemented method 'ResetToDefaults'
		// Here lies the not-yet-implemented method 'SetStopSpawning'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
