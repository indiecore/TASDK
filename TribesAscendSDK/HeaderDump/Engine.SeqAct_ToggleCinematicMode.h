#pragma once
#include "Engine.SequenceAction.h"
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
namespace UnrealScript
{
	class SeqAct_ToggleCinematicMode : public SequenceAction
	{
	public:
		ADD_BOOL(bHidePlayer, 232, 0x4)
		ADD_BOOL(bHideHUD, 232, 0x10)
		ADD_BOOL(bDisableMovement, 232, 0x1)
		ADD_BOOL(bDisableTurning, 232, 0x2)
		ADD_BOOL(bDisableInput, 232, 0x8)
		ADD_BOOL(bDroppedPickups, 232, 0x40)
		ADD_BOOL(bDeadBodies, 232, 0x20)
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_ToggleCinematicMode.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
