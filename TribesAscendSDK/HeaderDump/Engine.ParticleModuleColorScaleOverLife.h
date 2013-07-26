#pragma once
#include "Engine.ParticleModuleColorBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleColorScaleOverLife." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleColorScaleOverLife." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleColorScaleOverLife : public ParticleModuleColorBase
	{
	public:
		ADD_VAR(::BoolProperty, bEmitterTime, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, AlphaScaleOverLife, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, ColorScaleOverLife, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
