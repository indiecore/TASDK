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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ParticleModule : public Object
	{
	public:
		enum EModuleType : byte
		{
			EPMT_General = 0,
			EPMT_TypeData = 1,
			EPMT_Beam = 2,
			EPMT_Trail = 3,
			EPMT_Spawn = 4,
			EPMT_Required = 5,
			EPMT_Event = 6,
			EPMT_MAX = 7,
		};
		enum EParticleSourceSelectionMethod : byte
		{
			EPSSM_Random = 0,
			EPSSM_Sequential = 1,
			EPSSM_MAX = 2,
		};
		struct ParticleCurvePair
		{
		public:
			ADD_OBJECT(Object, CurveObject, 12)
			ADD_STRUCT(ScriptString*, CurveName, 0)
		};
		struct ParticleRandomSeedInfo
		{
		public:
			ADD_STRUCT(ScriptArray<int>, RandomSeeds, 12)
			ADD_BOOL(bResetSeedOnEmitterLooping, 8, 0x4)
			ADD_BOOL(bInstanceSeedIsIndex, 8, 0x2)
			ADD_BOOL(bGetSeedFromInstance, 8, 0x1)
			ADD_STRUCT(ScriptName, ParameterName, 0)
		};
		ADD_STRUCT(Object::Color, ModuleEditorColor, 68)
		ADD_STRUCT(byte, LODValidity, 64)
		ADD_BOOL(bRequiresLoopingNotification, 60, 0x400)
		ADD_BOOL(bSupportsRandomSeed, 60, 0x200)
		ADD_BOOL(LODDuplicate, 60, 0x100)
		ADD_BOOL(bEditable, 60, 0x80)
		ADD_BOOL(bEnabled, 60, 0x40)
		ADD_BOOL(bSupported3DDrawMode, 60, 0x20)
		ADD_BOOL(b3DDrawMode, 60, 0x10)
		ADD_BOOL(bCurvesAsColor, 60, 0x8)
		ADD_BOOL(bFinalUpdateModule, 60, 0x4)
		ADD_BOOL(bUpdateModule, 60, 0x2)
		ADD_BOOL(bSpawnModule, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
