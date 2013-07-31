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
	class InterpTrack : public Object
	{
	public:
		enum ETrackActiveCondition : byte
		{
			ETAC_Always = 0,
			ETAC_GoreEnabled = 1,
			ETAC_GoreDisabled = 2,
			ETAC_MAX = 3,
		};
		struct SubTrackGroup
		{
		public:
			ADD_STRUCT(ScriptArray<int>, TrackIndices, 12)
			ADD_BOOL(bIsSelected, 24, 0x2)
			ADD_BOOL(bIsCollapsed, 24, 0x1)
			ADD_STRUCT(ScriptString*, GroupName, 0)
		};
		struct SupportedSubTrackInfo
		{
		public:
			ADD_STRUCT(int, GroupIndex, 16)
			ADD_STRUCT(ScriptString*, SubTrackName, 4)
			ADD_OBJECT(ScriptClass, SupportedClass, 0)
		};
		ADD_STRUCT(ScriptArray<class InterpTrack*>, SubTracks, 68)
		ADD_STRUCT(ScriptArray<InterpTrack::SubTrackGroup>, SubTrackGroups, 80)
		ADD_STRUCT(ScriptArray<InterpTrack::SupportedSubTrackInfo>, SupportedSubTracks, 92)
		ADD_BOOL(bIsCollapsed, 124, 0x100)
		ADD_BOOL(bIsRecording, 124, 0x80)
		ADD_BOOL(bIsSelected, 124, 0x40)
		ADD_BOOL(bVisible, 124, 0x20)
		ADD_BOOL(bSubTrackOnly, 124, 0x10)
		ADD_BOOL(bIsAnimControlTrack, 124, 0x8)
		ADD_BOOL(bDisableTrack, 124, 0x4)
		ADD_BOOL(bDirGroupOnly, 124, 0x2)
		ADD_BOOL(bOnePerGroup, 124, 0x1)
		ADD_STRUCT(ScriptString*, TrackTitle, 112)
		ADD_STRUCT(InterpTrack::ETrackActiveCondition, ActiveCondition, 108)
		ADD_OBJECT(ScriptClass, TrackInstClass, 104)
		ADD_STRUCT(Object::Pointer, CurveEdVTable, 64)
		ADD_STRUCT(Object::Pointer, VfTable_FInterpEdInputInterface, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
