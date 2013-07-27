#pragma once
#include "Engine.BlockingVolume.h"
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
	class DynamicBlockingVolume : public BlockingVolume
	{
	public:
		class CheckpointRecord
		{
		public:
			ADD_BOOL(bNeedsReplication, 24, 0x4)
			ADD_BOOL(bBlockActors, 24, 0x2)
			ADD_BOOL(bCollideActors, 24, 0x1)
			ADD_STRUCT(Object::Rotator, Rotation, 12)
			ADD_STRUCT(Object::Vector, Location, 0)
		};
		ADD_BOOL(bEnabled, 524, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicBlockingVolume.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateCheckpointRecord(DynamicBlockingVolume::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicBlockingVolume.CreateCheckpointRecord");
			byte params[28] = { NULL };
			*(DynamicBlockingVolume::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(DynamicBlockingVolume::CheckpointRecord*)&params[0];
		}
		void ApplyCheckpointRecord(DynamicBlockingVolume::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicBlockingVolume.ApplyCheckpointRecord");
			byte params[28] = { NULL };
			*(DynamicBlockingVolume::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(DynamicBlockingVolume::CheckpointRecord*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
