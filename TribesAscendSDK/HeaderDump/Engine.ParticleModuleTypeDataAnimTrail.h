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
	class ParticleModuleTypeDataAnimTrail : public ParticleModuleTypeDataBase
	{
	public:
		ADD_STRUCT(float, TangentTessellationScalar, 96)
		ADD_STRUCT(float, DistanceTessellationStepSize, 92)
		ADD_STRUCT(float, TilingDistance, 88)
		ADD_BOOL(bRenderTessellation, 84, 0x80)
		ADD_BOOL(bRenderTangents, 84, 0x40)
		ADD_BOOL(bRenderSpawnPoints, 84, 0x20)
		ADD_BOOL(bRenderGeometry, 84, 0x10)
		ADD_BOOL(bTangentRecalculationEveryFrame, 84, 0x8)
		ADD_BOOL(bEnablePreviousTangentRecalculation, 84, 0x4)
		ADD_BOOL(bClipSourceSegement, 84, 0x2)
		ADD_BOOL(bDeadTrailsOnDeactivate, 84, 0x1)
		ADD_STRUCT(int, SheetsPerTrail, 80)
		ADD_STRUCT(ScriptName, ControlEdgeName, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
