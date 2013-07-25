#pragma once
#include "Engine.Actor.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.ParticleSystem.h"
#include "Engine.SeqAct_ParticleEventGenerator.h"
#include "Engine.SeqAct_SetParticleSysParam.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Emitter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Emitter : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bCurrentlyActive, 0x4)
		ADD_VAR(::BoolProperty, bPostUpdateTickGroup, 0x2)
		ADD_VAR(::BoolProperty, bDestroyOnSystemFinish, 0x1)
		void SetTemplate(class ParticleSystem* NewTemplate, bool bDestroyOnFinish)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetTemplate");
			byte* params = (byte*)malloc(8);
			*(class ParticleSystem**)params = NewTemplate;
			*(bool*)(params + 4) = bDestroyOnFinish;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FinishedComponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.OnParticleSystemFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = FinishedComponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnParticleEventGenerator(class SeqAct_ParticleEventGenerator* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.OnParticleEventGenerator");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ParticleEventGenerator**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFloatParameter(ScriptName ParameterName, float Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetFloatParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVectorParameter(ScriptName ParameterName, Vector Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetVectorParameter");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = ParameterName;
			*(Vector*)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetColorParameter(ScriptName ParameterName, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetColorParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetExtColorParameter(ScriptName ParameterName, byte Red, byte Green, byte Blue, byte Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetExtColorParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(params + 8) = Red;
			*(params + 9) = Green;
			*(params + 10) = Blue;
			*(params + 11) = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActorParameter(ScriptName ParameterName, class Actor* Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetActorParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(class Actor**)(params + 8) = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetParticleSysParam(class SeqAct_SetParticleSysParam* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.OnSetParticleSysParam");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetParticleSysParam**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.ShouldSaveForCheckpoint");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CreateCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.Emitter.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.CreateCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Emitter.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Emitter.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ApplyCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.Emitter.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Emitter.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Emitter.CheckpointRecord'!
void**)params;
			free(params);
		}
		void HideSelf()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.HideSelf");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
