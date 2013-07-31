#pragma once
#include "Core.Object.h"
#include "Engine.PostProcessEffect.h"
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
	class AmbientOcclusionEffect : public PostProcessEffect
	{
	public:
		enum EAmbientOcclusionQuality : byte
		{
			AO_High = 0,
			AO_Medium = 1,
			AO_Low = 2,
			AO_MAX = 3,
		};
		ADD_STRUCT(float, HistoryWeightConvergenceTime, 188)
		ADD_STRUCT(float, HistoryConvergenceTime, 184)
		ADD_STRUCT(int, FilterSize, 180)
		ADD_STRUCT(float, FilterDistanceScale, 176)
		ADD_STRUCT(float, EdgeDistanceScale, 172)
		ADD_STRUCT(float, EdgeDistanceThreshold, 168)
		ADD_STRUCT(float, HaloOcclusion, 164)
		ADD_STRUCT(float, HaloDistanceScale, 160)
		ADD_STRUCT(float, HaloDistanceThreshold, 156)
		ADD_STRUCT(float, OcclusionFadeoutMaxDistance, 152)
		ADD_STRUCT(float, OcclusionFadeoutMinDistance, 148)
		ADD_STRUCT(AmbientOcclusionEffect::EAmbientOcclusionQuality, OcclusionQuality, 144)
		ADD_STRUCT(Object::LinearColor, OcclusionColor, 100)
		ADD_STRUCT(float, OcclusionAttenuation, 140)
		ADD_STRUCT(float, OcclusionRadius, 136)
		ADD_BOOL(bAngleBasedSSAO, 132, 0x2)
		ADD_BOOL(SSAO2, 132, 0x1)
		ADD_STRUCT(float, MinOcclusion, 128)
		ADD_STRUCT(float, OcclusionBias, 124)
		ADD_STRUCT(float, OcclusionScale, 120)
		ADD_STRUCT(float, OcclusionPower, 116)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
