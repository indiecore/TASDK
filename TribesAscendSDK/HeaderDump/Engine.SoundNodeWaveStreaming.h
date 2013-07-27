#pragma once
#include "Engine.SoundNodeWave.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SoundNodeWaveStreaming : public SoundNodeWave
	{
	public:
		ADD_STRUCT(ScriptArray<byte>, QueuedAudio, 436)
		void QueueAudio(ScriptArray<byte> Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundNodeWaveStreaming.QueueAudio");
			byte params[12] = { NULL };
			*(ScriptArray<byte>*)&params[0] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetAudio()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundNodeWaveStreaming.ResetAudio");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AvailableAudioBytes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundNodeWaveStreaming.AvailableAudioBytes");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void GeneratePCMData(ScriptArray<byte>& Buffer, int SamplesNeeded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundNodeWaveStreaming.GeneratePCMData");
			byte params[16] = { NULL };
			*(ScriptArray<byte>*)&params[0] = Buffer;
			*(int*)&params[12] = SamplesNeeded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Buffer = *(ScriptArray<byte>*)&params[0];
		}
	};
}
#undef ADD_STRUCT
