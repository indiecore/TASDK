#pragma once
#include "Core.Object.Vector2D.h"
#include "Core.Object.LinearColor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Canvas.DepthFieldGlowInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Canvas.DepthFieldGlowInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DepthFieldGlowInfo
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, GlowInnerRadius, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, GlowOuterRadius, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, GlowColor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableGlow, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
