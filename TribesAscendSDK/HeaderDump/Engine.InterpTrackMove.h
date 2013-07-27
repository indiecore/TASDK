#pragma once
#include "Engine.InterpTrack.h"
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
	class InterpTrackMove : public InterpTrack
	{
	public:
		enum EInterpTrackMoveRotMode : byte
		{
			IMR_Keyframed = 0,
			IMR_LookAtGroup = 1,
			IMR_Ignore = 2,
			IMR_MAX = 3,
		};
		enum EInterpTrackMoveFrame : byte
		{
			IMF_World = 0,
			IMF_RelativeToInitial = 1,
			IMF_MAX = 2,
		};
		struct InterpLookupPoint
		{
		public:
			ADD_STRUCT(float, Time, 8)
			ADD_STRUCT(ScriptName, GroupName, 0)
		};
		struct InterpLookupTrack
		{
		public:
			ADD_STRUCT(ScriptArray<InterpTrackMove::InterpLookupPoint>, Points, 0)
		};
		ADD_STRUCT(InterpTrackMove::EInterpTrackMoveRotMode, RotMode, 193)
		ADD_STRUCT(InterpTrackMove::EInterpTrackMoveFrame, MoveFrame, 192)
		ADD_BOOL(bHide3DTrack, 188, 0x20)
		ADD_BOOL(bShowRotationOnCurveEd, 188, 0x10)
		ADD_BOOL(bShowTranslationOnCurveEd, 188, 0x8)
		ADD_BOOL(bDisableMovement, 188, 0x4)
		ADD_BOOL(bShowArrowAtKeys, 188, 0x2)
		ADD_BOOL(bUseQuatInterpolation, 188, 0x1)
		ADD_STRUCT(float, AngCurveTension, 184)
		ADD_STRUCT(float, LinCurveTension, 180)
		ADD_STRUCT(ScriptName, LookAtGroupName, 172)
		ADD_STRUCT(InterpTrackMove::InterpLookupTrack, LookupTrack, 160)
		ADD_STRUCT(Object::InterpCurveVector, EulerTrack, 144)
		ADD_STRUCT(Object::InterpCurveVector, PosTrack, 128)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
