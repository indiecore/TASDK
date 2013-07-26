#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleBeamBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleBeamSource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleBeamSource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleBeamSource : public ParticleModuleBeamBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, SourceStrength, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, SourceTangent, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, Source, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLockSourceStength, 0x8)
		ADD_VAR(::BoolProperty, bLockSourceTangent, 0x4)
		ADD_VAR(::BoolProperty, bLockSource, 0x2)
		ADD_VAR(::BoolProperty, bSourceAbsolute, 0x1)
		ADD_VAR(::NameProperty, SourceName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SourceTangentMethod, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SourceMethod, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
