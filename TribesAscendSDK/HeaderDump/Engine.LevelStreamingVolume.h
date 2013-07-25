#pragma once
#include "Engine.Volume.h"
#include "Engine.SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LevelStreamingVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LevelStreamingVolume : public Volume
	{
	public:
		ADD_VAR(::FloatProperty, TestVolumeDistance, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Usage, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, StreamingUsage, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTestDistanceToVolume, 0x4)
		ADD_VAR(::BoolProperty, bDisabled, 0x2)
		ADD_VAR(::BoolProperty, bEditorPreVisOnly, 0x1)
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LevelStreamingVolume.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.LevelStreamingVolume.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LevelStreamingVolume.CreateCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.LevelStreamingVolume.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.LevelStreamingVolume.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ApplyCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.LevelStreamingVolume.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LevelStreamingVolume.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.LevelStreamingVolume.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.LevelStreamingVolume.CheckpointRecord'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
