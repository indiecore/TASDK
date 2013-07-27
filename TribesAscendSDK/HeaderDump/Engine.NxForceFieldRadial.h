#pragma once
#include "Engine.NxForceField.h"
#include "Core.Object.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.ForceFieldShape.h"
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
	class NxForceFieldRadial : public NxForceField
	{
	public:
		ADD_STRUCT(Object::Pointer, Kernel, 564)
		ADD_STRUCT(PrimitiveComponent::ERadialImpulseFalloff, ForceFalloff, 560)
		ADD_STRUCT(float, SelfRotationStrength, 556)
		ADD_STRUCT(float, ForceRadius, 552)
		ADD_STRUCT(float, ForceStrength, 548)
		ADD_OBJECT(ForceFieldShape, Shape, 540)
		void DoInitRBPhys()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21228);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
