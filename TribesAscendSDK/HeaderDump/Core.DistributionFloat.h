#pragma once
#include "Core.Component.h"
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
	class DistributionFloat : public Component
	{
	public:
		struct RawDistributionFloat : public RawDistribution
		{
		};
		ADD_BOOL(bIsDirty, 76, 0x2)
		ADD_BOOL(bCanBeBaked, 76, 0x1)
		ADD_STRUCT(Object::Pointer, VfTable_FCurveEdInterface, 72)
		float GetFloatValue(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3432);
			byte params[8] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
