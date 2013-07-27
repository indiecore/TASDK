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
	class ParticleModuleTypeDataRibbon : public ParticleModuleTypeDataBase
	{
	public:
		enum ETrailsRenderAxisOption : byte
		{
			Trails_CameraUp = 0,
			Trails_SourceUp = 1,
			Trails_WorldUp = 2,
			Trails_MAX = 3,
		};
		ADD_STRUCT(float, TangentTessellationScalar, 108)
		ADD_STRUCT(float, DistanceTessellationStepSize, 104)
		ADD_STRUCT(float, TilingDistance, 100)
		ADD_STRUCT(float, TangentSpawningScalar, 96)
		ADD_STRUCT(ParticleModuleTypeDataRibbon::ETrailsRenderAxisOption, RenderAxis, 92)
		ADD_STRUCT(int, MaxTessellationBetweenParticles, 72)
		ADD_BOOL(bRenderTessellation, 88, 0x100)
		ADD_BOOL(bRenderTangents, 88, 0x80)
		ADD_BOOL(bRenderSpawnPoints, 88, 0x40)
		ADD_BOOL(bRenderGeometry, 88, 0x20)
		ADD_BOOL(bTangentRecalculationEveryFrame, 88, 0x10)
		ADD_BOOL(bEnablePreviousTangentRecalculation, 88, 0x8)
		ADD_BOOL(bClipSourceSegement, 88, 0x4)
		ADD_BOOL(bDeadTrailsOnSourceLoss, 88, 0x2)
		ADD_BOOL(bDeadTrailsOnDeactivate, 88, 0x1)
		ADD_STRUCT(int, MaxParticleInTrailCount, 84)
		ADD_STRUCT(int, MaxTrailCount, 80)
		ADD_STRUCT(int, SheetsPerTrail, 76)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
