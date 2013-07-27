#pragma once
#include "Core.Object.h"
#include "Engine.ParticleLODLevel.h"
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
	class ParticleEmitter : public Object
	{
	public:
		enum EEmitterRenderMode : byte
		{
			ERM_Normal = 0,
			ERM_Point = 1,
			ERM_Cross = 2,
			ERM_None = 3,
			ERM_MAX = 4,
		};
		enum EParticleSubUVInterpMethod : byte
		{
			PSUVIM_None = 0,
			PSUVIM_Linear = 1,
			PSUVIM_Linear_Blend = 2,
			PSUVIM_Random = 3,
			PSUVIM_Random_Blend = 4,
			PSUVIM_MAX = 5,
		};
		enum EParticleBurstMethod : byte
		{
			EPBM_Instant = 0,
			EPBM_Interpolated = 1,
			EPBM_MAX = 2,
		};
		class ParticleBurst
		{
		public:
			ADD_STRUCT(float, Time, 8)
			ADD_STRUCT(int, CountLow, 4)
			ADD_STRUCT(int, Count, 0)
		};
		ADD_STRUCT(ScriptArray<class ParticleLODLevel*>, LODLevels, 80)
		ADD_STRUCT(int, InitialAllocationCount, 100)
		ADD_STRUCT(int, PeakActiveParticles, 96)
		ADD_BOOL(bCookedOut, 92, 0x8)
		ADD_BOOL(bIsSoloing, 92, 0x4)
		ADD_BOOL(bCollapsed, 92, 0x2)
		ADD_BOOL(ConvertedModules, 92, 0x1)
		ADD_STRUCT(Object::Color, EmitterEditorColor, 76)
		ADD_STRUCT(ParticleEmitter::EEmitterRenderMode, EmitterRenderMode, 72)
		ADD_STRUCT(int, SubUVDataOffset, 68)
		ADD_STRUCT(ScriptName, EmitterName, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
