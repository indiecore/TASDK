#pragma once
#include "Engine.ParticleModuleKillBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleKillHeight." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleKillHeight." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleKillHeight : public ParticleModuleKillBase
	{
	public:
		ADD_VAR(::BoolProperty, bApplyPSysScale, 0x4)
		ADD_VAR(::BoolProperty, bFloor, 0x2)
		ADD_VAR(::BoolProperty, bAbsolute, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Height, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
