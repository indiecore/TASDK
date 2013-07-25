#pragma once
#include "Engine__SoundNode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNodeWave." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundNodeWave." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeWave : public SoundNode
	{
	public:
		ADD_VAR(::StrProperty, SourceFileTimestamp, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SourceFilePath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Comment, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ResourceData'!
		ADD_VAR(::IntProperty, ResourceSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ResourceID, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.UntypedBulkData_Mirror' for the property named 'CompressedPS3Data'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.UntypedBulkData_Mirror' for the property named 'CompressedXbox360Data'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.UntypedBulkData_Mirror' for the property named 'CompressedPCData'!
		ADD_VAR(::IntProperty, RawPCMDataSize, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'RawPCMData'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VorbisDecompressor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.UntypedBulkData_Mirror' for the property named 'RawData'!
		ADD_VAR(::IntProperty, SampleRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumChannels, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Pitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Volume, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SpokenText, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DecompressionType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TTSSpeaker, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bManualWordWrap, 0x40)
		ADD_VAR(::BoolProperty, bMature, 0x20)
		ADD_VAR(::BoolProperty, bProcedural, 0x10)
		ADD_VAR(::BoolProperty, bUseTTS, 0x8)
		ADD_VAR(::BoolProperty, bDynamicResource, 0x4)
		ADD_VAR(::BoolProperty, bLoopingSound, 0x2)
		ADD_VAR(::BoolProperty, bForceRealTimeDecompression, 0x1)
		ADD_VAR(::IntProperty, CompressionQuality, 0xFFFFFFFF)
		void GeneratePCMData(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Buffer, int SamplesNeeded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundNodeWave.GeneratePCMData");
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
#undef ADD_VAR
#undef ADD_STRUCT
