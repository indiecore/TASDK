#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleModuleParameterDynamic.EmitterDynamicParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ParticleModuleParameterDynamic.EmitterDynamicParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class EmitterDynamicParameter
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, ParamValue, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bScaleVelocityByParamValue, 0x1)
		ADD_VAR(::ByteProperty, ValueMethod, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSpawnTimeOnly, 0x2)
		ADD_VAR(::BoolProperty, bUseEmitterTime, 0x1)
		ADD_VAR(::NameProperty, ParamName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
