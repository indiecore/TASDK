#pragma once
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Scout." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Scout : public Pawn
	{
	public:
		ADD_VAR(::FloatProperty, MaxMantleFallTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxMantleLateralDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinMantleLateralDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxMantleFallDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinMantleFallDist, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHightlightOneWayReachSpecs, 0x2)
		ADD_VAR(::BoolProperty, NavMeshGen_ExpansionDoObstacleMeshSimplification, 0x1)
		ADD_VAR(::FloatProperty, NavMeshGen_MinEdgeLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_MaxGroundCheckSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_EdgeMaxDelta, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_HeightMergeThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_MaxPolyHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_MinMergeDotLargeArea, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_MinMergeDotSmallArea, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_MinMergeDotAreaThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_BorderBackfill_CheckDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_MinPolyArea, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_VertZDeltaSnapThresh, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_MaxStepHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_MaxDropHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_StartingHeightOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_EntityHalfHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NavMeshGen_StepSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinNumPlayerStarts, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxLandingVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TestFallSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TestMaxFallSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TestGroundSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TestJumpZ, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
