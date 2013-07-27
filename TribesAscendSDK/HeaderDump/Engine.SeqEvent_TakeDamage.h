#pragma once
#include "Engine.SequenceEvent.h"
#include "Engine.Actor.h"
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
	class SeqEvent_TakeDamage : public SequenceEvent
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptClass*>, DamageTypes, 264)
		ADD_STRUCT(ScriptArray<ScriptClass*>, IgnoreDamageTypes, 276)
		ADD_BOOL(bResetDamageOnToggle, 292, 0x1)
		ADD_STRUCT(float, CurrentDamage, 288)
		ADD_STRUCT(float, DamageThreshold, 260)
		ADD_STRUCT(float, MinDamageAmount, 256)
		bool IsValidDamageType(ScriptClass* inDamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26157);
			byte params[8] = { NULL };
			*(ScriptClass**)params = inDamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void HandleDamage(class Actor* InOriginator, class Actor* InInstigator, ScriptClass* inDamageType, int inAmount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26162);
			byte params[16] = { NULL };
			*(class Actor**)params = InOriginator;
			*(class Actor**)&params[4] = InInstigator;
			*(ScriptClass**)&params[8] = inDamageType;
			*(int*)&params[12] = inAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26170);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26171);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void Toggled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26173);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
