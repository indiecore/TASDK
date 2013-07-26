#pragma once
#include "Core.Object.Vector.h"
#include "Engine.Material.MaterialInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Material.VectorMaterialInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Material.VectorMaterialInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class VectorMaterialInput : public MaterialInput
	{
	public:
		ADD_STRUCT(::VectorProperty, Constant, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, UseConstant, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
