#pragma once
#include "Engine__TextureRenderTarget.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TextureRenderTargetCube." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TextureRenderTargetCube : public TextureRenderTarget
	{
	public:
		ADD_VAR(::ByteProperty, Format, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
