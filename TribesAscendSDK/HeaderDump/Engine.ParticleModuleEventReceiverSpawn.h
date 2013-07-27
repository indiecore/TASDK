#pragma once
#include "Engine.ParticleModuleEventReceiverBase.h"
#include "Core.DistributionFloat.h"
#include "Core.DistributionVector.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleEventReceiverSpawn : public ParticleModuleEventReceiverBase
	{
	public:
		ADD_STRUCT(DistributionVector::RawDistributionVector, InheritVelocityScale, 116)
		ADD_BOOL(bInheritVelocity, 112, 0x4)
		ADD_BOOL(bUsePSysLocation, 112, 0x2)
		ADD_BOOL(bUseParticleTime, 112, 0x1)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, SpawnCount, 84)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
