#pragma once
#include "Engine.Actor.h"
#include "Engine.MaterialInstanceTimeVarying.h"
#include "Engine.SoundCue.h"
#include "Engine.ParticleSystem.h"
#include "TribesGame.TrCallIn_CrashLandInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn_DeliveryPod." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrCallIn_DeliveryPod." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn_DeliveryPod." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn_DeliveryPod : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, Speed, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetImpactPoint, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetHitNormal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LifeAfterImpact, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, ImpactSound)
		ADD_OBJECT(SoundCue, FallingSound)
		ADD_OBJECT(ParticleSystem, DeliveryPodImpactTemplate)
		ADD_OBJECT(ParticleSystem, DeliveryPodParticleTemplate)
		ADD_VAR(::FloatProperty, DecalDissolveTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HitDecalWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HitDecalHeight, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceTimeVarying, PodHitDecal)
		float GetTerminalVelocity()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_DeliveryPod.GetTerminalVelocity");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void Init(class TrCallIn_CrashLandInfo* CrashInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_DeliveryPod.Init");
			byte* params = (byte*)malloc(4);
			*(class TrCallIn_CrashLandInfo**)params = CrashInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BreakApart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_DeliveryPod.BreakApart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_DeliveryPod.HideMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_DeliveryPod.ParticleSystemFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_DeliveryPod.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_DeliveryPod.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
