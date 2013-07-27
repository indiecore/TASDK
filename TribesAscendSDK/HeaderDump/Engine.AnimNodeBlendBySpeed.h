#pragma once
#include "Engine.AnimNodeBlendList.h"
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
	class AnimNodeBlendBySpeed : public AnimNodeBlendList
	{
	public:
		ADD_STRUCT(ScriptArray<float>, Constraints, 296)
		ADD_STRUCT(float, BlendDelayRemaining, 320)
		ADD_STRUCT(float, BlendDownDelay, 316)
		ADD_STRUCT(float, BlendUpDelay, 312)
		ADD_BOOL(bUseAcceleration, 308, 0x1)
		ADD_STRUCT(float, BlendDownPerc, 292)
		ADD_STRUCT(float, BlendDownTime, 288)
		ADD_STRUCT(float, BlendUpTime, 284)
		ADD_STRUCT(int, LastChannel, 280)
		ADD_STRUCT(float, Speed, 276)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
