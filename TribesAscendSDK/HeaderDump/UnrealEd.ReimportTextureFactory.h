#pragma once
#include "UnrealEd.TextureFactory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UnrealEd.ReimportTextureFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ReimportTextureFactory : public TextureFactory
	{
	public:
		ADD_VAR(::BoolProperty, NoCompression, 0x1)
		ADD_VAR(::BoolProperty, CompressionNoAlpha, 0x1)
		ADD_VAR(::ByteProperty, CompressionSettings, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, DeferCompression, 0x1)
		ADD_VAR(::BoolProperty, Create Material?, 0x1)
		ADD_VAR(::BoolProperty, RGB To Diffuse, 0x1)
		ADD_VAR(::BoolProperty, RGB To Emissive, 0x1)
		ADD_VAR(::BoolProperty, Alpha To Specular, 0x1)
		ADD_VAR(::BoolProperty, Alpha To Emissive, 0x1)
		ADD_VAR(::BoolProperty, Alpha To Opacity, 0x1)
		ADD_VAR(::BoolProperty, Alpha To Opacity Mask, 0x1)
		ADD_VAR(::BoolProperty, Two Sided?, 0x1)
		ADD_VAR(::ByteProperty, Blending, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Lighting Model, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, FlipBook, 0x1)
		ADD_VAR(::ByteProperty, MipGenSettings, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
