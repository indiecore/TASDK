#pragma once
#include "Engine.ParticleModuleTypeDataBase.h"
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
	class ParticleModuleTypeDataTrail2 : public ParticleModuleTypeDataBase
	{
	public:
		ADD_BOOL(RenderTessellation, 100, 0x20)
		ADD_BOOL(RenderLines, 100, 0x10)
		ADD_BOOL(RenderDirectLine, 100, 0x8)
		ADD_BOOL(RenderGeometry, 100, 0x4)
		ADD_BOOL(bClearTangents, 100, 0x2)
		ADD_BOOL(bClipSourceSegement, 100, 0x1)
		ADD_STRUCT(int, MaxParticleInTrailCount, 96)
		ADD_STRUCT(int, MaxTrailCount, 92)
		ADD_STRUCT(int, Sheets, 88)
		ADD_STRUCT(int, TextureTile, 84)
		ADD_STRUCT(float, TessellationStrength, 80)
		ADD_STRUCT(float, TessellationFactorDistance, 76)
		ADD_STRUCT(int, TessellationFactor, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
