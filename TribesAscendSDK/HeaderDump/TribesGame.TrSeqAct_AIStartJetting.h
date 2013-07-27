#pragma once
#include "Engine.SequenceAction.h"
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
	class TrSeqAct_AIStartJetting : public SequenceAction
	{
	public:
		ADD_BOOL(m_bResetVelocity, 248, 0x1)
		ADD_STRUCT(Object::Vector, Direction, 236)
		ADD_STRUCT(float, Magnitude, 232)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
