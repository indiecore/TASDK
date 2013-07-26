#pragma once
#include "Engine.Font.h"
#include "Core.Object.Vector2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Canvas.TextSizingParameters." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Canvas.TextSizingParameters." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Canvas.TextSizingParameters." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TextSizingParameters
	{
	public:
		ADD_VAR(::FloatProperty, ViewportHeight, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, SpacingAdjust, 0xFFFFFFFF)
		ADD_OBJECT(Font, DrawFont)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, Scaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DrawYL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DrawXL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DrawY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DrawX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
