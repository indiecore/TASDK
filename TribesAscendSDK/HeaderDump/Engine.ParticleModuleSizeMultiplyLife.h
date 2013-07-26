#pragma once
#include "Engine.ParticleModuleSizeBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleSizeMultiplyLife." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleSizeMultiplyLife." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSizeMultiplyLife : public ParticleModuleSizeBase
	{
	public:
		ADD_VAR(::BoolProperty, MultiplyZ, 0x4)
		ADD_VAR(::BoolProperty, MultiplyY, 0x2)
		ADD_VAR(::BoolProperty, MultiplyX, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, LifeMultiplier, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
