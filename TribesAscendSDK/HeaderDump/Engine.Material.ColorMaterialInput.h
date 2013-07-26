#pragma once
#include "Engine.Material.MaterialInput.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Material.ColorMaterialInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Material.ColorMaterialInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ColorMaterialInput : public MaterialInput
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Color>, Constant, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, UseConstant, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
