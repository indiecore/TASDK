#pragma once
#include "Core.Component.h"
#include "Engine.Actor.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ActorComponent : public Component
	{
	public:
		ADD_STRUCT(Object::ETickingGroup, TickGroup, 84)
		ADD_BOOL(bNeedsUpdateTransform, 80, 0x8)
		ADD_BOOL(bNeedsReattach, 80, 0x4)
		ADD_BOOL(bTickInEditor, 80, 0x2)
		ADD_BOOL(bAttached, 80, 0x1)
		ADD_OBJECT(Actor, Owner, 76)
		ADD_STRUCT(Object::Pointer, Scene, 72)
		void SetTickGroup(Object::ETickingGroup NewTickGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4734);
			byte params[1] = { NULL };
			*(Object::ETickingGroup*)params = NewTickGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetComponentRBFixed(bool bFixed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4736);
			byte params[4] = { NULL };
			*(bool*)params = bFixed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceUpdate(bool bTransformOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4738);
			byte params[4] = { NULL };
			*(bool*)params = bTransformOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachFromAny()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4740);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
