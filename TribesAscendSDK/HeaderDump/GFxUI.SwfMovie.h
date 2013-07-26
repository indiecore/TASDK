#pragma once
#include "GFxUI.GFxRawData.h"
#include "Core.Object.QWord.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxUI.SwfMovie." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GFxUI.SwfMovie." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SwfMovie : public GFxRawData
	{
	public:
		ADD_STRUCT(::QWordProperty, ImportTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RTVideoTextures, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RTTextures, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SourceFileTimestamp, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TextureFormat, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TextureRescale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PackTextureSize, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SourceFile, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPackTextures, 0x4)
		ADD_VAR(::BoolProperty, bSetSRGBOnImportedTextures, 0x2)
		ADD_VAR(::BoolProperty, bUsesFontlib, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
