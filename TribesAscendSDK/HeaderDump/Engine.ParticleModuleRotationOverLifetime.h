#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleRotationBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleRotationOverLifetime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleRotationOverLifetime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleRotationOverLifetime : public ParticleModuleRotationBase
	{
	public:
		ADD_VAR(::BoolProperty, Scale, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, RotationOverLife, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
