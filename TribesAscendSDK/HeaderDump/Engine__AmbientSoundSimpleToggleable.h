#pragma once
#include "Engine__AmbientSoundSimple.h"
#include "Engine__SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AmbientSoundSimpleToggleable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AmbientSoundSimpleToggleable : public AmbientSoundSimple
	{
	public:
		ADD_VAR(::FloatProperty, FadeOutVolumeLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOutDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInVolumeLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInDuration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIgnoreAutoPlay, 0x4)
		ADD_VAR(::BoolProperty, bFadeOnToggle, 0x2)
		ADD_VAR(::BoolProperty, bCurrentlyPlaying, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AmbientSoundSimpleToggleable.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AmbientSoundSimpleToggleable.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartPlaying()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AmbientSoundSimpleToggleable.StartPlaying");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopPlaying()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AmbientSoundSimpleToggleable.StopPlaying");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AmbientSoundSimpleToggleable.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.AmbientSoundSimpleToggleable.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AmbientSoundSimpleToggleable.CreateCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.AmbientSoundSimpleToggleable.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.AmbientSoundSimpleToggleable.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ApplyCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.AmbientSoundSimpleToggleable.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AmbientSoundSimpleToggleable.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.AmbientSoundSimpleToggleable.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.AmbientSoundSimpleToggleable.CheckpointRecord'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
