#pragma once
#include "Core.Object.h"
#include "Engine.NxForceFieldComponent.h"
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
	class NxForceFieldCylindricalComponent : public NxForceFieldComponent
	{
	public:
		ADD_STRUCT(Object::Pointer, Kernel, 608)
		ADD_BOOL(UseSpecialRadialForce, 604, 0x1)
		ADD_STRUCT(float, HeightOffset, 600)
		ADD_STRUCT(float, ForceHeight, 596)
		ADD_STRUCT(float, EscapeVelocity, 592)
		ADD_STRUCT(float, LiftFalloffHeight, 588)
		ADD_STRUCT(float, ForceTopRadius, 584)
		ADD_STRUCT(float, ForceRadius, 580)
		ADD_STRUCT(float, LiftStrength, 576)
		ADD_STRUCT(float, RotationalStrength, 572)
		ADD_STRUCT(float, RadialStrength, 568)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
