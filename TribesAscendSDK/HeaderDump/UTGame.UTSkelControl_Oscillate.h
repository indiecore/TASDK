#pragma once
#include "Engine.SkelControlSingleBone.h"
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
namespace UnrealScript
{
	class UTSkelControl_Oscillate : public SkelControlSingleBone
	{
	public:
		ADD_BOOL(bReverseDirection, 256, 0x1)
		ADD_STRUCT(float, CurrentTime, 252)
		ADD_STRUCT(float, Period, 248)
		ADD_STRUCT(Vector, MaxDelta, 236)
		void TickSkelControl(float DeltaTime, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49375);
			byte params[8] = { NULL };
			*(float*)params = DeltaTime;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
