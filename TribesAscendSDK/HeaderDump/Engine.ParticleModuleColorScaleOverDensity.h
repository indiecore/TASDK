#pragma once
#include "Engine.ParticleModuleColorBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleColorScaleOverDensity." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleColorScaleOverDensity : public ParticleModuleColorBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, AlphaScaleOverDensity, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, ColorScaleOverDensity, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
