#pragma once
#include "Engine.ParticleModuleCameraBase.h"
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
	class ParticleModuleCameraOffset : public ParticleModuleCameraBase
	{
	public:
		enum EParticleCameraOffsetUpdateMethod : byte
		{
			EPCOUM_DirectSet = 0,
			EPCOUM_Additive = 1,
			EPCOUM_Scalar = 2,
			EPCOUM_MAX = 3,
		};
		ADD_STRUCT(ParticleModuleCameraOffset::EParticleCameraOffsetUpdateMethod, UpdateMethod, 104)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, CameraOffset, 72)
		ADD_BOOL(bSpawnTimeOnly, 100, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
