#pragma once
#include "Engine.NxForceField.h"
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
	class NxTornadoAngularForceField : public NxForceField
	{
	public:
		ADD_STRUCT(Object::Pointer, Kernel, 584)
		ADD_STRUCT(float, SelfRotationStrength, 580)
		ADD_BOOL(BSpecialRadialForceMode, 576, 0x1)
		ADD_STRUCT(float, HeightOffset, 572)
		ADD_STRUCT(float, ForceHeight, 568)
		ADD_STRUCT(float, EscapeVelocity, 564)
		ADD_STRUCT(float, LiftFalloffHeight, 560)
		ADD_STRUCT(float, ForceTopRadius, 556)
		ADD_STRUCT(float, ForceRadius, 552)
		ADD_STRUCT(float, LiftStrength, 548)
		ADD_STRUCT(float, RotationalStrength, 544)
		ADD_STRUCT(float, RadialStrength, 540)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
