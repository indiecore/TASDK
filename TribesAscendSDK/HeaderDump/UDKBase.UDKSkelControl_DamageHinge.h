#pragma once
#include "UDKBase.UDKSkelControl_Damage.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_DamageHinge : public UDKSkelControl_Damage
	{
	public:
		ADD_STRUCT(float, SpringStiffness, 392)
		ADD_STRUCT(float, CurrentAngle, 388)
		ADD_STRUCT(float, AVModifier, 384)
		ADD_STRUCT(Object::EAxis, PivotAxis, 380)
		ADD_STRUCT(float, MaxAngle, 376)
	};
}
#undef ADD_STRUCT
