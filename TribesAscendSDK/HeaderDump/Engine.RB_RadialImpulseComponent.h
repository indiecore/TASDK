#pragma once
#include "Engine.PrimitiveComponent.h"
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
	class RB_RadialImpulseComponent : public PrimitiveComponent
	{
	public:
		ADD_BOOL(bCauseFracture, 500, 0x2)
		ADD_BOOL(bVelChange, 500, 0x1)
		ADD_STRUCT(float, ImpulseRadius, 496)
		ADD_STRUCT(float, ImpulseStrength, 492)
		ADD_STRUCT(PrimitiveComponent::ERadialImpulseFalloff, ImpulseFalloff, 488)
		void FireImpulse(Vector Origin)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25317);
			byte params[12] = { NULL };
			*(Vector*)params = Origin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
