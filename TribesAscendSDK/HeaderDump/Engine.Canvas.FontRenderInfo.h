#pragma once
#include "Engine.Canvas.DepthFieldGlowInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Canvas.FontRenderInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Canvas.FontRenderInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FontRenderInfo
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<DepthFieldGlowInfo>, GlowInfo, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableShadow, 0x2)
		ADD_VAR(::BoolProperty, bClipText, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
