#pragma once
#include "Engine.Texture.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TextureRenderTarget." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TextureRenderTarget : public Texture
	{
	public:
		ADD_VAR(::FloatProperty, TargetGamma, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRenderOnce, 0x4)
		ADD_VAR(::BoolProperty, bNeedsTwoCopies, 0x2)
		ADD_VAR(::BoolProperty, bUpdateImmediate, 0x1)
	};
}
#undef ADD_VAR
