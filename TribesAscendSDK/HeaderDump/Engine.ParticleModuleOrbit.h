#pragma once
#include "Engine.ParticleModuleOrbitBase.h"
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
	class ParticleModuleOrbit : public ParticleModuleOrbitBase
	{
	public:
		enum EOrbitChainMode : byte
		{
			EOChainMode_Add = 0,
			EOChainMode_Scale = 1,
			EOChainMode_Link = 2,
			EOChainMode_MAX = 3,
		};
		class OrbitOptions
		{
		public:
			ADD_BOOL(bUseEmitterTime, 0, 0x4)
			ADD_BOOL(bProcessDuringUpdate, 0, 0x2)
			ADD_BOOL(bProcessDuringSpawn, 0, 0x1)
		};
		ADD_STRUCT(ParticleModuleOrbit::OrbitOptions, RotationRateOptions, 172)
		ADD_STRUCT(DistributionVector::RawDistributionVector, RotationRateAmount, 144)
		ADD_STRUCT(ParticleModuleOrbit::OrbitOptions, RotationOptions, 140)
		ADD_STRUCT(DistributionVector::RawDistributionVector, RotationAmount, 112)
		ADD_STRUCT(ParticleModuleOrbit::OrbitOptions, OffsetOptions, 108)
		ADD_STRUCT(DistributionVector::RawDistributionVector, OffsetAmount, 80)
		ADD_STRUCT(ParticleModuleOrbit::EOrbitChainMode, ChainMode, 76)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
