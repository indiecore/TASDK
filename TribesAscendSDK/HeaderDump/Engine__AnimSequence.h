#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimSequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AnimSequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimSequence." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimSequence : public Object
	{
	public:
		ADD_VAR(::FloatProperty, SequenceLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RateScale, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SequenceName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumFrames, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNoLoopingInterpolation, 0x1)
		ADD_VAR(::BoolProperty, bIsAdditive, 0x2)
		ADD_VAR(::BoolProperty, bAdditiveBuiltLooping, 0x4)
		ADD_VAR(::BoolProperty, bDoNotOverrideCompression, 0x8)
		ADD_VAR(::BoolProperty, bHasBeenUsed, 0x10)
		ADD_OBJECT(AnimationCompressionAlgorithm, CompressionScheme)
		ADD_VAR(::ByteProperty, TranslationCompressionFormat, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RotationCompressionFormat, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, KeyEncodingFormat, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'TranslationCodec'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'RotationCodec'!
		ADD_VAR(::NameProperty, AdditiveRefName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EncodingPkgVersion, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CompressCommandletVersion, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UseScore, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
