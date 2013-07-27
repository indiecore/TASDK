#pragma once
#include "Engine.SoundNode.h"
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
	class SoundNodeRandom : public SoundNode
	{
	public:
		ADD_STRUCT(ScriptArray<float>, Weights, 76)
		ADD_STRUCT(ScriptArray<bool>, HasBeenUsed, 92)
		ADD_STRUCT(int, NumRandomUsed, 104)
		ADD_BOOL(bRandomizeWithoutReplacement, 88, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
