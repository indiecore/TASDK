#pragma once
#include "Engine.NxRadialForceField.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxRadialCustomForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxRadialCustomForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxRadialCustomForceField : public NxRadialForceField
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Kernel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SelfRotationStrength, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
