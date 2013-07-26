#pragma once
#include "Engine.ParticleModuleKillBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleKillBox." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleKillBox." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleKillBox : public ParticleModuleKillBase
	{
	public:
		ADD_VAR(::BoolProperty, bKillInside, 0x2)
		ADD_VAR(::BoolProperty, bAbsolute, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, UpperRightCorner, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, LowerLeftCorner, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
