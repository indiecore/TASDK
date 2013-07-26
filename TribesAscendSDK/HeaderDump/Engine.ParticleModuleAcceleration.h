#pragma once
#include "Engine.ParticleModuleAccelerationBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleAcceleration." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleAcceleration." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleAcceleration : public ParticleModuleAccelerationBase
	{
	public:
		ADD_VAR(::BoolProperty, bApplyOwnerScale, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, Acceleration, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
