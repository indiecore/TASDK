#pragma once
#include "Engine.Pawn.h"
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
	class Scout : public Pawn
	{
	public:
		class PathSizeInfo
		{
		public:
			ADD_STRUCT(byte, PathColor, 20)
			ADD_STRUCT(float, CrouchHeight, 16)
			ADD_STRUCT(float, Height, 12)
			ADD_STRUCT(float, Radius, 8)
			ADD_STRUCT(ScriptName, Desc, 0)
		};
		ADD_STRUCT(ScriptArray<Scout::PathSizeInfo>, PathSizes, 1144)
		ADD_STRUCT(ScriptArray<Object::Color>, EdgePathColors, 1184)
		ADD_STRUCT(float, MaxMantleFallTime, 1280)
		ADD_STRUCT(float, MaxMantleLateralDist, 1276)
		ADD_STRUCT(float, MinMantleLateralDist, 1272)
		ADD_STRUCT(float, MaxMantleFallDist, 1268)
		ADD_STRUCT(float, MinMantleFallDist, 1264)
		ADD_BOOL(bHightlightOneWayReachSpecs, 1260, 0x2)
		ADD_BOOL(NavMeshGen_ExpansionDoObstacleMeshSimplification, 1260, 0x1)
		ADD_STRUCT(float, NavMeshGen_MinEdgeLength, 1256)
		ADD_STRUCT(float, NavMeshGen_MaxGroundCheckSize, 1252)
		ADD_STRUCT(float, NavMeshGen_EdgeMaxDelta, 1248)
		ADD_STRUCT(float, NavMeshGen_HeightMergeThreshold, 1244)
		ADD_STRUCT(float, NavMeshGen_MaxPolyHeight, 1240)
		ADD_STRUCT(float, NavMeshGen_MinMergeDotLargeArea, 1236)
		ADD_STRUCT(float, NavMeshGen_MinMergeDotSmallArea, 1232)
		ADD_STRUCT(float, NavMeshGen_MinMergeDotAreaThreshold, 1228)
		ADD_STRUCT(float, NavMeshGen_BorderBackfill_CheckDist, 1224)
		ADD_STRUCT(float, NavMeshGen_MinPolyArea, 1220)
		ADD_STRUCT(float, NavMeshGen_VertZDeltaSnapThresh, 1216)
		ADD_STRUCT(float, NavMeshGen_MaxStepHeight, 1212)
		ADD_STRUCT(float, NavMeshGen_MaxDropHeight, 1208)
		ADD_STRUCT(float, NavMeshGen_StartingHeightOffset, 1204)
		ADD_STRUCT(float, NavMeshGen_EntityHalfHeight, 1200)
		ADD_STRUCT(float, NavMeshGen_StepSize, 1196)
		ADD_OBJECT(ScriptClass, DefaultReachSpecClass, 1180)
		ADD_STRUCT(int, MinNumPlayerStarts, 1176)
		ADD_STRUCT(float, MaxLandingVelocity, 1172)
		ADD_STRUCT(float, TestFallSpeed, 1168)
		ADD_STRUCT(float, TestMaxFallSpeed, 1164)
		ADD_STRUCT(float, TestGroundSpeed, 1160)
		ADD_STRUCT(float, TestJumpZ, 1156)
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Scout.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
