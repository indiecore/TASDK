#pragma once
#include "Engine.ParticleModuleLocationPrimitiveBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleLocationPrimitiveCylinder." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleLocationPrimitiveCylinder." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLocationPrimitiveCylinder : public ParticleModuleLocationPrimitiveBase
	{
	public:
		ADD_VAR(::ByteProperty, HeightAxis, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, RadialVelocity, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, StartHeight, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, StartRadius, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
