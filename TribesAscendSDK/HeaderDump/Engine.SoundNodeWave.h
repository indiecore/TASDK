#pragma once
#include "Engine.SoundNode.h"
#include "Engine.EngineTypes.h"
#include "Core.Object.h"
#include "Engine.AudioDevice.h"
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
	class SoundNodeWave : public SoundNode
	{
	public:
		enum EDecompressionType : byte
		{
			DTYPE_Setup = 0,
			DTYPE_Invalid = 1,
			DTYPE_Preview = 2,
			DTYPE_Native = 3,
			DTYPE_RealTime = 4,
			DTYPE_Procedural = 5,
			DTYPE_Xenon = 6,
			DTYPE_MAX = 7,
		};
		ADD_STRUCT(ScriptArray<int>, ChannelOffsets, 120)
		ADD_STRUCT(ScriptArray<int>, ChannelSizes, 132)
		ADD_STRUCT(ScriptArray<EngineTypes::SubtitleCue>, Subtitles, 376)
		ADD_STRUCT(ScriptArray<EngineTypes::LocalizedSubtitle>, LocalizedSubtitles, 400)
		ADD_STRUCT(ScriptString*, SourceFileTimestamp, 424)
		ADD_STRUCT(ScriptString*, SourceFilePath, 412)
		ADD_STRUCT(ScriptString*, Comment, 388)
		ADD_STRUCT(Object::Pointer, ResourceData, 372)
		ADD_STRUCT(int, ResourceSize, 368)
		ADD_STRUCT(int, ResourceID, 364)
		ADD_STRUCT(Object::UntypedBulkData_Mirror, CompressedPS3Data, 312)
		ADD_STRUCT(Object::UntypedBulkData_Mirror, CompressedXbox360Data, 260)
		ADD_STRUCT(Object::UntypedBulkData_Mirror, CompressedPCData, 208)
		ADD_STRUCT(int, RawPCMDataSize, 204)
		ADD_STRUCT(Object::Pointer, RawPCMData, 200)
		ADD_STRUCT(Object::Pointer, VorbisDecompressor, 196)
		ADD_STRUCT(Object::UntypedBulkData_Mirror, RawData, 144)
		ADD_STRUCT(int, SampleRate, 116)
		ADD_STRUCT(int, NumChannels, 112)
		ADD_STRUCT(float, Duration, 108)
		ADD_STRUCT(float, Pitch, 104)
		ADD_STRUCT(float, Volume, 100)
		ADD_STRUCT(ScriptString*, SpokenText, 88)
		ADD_STRUCT(SoundNodeWave::EDecompressionType, DecompressionType, 85)
		ADD_STRUCT(AudioDevice::ETTSSpeaker, TTSSpeaker, 84)
		ADD_BOOL(bManualWordWrap, 80, 0x40)
		ADD_BOOL(bMature, 80, 0x20)
		ADD_BOOL(bProcedural, 80, 0x10)
		ADD_BOOL(bUseTTS, 80, 0x8)
		ADD_BOOL(bDynamicResource, 80, 0x4)
		ADD_BOOL(bLoopingSound, 80, 0x2)
		ADD_BOOL(bForceRealTimeDecompression, 80, 0x1)
		ADD_STRUCT(int, CompressionQuality, 76)
		void GeneratePCMData(ScriptArray<byte>& Buffer, int SamplesNeeded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundNodeWave.GeneratePCMData");
			byte params[16] = { NULL };
			*(ScriptArray<byte>*)&params[0] = Buffer;
			*(int*)&params[12] = SamplesNeeded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Buffer = *(ScriptArray<byte>*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
