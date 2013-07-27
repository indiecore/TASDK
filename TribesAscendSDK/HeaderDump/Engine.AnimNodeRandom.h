#pragma once
#include "Engine.AnimNodeBlendList.h"
#include "Engine.AnimNodeSequence.h"
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
	class AnimNodeRandom : public AnimNodeBlendList
	{
	public:
		class RandomAnimInfo
		{
		public:
			ADD_STRUCT(float, LastPosition, 28)
			ADD_STRUCT(byte, LoopCount, 24)
			ADD_BOOL(bStillFrame, 20, 0x1)
			ADD_STRUCT(Object::Vector2D, PlayRateRange, 12)
			ADD_STRUCT(float, BlendInTime, 8)
			ADD_STRUCT(byte, LoopCountMax, 5)
			ADD_STRUCT(byte, LoopCountMin, 4)
			ADD_STRUCT(float, Chance, 0)
		};
		ADD_STRUCT(ScriptArray<AnimNodeRandom::RandomAnimInfo>, RandomInfo, 276)
		ADD_BOOL(bPickedPendingChildIndex, 296, 0x1)
		ADD_STRUCT(int, PendingChildIndex, 292)
		ADD_OBJECT(AnimNodeSequence, PlayingSeqNode, 288)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
