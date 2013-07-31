#pragma once
#include "Engine.AnimNodeBlendBySpeed.h"
#include "Engine.Actor.h"
#include "TribesGame.TrPawn.h"
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
	class TrAnimNodeBlendBySpeed : public AnimNodeBlendBySpeed
	{
	public:
		ADD_STRUCT(ScriptArray<float>, m_BaseSpeed, 328)
		ADD_STRUCT(ScriptArray<Actor::EPhysics>, m_IgnoredPhysics, 344)
		ADD_BOOL(m_bIgnoreZVelocity, 340, 0x1)
		ADD_OBJECT(TrPawn, m_TrPawn, 324)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
