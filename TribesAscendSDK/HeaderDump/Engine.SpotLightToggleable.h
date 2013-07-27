#pragma once
#include "Engine.SpotLight.h"
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
	class SpotLightToggleable : public SpotLight
	{
	public:
		class CheckpointRecord
		{
		public:
			ADD_BOOL(bEnabled, 0, 0x1)
		};
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpotLightToggleable.ShouldSaveForCheckpoint");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CreateCheckpointRecord(SpotLightToggleable::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpotLightToggleable.CreateCheckpointRecord");
			byte params[4] = { NULL };
			*(SpotLightToggleable::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(SpotLightToggleable::CheckpointRecord*)&params[0];
		}
		void ApplyCheckpointRecord(SpotLightToggleable::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpotLightToggleable.ApplyCheckpointRecord");
			byte params[4] = { NULL };
			*(SpotLightToggleable::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(SpotLightToggleable::CheckpointRecord*)&params[0];
		}
	};
}
#undef ADD_BOOL
