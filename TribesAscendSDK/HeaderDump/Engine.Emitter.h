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
		struct CheckpointRecord
		{
		public:
			ADD_BOOL(bIsActive, 0, 0x1)
		};
		ADD_BOOL(bCurrentlyActive, 484, 0x4)
		ADD_BOOL(bPostUpdateTickGroup, 484, 0x2)
		ADD_BOOL(bDestroyOnSystemFinish, 484, 0x1)
		void SetTemplate(class ParticleSystem* NewTemplate, bool bDestroyOnFinish)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15147);
			byte params[8] = { NULL };
			*(class ParticleSystem**)params = NewTemplate;
			*(bool*)&params[4] = bDestroyOnFinish;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15150);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15151);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FinishedComponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15153);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = FinishedComponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15155);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnParticleEventGenerator(class SeqAct_ParticleEventGenerator* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15157);
			byte params[4] = { NULL };
			*(class SeqAct_ParticleEventGenerator**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15159);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFloatParameter(ScriptName ParameterName, float Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15160);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVectorParameter(ScriptName ParameterName, Vector Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15163);
			byte params[20] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Vector*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetColorParameter(ScriptName ParameterName, Object::Color Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15166);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::Color*)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetExtColorParameter(ScriptName ParameterName, byte Red, byte Green, byte Blue, byte Alpha)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15169);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			params[8] = Red;
			params[9] = Green;
			params[10] = Blue;
			params[11] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActorParameter(ScriptName ParameterName, class Actor* Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15176);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Actor**)&params[8] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetParticleSysParam(class SeqAct_SetParticleSysParam* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15179);
			byte params[4] = { NULL };
			*(class SeqAct_SetParticleSysParam**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15187);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void CreateCheckpointRecord(Emitter::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15189);
			byte params[4] = { NULL };
			*(Emitter::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(Emitter::CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(Emitter::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15191);
			byte params[4] = { NULL };
			*(Emitter::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(Emitter::CheckpointRecord*)params;
		}
		void HideSelf()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15193);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
