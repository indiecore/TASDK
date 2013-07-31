#pragma once
#include "Engine.NxRadialForceField.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NxRadialCustomForceField : public NxRadialForceField
	{
	public:
		ADD_STRUCT(Object::Pointer, Kernel, 564)
		ADD_STRUCT(float, SelfRotationStrength, 560)
	};
}
#undef ADD_STRUCT
