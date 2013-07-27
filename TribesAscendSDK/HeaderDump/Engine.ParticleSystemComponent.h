#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.ParticleSystemReplay.h"
#include "Engine.MaterialInterface.h"
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
	class ParticleSystemComponent : public PrimitiveComponent
	{
	public:
		enum EParticleSysParamType : byte
		{
			PSPT_None = 0,
			PSPT_Scalar = 1,
			PSPT_ScalarRand = 2,
			PSPT_Vector = 3,
			PSPT_VectorRand = 4,
			PSPT_Color = 5,
			PSPT_Actor = 6,
			PSPT_Material = 7,
			PSPT_MAX = 8,
		};
		enum ParticleReplayState : byte
		{
			PRS_Disabled = 0,
			PRS_Capturing = 1,
			PRS_Replaying = 2,
			PRS_MAX = 3,
		};
		enum EParticleEventType : byte
		{
			EPET_Any = 0,
			EPET_Spawn = 1,
			EPET_Death = 2,
			EPET_Collision = 3,
			EPET_Kismet = 4,
			EPET_MAX = 5,
		};
		struct ViewParticleEmitterInstanceMotionBlurInfo
		{
		public:
			ADD_STRUCT(Object::Map_Mirror, EmitterInstanceMBInfoMap, 0)
		};
		struct ParticleEventData
		{
		public:
			ADD_STRUCT(Vector, Velocity, 40)
			ADD_STRUCT(Vector, Direction, 28)
			ADD_STRUCT(Vector, Location, 16)
			ADD_STRUCT(float, EmitterTime, 12)
			ADD_STRUCT(ScriptName, EventName, 4)
			ADD_STRUCT(int, Type, 0)
		};
		struct ParticleEventSpawnData : public ParticleEventData
		{
		};
		struct ParticleEventDeathData : public ParticleEventData
		{
		public:
			ADD_STRUCT(float, ParticleTime, 52)
		};
		struct ParticleEventCollideData : public ParticleEventData
		{
		public:
			ADD_STRUCT(ScriptName, BoneName, 76)
			ADD_STRUCT(int, Item, 72)
			ADD_STRUCT(float, Time, 68)
			ADD_STRUCT(Vector, Normal, 56)
			ADD_STRUCT(float, ParticleTime, 52)
		};
		struct ParticleEventKismetData : public ParticleEventData
		{
		public:
			ADD_STRUCT(Vector, Normal, 56)
			ADD_BOOL(UsePSysCompLocation, 52, 0x1)
		};
		struct ParticleEmitterInstanceMotionBlurInfo
		{
		public:
			ADD_STRUCT(Object::Map_Mirror, ParticleMBInfoMap, 0)
		};
		struct ParticleEmitterInstance
		{
		};
		struct ParticleSysParam
		{
		public:
			ADD_OBJECT(MaterialInterface, Material, 52)
			ADD_OBJECT(Actor, Actor, 48)
			ADD_STRUCT(Object::Color, Color, 44)
			ADD_STRUCT(Vector, Vector_Low, 32)
			ADD_STRUCT(Vector, Vector, 20)
			ADD_STRUCT(float, Scalar_Low, 16)
			ADD_STRUCT(float, Scalar, 12)
			ADD_STRUCT(ParticleSystemComponent::EParticleSysParamType, ParamType, 8)
			ADD_STRUCT(ScriptName, Name, 0)
		};
		ADD_OBJECT(ParticleSystem, Template, 488)
		ADD_OBJECT(ScriptClass, LightEnvironmentClass, 492)
		ADD_STRUCT(ScriptArray<Object::Pointer>, EmitterInstances, 496)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, SMComponents, 508)
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, SMMaterialInterfaces, 520)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, SkelMeshComponents, 532)
		ADD_STRUCT(ScriptArray<ParticleSystemComponent::ViewParticleEmitterInstanceMotionBlurInfo>, ViewMBInfoArray, 544)
		ADD_BOOL(bAutoActivate, 556, 0x1)
		ADD_BOOL(bWasCompleted, 556, 0x2)
		ADD_BOOL(bSuppressSpawning, 556, 0x4)
		ADD_BOOL(bWasDeactivated, 556, 0x8)
		ADD_BOOL(bResetOnDetach, 556, 0x10)
		ADD_BOOL(bUpdateOnDedicatedServer, 556, 0x20)
		ADD_BOOL(bJustAttached, 556, 0x40)
		ADD_BOOL(bIsActive, 556, 0x80)
		ADD_BOOL(bWarmingUp, 556, 0x100)
		ADD_BOOL(bIsCachedInPool, 556, 0x200)
		ADD_BOOL(bOverrideLODMethod, 556, 0x400)
		ADD_BOOL(bSkipUpdateDynamicDataDuringTick, 556, 0x800)
		ADD_BOOL(bUpdateComponentInTick, 556, 0x1000)
		ADD_BOOL(bDeferredBeamUpdate, 556, 0x2000)
		ADD_BOOL(bForcedInActive, 556, 0x4000)
		ADD_BOOL(bIsWarmingUp, 556, 0x8000)
		ADD_BOOL(bIsViewRelevanceDirty, 556, 0x10000)
		ADD_BOOL(bRecacheViewRelevance, 556, 0x20000)
		ADD_BOOL(bLODUpdatePending, 556, 0x40000)
		ADD_BOOL(bSkipSpawnCountCheck, 556, 0x80000)
		ADD_STRUCT(ScriptArray<ParticleSystemComponent::ParticleSysParam>, InstanceParameters, 560)
		ADD_STRUCT(Vector, OldPosition, 572)
		ADD_STRUCT(Vector, PartSysVelocity, 584)
		ADD_STRUCT(float, WarmupTime, 596)
		ADD_STRUCT(int, LODLevel, 600)
		ADD_STRUCT(float, SecondsBeforeInactive, 604)
		ADD_STRUCT(float, TimeSinceLastForceUpdateTransform, 608)
		ADD_STRUCT(float, MaxTimeBeforeForceUpdateTransform, 612)
		ADD_STRUCT(int, EditorLODLevel, 616)
		ADD_STRUCT(float, AccumTickTime, 620)
		ADD_STRUCT(ParticleSystem::ParticleSystemLODMethod, LODMethod, 624)
		ADD_STRUCT(ParticleSystemComponent::ParticleReplayState, ReplayState, 625)
		ADD_STRUCT(ScriptArray<PrimitiveComponent::MaterialViewRelevance>, CachedViewRelevanceFlags, 628)
		ADD_STRUCT(ScriptArray<class ParticleSystemReplay*>, ReplayClips, 640)
		ADD_STRUCT(int, ReplayClipIDNumber, 652)
		ADD_STRUCT(int, ReplayFrameIndex, 656)
		ADD_STRUCT(float, AccumLODDistanceCheckTime, 660)
		ADD_STRUCT(ScriptArray<ParticleSystemComponent::ParticleEventSpawnData>, SpawnEvents, 664)
		ADD_STRUCT(ScriptArray<ParticleSystemComponent::ParticleEventDeathData>, DeathEvents, 676)
		ADD_STRUCT(ScriptArray<ParticleSystemComponent::ParticleEventCollideData>, CollisionEvents, 688)
		ADD_STRUCT(ScriptArray<ParticleSystemComponent::ParticleEventKismetData>, KismetEvents, 700)
		ADD_STRUCT(Object::Pointer, ReleaseResourcesFence, 712)
		ADD_STRUCT(float, CustomTimeDilation, 716)
		ADD_STRUCT(float, EmitterDelay, 720)
		void SetTemplate(class ParticleSystem* NewTemplate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7292);
			byte params[4] = { NULL };
			*(class ParticleSystem**)params = NewTemplate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActivateSystem(bool bFlagAsJustAttached)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7295);
			byte params[4] = { NULL };
			*(bool*)params = bFlagAsJustAttached;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActive(bool bNowActive, bool bFlagAsJustAttached)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14789);
			byte params[8] = { NULL };
			*(bool*)params = bNowActive;
			*(bool*)&params[4] = bFlagAsJustAttached;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSystem)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14951);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSystem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DeactivateSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14955);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillParticlesForced()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14956);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillParticlesInEmitter(ScriptName InEmitterName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14957);
			byte params[8] = { NULL };
			*(ScriptName*)params = InEmitterName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkipUpdateDynamicDataDuringTick(bool bInSkipUpdateDynamicDataDuringTick)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14959);
			byte params[4] = { NULL };
			*(bool*)params = bInSkipUpdateDynamicDataDuringTick;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetSkipUpdateDynamicDataDuringTick()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14961);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetKillOnDeactivate(int EmitterIndex, bool bKill)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14963);
			byte params[8] = { NULL };
			*(int*)params = EmitterIndex;
			*(bool*)&params[4] = bKill;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetKillOnCompleted(int EmitterIndex, bool bKill)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14966);
			byte params[8] = { NULL };
			*(int*)params = EmitterIndex;
			*(bool*)&params[4] = bKill;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RewindEmitterInstance(int EmitterIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14969);
			byte params[4] = { NULL };
			*(int*)params = EmitterIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RewindEmitterInstances()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14971);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBeamType(int EmitterIndex, int NewMethod)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14972);
			byte params[8] = { NULL };
			*(int*)params = EmitterIndex;
			*(int*)&params[4] = NewMethod;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBeamTessellationFactor(int EmitterIndex, float NewFactor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14975);
			byte params[8] = { NULL };
			*(int*)params = EmitterIndex;
			*(float*)&params[4] = NewFactor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBeamEndPoint(int EmitterIndex, Vector NewEndPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14978);
			byte params[16] = { NULL };
			*(int*)params = EmitterIndex;
			*(Vector*)&params[4] = NewEndPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBeamDistance(int EmitterIndex, float Distance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14981);
			byte params[8] = { NULL };
			*(int*)params = EmitterIndex;
			*(float*)&params[4] = Distance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBeamSourcePoint(int EmitterIndex, Vector NewSourcePoint, int SourceIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14984);
			byte params[20] = { NULL };
			*(int*)params = EmitterIndex;
			*(Vector*)&params[4] = NewSourcePoint;
			*(int*)&params[16] = SourceIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBeamSourceTangent(int EmitterIndex, Vector NewTangentPoint, int SourceIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14988);
			byte params[20] = { NULL };
			*(int*)params = EmitterIndex;
			*(Vector*)&params[4] = NewTangentPoint;
			*(int*)&params[16] = SourceIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBeamSourceStrength(int EmitterIndex, float NewSourceStrength, int SourceIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14992);
			byte params[12] = { NULL };
			*(int*)params = EmitterIndex;
			*(float*)&params[4] = NewSourceStrength;
			*(int*)&params[8] = SourceIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBeamTargetPoint(int EmitterIndex, Vector NewTargetPoint, int TargetIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14996);
			byte params[20] = { NULL };
			*(int*)params = EmitterIndex;
			*(Vector*)&params[4] = NewTargetPoint;
			*(int*)&params[16] = TargetIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBeamTargetTangent(int EmitterIndex, Vector NewTangentPoint, int TargetIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15000);
			byte params[20] = { NULL };
			*(int*)params = EmitterIndex;
			*(Vector*)&params[4] = NewTangentPoint;
			*(int*)&params[16] = TargetIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBeamTargetStrength(int EmitterIndex, float NewTargetStrength, int TargetIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15004);
			byte params[12] = { NULL };
			*(int*)params = EmitterIndex;
			*(float*)&params[4] = NewTargetStrength;
			*(int*)&params[8] = TargetIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int DetermineLODLevelForLocation(Vector& EffectLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15008);
			byte params[16] = { NULL };
			*(Vector*)params = EffectLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			EffectLocation = *(Vector*)params;
			return *(int*)&params[12];
		}
		void SetLODLevel(int InLODLevel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15011);
			byte params[4] = { NULL };
			*(int*)params = InLODLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEditorLODLevel(int InLODLevel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15013);
			byte params[4] = { NULL };
			*(int*)params = InLODLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetLODLevel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15015);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetEditorLODLevel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15017);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void SetFloatParameter(ScriptName ParameterName, float Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15019);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFloatRandParameter(ScriptName ParameterName, float Param, float ParamLow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15022);
			byte params[16] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Param;
			*(float*)&params[12] = ParamLow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVectorParameter(ScriptName ParameterName, Vector Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15026);
			byte params[20] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Vector*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVectorRandParameter(ScriptName ParameterName, Vector& Param, Vector& ParamLow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15029);
			byte params[32] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Vector*)&params[8] = Param;
			*(Vector*)&params[20] = ParamLow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Param = *(Vector*)&params[8];
			ParamLow = *(Vector*)&params[20];
		}
		void SetColorParameter(ScriptName ParameterName, Object::Color Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15033);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::Color*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActorParameter(ScriptName ParameterName, class Actor* Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15036);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Actor**)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMaterialParameter(ScriptName ParameterName, class MaterialInterface* Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15039);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class MaterialInterface**)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetFloatParameter(ScriptName InName, float& OutFloat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15042);
			byte params[16] = { NULL };
			*(ScriptName*)params = InName;
			*(float*)&params[8] = OutFloat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutFloat = *(float*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetVectorParameter(ScriptName InName, Vector& OutVector)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15046);
			byte params[24] = { NULL };
			*(ScriptName*)params = InName;
			*(Vector*)&params[8] = OutVector;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVector = *(Vector*)&params[8];
			return *(bool*)&params[20];
		}
		bool GetColorParameter(ScriptName InName, Object::Color& OutColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15050);
			byte params[16] = { NULL };
			*(ScriptName*)params = InName;
			*(Object::Color*)&params[8] = OutColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutColor = *(Object::Color*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetActorParameter(ScriptName InName, class Actor*& OutActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15054);
			byte params[16] = { NULL };
			*(ScriptName*)params = InName;
			*(class Actor**)&params[8] = OutActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutActor = *(class Actor**)&params[8];
			return *(bool*)&params[12];
		}
		bool GetMaterialParameter(ScriptName InName, class MaterialInterface*& OutMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15058);
			byte params[16] = { NULL };
			*(ScriptName*)params = InName;
			*(class MaterialInterface**)&params[8] = OutMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutMaterial = *(class MaterialInterface**)&params[8];
			return *(bool*)&params[12];
		}
		void ClearParameter(ScriptName ParameterName, ParticleSystemComponent::EParticleSysParamType ParameterType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15062);
			byte params[9] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(ParticleSystemComponent::EParticleSysParamType*)&params[8] = ParameterType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetToDefaults()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15067);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStopSpawning(int InEmitterIndex, bool bInStopSpawning)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15068);
			byte params[8] = { NULL };
			*(int*)params = InEmitterIndex;
			*(bool*)&params[4] = bInStopSpawning;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
