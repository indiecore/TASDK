#pragma once
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleSubUVBase.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleSubUVDirect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSubUVDirect : public ParticleModuleSubUVBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, SubUVSize, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, SubUVPosition, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
