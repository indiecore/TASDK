#pragma once
#include "Engine.AmbientSoundSimple.h"
#include "Engine.SeqAct_Toggle.h"
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
namespace UnrealScript
{
	class AmbientSoundSimpleToggleable : public AmbientSoundSimple
	{
	public:
		struct CheckpointRecord
		{
		public:
			ADD_BOOL(bCurrentlyPlaying, 0, 0x1)
		};
		ADD_STRUCT(float, FadeOutVolumeLevel, 516)
		ADD_STRUCT(float, FadeOutDuration, 512)
		ADD_STRUCT(float, FadeInVolumeLevel, 508)
		ADD_STRUCT(float, FadeInDuration, 504)
		ADD_BOOL(bIgnoreAutoPlay, 500, 0x4)
		ADD_BOOL(bFadeOnToggle, 500, 0x2)
		ADD_BOOL(bCurrentlyPlaying, 500, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10477);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10478);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartPlaying()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10480);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopPlaying()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10481);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10482);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateCheckpointRecord(AmbientSoundSimpleToggleable::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10484);
			byte params[4] = { NULL };
			*(AmbientSoundSimpleToggleable::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(AmbientSoundSimpleToggleable::CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(AmbientSoundSimpleToggleable::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10486);
			byte params[4] = { NULL };
			*(AmbientSoundSimpleToggleable::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(AmbientSoundSimpleToggleable::CheckpointRecord*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
