#pragma once
#include "Engine.ParticleModuleTypeDataBase.h"
#include "Core.Object.h"
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
	class ParticleModuleTypeDataTrail : public ParticleModuleTypeDataBase
	{
	public:
		ADD_STRUCT(Vector, SpawnDistance, 108)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Tension, 80)
		ADD_STRUCT(int, TessellationFactor, 76)
		ADD_BOOL(SpawnByDistance, 72, 0x10)
		ADD_BOOL(Tapered, 72, 0x8)
		ADD_BOOL(RenderTessellation, 72, 0x4)
		ADD_BOOL(RenderLines, 72, 0x2)
		ADD_BOOL(RenderGeometry, 72, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
