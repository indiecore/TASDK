#pragma once
#include "Engine.NxGenericForceField.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NxGenericForceFieldCapsule : public NxGenericForceField
	{
	public:
		ADD_STRUCT(float, CapsuleRadius, 704)
		ADD_STRUCT(float, CapsuleHeight, 700)
	};
}
#undef ADD_STRUCT
