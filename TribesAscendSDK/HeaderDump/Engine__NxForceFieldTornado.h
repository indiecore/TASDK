#pragma once
#include "Engine__NxForceField.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxForceFieldTornado." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxForceFieldTornado." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NxForceFieldTornado." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NxForceFieldTornado : public NxForceField
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Kernel'!
		ADD_VAR(::FloatProperty, SelfRotationStrength, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, BSpecialRadialForceMode, 0x1)
		ADD_VAR(::FloatProperty, HeightOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EscapeVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LiftFalloffHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceTopRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LiftStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotationalStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialStrength, 0xFFFFFFFF)
		ADD_OBJECT(ForceFieldShape, Shape)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
