#pragma once
#include "Engine.NxForceField.h"
#include "Core.Object.h"
#include "Engine.ForceFieldShape.h"
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
	class NxForceFieldTornado : public NxForceField
	{
	public:
		ADD_STRUCT(Object::Pointer, Kernel, 592)
		ADD_STRUCT(float, SelfRotationStrength, 588)
		ADD_BOOL(BSpecialRadialForceMode, 584, 0x1)
		ADD_STRUCT(float, HeightOffset, 580)
		ADD_STRUCT(float, ForceHeight, 576)
		ADD_STRUCT(float, EscapeVelocity, 572)
		ADD_STRUCT(float, LiftFalloffHeight, 568)
		ADD_STRUCT(float, ForceTopRadius, 564)
		ADD_STRUCT(float, ForceRadius, 560)
		ADD_STRUCT(float, LiftStrength, 556)
		ADD_STRUCT(float, RotationalStrength, 552)
		ADD_STRUCT(float, RadialStrength, 548)
		ADD_OBJECT(ForceFieldShape, Shape, 540)
		void DoInitRBPhys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxForceFieldTornado.DoInitRBPhys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
