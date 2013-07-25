#pragma once
#include "Engine__SoundNodeWave.h"
namespace UnrealScript
{
	class SoundNodeWaveStreaming : public SoundNodeWave
	{
	public:
		void QueueAudio(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundNodeWaveStreaming.QueueAudio");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetAudio()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundNodeWaveStreaming.ResetAudio");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AvailableAudioBytes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundNodeWaveStreaming.AvailableAudioBytes");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void GeneratePCMData(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Buffer, int SamplesNeeded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundNodeWaveStreaming.GeneratePCMData");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Buffer;
			*(int*)(params + 12) = SamplesNeeded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Buffer = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
	};
}
