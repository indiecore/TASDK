#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.ParticleSystem.h"
#include "Engine.SeqAct_ParticleEventGenerator.h"
#include "Engine.SeqAct_SetParticleSysParam.h"
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
namespace UnrealScript
{
	class Emitter : public Actor
	{
	public:
		class CheckpointRecord
		{
		public:
			ADD_BOOL(bIsActive, 0, 0x1)
		};
		ADD_BOOL(bCurrentlyActive, 484, 0x4)
		ADD_BOOL(bPostUpdateTickGroup, 484, 0x2)
		ADD_BOOL(bDestroyOnSystemFinish, 484, 0x1)
		void SetTemplate(class ParticleSystem* NewTemplate, bool bDestroyOnFinish)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetTemplate");
			byte params[8] = { NULL };
			*(class ParticleSystem**)&params[0] = NewTemplate;
			*(bool*)&params[4] = bDestroyOnFinish;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FinishedComponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.OnParticleSystemFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = FinishedComponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnParticleEventGenerator(class SeqAct_ParticleEventGenerator* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.OnParticleEventGenerator");
			byte params[4] = { NULL };
			*(class SeqAct_ParticleEventGenerator**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFloatParameter(ScriptName ParameterName, float Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetFloatParameter");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(float*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVectorParameter(ScriptName ParameterName, Object::Vector Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetVectorParameter");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(Object::Vector*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetColorParameter(ScriptName ParameterName, Object::Color Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetColorParameter");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(Object::Color*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetExtColorParameter(ScriptName ParameterName, byte Red, byte Green, byte Blue, byte Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetExtColorParameter");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			params[8] = Red;
			params[9] = Green;
			params[10] = Blue;
			params[11] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActorParameter(ScriptName ParameterName, class Actor* Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.SetActorParameter");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(class Actor**)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetParticleSysParam(class SeqAct_SetParticleSysParam* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.OnSetParticleSysParam");
			byte params[4] = { NULL };
			*(class SeqAct_SetParticleSysParam**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.ShouldSaveForCheckpoint");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CreateCheckpointRecord(Emitter::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.CreateCheckpointRecord");
			byte params[4] = { NULL };
			*(Emitter::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(Emitter::CheckpointRecord*)&params[0];
		}
		void ApplyCheckpointRecord(Emitter::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.ApplyCheckpointRecord");
			byte params[4] = { NULL };
			*(Emitter::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(Emitter::CheckpointRecord*)&params[0];
		}
		void HideSelf()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Emitter.HideSelf");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
