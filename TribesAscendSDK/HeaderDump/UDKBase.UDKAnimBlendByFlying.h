#pragma once
#include "UDKBase.UDKPawn.h"
#include "UDKBase.UDKAnimBlendBase.h"
#include "Engine.AnimNodeAimOffset.h"
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
	class UDKAnimBlendByFlying : public UDKAnimBlendBase
	{
	public:
		enum EFlyingState : byte
		{
			Flying_NotFlying = 0,
			Flying_OpeningWings = 1,
			Flying_Flying = 2,
			Flying_ClosingWings = 3,
			Flying_MAX = 4,
		};
		ADD_STRUCT(ScriptName, EndingAnimName, 324)
		ADD_BOOL(bHasEndingAnim, 320, 0x2)
		ADD_BOOL(bHasStartingAnim, 320, 0x1)
		ADD_STRUCT(ScriptName, StartingAnimName, 312)
		ADD_OBJECT(AnimNodeAimOffset, FlyingDir, 308)
		ADD_OBJECT(UDKAnimBlendBase, FlyingMode, 304)
		ADD_OBJECT(UDKPawn, Pawn, 300)
		ADD_STRUCT(UDKAnimBlendByFlying::EFlyingState, FlyingState, 296)
		void UpdateFlyingState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimBlendByFlying.UpdateFlyingState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
