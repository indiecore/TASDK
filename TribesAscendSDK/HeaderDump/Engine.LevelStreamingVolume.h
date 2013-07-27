#pragma once
#include "Engine.LevelStreaming.h"
#include "Engine.Volume.h"
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
	class LevelStreamingVolume : public Volume
	{
	public:
		enum EStreamingVolumeUsage : byte
		{
			SVB_Loading = 0,
			SVB_LoadingAndVisibility = 1,
			SVB_VisibilityBlockingOnLoad = 2,
			SVB_BlockingOnLoad = 3,
			SVB_LoadingNotVisible = 4,
			SVB_MAX = 5,
		};
		struct CheckpointRecord
		{
		public:
			ADD_BOOL(bDisabled, 0, 0x1)
		};
		ADD_STRUCT(ScriptArray<class LevelStreaming*>, StreamingLevels, 520)
		ADD_STRUCT(float, TestVolumeDistance, 540)
		ADD_STRUCT(LevelStreamingVolume::EStreamingVolumeUsage, Usage, 537)
		ADD_STRUCT(LevelStreamingVolume::EStreamingVolumeUsage, StreamingUsage, 536)
		ADD_BOOL(bTestDistanceToVolume, 532, 0x4)
		ADD_BOOL(bDisabled, 532, 0x2)
		ADD_BOOL(bEditorPreVisOnly, 532, 0x1)
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19395);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateCheckpointRecord(LevelStreamingVolume::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19397);
			byte params[4] = { NULL };
			*(LevelStreamingVolume::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(LevelStreamingVolume::CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(LevelStreamingVolume::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19399);
			byte params[4] = { NULL };
			*(LevelStreamingVolume::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(LevelStreamingVolume::CheckpointRecord*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
