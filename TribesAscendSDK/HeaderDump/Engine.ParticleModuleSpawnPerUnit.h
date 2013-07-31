#pragma once
#include "Engine.ParticleModuleSpawnBase.h"
#include "Core.DistributionFloat.h"
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
	class ParticleModuleSpawnPerUnit : public ParticleModuleSpawnBase
	{
	public:
		ADD_STRUCT(float, MovementTolerance, 112)
		ADD_BOOL(bIgnoreMovementAlongZ, 108, 0x8)
		ADD_BOOL(bIgnoreMovementAlongY, 108, 0x4)
		ADD_BOOL(bIgnoreMovementAlongX, 108, 0x2)
		ADD_BOOL(bIgnoreSpawnRateWhenMoving, 108, 0x1)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, SpawnPerUnit, 80)
		ADD_STRUCT(float, UnitScalar, 76)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
