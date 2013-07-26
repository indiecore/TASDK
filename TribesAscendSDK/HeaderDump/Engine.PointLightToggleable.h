#pragma once
#include "Engine.PointLight.h"
#include "Engine.PointLightToggleable.CheckpointRecord.h"
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
		void CreateCheckpointRecord(CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightToggleable.CreateCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(CheckpointRecord*)params;
			free(params);
		}
		void ApplyCheckpointRecord(CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightToggleable.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(CheckpointRecord*)params;
			free(params);
		}
	};
}
