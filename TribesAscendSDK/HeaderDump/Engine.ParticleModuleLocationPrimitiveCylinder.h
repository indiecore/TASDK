#pragma once
#include "Engine.ParticleModuleLocationPrimitiveBase.h"
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
	class ParticleModuleLocationPrimitiveCylinder : public ParticleModuleLocationPrimitiveBase
	{
	public:
		enum CylinderHeightAxis : byte
		{
			PMLPC_HEIGHTAXIS_X = 0,
			PMLPC_HEIGHTAXIS_Y = 1,
			PMLPC_HEIGHTAXIS_Z = 2,
			PMLPC_HEIGHTAXIS_MAX = 3,
		};
		ADD_STRUCT(ParticleModuleLocationPrimitiveCylinder::CylinderHeightAxis, HeightAxis, 192)
		ADD_BOOL(RadialVelocity, 132, 0x1)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, StartHeight, 164)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, StartRadius, 136)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
