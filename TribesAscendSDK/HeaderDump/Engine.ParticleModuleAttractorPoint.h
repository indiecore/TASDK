#pragma once
#include "Engine.ParticleModuleAttractorBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleAttractorPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleAttractorPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleAttractorPoint : public ParticleModuleAttractorBase
	{
	public:
		ADD_VAR(::BoolProperty, bUseWorldSpacePosition, 0x8)
		ADD_VAR(::BoolProperty, bOverrideVelocity, 0x4)
		ADD_VAR(::BoolProperty, bAffectBaseVelocity, 0x2)
		ADD_VAR(::BoolProperty, StrengthByDistance, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Strength, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Range, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, Position, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
