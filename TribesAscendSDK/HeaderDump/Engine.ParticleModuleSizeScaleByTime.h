#pragma once
#include "Engine.ParticleModuleSizeBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleSizeScaleByTime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleSizeScaleByTime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSizeScaleByTime : public ParticleModuleSizeBase
	{
	public:
		ADD_VAR(::BoolProperty, bEnableZ, 0x4)
		ADD_VAR(::BoolProperty, bEnableY, 0x2)
		ADD_VAR(::BoolProperty, bEnableX, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, SizeScaleByTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
