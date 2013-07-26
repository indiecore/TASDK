#pragma once
#include "Engine.BlockingVolume.h"
#include "Engine.DynamicBlockingVolume.CheckpointRecord.h"
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
		void CreateCheckpointRecord(CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicBlockingVolume.CreateCheckpointRecord");
			byte* params = (byte*)malloc(28);
			*(CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(CheckpointRecord*)params;
			free(params);
		}
		void ApplyCheckpointRecord(CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicBlockingVolume.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(28);
			*(CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(CheckpointRecord*)params;
			free(params);
		}
	};
}
#undef ADD_VAR
