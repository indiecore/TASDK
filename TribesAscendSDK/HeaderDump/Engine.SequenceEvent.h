#pragma once
#include "Engine.SequenceOp.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SequenceEvent : public SequenceOp
	{
	public:
		ADD_BOOL(bEnabled, 244, 0x1)
		ADD_STRUCT(int, MaxTriggerCount, 236)
		ADD_STRUCT(int, TriggerCount, 232)
		ADD_BOOL(bPlayerOnly, 244, 0x2)
		ADD_STRUCT(ScriptArray<class SequenceEvent*>, DuplicateEvts, 208)
		ADD_STRUCT(int, MaxWidth, 252)
		ADD_STRUCT(byte, Priority, 248)
		ADD_BOOL(bClientSideOnly, 244, 0x8)
		ADD_BOOL(bRegistered, 244, 0x4)
		ADD_STRUCT(float, ReTriggerDelay, 240)
		ADD_STRUCT(float, ActivationTime, 228)
		ADD_OBJECT(Actor, Instigator, 224)
		ADD_OBJECT(Actor, Originator, 220)
		bool CheckActivate(class Actor* InOriginator, class Actor* InInstigator, bool bTest, ScriptArray<int>& ActivateIndices, bool bPushTop)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4292);
			byte params[32] = { NULL };
			*(class Actor**)params = InOriginator;
			*(class Actor**)&params[4] = InInstigator;
			*(bool*)&params[8] = bTest;
			*(ScriptArray<int>*)&params[12] = ActivateIndices;
			*(bool*)&params[24] = bPushTop;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActivateIndices = *(ScriptArray<int>*)&params[12];
			return *(bool*)&params[28];
		}
		void RegisterEvent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26085);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26092);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Toggled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26093);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
