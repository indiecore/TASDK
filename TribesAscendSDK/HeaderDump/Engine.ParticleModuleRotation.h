#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleRotationBase.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleRotation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleRotation : public ParticleModuleRotationBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, StartRotation, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
