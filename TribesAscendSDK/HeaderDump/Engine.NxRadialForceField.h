#pragma once
#include "Engine.NxForceField.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxRadialForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxRadialForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxRadialForceField : public NxForceField
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, LinearKernel, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ForceFalloff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceStrength, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
