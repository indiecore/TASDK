#pragma once
#include "Engine.PointLight.h"
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
	class PointLightToggleable : public PointLight
	{
	public:
		class CheckpointRecord
		{
		public:
			ADD_BOOL(bEnabled, 0, 0x1)
		};
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightToggleable.ShouldSaveForCheckpoint");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CreateCheckpointRecord(PointLightToggleable::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightToggleable.CreateCheckpointRecord");
			byte params[4] = { NULL };
			*(PointLightToggleable::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(PointLightToggleable::CheckpointRecord*)&params[0];
		}
		void ApplyCheckpointRecord(PointLightToggleable::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightToggleable.ApplyCheckpointRecord");
			byte params[4] = { NULL };
			*(PointLightToggleable::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(PointLightToggleable::CheckpointRecord*)&params[0];
		}
	};
}
#undef ADD_BOOL
