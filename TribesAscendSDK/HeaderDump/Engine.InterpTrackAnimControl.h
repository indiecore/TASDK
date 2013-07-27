#pragma once
#include "Engine.InterpTrackFloatBase.h"
#include "Engine.AnimSet.h"
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
	class InterpTrackAnimControl : public InterpTrackFloatBase
	{
	public:
		class AnimControlTrackKey
		{
		public:
			ADD_BOOL(bReverse, 24, 0x2)
			ADD_BOOL(bLooping, 24, 0x1)
			ADD_STRUCT(float, AnimPlayRate, 20)
			ADD_STRUCT(float, AnimEndOffset, 16)
			ADD_STRUCT(float, AnimStartOffset, 12)
			ADD_STRUCT(ScriptName, AnimSeqName, 4)
			ADD_STRUCT(float, StartTime, 0)
		};
		ADD_STRUCT(ScriptArray<class AnimSet*>, AnimSets, 148)
		ADD_STRUCT(ScriptArray<InterpTrackAnimControl::AnimControlTrackKey>, AnimSeqs, 168)
		ADD_BOOL(bEnableRootMotion, 180, 0x1)
		ADD_STRUCT(ScriptName, SlotName, 160)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
