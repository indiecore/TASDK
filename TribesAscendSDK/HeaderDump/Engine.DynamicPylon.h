#pragma once
#include "Engine.Pylon.h"
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
	class DynamicPylon : public Pylon
	{
	public:
		ADD_BOOL(bMoving, 832, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14852);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RebuildDynamicEdges()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14853);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlushDynamicEdges()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14854);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartedMoving()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14855);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StoppedMoving()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14856);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
