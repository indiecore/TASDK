#pragma once
#include "Engine.PBRuleNodeBase.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeComment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PBRuleNodeComment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeComment : public PBRuleNodeBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Color>, FillColor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFilled, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Color>, BorderColor, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BorderWidth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
