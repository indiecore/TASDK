#pragma once
#include "Engine.ParticleModuleAttractorBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleAttractorParticle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleAttractorParticle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleAttractorParticle : public ParticleModuleAttractorBase
	{
	public:
		ADD_VAR(::IntProperty, LastSelIndex, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SelectionMethod, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EmitterName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Strength, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInheritSourceVel, 0x8)
		ADD_VAR(::BoolProperty, bRenewSource, 0x4)
		ADD_VAR(::BoolProperty, bAffectBaseVelocity, 0x2)
		ADD_VAR(::BoolProperty, bStrengthByDistance, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Range, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
