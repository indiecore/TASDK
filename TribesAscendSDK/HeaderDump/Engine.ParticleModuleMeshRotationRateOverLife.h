#pragma once
#include "Engine.ParticleModuleRotationRateBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleMeshRotationRateOverLife." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleMeshRotationRateOverLife." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleMeshRotationRateOverLife : public ParticleModuleRotationRateBase
	{
	public:
		ADD_VAR(::BoolProperty, bScaleRotRate, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, RotRate, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
