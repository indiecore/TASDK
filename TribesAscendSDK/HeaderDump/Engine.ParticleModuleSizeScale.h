#pragma once
#include "Engine.ParticleModuleSizeBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleSizeScale." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleSizeScale." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSizeScale : public ParticleModuleSizeBase
	{
	public:
		ADD_VAR(::BoolProperty, EnableZ, 0x4)
		ADD_VAR(::BoolProperty, EnableY, 0x2)
		ADD_VAR(::BoolProperty, EnableX, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, SizeScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
