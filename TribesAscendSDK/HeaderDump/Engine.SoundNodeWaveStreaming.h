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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26982);
			byte params[12] = { NULL };
			*(ScriptArray<byte>*)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetAudio()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26985);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AvailableAudioBytes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26986);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void GeneratePCMData(ScriptArray<byte>& Buffer, int SamplesNeeded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26988);
			byte params[16] = { NULL };
			*(ScriptArray<byte>*)params = Buffer;
			*(int*)&params[12] = SamplesNeeded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Buffer = *(ScriptArray<byte>*)params;
		}
	};
}
#undef ADD_STRUCT
