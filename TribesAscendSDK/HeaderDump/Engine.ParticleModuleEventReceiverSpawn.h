#pragma once
#include "Engine.ParticleModuleEventReceiverBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleEventReceiverSpawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleEventReceiverSpawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleEventReceiverSpawn : public ParticleModuleEventReceiverBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, InheritVelocityScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInheritVelocity, 0x4)
		ADD_VAR(::BoolProperty, bUsePSysLocation, 0x2)
		ADD_VAR(::BoolProperty, bUseParticleTime, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, SpawnCount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
