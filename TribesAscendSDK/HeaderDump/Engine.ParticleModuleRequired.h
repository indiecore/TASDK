#pragma once
#include "Engine.ParticleModule.h"
#include "Engine.ParticleEmitter.h"
#include "Core.Object.h"
#include "Core.DistributionFloat.h"
#include "Engine.MaterialInterface.h"
#include "Engine.ParticleSpriteEmitter.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ParticleModuleRequired : public ParticleModule
	{
	public:
		enum EEmitterNormalsMode : byte
		{
			ENM_CameraFacing = 0,
			ENM_Spherical = 1,
			ENM_Cylindrical = 2,
			ENM_MAX = 3,
		};
		enum EParticleSortMode : byte
		{
			PSORTMODE_None = 0,
			PSORTMODE_ViewProjDepth = 1,
			PSORTMODE_DistanceToView = 2,
			PSORTMODE_Age_OldestFirst = 3,
			PSORTMODE_Age_NewestFirst = 4,
			PSORTMODE_MAX = 5,
		};
		ADD_STRUCT(ScriptArray<ParticleEmitter::ParticleBurst>, BurstList, 128)
		ADD_STRUCT(Vector, NormalsCylinderDirection, 184)
		ADD_STRUCT(Vector, NormalsSphereCenter, 172)
		ADD_STRUCT(float, DownsampleThresholdScreenFraction, 168)
		ADD_STRUCT(int, MaxDrawCount, 164)
		ADD_STRUCT(int, RandomImageChanges, 160)
		ADD_STRUCT(float, RandomImageTime, 156)
		ADD_STRUCT(int, SubImages_Vertical, 152)
		ADD_STRUCT(int, SubImages_Horizontal, 148)
		ADD_STRUCT(float, EmitterDelayLow, 144)
		ADD_STRUCT(float, EmitterDelay, 140)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, SpawnRate, 100)
		ADD_STRUCT(int, EmitterLoops, 96)
		ADD_STRUCT(float, EmitterDurationLow, 92)
		ADD_STRUCT(float, EmitterDuration, 88)
		ADD_BOOL(bUseMaxDrawCount, 84, 0x800)
		ADD_BOOL(bDirectUV, 84, 0x400)
		ADD_BOOL(bScaleUV, 84, 0x200)
		ADD_BOOL(bDelayFirstLoopOnly, 84, 0x100)
		ADD_BOOL(bEmitterDelayUseRange, 84, 0x80)
		ADD_BOOL(bDurationRecalcEachLoop, 84, 0x40)
		ADD_BOOL(bEmitterDurationUseRange, 84, 0x20)
		ADD_BOOL(bUseLegacyEmitterTime, 84, 0x10)
		ADD_BOOL(bRequiresSorting, 84, 0x8)
		ADD_BOOL(bKillOnCompleted, 84, 0x4)
		ADD_BOOL(bKillOnDeactivate, 84, 0x2)
		ADD_BOOL(bUseLocalSpace, 84, 0x1)
		ADD_STRUCT(ParticleModuleRequired::EEmitterNormalsMode, EmitterNormalsMode, 80)
		ADD_STRUCT(ParticleEmitter::EParticleSubUVInterpMethod, InterpolationMethod, 79)
		ADD_STRUCT(ParticleEmitter::EParticleBurstMethod, ParticleBurstMethod, 78)
		ADD_STRUCT(ParticleModuleRequired::EParticleSortMode, SortMode, 77)
		ADD_OBJECT(MaterialInterface, Material, 72)
		ADD_STRUCT(ParticleSpriteEmitter::EParticleScreenAlignment, ScreenAlignment, 76)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
