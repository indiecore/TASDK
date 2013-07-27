#pragma once
#include "Engine.KActor.h"
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
	class KActorSpawnable : public KActor
	{
	public:
		ADD_BOOL(bScalingToZero, 712, 0x2)
		ADD_BOOL(bRecycleScaleToZero, 712, 0x1)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19080);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19081);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecycleInternal()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19082);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetComponents()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19083);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
