#pragma once
#include "Engine__PointLight.h"
namespace UnrealScript
{
	class PointLightToggleable : public PointLight
	{
	public:
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightToggleable.ShouldSaveForCheckpoint");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CreateCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.PointLightToggleable.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightToggleable.CreateCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.PointLightToggleable.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.PointLightToggleable.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ApplyCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.PointLightToggleable.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightToggleable.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.PointLightToggleable.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.PointLightToggleable.CheckpointRecord'!
void**)params;
			free(params);
		}
	};
}
