#pragma once
#include "Engine.Material.MaterialInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Material.ScalarMaterialInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ScalarMaterialInput : public MaterialInput
	{
	public:
		ADD_VAR(::FloatProperty, Constant, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, UseConstant, 0x1)
	};
}
#undef ADD_VAR
