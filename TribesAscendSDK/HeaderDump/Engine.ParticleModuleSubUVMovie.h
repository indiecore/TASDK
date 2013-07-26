#pragma once
#include "Engine.ParticleModuleSubUV.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleSubUVMovie." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleSubUVMovie." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSubUVMovie : public ParticleModuleSubUV
	{
	public:
		ADD_VAR(::IntProperty, StartingFrame, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, FrameRate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseEmitterTime, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
