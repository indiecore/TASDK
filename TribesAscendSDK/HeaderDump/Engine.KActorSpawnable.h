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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorSpawnable.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorSpawnable.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecycleInternal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorSpawnable.RecycleInternal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetComponents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorSpawnable.ResetComponents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
