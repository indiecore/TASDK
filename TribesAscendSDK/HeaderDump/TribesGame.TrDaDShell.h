#pragma once
#include "Engine.InterpActor.h"
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
	class TrDaDShell : public InterpActor
	{
	public:
		ADD_BOOL(r_bShield0Up, 588, 0x1)
		ADD_BOOL(r_bShield1Up, 588, 0x2)
		ADD_BOOL(r_bShield2Up, 588, 0x4)
		ADD_BOOL(r_bIsRotating, 588, 0x8)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79707);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79709);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79710);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79711);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
