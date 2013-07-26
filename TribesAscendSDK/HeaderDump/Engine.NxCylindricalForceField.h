#pragma once
#include "Engine.NxForceField.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxCylindricalForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxCylindricalForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxCylindricalForceField : public NxForceField
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Kernel, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, UseSpecialRadialForce, 0x1)
		ADD_VAR(::FloatProperty, HeightOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EscapeVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LiftFalloffHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceTopRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LiftStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotationalStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialStrength, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
