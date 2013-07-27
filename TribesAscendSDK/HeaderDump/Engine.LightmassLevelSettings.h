#pragma once
#include "Core.Object.h"
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
	class LightmassLevelSettings : public Object
	{
	public:
		ADD_STRUCT(float, MaxOcclusionDistance, 104)
		ADD_STRUCT(float, FullyOccludedSamplesFraction, 100)
		ADD_STRUCT(float, OcclusionExponent, 96)
		ADD_STRUCT(float, IndirectIlluminationOcclusionFraction, 92)
		ADD_STRUCT(float, DirectIlluminationOcclusionFraction, 88)
		ADD_BOOL(bVisualizeAmbientOcclusion, 84, 0x2)
		ADD_BOOL(bUseAmbientOcclusion, 84, 0x1)
		ADD_STRUCT(float, SpecularBoost, 80)
		ADD_STRUCT(float, DiffuseBoost, 76)
		ADD_STRUCT(float, EmissiveBoost, 72)
		ADD_STRUCT(float, EnvironmentIntensity, 68)
		ADD_STRUCT(Object::Color, EnvironmentColor, 64)
		ADD_STRUCT(int, NumIndirectLightingBounces, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
