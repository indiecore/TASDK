#pragma once
#include "Engine.BlockingVolume.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DynamicBlockingVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DynamicBlockingVolume : public BlockingVolume
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicBlockingVolume.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.DynamicBlockingVolume.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicBlockingVolume.CreateCheckpointRecord");
			byte* params = (byte*)malloc(28);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.DynamicBlockingVolume.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.DynamicBlockingVolume.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ApplyCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.DynamicBlockingVolume.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicBlockingVolume.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(28);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.DynamicBlockingVolume.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.DynamicBlockingVolume.CheckpointRecord'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
