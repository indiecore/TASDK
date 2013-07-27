#pragma once
#include "Engine.PBRuleNodeBase.h"
#include "Engine.ProcBuilding.h"
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
	class PBRuleNodeCorner : public PBRuleNodeBase
	{
	public:
		class RBCornerAngleInfo
		{
		public:
			ADD_STRUCT(float, CornerSize, 4)
			ADD_STRUCT(float, Angle, 0)
		};
		ADD_STRUCT(ScriptArray<PBRuleNodeCorner::RBCornerAngleInfo>, Angles, 108)
		ADD_STRUCT(float, RoundCurvature, 140)
		ADD_STRUCT(int, RoundTesselation, 136)
		ADD_STRUCT(float, CornerShapeOffset, 132)
		ADD_STRUCT(ProcBuilding::EPBCornerType, CornerType, 128)
		ADD_BOOL(bUseAdjacentRulesetForRightGap, 124, 0x2)
		ADD_BOOL(bNoMeshForConcaveCorners, 124, 0x1)
		ADD_STRUCT(float, FlatThreshold, 120)
		ADD_STRUCT(float, CornerSize, 104)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
