#pragma once
#include "Engine.InterpTrack.h"
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
	class InterpTrackHeadTracking : public InterpTrack
	{
	public:
		enum EHeadTrackingAction : byte
		{
			EHTA_DisableHeadTracking = 0,
			EHTA_EnableHeadTracking = 1,
			EHTA_MAX = 2,
		};
		struct HeadTrackingKey
		{
		public:
			ADD_STRUCT(InterpTrackHeadTracking::EHeadTrackingAction, Action, 4)
			ADD_STRUCT(float, Time, 0)
		};
		ADD_STRUCT(ScriptArray<InterpTrackHeadTracking::HeadTrackingKey>, HeadTrackingTrack, 128)
		ADD_STRUCT(ScriptArray<ScriptName>, TrackControllerName, 140)
		ADD_STRUCT(ScriptArray<ScriptClass*>, ActorClassesToLookAt, 172)
		ADD_STRUCT(ScriptArray<ScriptName>, TargetBoneNames, 184)
		ADD_STRUCT(float, MaxInterestTime, 168)
		ADD_STRUCT(float, MinLookAtTime, 164)
		ADD_STRUCT(float, MaxLookAtTime, 160)
		ADD_BOOL(bLookAtPawns, 156, 0x2)
		ADD_BOOL(bDisableBeyondLimit, 156, 0x1)
		ADD_STRUCT(float, LookAtActorRadius, 152)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
