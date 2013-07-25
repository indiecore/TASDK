#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Actor.h"
#include "Engine.MaterialInterface.h"
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
		ADD_STRUCT(::VectorProperty, OldPosition, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PartSysVelocity, 0xFFFFFFFF)
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
		void SetTemplate(class ParticleSystem* NewTemplate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetTemplate");
			byte* params = (byte*)malloc(4);
			*(class ParticleSystem**)params = NewTemplate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActivateSystem(bool bFlagAsJustAttached)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.ActivateSystem");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bFlagAsJustAttached;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActive(bool bNowActive, bool bFlagAsJustAttached)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetActive");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bNowActive;
			*(bool*)(params + 4) = bFlagAsJustAttached;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSystem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.OnSystemFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSystem;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DeactivateSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.DeactivateSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillParticlesForced()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.KillParticlesForced");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillParticlesInEmitter(ScriptName InEmitterName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.KillParticlesInEmitter");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = InEmitterName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSkipUpdateDynamicDataDuringTick(bool bInSkipUpdateDynamicDataDuringTick)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetSkipUpdateDynamicDataDuringTick");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInSkipUpdateDynamicDataDuringTick;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetSkipUpdateDynamicDataDuringTick()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.GetSkipUpdateDynamicDataDuringTick");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetKillOnDeactivate(int EmitterIndex, bool bKill)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetKillOnDeactivate");
			byte* params = (byte*)malloc(8);
			*(int*)params = EmitterIndex;
			*(bool*)(params + 4) = bKill;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetKillOnCompleted(int EmitterIndex, bool bKill)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetKillOnCompleted");
			byte* params = (byte*)malloc(8);
			*(int*)params = EmitterIndex;
			*(bool*)(params + 4) = bKill;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RewindEmitterInstance(int EmitterIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.RewindEmitterInstance");
			byte* params = (byte*)malloc(4);
			*(int*)params = EmitterIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RewindEmitterInstances()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.RewindEmitterInstances");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBeamType(int EmitterIndex, int NewMethod)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetBeamType");
			byte* params = (byte*)malloc(8);
			*(int*)params = EmitterIndex;
			*(int*)(params + 4) = NewMethod;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBeamTessellationFactor(int EmitterIndex, float NewFactor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetBeamTessellationFactor");
			byte* params = (byte*)malloc(8);
			*(int*)params = EmitterIndex;
			*(float*)(params + 4) = NewFactor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBeamEndPoint(int EmitterIndex, Vector NewEndPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetBeamEndPoint");
			byte* params = (byte*)malloc(16);
			*(int*)params = EmitterIndex;
			*(Vector*)(params + 4) = NewEndPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBeamDistance(int EmitterIndex, float Distance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetBeamDistance");
			byte* params = (byte*)malloc(8);
			*(int*)params = EmitterIndex;
			*(float*)(params + 4) = Distance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBeamSourcePoint(int EmitterIndex, Vector NewSourcePoint, int SourceIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetBeamSourcePoint");
			byte* params = (byte*)malloc(20);
			*(int*)params = EmitterIndex;
			*(Vector*)(params + 4) = NewSourcePoint;
			*(int*)(params + 16) = SourceIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBeamSourceTangent(int EmitterIndex, Vector NewTangentPoint, int SourceIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetBeamSourceTangent");
			byte* params = (byte*)malloc(20);
			*(int*)params = EmitterIndex;
			*(Vector*)(params + 4) = NewTangentPoint;
			*(int*)(params + 16) = SourceIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBeamSourceStrength(int EmitterIndex, float NewSourceStrength, int SourceIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetBeamSourceStrength");
			byte* params = (byte*)malloc(12);
			*(int*)params = EmitterIndex;
			*(float*)(params + 4) = NewSourceStrength;
			*(int*)(params + 8) = SourceIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBeamTargetPoint(int EmitterIndex, Vector NewTargetPoint, int TargetIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetBeamTargetPoint");
			byte* params = (byte*)malloc(20);
			*(int*)params = EmitterIndex;
			*(Vector*)(params + 4) = NewTargetPoint;
			*(int*)(params + 16) = TargetIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBeamTargetTangent(int EmitterIndex, Vector NewTangentPoint, int TargetIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetBeamTargetTangent");
			byte* params = (byte*)malloc(20);
			*(int*)params = EmitterIndex;
			*(Vector*)(params + 4) = NewTangentPoint;
			*(int*)(params + 16) = TargetIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBeamTargetStrength(int EmitterIndex, float NewTargetStrength, int TargetIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetBeamTargetStrength");
			byte* params = (byte*)malloc(12);
			*(int*)params = EmitterIndex;
			*(float*)(params + 4) = NewTargetStrength;
			*(int*)(params + 8) = TargetIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int DetermineLODLevelForLocation(Vector& EffectLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.DetermineLODLevelForLocation");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = EffectLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			EffectLocation = *(Vector*)params;
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetLODLevel(int InLODLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetLODLevel");
			byte* params = (byte*)malloc(4);
			*(int*)params = InLODLevel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetEditorLODLevel(int InLODLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetEditorLODLevel");
			byte* params = (byte*)malloc(4);
			*(int*)params = InLODLevel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetLODLevel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.GetLODLevel");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetEditorLODLevel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.GetEditorLODLevel");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void SetFloatParameter(ScriptName ParameterName, float Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetFloatParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFloatRandParameter(ScriptName ParameterName, float Param, float ParamLow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetFloatRandParameter");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = Param;
			*(float*)(params + 12) = ParamLow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVectorParameter(ScriptName ParameterName, Vector Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetVectorParameter");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = ParameterName;
			*(Vector*)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVectorRandParameter(ScriptName ParameterName, Vector& Param, Vector& ParamLow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetVectorRandParameter");
			byte* params = (byte*)malloc(32);
			*(ScriptName*)params = ParameterName;
			*(Vector*)(params + 8) = Param;
			*(Vector*)(params + 20) = ParamLow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Param = *(Vector*)(params + 8);
			ParamLow = *(Vector*)(params + 20);
			free(params);
		}
		void SetColorParameter(ScriptName ParameterName, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetColorParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActorParameter(ScriptName ParameterName, class Actor* Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetActorParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(class Actor**)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMaterialParameter(ScriptName ParameterName, class MaterialInterface* Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetMaterialParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(class MaterialInterface**)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetFloatParameter(ScriptName InName, float& OutFloat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.GetFloatParameter");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = InName;
			*(float*)(params + 8) = OutFloat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutFloat = *(float*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetVectorParameter(ScriptName InName, Vector& OutVector)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.GetVectorParameter");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = InName;
			*(Vector*)(params + 8) = OutVector;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutVector = *(Vector*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetColorParameter(ScriptName InName, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void*& OutColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.GetColorParameter");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = InName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 8) = OutColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutColor = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetActorParameter(ScriptName InName, class Actor*& OutActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.GetActorParameter");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = InName;
			*(class Actor**)(params + 8) = OutActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutActor = *(class Actor**)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetMaterialParameter(ScriptName InName, class MaterialInterface*& OutMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.GetMaterialParameter");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = InName;
			*(class MaterialInterface**)(params + 8) = OutMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutMaterial = *(class MaterialInterface**)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void ClearParameter(ScriptName ParameterName, byte ParameterType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.ClearParameter");
			byte* params = (byte*)malloc(9);
			*(ScriptName*)params = ParameterName;
			*(params + 8) = ParameterType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetToDefaults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.ResetToDefaults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStopSpawning(int InEmitterIndex, bool bInStopSpawning)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleSystemComponent.SetStopSpawning");
			byte* params = (byte*)malloc(8);
			*(int*)params = InEmitterIndex;
			*(bool*)(params + 4) = bInStopSpawning;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
