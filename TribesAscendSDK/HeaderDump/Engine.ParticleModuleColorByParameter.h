#pragma once
#include "Engine.ParticleModuleColorBase.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleColorByParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleColorByParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleColorByParameter : public ParticleModuleColorBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Color>, DefaultColor, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ColorParam, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
